#include <iostream>
#include <set>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    static int numUniqueEmails(vector<string> &emails) {
        return clean(emails).size();
    }

    static set<pair<string, string>> clean(vector<string> &emails) {
        set<pair<string, string>> uniqueEmails;
        for (const auto &e : emails)
            uniqueEmails.insert({cleanLocalName(getLocalName(e)), getDomainName(e)});

        return uniqueEmails;
    }

    static string getLocalName(const string &email) {
        auto loc = email.find('@');
        return email.substr(0, loc);
    }

    static string getDomainName(const string &email) {
        auto loc = email.find('@');
        return email.substr(loc, email.length());
    }

    static string cleanLocalName(const string &localName) {
        string cleanedName;
        auto loc = localName.find('+');
        cleanedName = localName.substr(0, loc);
        cleanedName.erase(std::remove(cleanedName.begin(), cleanedName.end(), '.'), cleanedName.end());

        return cleanedName;
    }
};

int main() {
//    vector<string> emails {"j.louis+lael@lenovo.com"};
//    Solution sol;
//    auto localName = sol.getLocalName(emails[0]);
//    auto domainName = sol.getDomainName(emails[0]);
//    auto cleanedName = sol.cleanLocalName(localName);
//    cout << "localName: " << localName << endl;
//    cout << "domainName: " << domainName << endl;
//    cout << "cleanedName: " << cleanedName << endl;

    vector<string> input{"test.email+alex@leetcode.com", "test.e.mail+bob.cathy@leetcode.com",
                         "testemail+david@lee.tcode.com"};
    Solution sol;
    cout << "num: " << sol.numUniqueEmails(input) << endl;
}

