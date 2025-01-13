// https://www.hackerrank.com/contests/sda-hw-6-2022/challenges/validate-bst-2

#include <iostream>
#include <vector>
#include <map>

using namespace std;

struct Node
{
    int key;
    Node *left, *right;

    Node(int key)
    {
        this->key = key;
        this->left = nullptr;
        this->right = nullptr;
    }
};

struct BinaryTree
{
    Node* root = nullptr;

    Node* insertNode(vector<vector<int>>& data, int key, int indexLeft, int indexRight)
    {
        Node* node = new Node(key);

        if (root == nullptr)
            root = node;

        if (indexLeft != -1)
            node->left = insertNode(data, data[indexLeft][0], data[indexLeft][1], data[indexLeft][2]);

        if (indexRight != -1)
            node->right = insertNode(data, data[indexRight][0], data[indexRight][1], data[indexRight][2]);
        
        return node;
    }

    bool isBinarySearchTree()
    {
        return isBinarySearchTree(root);
    }
private:
    bool isBinarySearchTree(Node* curr)
    {
        Node *leftMax = nullptr, *rightMin = nullptr;

        if (curr->left != nullptr)
            leftMax = curr->left;
        while (leftMax != nullptr && leftMax->right != nullptr)
            leftMax = leftMax->right;
        
        if (curr->right != nullptr)
            rightMin = curr->right;
        while (rightMin != nullptr && rightMin->left != nullptr)
            rightMin = rightMin->left;
        
        return (leftMax == nullptr || leftMax->key < curr->key)
            && (rightMin == nullptr || rightMin->key > curr->key)
            && (curr->left == nullptr || isBinarySearchTree(curr->left))
            && (curr->right == nullptr || isBinarySearchTree(curr->right));
    }
};

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    unsigned T;
    cin >> T;

    for (size_t i = 0; i < T; i++)
    {
        unsigned N;
        cin >> N;
        
        vector<vector<int>> data = vector<vector<int>>(N);
        for (size_t i = 0; i < N; i++)
            data[i] = vector<int>(3);

        for (size_t i = 0; i < N; i++)
            for (size_t j = 0; j < 3; j++)
                cin >> data[i][j];

        BinaryTree tree;

        tree.insertNode(data, data[0][0], data[0][1], data[0][2]);

        cout << tree.isBinarySearchTree() << '\n';
    }

    return 0;
}