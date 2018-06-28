#include <iostream>
#include <string>
#include <cstdlib>

using namespace std;

#include "base.h"

#define ARGC 6
#define HELP "Usage: ./apriori <support_threshold> <sort_type> <max_rules> <goods> <transactions> <filename>\n\
1) double support_threshold - minimum \"support\" value of Apriori algorithm in percents\n\
2) char   sort_type[]       - \"inc\", \"des\" or \"none\"\n\
3) int    max_rules         - maximum amount of rules to be displayed\n\
4) int    goods             - amount of goods' types in database\n\
5) int    transactions      - amount of transactions in database\n\
6) char   filename[]        - name of file with database\
"

int main(int argc, char *argv[]) {
    if (argc <= ARGC) {
        cerr << HELP << endl;
        return 0;
    }
    double support_threshold { atof(argv[1]) };
    string sort_type         { argv[2] };
    int max_rules            { atoi(argv[3]) };
    int goods                { atoi(argv[4]) };
    int transactions         { atoi(argv[5]) };
    string filename          { argv[6] };
    cout << support_threshold << endl << sort_type << endl << max_rules << endl << goods << endl << transactions << endl << filename << endl;

    Base base(filename, transactions, goods, support_threshold);
    base.sort(sort_type);

    for(vector <Node *>::const_iterator it = base.getTotalSupports().begin(); it != base.getTotalSupports().end(); ++it) {
        cout << (*it)->getName() << ' ' << (double) (*it)->getSupport() / transactions << endl;
    }
    // for (int j = 0; j < base.getM(); ++j) {
    //     cout << j << ' ';
    //     int i;
    //     for (i = 0; i < base.getN(); ++i) {
    //         cout << base.getData()[j * base.getN() + i];
    //     }
    //     cout << ' ' << i << endl;
    // }
}
