// https://www.hackerrank.com/contests/sda-hw-7-2022/challenges/challenge-3754

#include <iostream>
#include <unordered_set>
#include <queue>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned Q;
    cin >> Q;

    for (size_t i = 0; i < Q; i++)
    {
        unsigned N;
        cin >> N;

        unordered_set<unsigned> uniqueSweets;
        queue<unsigned> sequence;

        unsigned max = 0;

        for (size_t j = 0; j < N; j++)
        {
            unsigned X;
            cin >> X;

            if (uniqueSweets.count(X))
            {
                if (uniqueSweets.size() > max)
                    max = uniqueSweets.size();
                
                while (!sequence.empty())
                {
                    unsigned first = sequence.front();
                    sequence.pop();

                    uniqueSweets.erase(first);

                    if (first == X)
                        break;
                }
            }

            uniqueSweets.insert(X);
            sequence.push(X);
        }

        if (uniqueSweets.size() > max)
            max = uniqueSweets.size();

        cout << max << '\n';
    }

    return 0;
}