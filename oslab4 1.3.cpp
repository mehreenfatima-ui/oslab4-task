
#include <iostream>
#include <thread>
#include <chrono>
using namespace std;

void logger() {
    for (int i = 1; i <= 5; i++) {
        cout << "Background logger working... " << i << endl;

        // Simulate flushing data to disk
        this_thread::sleep_for(chrono::seconds(1));
    }

    cout << "Logger thread finished." << endl;
}

int main() {
    cout << "Main thread started." << endl;

    thread t(logger);

    t.detach();

    cout << "Logger thread detached from main thread." << endl;
    cout << "Main thread will continue working." << endl;

    // Keep main alive so the background thread can finish
    this_thread::sleep_for(chrono::seconds(6));

    cout << "Main thread finished." << endl;

    return 0;
}