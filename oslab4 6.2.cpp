
#include <iostream>
#include <thread>
#include <atomic>
#include <chrono>
using namespace std;

atomic<bool> stop_requested(false);

void worker()
{
    while (!stop_requested)
    {
        cout << "Worker is doing work..." << endl;
        this_thread::sleep_for(chrono::milliseconds(500));
    }

    cout << "Stop requested. Cleaning up resources..." << endl;
    cout << "Worker stopped safely." << endl;
}

int main()
{
    thread t(worker);

    this_thread::sleep_for(chrono::seconds(2));

    cout << "Main: Requesting worker to stop." << endl;
    stop_requested = true;

    t.join();

    cout << "Main: Program finished." << endl;

    return 0;
}