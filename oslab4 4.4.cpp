
#include <iostream>
#include <thread>
#include <mutex>
#include <condition_variable>
using namespace std;

bool ready = false;
mutex m;
condition_variable cv;

void worker(int id) {
    {
        unique_lock<mutex> lock(m);
        cv.wait(lock, [] { return ready; });
    }

    cout << "Worker " << id << " started benchmarking." << endl;
}

int main() {
    thread t1(worker, 1);
    thread t2(worker, 2);
    thread t3(worker, 3);

    cout << "Main: Preparing shared memory..." << endl;

    {
        lock_guard<mutex> lock(m);
        ready = true;
    }

    cv.notify_all();

    t1.join();
    t2.join();
    t3.join();

    cout << "All workers completed." << endl;

    return 0;
}