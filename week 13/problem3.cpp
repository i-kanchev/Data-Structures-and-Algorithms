// https://www.hackerrank.com/contests/sda-hw-13-2022-1/challenges/exam-7

#include <iostream>
#include <vector>
#include <string>

using namespace std;

bool check(const unsigned count[])
{
    for (size_t i = 0; i <= 25; i++)
        if (count[i] != 0 && count[i] % 2 == 0)
            return false;

    return true;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string str;
    cin >> str;

    unsigned count[26];
    unsigned d[3000];
    
    for (size_t i = 0; i < 26; i++)
        count[i] = 0;
    for (size_t i = 0; i < 3000; i++)
        d[i] = 0;

    for (size_t i = 0; i < str.size(); i++)
    {
        count[str[i] - 'a']++;
        if (!check(count))
        {
            d[i] = 3000;
            unsigned temp[26];

            for (size_t j = 0; j < 26; j++)
                temp[j] = 0;

            for (size_t j = i; j > 0;)
            {
                temp[str[j--] - 'a']++;
                if (check(temp))
                    d[i] = min(d[i], d[j] + 1);
            }
        }
    }

    cout << d[str.size() - 1] + 1;

    return 0;
}