//
// Created by jlouis on 2/6/2020.
//

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static int totalFruit(vector<int> &tree) {
        unordered_set<int> baskets;
        int topSize = 0, currentSize = 0, nextStartIndex = 0;
        bool secondType = false;

        for (int i = nextStartIndex; i < tree.size();) {
            if (baskets.find(tree[i]) != baskets.end()) {
                currentSize++;
                i++;
            } else if (baskets.size() < 2) {
                if (secondType)
                    nextStartIndex = i;
                else
                    secondType = true;
                baskets.insert(tree[i]);
                currentSize++;
                i++;
            } else {
                topSize = max(currentSize, topSize);
                currentSize = 0;
                baskets.clear();
                secondType = false;
                i = nextStartIndex;

                if (topSize > (tree.size() - i))
                    break;
            }
        }
        topSize = max(currentSize, topSize);
        return topSize;
    }
};

int main() {
    vector<int> input = {3, 3, 3, 1, 2, 1, 1, 2, 3, 3, 4};
    cout << Solution::totalFruit(input) << endl;
}