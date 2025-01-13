// https://www.hackerrank.com/contests/sda-hw-7-2022/challenges/zoros-mask

#include <iostream>
#include <vector>
#include <set>
#include <cmath>

using namespace std;

void findVariations(unsigned num, set<unsigned>& uniqueMasks, vector<unsigned>& digits)
{
    if (uniqueMasks.count(num))
        return;

    uniqueMasks.insert(num);

    for (size_t i = 0; i < digits.size(); i++)
    {
        if (num < digits[i])
            return;
        
        if ((num & digits[i]) != 0)
            findVariations(num - digits[i], uniqueMasks, digits);
    }
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    set<unsigned> uniqueMasks;
    vector<unsigned> digits;

    for (size_t i = 0; i < 20; i++)
        digits.push_back(pow(2, i));

    unsigned n;
    cin >> n;

    for (size_t i = 0; i < n; i++)
    {
        unsigned a;
        cin >> a;

        findVariations(a, uniqueMasks, digits);
    }

    cout << uniqueMasks.size();

    return 0;
}