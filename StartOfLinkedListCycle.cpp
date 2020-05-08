#include <iostream>
#include <set>

using namespace std;

class ListNode {
public:
    int value = 0;
    ListNode *next;

    ListNode(int value) {
        this->value = value;
        next = nullptr;
    }
};

class LinkedListCycleStart {
public:
    static ListNode *findCycleStart(ListNode *head) {
        set<ListNode *> seen;

        while (head) {
            if (seen.find(head) == seen.end()) {
                seen.insert(head);
                head = head->next;
            } else return head;
        }
        return nullptr;
    }
};