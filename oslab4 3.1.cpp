
#include <iostream>
#include <thread>
#include <shared_mutex>
using namespace std;

int data = 100;
shared_mutex rw_mtx;

void reader(int id) {
    shared_lock<shared_mutex> lock(rw_mtx);

    cout << "Reader " << id << " reads data: "
         << data << endl;
}

void writer() {
    unique_lock<shared_mutex> lock(rw_mtx);

    data = data + 50;
    cout << "Writer updates data to: "
         << data << endl;
}

int main() {
    thread r1(reader, 1);
    thread r2(reader, 2);
    r1.join();
    r2.join();

    thread w(writer);
    w.join();

    thread r3(reader, 3);
    r3.join();

    return 0;
}