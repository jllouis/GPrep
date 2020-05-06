#include <iostream>
#include <vector>
#include <queue>
#include <deque>

using namespace std;

vector<int> findThreeLargestNumbers(vector<int> array) {
    priority_queue<int, vector<int>, greater<>> topThree;

    for (int i = 0; i < 3; ++i)
        topThree.push(array[i]);

    for (int i = 3; i < array.size(); ++i)
        if (array[i] > topThree.top()) {
            topThree.pop();
            topThree.push(array[i]);
        }

    vector<int> result;
    while (!topThree.empty()) {
        result.push_back(topThree.top());
        topThree.pop();
    }

    return result;
}

int main() {
    auto input = {141, 1, 17, -7, -17, -27, 18, 541, 8, 7, 7};
    for (auto e : findThreeLargestNumbers(input))
        cout << e << " ";
}

