// https://www.hackerrank.com/contests/sda-hw-10-2022/challenges/challenge-2852

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

unordered_map<unsigned, unsigned> findConnectivity(const unordered_map<unsigned, vector<unsigned>>& graph)
{
    unordered_set<unsigned> nodes;

    for (auto key : graph)
        nodes.insert(key.first);

    unsigned counter = 1;
    unordered_map<unsigned, unsigned> connectivity;

    while (!nodes.empty())
    {
        queue<unsigned> traverse;
        traverse.push(*nodes.begin());

        while (!traverse.empty())
        {
            unsigned node = traverse.front();
            traverse.pop();

            if (!nodes.count(node))
                continue;

            nodes.erase(node);
            connectivity.insert({node, counter});

            for (auto edge : graph.at(node))
                traverse.push(edge);
        }

        counter++;
    }

    return connectivity;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned N, M, K;
    cin >> N >> M;

    unordered_map<unsigned, vector<unsigned>> graph;

    for (unsigned i = 1; i <= N; i++)
        graph.insert({ i, {} });

    for (size_t i = 0; i < M; i++)
    {
        unsigned from, to;
        cin >> from >> to;

        graph.at(from).push_back(to);
        graph.at(to).push_back(from);
    }

    unordered_map<unsigned, unsigned> connectivity = findConnectivity(graph);

    cin >> K;

    for (size_t i = 0; i < K; i++)
    {
        unsigned from, to;
        cin >> from >> to;

        if (connectivity.at(from) == connectivity.at(to))
            cout << 1 << ' ';
        else
            cout << 0 << ' ';
    }

    return 0;
}