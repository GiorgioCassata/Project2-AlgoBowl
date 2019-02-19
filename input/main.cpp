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

    int count = 0;
    ofstream file;
    file.open("input.txt");

    file << "654" << endl;

    for ( int i = 0; i < 16; ++i ) {
        file << pow(2,i) << ' ';
        count++;
    }
    file << pow(2,17) - 1 << ' ';
    count++;

    for ( int i = 6; i < 32; ++i ) {
        file << pow(2,17) + fib(i) << ' ';
        count++;
    }

    int last = 963112;
    for (int i = 0; i<200; i++){
        last  = last + (rand()%139) + 23;
        file << last << ' ';
        count++;
    }

    last = 3000000;
    for (int i = 0; i<200; i++){
        last  = last + (rand()%289) + 88;
        file << last << ' ';
        count++;
    }

    last = 500000000;
    for (int i = 1; i<211; i++){
        last  = last + pow(i,3);
        file << last << ' ';
        count++;
    }
    file << 999999999;
    count++;



    cout << count << endl;


    file.close();
    return 0;
}
