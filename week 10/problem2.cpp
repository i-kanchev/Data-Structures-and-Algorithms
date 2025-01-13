// https://www.hackerrank.com/contests/sda-hw-10-2022/challenges/challenge-2752

#include <iostream>
#include <vector>
#include <string>
#include <stack>
#include <unordered_map>
#include <unordered_set>

using namespace std;

void topologicalSort(char curr, unordered_set<char>& unvisited, stack<char>& lexicographicOrder, unordered_map<char, vector<char>>& graph)
{
    unvisited.erase(curr);

    for (auto edge : graph.at(curr))
        if (unvisited.count(edge))
            topologicalSort(edge, unvisited, lexicographicOrder, graph);

    lexicographicOrder.push(curr);
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned N;
    cin >> N;

    vector<string> words(N);

    for (size_t i = 0; i < N; i++)
        cin >> words[i];

    unordered_map<char, vector<char>> graph;

    for (size_t i = 1; i < N; i++)
    {
        unsigned index = 0;

        while (words[i - 1][index] == words[i][index])
            index++;

        char from = words[i - 1][index];
        char to = words[i][index];

        if (from != '\0' && !graph.count(from))
            graph.insert({ from, {} });
        if (to != '\0' && !graph.count(to))
            graph.insert({ to, {} });

        if (from == '\0' || to == '\0')
            continue;

        graph.at(from).push_back(to);
    }

    stack<char> lexicographicOrder;

    unordered_set<char> unvisited;
    for (auto symbol : graph)
        unvisited.insert(symbol.first);

    for (auto symbol : graph)
        if (unvisited.count(symbol.first))
            topologicalSort(symbol.first, unvisited, lexicographicOrder, graph);

    while (!lexicographicOrder.empty())
    {
        cout << lexicographicOrder.top() << ' ';
        lexicographicOrder.pop();
    }

    return 0;
}