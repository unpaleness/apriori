#include <fstream>
#include <algorithm>
#include <iostream>

#include "base.h"

/**********
 * PUBLIC *
 **********/

Base::Base(const string &filename, int m, int n, double supportThreshold) :
    m(m),
    n(n),
    supportThreshold(supportThreshold)
{
    read(filename);
    countSupport();
    mergeLayers();
}

Base::~Base() {
    delete [] data;
}

// char *Base::getData() { return data; }
// int Base::getM() { return m; }
// int Base::getN() { return n; }
const vector <vector <Node> > &Base::getSupports() const {
    return layersSupport;
}

const vector <Node *> &Base::getTotalSupports() const {
    return totalSupports;
}

void Base::sort(const string &sort_type) {
    if (sort_type.compare("inc") == 0) {
        cout << sort_type << endl;
        std::sort(totalSupports.begin(), totalSupports.end(), [](Node *a, Node *b) { return a->getSupport() < b->getSupport(); });
    }
    if (sort_type.compare("des") == 0) {
        cout << sort_type << endl;
        std::sort(totalSupports.begin(), totalSupports.end(), [](Node *a, Node *b) { return a->getSupport() > b->getSupport(); });
    }
}

/***********
 * PRIVATE *
 ***********/

void Base::read(const string &filename) {
    ifstream input(filename, ios::in);
    data = new char [m * n];
    for (int j = 0; j < m; ++j) {
        char buf[n + 1];
        input.getline(buf, n + 1);
        for (int i = 0; i < n; ++i) {
            data[j * n + i] = buf[i];
        }
    }
    input.close();
}

void Base::countSupport() {
    /* 1. Count 1-element layer */
    // 1) step
    vector <Node> layer;
    for (int i = 0; i < n; ++i) {
        layer.push_back(Node(i, to_string(i)));
    }
    for (int j = 0; j < m; ++j) {
        for (int i = 0; i < n; ++i) {
            if (data[j * n + i] == '1') {
                ++layer[i];
            }
        }
    }
    layersSupport.push_back(layer);

    /* 2. Add other layers */
    // for (int i = 1; i < n; ++i) {

    // }
}

void Base::mergeLayers() {
    // NO, DO A HASH!
    for (size_t j = 0; j < layersSupport.size(); ++j) {
        for (size_t i = 0; i < layersSupport[j].size(); ++i) {
            totalSupports.push_back(&layersSupport[j][i]);
        }
    }
}
