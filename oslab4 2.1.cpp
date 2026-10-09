
#include <iostream>
#include <thread>
using namespace std;

int counter = 0;
const int N = 1000000;

void increment_routine() {
    for (int i = 0; i < N; i++) {
        counter++;  // Race condition: no synchronization
    }
}

int main() {
    thread t1(increment_routine);
    thread t2(increment_routine);

    t1.join();
    t2.join();

    cout << "Expected counter: " << 2 * N << endl;
    cout << "Actual counter: " << counter << endl;

    return 0;
}