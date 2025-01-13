// https://www.hackerrank.com/contests/sda-hw-1-2022/challenges/challenge-3648

#include <iostream>

using namespace std;

int main()
{
    unsigned profit = 0;
    bool isDecreasing = false, isIncreasing = false;
    
    unsigned N;
    
    cin >> N;
    
    unsigned* ChechevCoinValueByDays = new unsigned[N];
    
    for (size_t i = 0; i < N; i++)
    {
        cin >> ChechevCoinValueByDays[i];
    }
    
    for (size_t i = 0; i < N; i++)
    {
        if (i == N - 1)
        {
            if (isIncreasing)
                profit += ChechevCoinValueByDays[i];
            break;
        }
            
        if (isIncreasing)
        {
            if (ChechevCoinValueByDays[i] < ChechevCoinValueByDays[i + 1])
                continue;
            isIncreasing = false;
            isDecreasing = true;
            profit += ChechevCoinValueByDays[i];
        }
        else if (isDecreasing)
        {
            if (ChechevCoinValueByDays[i] > ChechevCoinValueByDays[i + 1])
                continue;
            isIncreasing = true;
            isDecreasing = false;
            profit -= ChechevCoinValueByDays[i];
        }
        else
        {
            if (ChechevCoinValueByDays[i] < ChechevCoinValueByDays[i + 1])
            {
                isIncreasing = true;
                profit -= ChechevCoinValueByDays[i];
            }
            else if (ChechevCoinValueByDays[i] > ChechevCoinValueByDays[i + 1])
                isDecreasing = true;
        }
    }
    
    cout << profit;

    delete[] ChechevCoinValueByDays;
    
    return 0;
}