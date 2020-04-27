/*
Given a string, find the length of the longest substring without repeating characters.

Example 1:

Input: "abcabcbb"
Output: 3
Explanation: The answer is "abc", with the length of 3.
Example 2:

Input: "bbbbb"
Output: 1
Explanation: The answer is "b", with the length of 1.
Example 3:

Input: "pwwkew"
Output: 3
Explanation: The answer is "wke", with the length of 3.
             Note that the answer must be a substring, "pwke" is a subsequence and not a substring.
*/

#include <algorithm>
#include <iostream>
#include <string>
#include <unordered_set>

using namespace std;

class Solution {
public:
    static int lengthOfLongestSubstring(string s) {
        int longestUnique = 0;
        int lPointer = 0, rPointer = 1;
        unordered_set<char> letters;
        bool unique = true;

        while (lPointer < s.length()) {
            for (int i = lPointer, k = rPointer; i < k;)
        }

    }
};