// https://www.hackerrank.com/contests/sda-hw-9-2022/challenges/longest-match

#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    string s1, s2;
    cin >> s1 >> s2;

    vector<unsigned> commonChars(s1.length() + s2.length() - 1, 0);

    unsigned longestSubstrLength = 0;

    for (size_t i = 0; i < s1.length(); i++)
        for (size_t j = 0; j < s2.length(); j++)
        {
            unsigned index = s1.length() - i + j - 1;
            
            if (s1[i] == s2[j])
                commonChars[index]++;
            else
                commonChars[index] = 0;

            if (commonChars[index] > longestSubstrLength)
                longestSubstrLength = commonChars[index];
        }

    cout << longestSubstrLength;

    return 0;
}