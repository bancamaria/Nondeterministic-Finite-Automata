#include <iostream>
#include <fstream>
#include <string>
#include "automat.h"
using namespace std;
ifstream f("machine.txt");
ifstream g("machine2.txt");

int main() {
    Automat A;
    f >> A;
    //g >> A;
    string w;
    f >> w;
    //g >> w;

    if(A.eval(w))
        cout << "Accepted word!";
    else
        cout << "Rejected word!";

    return 0;
}
