// https://www.hackerrank.com/contests/sda-hw-6-2022/challenges/parent

#include <iostream>
#include <vector>
#include <queue>

using namespace std;

struct Node
{
    unsigned key, generation;
    Node* parent;
    vector<Node*> heirs;

    Node(unsigned key, unsigned generation, Node* parentNode)
    {
        this->key = key;
        this->generation = generation;
        this->parent = parentNode;
    }
};

struct Tree
{
    Node* root = nullptr;

    bool areRelatives(Node* parent, Node* child)
    {
        while (child->generation > parent->generation)
            child = child->parent;

        return (parent == child);
    }

    void insertNode(unsigned parent, unsigned child, vector<Node*>& iter)
    {   
        if (root == nullptr)
        {
            Node* node = new Node(parent, 1, nullptr);
            root = node;

            iter[parent] = node;
        }

        Node* parentNode = iter[parent];
        Node* childNode = new Node(child, parentNode->generation + 1, parentNode);
        iter[child] = childNode;
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    Tree familyTree;

    unsigned N;
    cin >> N;

    vector<Node*> iter(N);

    for (size_t i = 0; i < N - 1; i++)
    {
        unsigned a, b;
        cin >> a >> b;

        familyTree.insertNode(a, b, iter);
    }

    unsigned Q;
    cin >> Q;

    for (size_t i = 0; i < Q; i++)
    {
        unsigned x, y;
        cin >> x >> y;

        if (familyTree.areRelatives(iter[x], iter[y]))
            cout << "YES\n";
        else
            cout << "NO\n";
    }

    return 0;
}