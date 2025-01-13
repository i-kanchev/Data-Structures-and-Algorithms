// https://www.hackerrank.com/contests/sda-hw-8-2022/challenges/elitism

#include <iostream>
#include <iomanip>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);

    unsigned N;
    cin >> N;

    priority_queue<unsigned> lowerPart;
    priority_queue<unsigned, vector<unsigned>, greater<unsigned>> upperPart;

    for (size_t i = 0; i < N; i++)
    {
        unsigned a;
        cin >> a;

        if (lowerPart.empty() || a <= lowerPart.top())
            lowerPart.push(a);
        else
            upperPart.push(a);

        int sizeDiff = upperPart.size() - lowerPart.size();

        if (sizeDiff == 2)
        {
            unsigned temp = upperPart.top();
            upperPart.pop();
            lowerPart.push(temp);
        }
        else if (sizeDiff == -2)
        {
            unsigned temp = lowerPart.top();
            lowerPart.pop();
            upperPart.push(temp);
        }

        if (sizeDiff == 1)
            cout << fixed << setprecision(1) << (double) upperPart.top() << '\n';
        else if (sizeDiff == -1)
            cout << fixed << setprecision(1) << (double) lowerPart.top() << '\n';
        else
            cout << fixed << setprecision(1) << (double) lowerPart.top() + (double) (upperPart.top() - lowerPart.top()) / 2 << '\n';

    }

    return 0;
}