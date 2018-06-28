#ifndef _BASE_H_
#define _BASE_H_

#include <string>
#include <vector>

using namespace std;

#include "node.h"

class Base {
public:
    Base(const string &filename, int m, int n, double supportThreshold);
    ~Base();
    // char *getData();
    // int getM();
    // int getN();
    const vector <vector <Node> > &getSupports() const;
    const vector <Node *> &getTotalSupports() const;

    void sort(const string &sort_type);

private:
    int m; // Amount of transactions
    int n; // Amount of goods
    double supportThreshold;
    char *data;
    vector <vector <Node> > layersSupport;
    vector <Node *> totalSupports;

    void read(const string &filename); // Reads database
    void countSupport(); // Counts support for every set of goods
    void mergeLayers(); // Merges all support layers into one single list 
};

#endif  // _BASE_H_
