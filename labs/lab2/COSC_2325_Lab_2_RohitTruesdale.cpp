#include <iostream>

using namespace std;

void main ()
    {
    unsigned char c1;
    unsigned char c2;
    unsigned char c3;
    unsigned char c4;
    unsigned long i1 (0xaabbccee);
    __asm {
        }
    cout.flags (ios::hex);
    cout << "results are " << (unsigned int) c1 << ", "
                                    << (unsigned int) c2 << ", "
                                    << (unsigned int) c3 << ", "
                                    << (unsigned int) c4 << endl;
}
