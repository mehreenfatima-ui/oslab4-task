
#include <iostream>
#include <thread>
#include <atomic>
using namespace std;

atomic<int> counter(0);
const int N = 100000;

void atomic_worker() {
    for (int i = 0; i < N; i++) {
        counter.fetch_add(1, memory_order_relaxed);
    }
}

int main() {
    thread t1(atomic_worker);
    thread t2(atomic_worker);

    t1.join();
    t2.join();

    cout << "Expected counter: " << 2 * N << endl;
    cout << "Actual counter: " << counter.load() << endl;

    return 0;
}