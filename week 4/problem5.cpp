// https://www.hackerrank.com/contests/sda-hw-4-2022/challenges/zuma-1

#include <iostream>
#include <vector>
#include <list>
#include <iterator>

using namespace std;

unsigned removeSequence(list<unsigned>& balls, list<unsigned>::iterator  it)
{
    bool removeFirst = false;
    unsigned counter = 0;

    list<unsigned>::iterator left = it;
    list<unsigned>::iterator right = next(it);

    while (*left == *it)
    {
        counter++;
        if (left == balls.begin())
        {
            removeFirst = true;
            break;
        }
        advance(left, -1);
    }

    while (right != balls.end() && *right == *it)
    {
        advance(right, 1);
        counter++;
    }

    if (counter < 3)
        return 0;

    if (removeFirst)
        balls.erase(left, right);
    else
        balls.erase(next(left), right);

    if (removeFirst || right == balls.end() || *left != *next(left))
        return counter;

    return counter + removeSequence(balls, left);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    
    unsigned N, Q;

    cin >> N;

    list<unsigned> balls;
    vector<list<unsigned>::iterator> iterators(2 * N);

    for (size_t i = 0; i < N; i++)
    {
        unsigned color;
        cin >> color;
        balls.push_back(color);
        iterators[i] = prev(balls.end());
    }

    cin >> Q;

    for (size_t i = 0; i < Q; i++)
    {
        unsigned P, C;
        cin >> P >> C;

        if (balls.empty())
        {
            cout << "Game Over" << '\n';
            continue;
        }

        list<unsigned>::iterator it = balls.insert(next(iterators[P]), C);
        iterators[N + i] = it;

        cout << removeSequence(balls, iterators[N + i]) << '\n';
    }

    if (balls.empty())
        cout << -1 << '\n';
    else
        for (auto const& ball : balls)
            std::cout << ball << ' ';

    return 0;
}