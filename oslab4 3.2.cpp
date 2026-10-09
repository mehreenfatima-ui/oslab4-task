
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int accountA = 1000;
int accountB = 2000;

mutex mtxA;
mutex mtxB;

void transfer_funds() {
    // Lock both mutexes without deadlock
    lock(mtxA, mtxB);

    // Adopt the locks so they unlock automatically
    lock_guard<mutex> lock1(mtxA, adopt_lock);
    lock_guard<mutex> lock2(mtxB, adopt_lock);

    accountA -= 100;
    accountB += 100;

    cout << "Money transferred successfully." << endl;
    cout << "Account A balance: " << accountA << endl;
    cout << "Account B balance: " << accountB << endl;
}

int main() {
    thread t1(transfer_funds);
    thread t2(transfer_funds);

    t1.join();
    t2.join();

    cout << "\nAll transfers completed." << endl;

    return 0;
}