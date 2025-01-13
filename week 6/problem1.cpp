// https://www.hackerrank.com/contests/sda-hw-6-2022/challenges/vertical-sums

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    int key, value;
    Node *left, *right;

    Node(int key, int value)
    {
        this->key = key;
        this->value = value;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct BinaryTree
{
    Node* root = nullptr;

    Node* insertNode(vector<vector<int>>& data, int key, int value, int indexLeft, int indexRight, int& lowerBound, int& upperBound)
    {
        if (value < lowerBound)
            lowerBound = value;
        if (value > upperBound)
            upperBound = value;
        
        Node* node = new Node(key, value);

        if (root == nullptr)
            root = node;

        if (indexLeft != -1)
            node->left = insertNode(data, data[indexLeft][0], value - 1, data[indexLeft][1], data[indexLeft][2], lowerBound, upperBound);

        if (indexRight != -1)
            node->right = insertNode(data, data[indexRight][0], value + 1, data[indexRight][1], data[indexRight][2], lowerBound, upperBound);
        
        return node;
    }

    void getTotalValue(vector<long long>& totalValues, const int& space)
    {
        getTotalValue(root, totalValues, space);
    }

private:
    void getTotalValue(Node* curr, vector<long long>& totalValues, const int& space)
    {
        if (curr != nullptr)
        {
            totalValues[curr->value + space] += curr->key;

            getTotalValue(curr->left, totalValues, space);
            getTotalValue(curr->right, totalValues, space);
        }
    }
};

int main()
{
    unsigned N;
    cin >> N;

    vector<vector<int>> data= vector<vector<int>>(N);
    for (size_t i = 0; i < N; i++)
        data[i] = vector<int>(3);

    for (size_t i = 0; i < N; i++)
        for (size_t j = 0; j < 3; j++)
            cin >> data[i][j];

    int lowerBound = 0, upperBound = 0;

    BinaryTree track;

    track.insertNode(data, data[0][0], 0, data[0][1], data[0][2], lowerBound, upperBound);

    lowerBound = -lowerBound;
    vector<long long> totalValues(lowerBound + upperBound + 1);

    track.getTotalValue(totalValues, lowerBound);

    for (size_t i = 0; i < totalValues.size(); i++)
        cout << totalValues[i] << ' ';

    return 0;
}