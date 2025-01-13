// https://www.hackerrank.com/contests/sda-hw-13-2022-1/challenges/violets

#include <iostream>

using namespace std;


int main() {
    unsigned n;
    cin >> n;
    
    unsigned d[5000000];
    d[0] = 2;
    d[1] = 2;
    
    for (size_t i = 2; i < n; i++)
        d[i] = (d[i - 1] + d[i - 2]) % 1000000007;
    
    cout << d[n - 1];
    
    return 0;
}