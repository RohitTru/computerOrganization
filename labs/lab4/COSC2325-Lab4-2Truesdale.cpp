#include <iostream>
using namespace std;

int main() {
    char Part1[] = "COSC 2325";
    char Part2[] = "Test 2";
    char Complete[20];

    _asm(
        // Copy Part1 into Complete string
        
        mov 0, ecx   				 //  (move only 8 bits) Initialize loop counter to 0
        loop_1:
        mov 0(ecx), al 			 // Copy a byte from ^ to AL register
        mov al, ecx 				 // Store the byte in Complete
        inc ecx       				 // Increment the loop counter
    	cmp al, al    				 // Check if end of Part1 reached
    	jump loop1  				 // If not 0, continue looping

        // Add a space
    	mov $' ', ecx  				// Store space character in Complete
    	inc ecx       			    // Increment the loop counter

        // Copy Part2 into Complete string
       	mov 0, edi                       // Initialize destination index to 0
        loop2:
        	mov edi, al 	 		 // Copy a byte from Part2 to AL register
        	mov al, ecx 			 // Store the byte in Complete
        	inc ecx       			 // Increment the loop counter
        	inc edi			             // Increment the destination index
        	cmp 0, al    			 // Check if end of Part2 reached
        	jump loop2  			 // If not 0, continue looping

        : "+c"(Complete), "+S"(Part1), "+D"(Part2)  // Inputs/Outputs for the assembly code
    );

    std::cout << "Complete: " << Complete << std::endl;

    return 0;
}



