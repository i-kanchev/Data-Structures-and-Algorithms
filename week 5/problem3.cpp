// https://www.hackerrank.com/contests/sda-hw-5-2022/challenges/challenge-3722

#include <iostream>
#include <stack>
#include <queue>

using namespace std;

void resolveConfrontation(stack<int>& positive, queue<int>& negative)
{
    while (!positive.empty() && !negative.empty())
    {
        if (positive.top() > -negative.front())
            negative.pop();
        else if (positive.top() < -negative.front())
            positive.pop();
        else
        {
            negative.pop();
            positive.pop();
        }
    }

    if (negative.empty())
        return;

    while (!negative.empty())
    {
        cout << negative.front() << ' ';
        negative.pop();
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned N;
    cin >> N;

    bool confrontation = false;

    stack<int> positive;
    queue<int> negative;

    for (unsigned i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;

        if (!confrontation)
        {
            if (temp < 0)
                cout << temp << ' ';
            else if (temp > 0)
            {
                confrontation = true;
                positive.push(temp);
            }

            continue;
        }

        if (temp < 0)
            negative.push(temp);
        else if (temp > 0)
        {
            resolveConfrontation(positive, negative);
            positive.push(temp);
        }
    }

    resolveConfrontation(positive, negative);

    if (!positive.empty())
    {
        stack<int> positiveRotate;

        while (!positive.empty())
        {
            positiveRotate.push(positive.top());
            positive.pop();
        }

        while (!positiveRotate.empty())
        {
            cout << positiveRotate.top() << ' ';
            positiveRotate.pop();
        }
    }
}