// https://www.hackerrank.com/contests/sda-hw-11-2022/challenges/task3-1

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned V, E, s, e;
    cin >> V >> E >> s >> e;

    unordered_map<unsigned, vector<pair<unsigned, unsigned>>> graph;

    for (unsigned i = 0; i < V; i++)
        graph.insert({ i, {} });

    for (size_t i = 0; i < E; i++)
    {
        unsigned from, to, value;
        cin >> from >> to >> value;

        graph.at(from).push_back({ to, value });
        graph.at(to).push_back({ from, value });
    }

    priority_queue<pair<unsigned, unsigned>, vector<pair<unsigned, unsigned>>, greater<pair<unsigned, unsigned>>> traverse;
    traverse.push({ 0, e });

    vector<unsigned long long> distance(V, -1);
    distance[e] = 0;

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

    vector<bool> visited(V, false);

    vector<unsigned long long> possiblePahts(V, 0);
    possiblePahts[e] = 1;

    priority_queue<pair<unsigned long long, unsigned>, vector<pair<unsigned long long, unsigned>>,
        greater<pair<unsigned long long, unsigned>>> pathsTraverse;

    for (size_t i = 0; i < V; i++)
        if (distance[i] != -1)
            pathsTraverse.push({ distance[i], i });

    while (!pathsTraverse.empty())
    {
        unsigned currNode = pathsTraverse.top().second;
        pathsTraverse.pop();

        for (auto nextNode : graph.at(currNode))
            if (visited[nextNode.first] && distance[currNode] > distance[nextNode.first])
            {
                possiblePahts[currNode] += possiblePahts[nextNode.first];
                possiblePahts[currNode] %= 1000000007;
            }

        visited[currNode] = true;
    }

    cout << possiblePahts[s];

    return 0;
}