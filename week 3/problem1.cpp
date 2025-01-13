// https://www.hackerrank.com/contests/sda-hw-3-2022/challenges/challenge-3668

#include <iostream>

using namespace std;

unsigned candySearch(long long index, long long left, long long right, unsigned& value)
{
    long long mid1 = left + (right - left) / 3;
    long long mid2 = left + 2 * (right - left) / 3;

    if (mid1 == mid2)
        return value;

    if (index <= mid1)
        candySearch(index, left, mid1, ++value);
    else if (index > mid2)
        candySearch(index, mid2 + 1, right, ++value);

    return value;
}

int main()
{
    unsigned P, N;

    cin >> P >> N;

    long long size = 1;

    for (size_t i = 0; i < P; i++)
        size *= 3;

    for (size_t i = 0; i < N; i++)
    {
        long long index;
        cin >> index;
        unsigned value = 1;
        cout << candySearch(index, 1 , size, value) << '\n';
    }

    return 0;
}