#include <set>
#include <iostream>

using namespace std;

class Solution {
public:

    static string recurse(string s, string t) {

        string r;
        while (!s.empty() && !t.empty()) {

            if (t[0] == s[0]) {
                r += s[0];
                s = s.substr(1, s.size()), t = t.substr(1, t.size());
            } else {
                int i = 0;
                for (; i < t.size() && t[i] != s[0]; ++i);

                if (i < t.size())
                    t = t.substr(i, t.size());
                else return r;
            }

        }

        return r;
    }

    static bool isSubsequence(string s, string t) {

        return recurse(s, std::move(t)) == s;

    }
};

int main() {
    cout << Solution::isSubsequence("abc", "ahbgdc") << endl;
    cout << Solution::isSubsequence("axc", "ahbgdc") << endl;
}