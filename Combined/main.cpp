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
    bool isCorrect;
    int adds;
    vector<string> groups = {"71", "72", "74", "75", "77", "78", "79", "80", "81", "82", "83", "84", "85", "86", "87", "88", "92"};

    for ( int i = 0; i < groups.size(); ++i ) {
        isCorrect = false;
        tempIn = in + groups.at(i) + type;
        tempOut = out + groups.at(i) + type;
        clock_t begin = clock();
        adds = solve(tempIn, tempOut);
        isCorrect = verify(tempIn,tempOut);
        clock_t end = clock(); // end of approach specific code
        double elapsed_secs = double(end - begin) / CLOCKS_PER_SEC;
        if (isCorrect) {
            cout << "Group " << groups.at(i) << ": " << "PASSED\t" << adds << " additions in " << elapsed_secs << " seconds" << endl;
        } else {
            cout << "Group " << groups.at(i) << ": " << "FAILED\t" << adds << " addition in " << elapsed_secs << " seconds" << endl;
        }
    }

    return 0;
}
