#include "node.h"

/**********
 * PUBLIC *
 **********/

Node::Node() {}

Node::Node(int itemId, const string &name) : itemId(itemId), name(name) {

}

Node::Node(const Node &node) {
    for (size_t i = 0; i < node.nParents(); ++i) {
        parents.push_back(const_cast <Node *> (&node.getParent(i)));
    }
    itemId = node.getItemId();
    support = node.getSupport();
    name = node.getName();
}

Node::~Node() {}

Node &Node::operator++() {
    ++support;
    return *this;
}

void Node::addParent(Node *parent) {
    parents.push_back(parent);
}

size_t Node::nParents() const { return parents.size(); }
const Node &Node::getParent(size_t i) const { return *parents[i]; }
int Node::getItemId() const { return itemId; }
int Node::getSupport() const { return support; }
const string &Node::getName() const { return name; }
 
/***********
 * PRIVATE *
 ***********/
