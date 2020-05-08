#include <iostream>
#include <vector>

using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value);

    void insert(vector<int> values, int i = 0);

    void invertedInsert(vector<int> values, int i = 0);
};

void invertBinaryTree(BinaryTree *tree) {
    if (!tree)
        return;
    auto leftNode = tree->left;
    tree->left = tree->right;
    tree->right = leftNode;

    if (tree->right)
        invertBinaryTree(tree->right);
    if (tree->left)
        invertBinaryTree(tree->left);
}