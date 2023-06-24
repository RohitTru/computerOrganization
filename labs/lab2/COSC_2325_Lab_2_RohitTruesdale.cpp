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
        mov eax,i1
		mov c1,al
		
		shr EAX, 8
		mov c2, al
		
		shr eax, 8
        mov c3, al
        
        shr eax, 8
        mov c4, al
        }
    cout.flags (ios::hex);
    cout << "results are " << (unsigned int) c1 << ", "
                                    << (unsigned int) c2 << ", "
                                    << (unsigned int) c3 << ", "
                                    << (unsigned int) c4 << endl;
}
