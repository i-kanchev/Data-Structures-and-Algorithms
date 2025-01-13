// https://www.hackerrank.com/contests/sda-hw-12-2022/challenges/challenge-2799

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Edge
{
    unsigned from;
    unsigned to;
    unsigned weight;

    Edge(unsigned from, unsigned to, unsigned weight)
    {
        this->from = from;
        this->to = to;
        this->weight = weight;
    }
};

struct Compare
{
    bool operator()(const Edge& e1, const Edge& e2)
    {
        return e1.weight > e2.weight;
    }
};

struct DisjointSets
{
    vector<unsigned> parent;
    vector<unsigned> rnk;
    unsigned n;

    DisjointSets(unsigned n)
    {
        this->n = n;
        for (size_t i = 0; i <= n; i++)
        {
            parent.push_back(i);
            rnk.push_back(0);
        }
    }

    unsigned find(unsigned u)
    {
        if (u != parent[u])
            parent[u] = find(parent[u]);
        return parent[u];
    }

    void merge(unsigned x, unsigned y)
    {
        x = find(x), y = find(y);

        if (rnk[x] > rnk[y])
            parent[y] = x;
        else
            parent[x] = y;

        if (rnk[x] == rnk[y])
            rnk[y]++;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned N, M;
    cin >> N >> M;

    priority_queue<Edge, vector<Edge>, Compare> PQ;

    for (size_t i = 0; i < M; i++)
    {
        unsigned from, to, weight;

        cin >> from >> to >> weight;

        PQ.push(Edge(from, to, weight));
    }

    unsigned min = 0, max = -1;

    while (!PQ.empty())
    {
        unsigned tempMin = PQ.top().weight;
        unsigned tempMax = -1;
        priority_queue<Edge, vector<Edge>, Compare> tempPQ = PQ;

        DisjointSets ds(N);

        unsigned counter = 0;

        while (!tempPQ.empty())
        {
            Edge curr = tempPQ.top();
            tempPQ.pop();
            
            unsigned u = curr.from;
            unsigned v = curr.to;

            unsigned set_u = ds.find(u);
            unsigned set_v = ds.find(v);

            if (set_u != set_v)
            {
                ds.merge(set_u, set_v);

                counter++;

                if (counter == N - 1)
                {
                    tempMax = curr.weight;
                    break;
                }
            }
        }

        if (tempMax - tempMin < max - min)
        {
            max = tempMax;
            min = tempMin;
        }

        unsigned toRemove = PQ.top().weight;

        while (!PQ.empty() && PQ.top().weight == toRemove)
            PQ.pop();
    }

    cout << min << ' ' << max;

    return 0;
}