#include <iostream>
#include <vector>
#include <cmath>

using namespace std;

class Solution {
public:

    static int getHighestIndex(vector<int> &nums, bool skip = false, const int skip_index = -1) {
        int highest = 0;

        for (auto i = 0; i < nums.size(); i++)
            if (skip && i == skip_index)
                continue;
            else if (nums[i] > nums[highest])
                highest = i;

        return highest;
    }

    static int dominantIndex(vector<int> &nums) {
        if (nums.size() < 2)
            return 0;

        int first = 0, second = 0;
        first = getHighestIndex(nums);
        second = getHighestIndex(nums, true, first);

        return (((nums[first]) >= (2 * nums[second])) || (nums[second] == 0)) ? first : -1;
    }
};

int main() {
    vector<int> list{1, 0};
    cout << Solution::dominantIndex(list) << endl;
}