#include <iostream>
#include <vector>

using namespace std;

class BinaryTree {
public:
    int value;
    BinaryTree *left;
    BinaryTree *right;

    BinaryTree(int value) {
        this->value = value;
        left = NULL;
        right = NULL;
    }
};

void traverse(BinaryTree *root, vector<int> &sums, long total = 0) {
    if (!root)
        return;

    total += root->value;

    if (root->left)
        traverse(root->left, sums, total);
    if (root->right)
        traverse(root->right, sums, total);
    if (!(root->left || root->right))
        sums.push_back(total);


}

vector<int> branchSums(BinaryTree *root) {
    vector<int> sums{};
    traverse(root, sums);
    return sums;
}