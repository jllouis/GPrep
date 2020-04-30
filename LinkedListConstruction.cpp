#include <iostream>
#include <vector>
#include<map>

using namespace std;

class Node {
public:
    int value;
    Node *prev;
    Node *next;

    Node(int value, Node *prev = nullptr, Node *next = nullptr) : value{value}, prev{prev}, next{next} {};
};

// Feel free to add new properties and methods to the class.
class DoublyLinkedList {
public:
    Node *head;
    Node *tail;

    DoublyLinkedList() {
        head = nullptr;
        tail = nullptr;
    }


    void setHead(Node *node) {
        if (!head) {
            head = node;
            tail = node;
        }

        Node *previous = node->prev;

        if (node->next)
            node->next->prev = node->prev;
        if (node->prev)
            node->prev->next = node->next;

        while (previous->prev)
            previous = previous->prev;

        previous->prev = node;
        node->next = previous;
    }

    void setTail(Node *node) {
        if (!node->next)
            return;

        Node *next = node->next;

        node->next->prev = node->prev;
        node->prev->next = node->next;

        while (next->next)
            next = next->next;

        next->next = node;
        node->prev = next;


    }

    void insertBefore(Node *node, Node *nodeToInsert) {

        if (node->prev) {
            node->prev->next = nodeToInsert;
            nodeToInsert->prev = node->prev;
        }

        node->prev = nodeToInsert;
        nodeToInsert->next = node;

    }

    void insertAfter(Node *node, Node *nodeToInsert) {
        if (node->next) {
            node->next->prev = nodeToInsert;
            nodeToInsert->next = node->next;
        }

        node->next = nodeToInsert;
        nodeToInsert->prev = node;
    }

    void insertAtPosition(int position, Node *nodeToInsert) {
        if (!head) {
            head = nodeToInsert;
            return;
        }

        auto pointer = head;
        Node *lastPointer;
        for (int counter = 1; counter < position; ++counter, lastPointer = pointer, pointer = pointer->next);


        if (pointer)
            insertBefore(pointer, nodeToInsert);
        else {
            lastPointer->next = nodeToInsert;
            nodeToInsert->prev = lastPointer;
        }
    }

    void removeNodesWithValue(int value) {
        Node *current = head;
        while (current) {
            if (current->value == value) {
                auto temp = current;
                current = current->next;
                remove(temp);
            }
            current = current->next;
        }
    }

    void remove(Node *node) {
        auto leftNode = node->prev, rightNode = node->next;

        if (leftNode)
            leftNode->next = rightNode;

        if (rightNode)
            rightNode->prev = leftNode;

        delete node;
    }

    bool containsNodeWithValue(int value) {
        auto pointer = head;

        while (pointer) {
            if (pointer->value == value)
                return true;
            else
                pointer = pointer->next;
        }

        return false;
    }

    void print() const {
        auto pointer = head;
        cout << ": ";
        while (pointer) {
            cout << pointer->value << " <-> ";
            pointer = pointer->next;
        }
    }
};

int main() {
    DoublyLinkedList linkedList;
    map<string, Node *> nodes;

    for (int i = 1; i <= 6; ++i)
        nodes[to_string(i)] = new Node(i);
    nodes["3-2"] = new Node(3);
    nodes["3-3"] = new Node(3);

    for (int i = 1; i <= 5; ++i)
        linkedList.insertAtPosition(i, nodes[to_string(i)]);

    linkedList.setHead(nodes["5"]);
    linkedList.setHead(nodes["4"]);
    linkedList.setHead(nodes["3"]);
    linkedList.setHead(nodes["2"]);
    linkedList.setHead(nodes["1"]);
    linkedList.setHead(nodes["4"]);
    linkedList.setTail(nodes["6"]);
    linkedList.insertBefore(nodes["6"], nodes["3"]);
    linkedList.insertAfter(nodes["6"], nodes["3-2"]);
    linkedList.insertAtPosition(1, nodes["3-3"]);
    linkedList.remove(nodes["2"]);
    linkedList.containsNodeWithValue(5);

    linkedList.print();
}
