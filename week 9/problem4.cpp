// https://www.hackerrank.com/contests/sda-hw-9-2022/challenges/challenge-3771

#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned N, M;
    cin >> N >> M;

    vector<unsigned> nums(N);

    for (int i = nums.size() - 1; i >= 0; i--)
        cin >> nums[i];

    unsigned long long counter = 0;

    unordered_map<unsigned, vector<unsigned>> mapping;

    for (size_t i = 0; i < N; i++)
    {
        unsigned temp = nums[i];

        if (mapping.count(temp * M) && mapping.count(temp * M * M))
        {
            for (unsigned value : mapping.at(temp* M))
                counter += value;
        }

        if (!mapping.count(temp))
            mapping.insert({ temp, {} });

        if (!mapping.count(temp * M))
            mapping.at(temp).push_back(0);
        else
            mapping.at(temp).push_back(mapping.at(temp * M).size());
    }

    cout << counter;

    return 0;
}