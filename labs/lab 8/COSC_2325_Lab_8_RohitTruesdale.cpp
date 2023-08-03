#include <iostream>
using namespace std;

// Declare two external assembly functions, 'CalcAverage' and 'FindHighest'
extern "C" long CalcAverage(long, long[]);
extern "C" long FindHighest(long, long[]);

int main() {
    // Two arrays of long integers
    long grades1[10] = {52, 77, 51, 89, 98, 74, 85, 92, 95, 86};
    long grades2[10] = {52, 77, 51, 89, 98, 74, 85, 92, 95, 86};

    // Calculate the average grade for 'grades1' using inline assembly
    long average1 = 0;
    _asm {
        mov cx, 9               // Set loop counter to 9 (number of elements in the array)
        lea si, grades1         // Load 'grades1' address into 'si' register

        calcLoop1:
        add ax, [si]        // Add the current element in 'grades1' to the accumulator 'ax'
        inc si              // Point to the next element in 'grades1'
        loop calcLoop1      // Loop back until 'cx' becomes zero

        mov bl, 9           // Set 'bl' register to 9 (used for division to calculate the average)
        div bl              // Perform division to get the average
        add al, 30h         // Convert the result in 'al' (average) to an ASCII character
        mov dl, al          // Move the ASCII value to 'dl' (used for printing)
        mov ah, 2           // Set 'ah' to 2 (DOS function to display a character)
        int 21h             // Display the average value to the console

        // Store the calculated average in the 'average1' variable
        mov average1, ax

        // Exit the program (DOS function)
        mov ah, 4Ch
        int 21h
    }

    //Find the highest grade for 'grades2' using inline assembly
    long highest = 0;
    _asm {
        mov cx, 10          // Set loop counter to 10 (number of elements in the array)
        lea si, grades2         // Load 'grades2' address into 'si' register

        // Initialize 'highest' variable
        mov al, [si]
        mov highest, al

        findLoop:
            mov al, [si]                // Load the current element of 'grades2' into 'al' register
            cmp highest, al             // Compare the current element with the current largest value 'highest'
            jg noChange                 // If the current element is greater than 'highest', update 'highest' with the current element
            mov highest, al
            noChange:
            inc si                      // Continue to the next element in 'grades2'
            loop findLoop               // Loop back until 'cx' becomes zero (end of the array)

        
        // Print a newline character to separate the outputs
        mov ah, 2
        mov dl, 0Ah
        int 21h

        // Exit the program gracefully (DOS function)
        mov ah, 4Ch
        int 21h
    }

    // Display the calculated average and highest grade for both arrays
    cout << "The average grade for test 1 is " << average1 << endl;
    cout << "The highest grade on test 1 is " << highest << endl;

    return 0;
}
