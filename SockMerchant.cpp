#include <vector>
#include <unordered_map>
#include <iostream>
#include <cmath>

using namespace std;

vector<string> split_string(string);

// Complete the sockMerchant function below.
int sockMerchant(int n, vector<int> ar) {
    unordered_map<int, int> pairs{};

    for (const int &i : ar) {
        if (pairs.find(i) != pairs.end())
            pairs[i]++;
        else
            pairs.insert({i, 1});
    }

    int numPairs = 0;
    for (const auto &i : pairs)
        numPairs += floor(i.second / 2);


    return numPairs;

}

int main() {
    cout << sockMerchant(9, {10, 20, 20, 10, 10, 30, 50, 10, 20}) << endl;
}