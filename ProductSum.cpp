#include <any>
#include <vector>
#include <iostream>

using namespace std;

int compute(const vector<any> &array, const int multiplier = 1) {
    int sum = 0;
    for (const auto &e : array)
        sum += multiplier * ((e.type() == typeid(vector<any>)) ? compute(any_cast<const vector<any> &>(e),
                                                                         multiplier + 1)
                                                               : any_cast<const int>(e));

    return sum;
}

int productSum(vector<any> array) {
    return compute(array);
}