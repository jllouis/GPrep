#include <vector>
#include <unordered_set>
#include <iostream>

using namespace std;

vector<int> findDuplicates(const vector<int> &arr1, const vector<int> &arr2) {
    vector<int> results;
    unordered_set<int> bucket(arr1.begin(), arr1.end());

    for (const int &number : arr2) {
        if (bucket.contains(number)) {
            results.push_back(number);
        }
    }

    return results;
}

int main() {

    for (const int &number : findDuplicates({1, 2, 3, 5, 6, 7}, {3, 6, 7, 8, 20}))
        cout << number << endl;
    return 0;
}