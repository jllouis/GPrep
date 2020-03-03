#include <map>
#include <iostream>
#include <vector>
#include <numeric>

using namespace std;

void updateTracker(map<int, int> &tracker, const int &c) {
    for (auto &t: tracker)
        if (t.first <= c)
            tracker[t.first]++;
}

int calculateHScore(const vector<int> &citations) {
    map<int, int> tracker{};
    for (const int &c : citations) {
        if (tracker.contains(c)) {
            updateTracker(tracker, c);
        } else {
            updateTracker(tracker, c);
            tracker.insert({c, accumulate(tracker.begin(), tracker.end(), 1,
                                          [&c](int value, const map<int, int>::value_type &p) {
                                              return (p.first > c) ? value + p.second : value;
                                          })});
        }

    }

    for (const auto &k : tracker)
        if (k.first == k.second)
            return k.first;

    return -1;
}

int main() {
    vector<int> citations{1, 4, 1, 4, 2, 1, 3, 5, 6};
    cout << calculateHScore(citations) << endl;
}