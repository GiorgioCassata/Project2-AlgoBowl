#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <cmath>

using namespace std;

int fib(int n) {
    int t1 = 0, t2 = 1, nextTerm = 0;
    for (int i = 1; i <= n; ++i)
    {
        // Prints the first two terms.
        if(i == 1)
        {
            //cout << " " << t1;
            continue;
        }
        if(i == 2)
        {
            //cout << t2 << " ";
            continue;
        }
        nextTerm = t1 + t2;
        t1 = t2;
        t2 = nextTerm;

        //cout << nextTerm << " ";
    }
    return nextTerm;
}


int main() {
    srand( time(0) );

    ofstream file;
    file.open("input.txt");

    file << "500" << endl;

    for ( int i = 0; i < 16; ++i ) {
        file << pow(2,i) << ' ';
    }
    file << pow(2,17) - 1 << ' ';

    for ( int i = 6; i < 32; ++i ) {
        file << pow(2,17) + fib(i) << ' ';
    }



    file.close();
    return 0;
}
