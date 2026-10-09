
#include <iostream>
#include <thread>
#include <future>
using namespace std;

void worker(promise<int> &prom) {
    int result = 42;
    cout << "Worker: Calculating result..." << endl;

    prom.set_value(result);
}

int main() {
    promise<int> prom;
    future<int> fut = prom.get_future();

    thread t(worker, ref(prom));

    cout << "Main: Waiting for result..." << endl;

    int result = fut.get();

    cout << "Main: Received result = " << result << endl;

    t.join();

    return 0;
}