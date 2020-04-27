//
// Created by jlouis on 4/12/2020.
//

#include <algorithm>
#include <numeric>
#include <vector>
#include <iostream>
#include <chrono>

using namespace std;

class Solution {
public:
    static int maxSubArray(vector<int> &num) {
        auto size = num.size();
        int max = INT32_MIN;

        auto t1 = chrono::high_resolution_clock::now();
        for (int s = 0; s < size; s++) {
            bool runOnce = true;
            for (int i = 0, j = s; j < size; i++, j++) {
                int sum = 0;
                if (runOnce) {
                    sum = accumulate(num.begin() + i, num.begin() + j + 1, 0);
                    runOnce = false;
                } else {
                    sum -= num[i];
                    sum += num[j];
                }
                max = std::max(sum, max);
            }
        }
        auto t2 = chrono::high_resolution_clock::now();
        cout << "Double for loop duration: " << chrono::duration_cast<chrono::microseconds>(t2 - t1).count() << endl;
        return max;
    }
};

int main() {
    vector<int> input{-2, 1, -3, 4, -1, 2, 1, -5, 4};
    cout << Solution::maxSubArray(input) << endl;
}