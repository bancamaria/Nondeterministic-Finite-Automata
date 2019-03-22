#include "automat.h"
#include <iostream>
#include <vector>
#include <set>
#include <string>
using namespace std;

istream& operator>>(istream& file, Automat& object) {
    int n;
    ///reading the states q0, q1, ...
    file >> n;
    for(int i = 0; i < n; i++) {
        char state;
        file >> state;
        object.Q.insert(state);
    }

    ///reading the letters
    file >> n;
    for(int i = 0; i < n; i++) {
        char letter;
        file >> letter;
        object.S.insert(letter);
    }

    ///reading the transitions
    file >> n;
    for(int i = 0; i < n; i++) {
        Automat::trans transition;
        file >> transition.initState >> transition.rule >> transition.destState;
        object.d.push_back(transition);
    }

    ///reading initial and final states
    file >> object.q0;
    file >> n;
    for (int i = 0; i < n; i++){
        char state;
        file >> state;
        object.F.insert(state);
    }
    return file;
}

bool Automat::eval(string w) {
    ///activating the set of current states
    set<char> currentStates;
    ///activating q0
    currentStates.insert(q0);

    for(string::iterator letter = w.begin(); letter != w.end()  &&  !currentStates.empty(); letter++){            ///current letter
        set<char> nextStates;                                                                                   ///the set of next states to be activated
        for(set<char>::iterator state = currentStates.begin(); state != currentStates.end(); state++){          ///activated state to be evaluated
            for(vector<Automat::trans>::iterator transition = d.begin(); transition != d.end(); transition++){  ///searching for transitions
                if(transition->initState == *state  &&  transition->rule == *letter)                            ///transition needs to be of currentState-letter> format
                    nextStates.insert(transition->destState);                                                   ///adding state to activate on next iteration
            }
        }
        ///activating the next states
        currentStates = nextStates;
    }
    ///searching for final states through the set of activated sets (in the end)
    for(set<char>::iterator state = currentStates.begin(); state != currentStates.end(); state++)
        if(F.find(*state) != F.end()) return true;
    return false;
}

