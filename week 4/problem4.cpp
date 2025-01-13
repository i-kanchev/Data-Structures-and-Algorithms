// https://www.hackerrank.com/contests/sda-hw-4-2022/challenges/some-challange

#include <iostream>
#include <vector>
#include <list>

using namespace std;

const unsigned SIZE = 1000001;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned T, N;

    cin >> T >> N;

    list<unsigned> packages;

    bool packageExist[SIZE] = {false};

    vector<list<unsigned>::iterator> packageIterators(SIZE);

    for (size_t i = 0; i < T; i++)
    {
        unsigned temp;
        cin >> temp;

        cout << boolalpha << packageExist[temp] << '\n';

        if (packageExist[temp])
        {
            packages.erase(packageIterators[temp]);
        }
        else if (packages.size() >= N)
        {
            packageExist[packages.back()] = false;
            packages.pop_back();
        }

        packageExist[temp] = true;
        packages.push_front(temp);
        packageIterators[temp] = packages.begin();
    }

    return 0;
}