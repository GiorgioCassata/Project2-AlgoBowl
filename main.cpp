#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>


using namespace std;

int main() {
    srand( time(0) );

    ofstream file;
    file.open("input.txt");

    file << "test";

    file.close();
    return 0;
}
