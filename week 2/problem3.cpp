// https://www.hackerrank.com/contests/sda-hw-2-2022/challenges/netflix-1-1

#include <iostream>

#include <string>

using namespace std;

const unsigned SYMBOLS_COUNT = 'z' - 'a' + 'Z' - 'A' + '9' - '0' + 3;

unsigned getValue(const char symbol)

{

    unsigned value;

    if (symbol >= 'A' && symbol <= 'Z')

        value = symbol - 'A';

    else if (symbol >= 'a' && symbol <= 'z')

        value = symbol - 'a' + 'Z' - 'A' + 1;

    else

        value = symbol - '0' + 'Z' - 'A' + 'z' - 'a' + 2;

    return value;

}

int main()

{

    string S;

    cin >> S;

    unsigned symbols[SYMBOLS_COUNT];

    for (size_t i = 0; i < SYMBOLS_COUNT; i++)

        symbols[i] = 0;

    for (size_t i = 0; i < S.length(); i++)

    {

        unsigned value = getValue(S[i]);

        symbols[value]++;

    }

    for (size_t i = 0; i < S.length(); i++)

        if (symbols[getValue(S[i])] == 1)

            cout << i << ' ';

    return 0;

}