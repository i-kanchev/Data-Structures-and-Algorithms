// https://www.hackerrank.com/contests/sda-hw-5-2022/challenges/challenge-3723

#include <algorithm>
#include <climits>
#include <iostream>
#include <iterator>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned N, k;
    int min = INT_MAX;
    long long sum = 0;
    cin >> N >> k;

    deque<int> diligence;

    for (unsigned i = 0; i < k; i++)
    {
        int p;
        cin >> p;

        if (p < min)
            min = p;

        diligence.push_back(p);
    }

    sum += min;

    for (unsigned i = 0; i < N - k; i++)
    {
        int first = diligence.front();
        diligence.pop_front();

        if (first == min)
        {
            deque<int>::iterator it = min_element(diligence.begin(), diligence.end());
            min = *it;
        }

        int p;
        cin >> p;
        diligence.push_back(p);

        if (p < min)
            min = p;

        sum += min;
    }

    cout << sum;
}