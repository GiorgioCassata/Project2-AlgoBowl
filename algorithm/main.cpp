#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ifstream input;
    ofstream output;

    vector<int> unvisited;
    vector<int> visited;

    bool exists;
    int indexVis = 0;
    int lastAddition;
    int numInputs;
    int tempInt;
    int i;
    input.open("input.txt");
    output.open("output.txt");

    input >> numInputs;

    // get all inputs into vector
    while(!input.eof()) {
        input >> tempInt;
        unvisited.push_back(tempInt);
    }

    // setup first number (always solves for 2)
    visited.push_back(1);
    lastAddition = 1 + 1; // addition instead of mult for clarification
    visited.push_back(lastAddition);
    output << 1 << ' ' << 1 << endl;
    cout << lastAddition << endl;
    i = -1;
    while (visited.back() < unvisited.back()) { // change this condition because we'll take more steps
        i++;
        // if next in input > (2 * lastAddition):
        if (unvisited.at(i) > 2 * lastAddition) {
            // do addition
            visited.push_back(2*lastAddition);
        } else {
    //     if (input - last) exists in visited
            exists = false;
            for (int j = 0; j < visited.size(); ++j) {
                if ((unvisited.at(i) - lastAddition) == visited.at(j)) {
                    exists = true;
                    indexVis = j;
                    break;
                }
            }
            if (exists) {
                output << lastAddition << ' ' << visited.at(indexVis) << endl;
                cout << lastAddition << endl;
                lastAddition = lastAddition + visited.at(indexVis);
                visited.push_back(lastAddition);
            } else {
                    //         find least greatest visited for its difference
                    exists = false;
                    for (int j = 0; j < visited.size(); ++j) {
                        if ((unvisited.at(i) - visited.at(j)) == lastAddition){
                            exists = true;
                            indexVis = j;
                            break;
                        }
                    }
                    if (exists) {
                        output << lastAddition << ' ' << visited.at(indexVis) << endl;
                        cout << lastAddition << endl;
                        lastAddition = lastAddition + visited.at(indexVis);
                        visited.push_back(lastAddition);
                    }
                    else {
                        output << lastAddition << ' ' << 1 << endl;
                        cout << lastAddition << endl;
                        lastAddition = lastAddition + 1;
                        visited.push_back(lastAddition);
                    }

            }
        }
    }

    input.close();
    output.close();
    return 0;
}
