#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <vector>
#include <string>

#include "functions.h"

using namespace std;

int main() {
    string in = "inputs/input_group";
    string out = "outputs/output_group";
    string type = ".txt";
    string tempIn, tempOut;
    vector<string> groups = {"71", "72", "74", "75", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "92"};

    for ( int i = 0; i < groups.size(); ++i ) {
        tempIn = in + groups.at(i) + type;
        tempOut = out + groups.at(i) + type;
        solve(tempIn, tempOut);
        if (verify(tempIn,tempOut)) {
            cout << "Group " << groups.at(i) << ": " << "PASSED" << endl;
        } else {
            cout << "Group " << groups.at(i) << ": " << "FAILED" << endl;
        }
    }

    return 0;
}
