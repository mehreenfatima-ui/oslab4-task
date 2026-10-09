
#include <iostream>
#include <thread>
#include <functional>
using namespace std;

void worker(int val, int& ref) {
    val = val + 10;
    ref = ref + 10;

    cout << "Inside thread:" << endl;
    cout << "Value parameter = " << val << endl;
    cout << "Reference parameter = " << ref << endl;
}

int main() {
    int local_x = 5;
    int local_y = 10;

    cout << "Before thread:" << endl;
    cout << "local_x = " << local_x << endl;
    cout << "local_y = " << local_y << endl;

    thread t(worker, local_x, ref(local_y));

    t.join();

    cout << "\nAfter thread:" << endl;
    cout << "local_x = " << local_x << endl;
    cout << "local_y = " << local_y << endl;

    return 0;
}