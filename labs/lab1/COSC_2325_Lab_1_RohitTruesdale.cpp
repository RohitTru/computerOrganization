#include <iostream>

using namespace std;

void main ()
{
    const unsigned char c1 (0x11);
    const unsigned char c2 (0x22);
    const unsigned char c3 (0x33);
    const unsigned char c4 (0x44);
    unsigned long i1 (0);
    _asm {     
        mov AH, c1       
        mov AL, c2       
        shl EAX, 16
        mov AH, c3
        mov Al, c4
        mov EAX, i1
    }   

        
cout << "result is " << hex << i1 << endl;
}