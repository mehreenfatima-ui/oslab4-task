
#include <iostream>
#include <future>
using namespace std;

int heavy_calc(int n) {
    int result = 0;

    for (int i = 1; i <= n; i++) {
        result += i;
    }

    return result;
}

int main() {
    cout << "Main: Starting calculation..." << endl;

    future<int> fut = async(launch::async, heavy_calc, 10);

    cout << "Main: Doing other work..." << endl;

    int res = fut.get();

    cout << "Final result = " << res << endl;

    return 0;
}