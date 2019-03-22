#ifndef AUTOMAT_H_INCLUDED
#define AUTOMAT_H_INCLUDED

#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

class Automat {
    set<char> Q, S, F;
    char q0;
    ///struct for transition edges
    struct transition {
        char initState, rule, destState;
        };
    vector<transition> d;

public:
    typedef transition trans;
    friend istream& operator>>(istream& file, Automat& object);
    bool eval(string w);
};

#endif // AUTOMAT_H_INCLUDED

