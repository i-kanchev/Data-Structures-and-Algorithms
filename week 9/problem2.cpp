// https://www.hackerrank.com/contests/sda-hw-9-2022/challenges/challenge-3769

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned N;
    cin >> N;

    unordered_set<unsigned> uniqueNums;
    queue<unsigned> sequence;

    unsigned max = 0;

    for (size_t j = 0; j < N; j++)
    {
        unsigned A;
        cin >> A;

        if (uniqueNums.count(A))
        {
            if (uniqueNums.size() > max)
                max = uniqueNums.size();

            while (!sequence.empty())
            {
                unsigned first = sequence.front();
                sequence.pop();

                uniqueNums.erase(first);

                if (first == A)
                    break;
            }
        }

        uniqueNums.insert(A);
        sequence.push(A);
    }

    if (uniqueNums.size() > max)
        max = uniqueNums.size();

    cout << max << '\n';

    return 0;
}