// https://www.hackerrank.com/contests/sda-hw-8-2022/challenges/challenge-2855

#include <iostream>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned K, T, B, N;
    cin >> K >> T >> B >> N;

    priority_queue<unsigned, vector<unsigned>, greater<unsigned>> queries;

    unsigned totalCounter = 0, currCounter = 0, groupsCounter = 0;

    while (groupsCounter < B)
    {
        if (totalCounter < N)
        {
            unsigned X;
            cin >> X;

            queries.push(X);

            totalCounter++;
            currCounter++;
        }
        else
            currCounter = T;

        if (currCounter == T)
        {
            for (size_t i = 0; i < K; i++)
            {
                cout << queries.top() << ' ';
                queries.pop();
            }
                
            currCounter = 0;
            groupsCounter++;
        }
    }

    return 0;
}