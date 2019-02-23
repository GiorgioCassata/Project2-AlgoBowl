#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>
#include <vector>

using namespace std;

int main() {
    ifstream input;
    ifstream output;
    int numSteps;
    int counter = 0;
    int tempInt;
    string tempStr;
    vector<int> unvisited;
    vector<int> visited;
    int  numInputs;
    int first, second;
    bool firstCheck, secondCheck;

    input.open("input_group92.txt");
    output.open("output_group92.txt");

    input >> numInputs;
    //cout << numInputs;
    //store numsteps
    output >> numSteps;

    // get all inputs into vector
    while(!input.eof()) {
        input >> tempInt;
        //tempInt = stoi(tempStr);
        unvisited.push_back(tempInt);
    }

    //for each step, check if the addition is correct and the number has been visited
    visited.push_back(1);
    while(!output.eof()) {
        counter++;
        output >> first;
        output >> second;
        firstCheck = false;
        secondCheck = false;
        for(int i = 0; i<visited.size(); i++){
            if(visited.at(i) == first){
                firstCheck = true;
            }
            if ( visited.at(i) == second){
                secondCheck= true;
            }
        }
        if (!firstCheck || !secondCheck){
            cout << "ERROR: Number Used On Line " << counter << " Not Visited " << endl;
            return 1;
        }
        visited.push_back(first + second);
        for(int i = 0; i<unvisited.size(); i++){
            if(unvisited.at(i) == first + second){
                unvisited.erase(unvisited.begin() + i);
            }
        }
    }

    //check if the number of steps match and each number of the input has been visited
    if (counter != numSteps) {
        cout << "bad steps" << endl;
        cout << counter << " instead of " << numSteps << endl;
        return 1;
    }

    if(unvisited.size() != 0){ // has to be 1 if input starts with 1
        cout << unvisited.at(0) << endl;
        cout << "ERROR: not all inputs visited" << endl;
        return 1;
    }

    cout << "ran without problems" << endl;
    input.close();
    output.close();
    return 0;
}
