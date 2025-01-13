// https://www.hackerrank.com/contests/sda-hw-2-2022/challenges/just-sorting-1

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

bool customCompare(const pair<unsigned, string> pair1, pair<unsigned, string> pair2)
{
    if (pair1.first > pair2.first)
        return true;
    if (pair1.first < pair2.first)
        return false;
    
    if (pair1.second < pair2.second)
        return true;
    if (pair1.second > pair2.second)
        return false;

    return false;
}

int main()
{
    unsigned N;

    cin >> N;

    vector<pair<unsigned, string>> students(N);

    for (size_t i = 0; i < N; i++)
        cin >> students[i].second;
    for (size_t i = 0; i < N; i++)
        cin >> students[i].first;

    sort(students.begin(), students.end(), customCompare);

    for (size_t i = 0; i < N; i++)
        cout << students[i].second << ' ' << students[i].first << '\n';

    return 0;
}