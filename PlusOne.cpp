#include <iostream>
#include <vector>

using namespace std;

class Solution {
public:

    static void addOne(vector<int> &digits) {
        bool carry = false;
        for (int i = digits.size(); i > 0; i--) {
            if (digits[i] == 9) {
                digits[i] = 0;
                carry = true;
                continue;
            } else if (carry) {
                if (digits[i] == 9) {
                    digits[i] = 0;
                    continue;
                } else if (i == 0) {
                    digits.insert(digits.begin(), 1);
                }
            } else
                digits[i]++;
        }
    }

    static vector<int> plusOne(vector<int> &digits) {
        if (digits.empty())
            return {};

        if (digits[digits.size() - 1] == 9)
            for (int i = digits.size(); i > 0; i--) {

            }
        else
            digits[digits.size() - 1]++;
    }
};

int main() {
    std::vector input{4, 3, 2, 1};
    for (const int &i : Solution::plusOne(input))
        cout << i << " ";
}