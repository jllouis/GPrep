#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static bool compareLeftEquality(const vector<int> &nums, const int index) {
        if (index == 0)
            return false;

        return nums[index] == nums[index - 1];

    }

    static bool compareRightEquality(const vector<int> &nums, const int index) {
        if (index == nums.size() - 1)
            return false;

        return nums[index] == nums[index + 1];
    }

    static int singleNumber(vector<int> &nums) {
        sort(nums.begin(), nums.end());

        for (int i = 0; i < nums.size(); i++)
            if (!(compareRightEquality(nums, i) || compareLeftEquality(nums, i)))
                return nums[i];
    }
};

int main() {
    vector<int> input{4, 1, 2, 1, 2};

    cout << Solution::singleNumber(input) << endl;
}