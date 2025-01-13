// https://www.hackerrank.com/contests/sda-hw-13-2022-1/challenges/christmas-wishlists

#include <vector>
#include <iostream>

using namespace std;

int main() {
    unsigned n;
    cin >> n;

    vector<unsigned> nums(n);
    for (size_t i = 0; i < n; i++)
        cin >> nums[i];

    unsigned d[10081];
    for (size_t i = 0; i <= 10080; i++)
        d[i] = 0;
    d[0] = 1;

    for (size_t i = 0; i < n; i++)
    {
        unsigned curr = nums[i];
        for (int j = 10080 - curr; j >= 0; j--)
        {
            d[j + curr] += d[j];
            d[j + curr] %= 1000000007;
        } 
    }

    unsigned variations = 0;
    for (size_t i = 0; i <= 10080; i++)
    {
        variations += d[i];
        variations %= 1000000007;
    }

    cout << variations;

    return 0;
}