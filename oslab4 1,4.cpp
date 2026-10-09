
#include <iostream>
#include <thread>
using namespace std;

void worker_fn() {
    for (int i = 1; i <= 3; i++) {
        cout << "Worker thread is running: " << i << endl;
    }
    cout << "Worker thread finished." << endl;
}

class AutoThread {
    thread t;

public:
    AutoThread(void (*func)()) : t(func) {}

    ~AutoThread() {
        if (t.joinable()) {
            t.join();
        }
    }
};

int main() {
    cout << "Main thread started." << endl;

    {
        AutoThread jt(worker_fn);
        cout << "Thread created." << endl;
        cout << "Leaving scope..." << endl;
    } // Destructor automatically joins the thread

    cout << "Worker completed. Main thread continues." << endl;

    return 0;
}