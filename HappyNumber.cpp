//
// Created by jlouis on 4/8/2020.
//

#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <cmath>

using namespace std;

class Solution {
public:
    static vector<int> getDigits(int num) {
        vector<int> digits;
        while (num > 9) {
            digits.emplace_back(num % 10);
            num /= 10;
        }
        digits.emplace_back(num % 10);
        digits.erase(std::remove(digits.begin(), digits.end(), 0), digits.end());

        return digits;
    }

    static int sumSquares(const vector<int> nums) {
        int sum = 0;

        for (auto i : nums)
            sum += pow(i, 2);

        return sum;
    }

    static bool isHappy(int n) {
        if (n == 0 || n == 1)
            return true;

        unordered_set<int> squareSums{};

        while (true) {
            auto digits = getDigits(n);
            if (digits.size() == 1 && digits[0] == 1)
                return true;
            n = sumSquares(digits);
            if (squareSums.find(n) != squareSums.end())
                return false;
            squareSums.insert(n);
        }
    }
};

int main() {
    cout << Solution::isHappy(19);
}