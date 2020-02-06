#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

class Solution {
public:
    string licenseKeyFormatting(string S, int K) {
        S.erase(remove(S.begin(), S.end(), '-'), S.end());
        transform(S.begin(), S.end(), S.begin(), ::toupper);
        auto remainder = S.length() % K;
        string formatted = S.substr(0, remainder);

        if(formatted.length() && (formatted.length() < S.length()))
            formatted += '-';

        for (int i = 0, j = 0; i+remainder < S.length(); ++i, ++j)
        {
            if ((j == K) && j) {
                formatted += "-";
                j = 0;
            }

            formatted += S[i+remainder];
        }

        return formatted;
    }
};


int main() {
    Solution sol;
    auto formatted = sol.licenseKeyFormatting("2-4A0r7-4k", 3);
    cout << "Formatted: " << formatted << endl;
    return 0;
}

