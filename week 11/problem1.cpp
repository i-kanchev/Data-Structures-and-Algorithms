// https://www.hackerrank.com/contests/sda-hw-11-2022/challenges/task1-6-3

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

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

    vector<unsigned> waitingTime(V);

    for (size_t i = 0; i < V; i++)
        cin >> waitingTime[i];

    for (size_t i = 0; i < E; i++)
    {
        unsigned from, to, value;
        cin >> from >> to >> value;

        graph.at(from).push_back({ to, value });
    }

    priority_queue<pair<unsigned, unsigned>, vector<pair<unsigned, unsigned>>, greater<pair<unsigned, unsigned>>> traverse;
    traverse.push({0, s});

    vector<unsigned long long> distance(V, -1);
    distance[s] = 0;

    while (!traverse.empty())
    {
        unsigned currNode = traverse.top().second;
        traverse.pop();

        for (auto edge : graph.at(currNode))
        {
            unsigned nextNode = edge.first;
            unsigned weight = edge.second;

            unsigned wait = 0;
            if (distance[currNode] % waitingTime[currNode] != 0)
                wait = waitingTime[currNode] - (distance[currNode] % waitingTime[currNode]);

            if (distance[nextNode] > distance[currNode] + weight + wait)
            {
                distance[nextNode] = distance[currNode] + weight + wait;
                traverse.push({ distance[nextNode] , nextNode });
            }
        }
    }

    if (distance[e] == -1)
        cout << -1;
    else
        cout << distance[e];

    return 0;
}