/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 *
 * Example:
Input: (2 -> 4 -> 3) + (5 -> 6 -> 4)
Output: 7 -> 0 -> 8
Explanation: 342 + 465 = 807.
 */
#include <iostream>
#include <stack>
#include <string>

using namespace std;

struct ListNode {
    int val;
    ListNode *next;

    ListNode(int x) : val(x), next(NULL) {}
};


class Solution {
public:
    static ListNode *addTwoNumbers(ListNode *l1, ListNode *l2) {

        int carryOver = 0;
        stack<int> sums;
        bool first = true;

        ListNode *head;
        listNode *ptr = &head;
        while (l1 && l2) {
            ListNode node;
            int sum = l1->val + l2->val + carryOver;
            if (carryOver > 9) {
//                sums.push(sum % 10);
                node(sum % 10);
                carryOver = sum / 10;
            } else {
                carryOver = 0;
//                sums.push(sum);
                node(sum);
            }

            l1 = l1->next;
            l2 = l2->next;

            if (first) {
                head = node;
                first = false;
            } else {
                ptr->next = node;
            }

        }

        if (!l1)
            while (l2) {
                sums.push(l2);
                l2 = l2->next;
            }
        else
            while (l1) {
                sums.push(l1);
                l1 = l1->next;
            }

//
//        ListNode result;
//        ListNode *pointer = result;
//
//        if
//        do {
//            pointer = new ListNode();
//        } while (!sums.empty())
    }

};