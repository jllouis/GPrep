#include <iostream>

using namespace std;

class BST {
public:
    int value;
    BST *left;
    BST *right;

//    BST(int val);
//    BST &insert(int val);
};

int findClosestValueInBst(BST *tree, int target) {
    if (!tree)
        return -1;

    if (target == tree->value)
        return tree->value;
    else if (target < tree->value) {
        if (tree->left)
            return findClosestValueInBst(tree->left, target);
        else return tree->value;
    } else if (target >= tree->value) {
        if (tree->right)
            return findClosestValueInBst(tree->right, target);
        else return tree->value;
    } else
        return -1;
}
