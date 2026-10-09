
#include <iostream>
#include <thread>
#include <mutex>
using namespace std;

int counter = 0;
const int N = 100000;

mutex mtx;

void safe_increment() {
    for (int i = 0; i < N; i++) {
        lock_guard<mutex> lock(mtx);
        counter++;
    }
}

int main() {
    thread t1(safe_increment);
    thread t2(safe_increment);

    t1.join();
    t2.join();

    cout << "Expected counter: " << 2 * N << endl;
    cout << "Actual counter: " << counter << endl;

    return 0;
}