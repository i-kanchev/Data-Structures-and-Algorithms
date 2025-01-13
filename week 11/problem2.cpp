// https://www.hackerrank.com/contests/sda-hw-11-2022/challenges/task2-3

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned V, E, Q;
    cin >> V >> E >> Q;

    unordered_map<unsigned, vector<pair<unsigned, unsigned>>> graph;
    
    for (unsigned i = 0; i < V; i++)
        graph.insert({ i, {} });

    for (size_t i = 0; i < E; i++)
    {
        unsigned from, to, value;
        cin >> from >> to >> value;

        graph.at(from).push_back({ to, value });
    }

    vector<vector<unsigned long long>> allShortestPaths;

    for (size_t i = 0; i < V; i++)
    {
        priority_queue<pair<unsigned, unsigned>, vector<pair<unsigned, unsigned>>, greater<pair<unsigned, unsigned>>> traverse;
        traverse.push({ 0, i });

        vector<unsigned long long> distance(V, -1);
        distance[i] = 0;

        while (!traverse.empty())
        {
            unsigned currNode = traverse.top().second;
            traverse.pop();

            for (auto edge : graph.at(currNode))
            {
                unsigned nextNode = edge.first;
                unsigned weight = edge.second;

                if (distance[nextNode] > distance[currNode] + weight)
                {
                    distance[nextNode] = distance[currNode] + weight;
                    traverse.push({ distance[nextNode] , nextNode });
                }
            }
        }

        allShortestPaths.push_back(distance);
    }

    for (size_t i = 0; i < Q; i++)
    {
        unsigned s, e;
        cin >> s >> e;

        if (allShortestPaths[s][e] == -1)
            cout << -1 << '\n';
        else
            cout << allShortestPaths[s][e] << '\n';
    }

    return 0;
}