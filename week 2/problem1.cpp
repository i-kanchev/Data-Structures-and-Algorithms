// https://www.hackerrank.com/contests/sda-hw-2-2022/challenges/1-146-1

#include <iostream>

using namespace std;

int main()
{
    unsigned N, counter = 0, oddCounter = 0;

    cin >> N;

    unsigned* sortedNumbers = new unsigned[N];
    unsigned* oddNumbers = new unsigned[N];

    for (size_t i = 0; i < N; i++)
    {
        unsigned num;
        cin >> num;
        if (num % 2 == 0)
            sortedNumbers[counter++] = num;
        else
            oddNumbers[oddCounter++] = num;
    }

    oddCounter = 0;

    while (counter < N)
        sortedNumbers[counter++] = oddNumbers[oddCounter++];

    for (size_t i = 0; i < N; i++)
        cout << sortedNumbers[i] << '\n';

    delete[] sortedNumbers;
    delete[] oddNumbers;

    return 0;
}