// https://www.hackerrank.com/contests/sda-hw-12-2022/challenges/roads-5

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned N, M, Q;
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

    unordered_map<unsigned, unsigned> connectivity;

    for (unsigned i = 1; i <= N; i++)
        connectivity.insert({ i, 0 });

    unsigned counter = 1;

    for (auto node : connectivity)
    {
        unsigned currNode = node.first;

        if (connectivity.at(currNode) != 0)
            continue;

        queue<unsigned> traverse;
        traverse.push(currNode);

        while (!traverse.empty())
        {
            unsigned curr = traverse.front();
            traverse.pop();
            connectivity.at(curr) = counter;

            for (auto edge : graph.at(curr))
                if (connectivity.at(edge) == 0)
                {
                    connectivity.at(edge) = counter;
                    traverse.push(edge);
                }
        }

        counter++;
    }
    
    cin >> Q;

    for (size_t i = 0; i < Q; i++)
    {
        unsigned type, from, to;

        cin >> type >> from >> to;

        if (type == 1)
        {
            if (connectivity.at(from) == connectivity.at(to))
                cout << 1;
            else
                cout << 0;
        }
        else
        {
            unsigned fromIndex = connectivity.at(from);
            unsigned toIndex = connectivity.at(to);

            if (fromIndex == toIndex)
                continue;

            for (auto node : connectivity)
                if (node.second == toIndex)
                    connectivity.at(node.first) = fromIndex;
        }
    }

    return 0;
}