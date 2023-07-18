#include <iostream>
using namespace std;

void main ()
	{
	unsigned long i1 = 1;
	unsigned long i2 = 1;
	unsigned long i3 = 0;
    unsigned long i4 = 0;
	
_asm{
    mov eax, i1 				// Move the value of i1 into the EAX register
    mov ebx, i2 				// Move value i2 into EBX 
    mov ecx, i3 				// Move value i3 into ECX 
    mov edx, i4 				// Move value i4 into EDX 

    oop_one: 				// Start of out first loop
        add eax, 3 				// Add 3 to i1
        imul ebx, 12 				// Multiply i2 by 12
        inc ecx 					// Increment i3

        cmp eax, 100  				// Compare i1 to 100
        jump loop_final 				// If i1 is greater than 100, jump to loop_final

    cmp ecx, 15 				// Compare i3 to 15
    jump loop_one 				// If i3 is less than 15, jump to loop_one

    cmp ebx, 999999 				// Compare i2 to 999999
    jump loop_final 				// If i2 is greater than or equal to 999999, jmp to loop_final

    jump loop_one           			// Jump back to loop_one

    loop_final: 				// Define
        mov i1, eax 				// Move the value in EAX back to i1
        mov i2, ebx				// Move the value in EBX back to i2
        mov i3, ecx 				// Move the value in ECX back to i3
        mov i4, edx 				// Move the value in EDX back to i4
    }

	cout << "Results are " << i1 << ", " << i2 << ", " << i3 << ", " << i4 << endl;

    // Set i3 to the number of times through the loop 
    i3 = count; 
    
    // Set i4 to the remainder of i1 divided by i3
    i4 = i1 % i3;

    // print the final values for  i1, i2, i3, and i4
    cout  << i1 << ", " << i2 << ", " << i3 << ", " << i4 << endl;
}
