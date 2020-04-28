#include <iostream>
#include <vector>
#include <deque>
#include <set>

using namespace std;

class Node {
public:
    string name;
    vector<Node *> children;
    bool visited = false;

    Node(string str) { name = str; }

    vector<string> depthFirstSearch(vector<string> *array) {
        deque<Node *> toVisit;
        for (auto c : children)
            toVisit.push_front(c);

        for (auto v : toVisit)
            array->push_back(v->name);

        return {};
    }

    Node *addChild(string name) {
        Node *child = new Node(name);
        children.push_back(child);
        return this;
    }
};