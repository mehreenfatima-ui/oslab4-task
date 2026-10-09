
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

const int N = 3;
int arrived = 0;
int phase = 1;

mutex m;
condition_variable cv;

void worker(int id) {
    cout << "Thread " << id << " completed Phase 1." << endl;

    unique_lock<mutex> lock(m);
    arrived++;

    if (arrived == N) {
        arrived = 0;
        phase++;
        cv.notify_all();
    } else {
        cv.wait(lock, [] { return phase == 2; });
    }

    lock.unlock();

    cout << "Thread " << id << " started Phase 2." << endl;
}

int main() {
    thread t1(worker, 1);
    thread t2(worker, 2);
    thread t3(worker, 3);

    t1.join();
    t2.join();
    t3.join();

    cout << "All threads completed." << endl;
    return 0;
}