// https://www.hackerrank.com/contests/sda-hw-1-2022/challenges/missing-bus-ticket

#include <iostream>

using namespace std;

int main()
{
    int N;
    
    cin >> N;
    
    bool* T = new bool[N + 1];
    
    for (int i = 0; i < N; i++)
    {
        T[i] = false;
    }
    
    for (int i = 0; i < N; i++)
    {
        int temp;
        cin >> temp;
        if(temp > 0 && temp <= N)
            T[temp - 1] = true;
    }
    
    for (int i = 0; i < N + 1; i++)
    {
        if (!T[i])
        {
            cout << i + 1;
            break;
        }
    }
    
    delete[] T;
    
    return 0;
}