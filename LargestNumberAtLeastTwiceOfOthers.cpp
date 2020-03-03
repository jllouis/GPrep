#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:
    static int dominantIndex(vector<int> &nums) {
        if (nums.size() < 2)
            return 0;

        int first = 0, second = 0;

        for (auto i = 0; i < nums.size(); i++)
            if (nums[i] > nums[first])
                first = i;

        for (auto i = 0; i < nums.size(); i++)
            if (i == first)
                continue;
            else if (nums[i] > nums[second])
                second = i;

        return (((nums[first]) >= (2 * nums[second])) || (nums[second] == 0)) ? first : -1;
    }
};

int main() {
    vector<int> list{2, 0, 0, 3};
    cout << Solution::dominantIndex(list) << endl;
}