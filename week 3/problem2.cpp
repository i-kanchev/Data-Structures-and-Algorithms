// https://www.hackerrank.com/contests/sda-hw-3-2022/challenges/challenge-3669

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    unsigned N, Q;

    cin >> N >> Q;

    vector<unsigned> students(N);

    for (size_t i = 0; i < N; i++)
        cin >> students[i];

    sort(students.begin(), students.end());

    for (size_t i = 0; i < Q; i++)
    {
        long min, max;

        cin >> min >> max;
        
        vector<unsigned>::iterator upperLimit, lowerLimit;

        upperLimit = upper_bound(students.begin(), students.end(), max);
        lowerLimit = lower_bound(students.begin(), upperLimit, min);

        cout << upperLimit - lowerLimit << '\n';
    }

    return 0;
}