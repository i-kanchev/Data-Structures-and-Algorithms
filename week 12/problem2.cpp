// https://www.hackerrank.com/contests/sda-hw-12-2022/challenges/2-146

#include <iostream>
#include <vector>
#include <queue>
#include <unordered_map>
#include <unordered_set>

using namespace std;

struct Road
{
    unsigned index;
    unsigned dest;
    long long weight;
    long long profit;

    Road(unsigned index, unsigned dest, long long weight, long long profit)
    {
        this->index = index;
        this->dest = dest;
        this->weight = weight;
        this->profit = profit;
    }
};

struct CompareRoads
{
    bool operator()(const Road& r1, const Road& r2)
    {
        if (r1.weight == r2.weight)
            return r1.profit < r2.profit;

        return r1.weight > r2.weight;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned N, M;
    cin >> N >> M;

    unordered_map<unsigned, vector<Road>> graph;

    for (unsigned i = 1; i <= N; i++)
        graph.insert({ i, {} });

    for (size_t i = 1; i <= M; i++)
    {
        unsigned from, to;
        long long weight, profit;
        cin >> from >> to >> weight >> profit;

        graph.at(from).push_back(Road(i, to, weight, profit));
        graph.at(to).push_back(Road(i, from, weight, profit));
    }

    unordered_set<unsigned> unvisited;

    for (unsigned i = 1; i <= N; i++)
        unvisited.insert(i);

    priority_queue<Road, vector<Road>, CompareRoads> PQ;

    for (auto road : graph.at(*unvisited.begin()))
        PQ.push(road);

    unvisited.erase(unvisited.begin());

    while (!unvisited.empty())
    {
        Road currRoad = PQ.top();
        while (!unvisited.count(currRoad.dest))
        {
            PQ.pop();
            currRoad = PQ.top();
        }
        PQ.pop();

        for (auto road : graph.at(currRoad.dest))
            if (unvisited.count(road.dest))
                PQ.push(road);

        unvisited.erase(currRoad.dest);

        cout << currRoad.index << '\n';
    }

    return 0;
}