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

class LinkedListCycle {
public:
    static bool hasCycle(ListNode *head) {
        set<ListNode *> seen;

        while (head) {
            if (seen.find(head) == seen.end()) {
                seen.insert(head);
                head = head->next;
            } else return true;
        }
        return false;
    }
};

int main(int argc, char *argv[]) {
    ListNode *head = new ListNode(1);
    head->next = new ListNode(2);
    head->next->next = new ListNode(3);
    head->next->next->next = new ListNode(4);
    head->next->next->next->next = new ListNode(5);
    head->next->next->next->next->next = new ListNode(6);
    cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;

    head->next->next->next->next->next->next = head->next->next;
    cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;

    head->next->next->next->next->next->next = head->next->next->next;
    cout << "LinkedList has cycle: " << LinkedListCycle::hasCycle(head) << endl;
}