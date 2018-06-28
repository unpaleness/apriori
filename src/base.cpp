#include <fstream>

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
const vector <vector <Node> > &Base::getSupport() const {
    return layersSupport;
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
    // for (int j = 0; j < layersSupport.size(); ++j) {

    // }
}
