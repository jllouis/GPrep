#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

vector<vector<int>> threeNumberSum(vector<int> array, int targetSum) {
    vector<vector<int>> results;

    sort(array.begin(), array.end()); // nlogn // {-8, -6, 1, 2, 3, 5, 6, 12}
    for (vector<int>::size_type i = 0; i < array.size(); ++i) {
        auto l = i + 1, r = array.size() - 1;

        while (l < r) {
            auto sum = array[i] + array[l] + array[r];

            if (sum < targetSum)
                l++;
            else if (sum > targetSum)
                r--;
            else {
                results.push_back({array[i], array[l], array[r]});
                l++;
            }
        }
    }


    return results;
}

int main() {

    for (const auto &v : threeNumberSum({12, 3, 1, 2, -6, 5, -8, 6}, 0)) {
        cout << "{ ";
        for (auto e : v)
            cout << e << ", ";
        cout << " }" << endl;
    }

}
