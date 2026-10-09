
#include <iostream>
#include <thread>
#include <mutex>
#include <algorithm>
using namespace std;

const int N = 5;
mutex forks[N];

void dine(int id)
{
    int left = id;
    int right = (id + 1) % N;

    int first = min(left, right);
    int second = max(left, right);

    cout << "Philosopher " << id << " is thinking." << endl;

    {
        unique_lock<mutex> l1(forks[first]);
        unique_lock<mutex> l2(forks[second]);

        cout << "Philosopher " << id << " is eating." << endl;
    }

    cout << "Philosopher " << id << " finished eating." << endl;
}

int main()
{
    thread philosophers[N];

    for (int i = 0; i < N; i++)
        philosophers[i] = thread(dine, i);

    for (int i = 0; i < N; i++)
        philosophers[i].join();

    cout << "All philosophers finished." << endl;

    return 0;
}