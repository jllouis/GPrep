/*Given an array of integers nums, write a method that returns the "pivot" index of this array.

We define the pivot index as the index where the sum of the numbers to the left of the index is equal to the sum of the numbers to the right of the index.

If no such index exists, we should return -1. If there are multiple pivot indexes, you should return the left-most pivot index.

Example 1:

Input:
nums = [1, 7, 3, 6, 5, 6]
Output: 3
Explanation:
The sum of the numbers to the left of index 3 (nums[3] = 6) is equal to the sum of numbers to the right of index 3.
Also, 3 is the first index where this occurs.


Example 2:

Input:
nums = [1, 2, 3]
Output: -1
Explanation:
There is no index that satisfies the conditions in the problem statement.


Note:

The length of nums will be in the range [0, 10000].
Each element nums[i] will be an integer in the range [-1000, 1000].
 */
#include <iostream>
#include <vector>
#include <numeric>
#include <unordered_set>

using namespace std;

class Solution {
public:

    static void moveLeft(vector<int> &nums, vector<int>::size_type &mid, int &leftSum, int &rightSum) {
        rightSum += nums[mid];
        mid--;
        leftSum -= nums[mid];
    }

    static void moveRight(vector<int> &nums, vector<int>::size_type &mid, int &leftSum, int &rightSum) {
        leftSum += nums[mid];
        mid++;
        rightSum -= nums[mid];
    }

    static void incrementLeft(vector<int> &nums, vector<int>::size_type &mid, int &leftSum, int &rightSum) {
        if (leftSum < 0)
            moveLeft(nums, mid, leftSum, rightSum);
        else
            moveRight(nums, mid, leftSum, rightSum);
    }

    static void incrementRight(vector<int> &nums, vector<int>::size_type &mid, int &leftSum, int &rightSum) {
        if (rightSum < 0)
            moveRight(nums, mid, leftSum, rightSum);
        else
            moveLeft(nums, mid, leftSum, rightSum);
    }

    static int pivotIndex(vector<int> &nums) {
        if (nums.size() < 3)
            return -1;

        vector<int>::size_type mid = nums.size() / 2;
        int leftSum = accumulate(nums.begin(), nums.begin() + mid, 0);
        int rightSum = accumulate(nums.begin() + mid + 1, nums.end(), 0);
        unordered_set<vector<int>::size_type> visited;

//        cout << "rightSum: " << rightSum << " leftSum: " << leftSum << endl;
        while (rightSum != leftSum) {
            if (rightSum < leftSum) {
                incrementRight(nums, mid, leftSum, rightSum);
            } else {
                incrementLeft(nums, mid, leftSum, rightSum);
            }

            if (visited.contains(mid))
                return -1;

            visited.insert(mid);
//            cout << "rightSum: " << rightSum << " leftSum: " << leftSum << endl;
        }

        int lastMid;
        while (rightSum == leftSum && mid > 0) {
            lastMid = mid;
            moveLeft(nums, mid, leftSum, rightSum);
            if (mid == 0 && rightSum != leftSum)
                return lastMid;
        }

        return (mid == 0) ? mid : mid + 1;
    }
};

int main(const int argc, const char *argv[]) {
    vector<int> nums{-1, -1, -1, 0, 1, 1};
    cout << Solution::pivotIndex(nums) << endl;
}
