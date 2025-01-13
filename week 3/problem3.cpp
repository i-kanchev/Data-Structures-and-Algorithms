// https://www.hackerrank.com/contests/sda-hw-3-2022/challenges/challenge-3670

#include <iostream>
#include <vector>

using namespace std;

bool trySplitting(const vector<long long>& devs, const unsigned N, const unsigned T, const long long value)
{
    long long temp = 0, counter = 1;

    for (size_t i = 0; i < N; i++)
    {
        if (temp + devs[i] <= value)
            temp += devs[i];
        else
        {
            temp = devs[i];
            counter++;
        }
    }

    return counter <= T;
}

long long bestSplitting(const vector<long long>& devs, const unsigned N, const unsigned T)
{
    long long lValue = 0, rValue = 0;

    for (size_t i = 0; i < N; i++)
    {
        if (devs[i] > lValue)
            lValue = devs[i];
        rValue += devs[i];
    }

    long long bestValue = 0;

    while (lValue <= rValue)
    {
        long long value = lValue + (rValue - lValue) / 2;

        if (trySplitting(devs, N, T, value))
        {
            bestValue = value;
            rValue = value - 1;
        }
        else
            lValue = value + 1;
    }

    return bestValue;
}

int main()
{
    unsigned N, T;

    cin >> N >> T;

    vector<long long> devs(N);

    for (size_t i = 0; i < N; i++)
        cin >> devs[i];

    cout << bestSplitting(devs, N, T);

    return 0;
}