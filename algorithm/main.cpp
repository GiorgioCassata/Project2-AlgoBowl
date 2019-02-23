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

    vector<int> unvisited, visited;

    bool exists;
    int indexVis = 0;
    int stepCounter = 0;
    int i = 0;
    int lastAddition, numInputs, tempInt;

    input.open("input_group92.txt");
    output.open("temp.txt");

    input >> numInputs;

    // get all inputs into vector
    while(!input.eof()) {
        input >> tempInt;
        unvisited.push_back(tempInt);
    }

    // Some files have an extra empty line which causes doubles of the last number
    // This removes that double if it exists
    if (unvisited.back() == unvisited.at(numInputs-1)) {
        unvisited.pop_back();
    }

    // check size of inputs matches actual size of inputs
    if (numInputs != unvisited.size()) {
        cout << "input size Doesnt match: " << unvisited.size() << " instead of " << numInputs << endl;
        return 1;
    }

    // setup first number (always solves for 2 using 1's)
    visited.push_back(1);
    lastAddition = 1 + 1; // actual addition for clarification
    visited.push_back(lastAddition);
    output << 1 << ' ' << 1 << endl;
    stepCounter++;
    // Will loop until the last addition is the same as the last target input
    while (visited.back() < unvisited.back()) {
        stepCounter++; // every loop results in an addition step

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
            continue; //continue wihtout iterating because this does not always meet reqs
        } else {
            // If there exists an addition with a visited number that results in the
            // next target input, it will always perform that addition
            exists = false;
            for (int j = visited.size()-1; j >= 0; --j) {
                if (unvisited.at(i) == visited.at(j) + lastAddition) {
                    exists = true;
                    indexVis = j;
                    break;
                }
            }
            if (exists) {
                output << lastAddition << ' ' << visited.at(indexVis) << endl;
                lastAddition = lastAddition + visited.at(indexVis);
                visited.push_back(lastAddition);
                i++;
                continue;
            } else {
                    // find the greatest visited that is a valid addition
                    exists = false;
                    for (int j = visited.size()-1; j >= 0; --j) {
                        if (unvisited.at(i) > visited.at(j) + lastAddition){
                            exists = true;
                            indexVis = j;
                            break;
                        }
                    }
                    if (exists) {
                        output << lastAddition << ' ' << visited.at(indexVis) << endl;
                        lastAddition = lastAddition + visited.at(indexVis);
                        visited.push_back(lastAddition);
                        continue; // doesnt always meet reqs to iterate
                    }
                    else {
                        cout << "Hey so like, this wasn't supposed to happen." << endl;
                        return 1;
                    }
            }
        }
        //i++; //iterate
    }

    input.close();
    output.close();

    // create actual output file
    input.open("temp.txt");
    output.open("output_group92.txt");

    stepCounter++;

    output << stepCounter << endl; //put stepCounter at beginning of actual output

    // transfer additions to actual output file
    for( int i = 1; i < stepCounter; ++i ) {
        input >> tempInt;
        output << tempInt;
        output << ' ';
        input >> tempInt;
        output << tempInt;
        output << endl;
    }

    input.close();
    output.close();
    return 0;
}
