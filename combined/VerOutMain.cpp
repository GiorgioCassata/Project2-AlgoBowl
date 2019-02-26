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
    string in = "inputs/input_group74";
    string out = "VerOutputs/output_from_";
    string out2 = "_to_74";
    string type = ".txt";
    string tempIn, tempOut;
    bool isCorrect;
    int adds;
    vector<string> groups = {"71", "72", "74", "75", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "92"};

    for ( int i = 0; i < groups.size(); ++i ) {
        isCorrect = false;
        tempIn = in + type;
        tempOut = out + groups.at(i) + out2 + type;
        //clock_t begin = clock();
        //adds = solve(tempIn, tempOut);
        //cout << tempIn << ' ' << tempOut << endl;
        isCorrect = verify(tempIn,tempOut);
        //clock_t end = clock(); // end of approach specific code
        //double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        if (isCorrect) {
            cout << "Group " << groups.at(i) << ": " << "PASSED\t" << endl;
        } else {
            cout << "Group " << groups.at(i) << ": " << "FAILED\t" << endl;
        }
    }

    return 0;
}
