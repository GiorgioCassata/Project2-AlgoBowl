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

    input.open("input.txt");
    output.open("output.txt");

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
            cout << "ERROR: Not Visited" << endl;
        }
        visited.push_back(first + second);
        for(int i = 0; i<unvisited.size(); i++){
            if(unvisited.at(i) == first + second){
                unvisited.erase(unvisited.begin() + i);
            }
        }
    }



    //check if the number of steps match and each number of the input has been visited
    if (counter == numSteps) {
        cout << "is all good" << endl;
    }

    if(unvisited.size() != 0){
        cout << "ERROR: not all inputs visited" << endl;
    }

    input.close();
    output.close();
    return 0;
}
