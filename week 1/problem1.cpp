// https://www.hackerrank.com/contests/sda-hw-1-2022/challenges/1-410

#include <iostream>

using namespace std;

unsigned redactions(char* str, unsigned len)
{
    unsigned redactions = 0;
    for (size_t i = 0; i < len - 1; i++)
    {
        if (str[i] == str[i + 1])
            redactions++;
    }
    return redactions;
}

int main()
{
    unsigned Q, len;
    
    cin >> Q;
    
    for (size_t i = 0; i < Q; i++)
    {
        cin >> len;
        char* str = new char[len + 1];
        cin >> str;
        
        cout << redactions(str, len) << endl;

        delete[] str;
    }
    
    return 0;
}