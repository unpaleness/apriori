#ifndef _NODE_H_
#define _NODE_H_

#include <string>
#include <vector>

using namespace std;

class Node {
public:
    Node();
    Node(int itemId, const string &name);
    Node(const Node &node);
    ~Node();

    Node &operator++();

    void addParent(Node *parent);
    size_t nParents() const;
    const Node &getParent(size_t i) const;
    int getItemId() const;
    int getSupport() const;
    const string &getName() const;

private:
    vector <Node *> parents;
    int itemId { 0 };
    int support { 0 };
    string name;
};

#endif // _NODE_H_
