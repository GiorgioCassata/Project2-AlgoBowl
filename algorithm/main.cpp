#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

void printVect(vector<int> a) {
    cout << endl;
    for (int z = 0; z < a.size(); ++z) {
        cout << a.at(z) << endl;
    }
    cout << endl;
}

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

    // setup first number (always solves for 2 using 1's)
    visited.push_back(1);
    lastAddition = 1 + 1; // addition instead of mult for clarification
    visited.push_back(lastAddition);
    output << 1 << ' ' << 1 << endl;
    //cout << lastAddition << endl;
    i = 0;
    while (visited.back() < unvisited.back()) { // change this condition because we'll take more steps
        // prevents skipping numbers
        if (unvisited.at(i) == lastAddition) {
            i++;
            continue;
        }

        // if the addition of the largest visited number with itself is
        // less than the target number, it will do that addition.
        if (unvisited.at(i) > 2 * lastAddition) {
            output << lastAddition << ' ' << lastAddition << endl;
            lastAddition = lastAddition + lastAddition;
            visited.push_back(lastAddition);
            continue; //continue wihtout iterating because this does not always meet an input
        } else {
            exists = false;
            for (int j = visited.size()-1; j >= 0; --j) {
                //cout << visited.at(j) << endl;
                //cout << (visited.at(j) + lastAddition) << endl;
                //cout << unvisited.at(i) << endl;
                if (unvisited.at(i) >= visited.at(j) + lastAddition) {
                    exists = true;
                    indexVis = j;
                    break;
                }
            }
            if (exists) {
                output << lastAddition << ' ' << visited.at(indexVis) << endl;
                //cout << lastAddition << endl;
                lastAddition = lastAddition + visited.at(indexVis);
                visited.push_back(lastAddition);
            } else {
                output << lastAddition << ' ' << 1 << endl;
                cout << lastAddition << endl;
                lastAddition = lastAddition + 1;
                visited.push_back(lastAddition);
                cout << "added 1??" << endl;
                //cout << "not supposed to happen?" << endl;
                //return 0;
            }
            /*else {
                    //find least greatest visited for its difference
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

            } */
        }
        i++; //iterate
    }
    printVect(visited);
    input.close();
    output.close();
    return 0;
}
