// https://www.hackerrank.com/contests/sda-hw-10-2022/challenges/challenge-3782

#include <iostream>
#include <vector>
#include <map>
#include <unordered_map>
#include <unordered_set>

using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned Q;
    cin >> Q;

    for (size_t i = 0; i < Q; i++)
    {
        unsigned N, M;
        cin >> N >> M;

        unordered_map<unsigned, unordered_set<unsigned>> graph;

        for (unsigned i = 1; i <= N; i++)
            graph.insert({ i, {} });

        for (size_t i = 0; i < M; i++)
        {
            unsigned from, to;
            cin >> from >> to;

            graph.at(from).insert(to);
            graph.at(to).insert(from);
        }

        unsigned K;
        cin >> K;

        map<unsigned, unsigned> visited;

        unordered_set<unsigned> lastVisited;
        unordered_set<unsigned> unvisited;

        lastVisited.insert(K);

        for (auto node : graph)
            unvisited.insert(node.first);
        unvisited.erase(K);

        unsigned counter = 1;

        while (!unvisited.empty())
        {
            unordered_set<unsigned> temp;

            vector<unsigned> toRemove;

            for (auto currUnvisited : unvisited)
                for (auto currLastVisited : lastVisited)
                    if (!graph.at(currLastVisited).count(currUnvisited))
                    {
                        visited.insert({ currUnvisited, counter });
                        temp.insert(currUnvisited);

                        toRemove.push_back(currUnvisited);

                        break;
                    }
                

            if (toRemove.size() == 0)
                break;

            for (auto node : toRemove)
                unvisited.erase(node);

            lastVisited = temp;

            counter++;
        }

        for (auto left : unvisited)
            visited.at(left) = -1;

        for (size_t i = 1; i <= N; i++)
            if (i != K)
                cout << visited.at(i) << ' ';

        cout << "\n";
    }

    return 0;
}