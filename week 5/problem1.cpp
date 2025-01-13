// https://www.hackerrank.com/contests/sda-hw-5-2022/challenges/challenge-3724

#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned N, M, T;
    cin >> N >> M >> T;

    unsigned row1, col1, row2 = -1, col2 = -1;

    cin >> row1 >> col1 >> row2 >> col2;

    vector<vector<bool>> warehouse(N);
    for (size_t i = 0; i < N; i++)
        warehouse[i] = vector<bool>(M);

    unsigned rottenApples = 0;
    queue<pair<unsigned, unsigned>> apples;

    warehouse[row1 - 1][col1 - 1] = true;
    rottenApples++;
    apples.push({ row1 - 1, col1 - 1 });

    if (row2 != -1)
    {
        warehouse[row2 - 1][col2 - 1] = true;
        rottenApples++;
        apples.push({ row2 - 1, col2 - 1 });
    }

    for (size_t i = 0; i < T; i++)
    {
        unsigned currSize = apples.size();
        for (size_t j = 0; j < currSize; j++)
        {
            pair<unsigned, unsigned> temp = apples.front();
            apples.pop();

            if (temp.first > 0 && !warehouse[temp.first - 1][temp.second])
            {
                warehouse[temp.first - 1][temp.second] = true;
                rottenApples++;
                apples.push({ temp.first - 1, temp.second });
            }
            if (temp.first < N - 1 && !warehouse[temp.first + 1][temp.second])
            {
                warehouse[temp.first + 1][temp.second] = true;
                rottenApples++;
                apples.push({ temp.first + 1, temp.second });
            }
            if (temp.second > 0 && !warehouse[temp.first][temp.second - 1])
            {
                warehouse[temp.first][temp.second - 1] = true;
                rottenApples++;
                apples.push({ temp.first, temp.second - 1});
            }
            if (temp.second < M - 1 && !warehouse[temp.first][temp.second + 1])
            {
                warehouse[temp.first][temp.second + 1] = true;
                rottenApples++;
                apples.push({ temp.first, temp.second + 1 });
            }
        }
    }

    cout << M * N - rottenApples;
}