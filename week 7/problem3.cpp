// https://www.hackerrank.com/contests/sda-hw-7-2022/challenges/challenge-2590

#include <iostream>

using namespace std;

struct Node
{
    unsigned value, leftBox, rightBox;
    Node* left, * right;

    Node(unsigned leftBox, unsigned rightBox)
    {
        this->value = 0;
        this->leftBox = leftBox;
        this->rightBox = rightBox;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct Tree
{
    Node* root;
    unsigned possibilities, shipSize;

    Tree(unsigned boxes, unsigned shipSize)
    {
        root = new Node(1, boxes);
        this->shipSize = shipSize;
        possibilities = (boxes + 1) / (shipSize + 1);
    }

    void separate(unsigned value)
    {
        Node* curr = root;

        while (curr->value != 0)
        {
            if (curr->value < value)
                curr = curr->right;
            else if (curr->value > value)
                curr = curr->left;
            else
                return;
        }

        if (curr->leftBox > value || curr->rightBox < value)
            return;

        if (value - curr->leftBox < shipSize && curr->rightBox - value < shipSize)
        {
            curr->leftBox = 0;
            curr->rightBox = 0;
            possibilities--;
        }
        else if (value - curr->leftBox < shipSize)
        {
            unsigned difference = (curr->rightBox - curr->leftBox + 2) / (shipSize + 1)
                - (curr->rightBox - value + 1) / (shipSize + 1);
            possibilities -= difference;
            curr->leftBox = value + 1;
        }
        else if (curr->rightBox - value < shipSize)
        {
            unsigned difference = (curr->rightBox - curr->leftBox + 2) / (shipSize + 1)
                - (value - curr->leftBox + 1) / (shipSize + 1);
            possibilities -= difference;
            curr->rightBox = value - 1;
        }
        else
        {
            unsigned difference;

            curr->value = value;

            curr->left = new Node(curr->leftBox, value - 1);
            curr->right = new Node(value + 1, curr->rightBox);

            difference = (curr->rightBox - curr->leftBox + 2) / (shipSize + 1)
                - (curr->left->rightBox - curr->left->leftBox + 2) / (shipSize + 1)
                - (curr->right->rightBox - curr->right->leftBox + 2) / (shipSize + 1);
            possibilities -= difference;
        }
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    unsigned N, K, A;
    cin >> N >> K >> A;

    Tree map(N, A);

    unsigned Q;
    cin >> Q;

    for (size_t i = 0; i < Q; i++)
    {
        unsigned X;
        cin >> X;

        map.separate(X);

        if (map.possibilities < K)
        {
            cout << i + 1;
            return 0;
        }
    }

    cout << -1;

    return 0;
}