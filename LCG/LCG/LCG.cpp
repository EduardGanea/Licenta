#include <iostream>
using namespace std;

class mRND {

public:
    void seed(unsigned int s) {     // seed used to generate a random first value
        _seed = s;
    }

protected:
    mRND() :
        _seed(0), a(0), c(0), m(2147483649) { }
    int rnd() {
        return (_seed = (a * _seed + c) % m);       // next value(_seed) = ( multiplier(a) * previous value(_seed) + Increment value(c) ) % modulus(m)
    }

    int a, c;
    unsigned int m, _seed;
};

class MS_RND : public mRND {    // Main subclass for generating random numbers
public:
    MS_RND() {
        a = 2140;       // multiplier (can be changed in order to generate other values)
        c = 25310133;  // increment   (can be changed in order to generate other values)
    }

    int rnd() {
        return mRND::rnd() >> 16;
    }
};

class SS_RND : public mRND {   // Secondary subclass for generating random numbers
public:
    SS_RND() {
        a = 1016404594;    // multiplier (can be changed in order to generate other values)
        c = 123452;        // increment   (can be changed in order to generate other values)
    }
    int rnd() {
        return mRND::rnd();
    }
};
int main(int argc, char* argv[]) {
    SS_RND ss_rnd;
    MS_RND ms_rnd;
    cout << "MS RAND:" << endl << "-----------" << endl;
    for (int x = 0; x < 6; x++)                         // generating first 6 random values according to the multiplier and increment chosen
        cout << ms_rnd.rnd() << endl;
    cout << endl << "SS RAND:" << endl << "-------------" << endl;
    for (int x = 0; x < 6; x++)                         // generating first 6 random values according to the multiplier and increment chosen
        cout << ss_rnd.rnd() << endl;
    return 0;
}