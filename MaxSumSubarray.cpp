#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

class MaxSumSubArrayOfSizeK {
public:
    static int findMaxSumSubarray(const int k, const vector<int> &arr) {
        int maxSum = 0;
        int windowSum = maxSum = accumulate(arr.begin(), arr.begin() + k, 0);
        for (int i = 0; i < size(arr) - k; ++i) {
            windowSum += arr[i + k];
            windowSum -= arr[i];
            maxSum = max(maxSum, windowSum);
        }

        return maxSum;
    }
};

int main() {
    auto input = {2, 1, 5, 1, 3, 2};

    cout << MaxSumSubArrayOfSizeK::findMaxSumSubarray(3, input);

}
