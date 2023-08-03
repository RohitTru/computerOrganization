#include <iostream>

int main()
{
    // Call the assembly function
    printMembersWithCriteria();

    return 0;
}

// Assembly code implementation of the function
__asm{

    pushl   %ebp                   // Function prologue - save the old base pointer
    movl   %esp, %ebp              // Set the new base pointer

    andl   $-16, %esp              // Align the stack pointer to a multiple of 16
    subl   $144, %esp              // Allocate space on the stack for local variables

    call   ___main                 // Call the startup code (equivalent to C's main function)

    // Initialize the arrays membershipLevels and officerPositions with the given values
    movl   $1, 80(%esp)
    movl   $3, 84(%esp)
    movl   $3, 88(%esp)
    movl   $4, 92(%esp)
    movl   $2, 96(%esp)
    movl   $4, 100(%esp)
    movl   $0, 104(%esp)
    movl   $1, 108(%esp)
    movl   $4, 112(%esp)
    movl   $2, 116(%esp)
    movl   $1, 120(%esp)
    movl   $4, 124(%esp)
    movl   $2, 128(%esp)
    movl   $2, 132(%esp)
    movl   $3, 136(%esp)
    
    // Initialize the officerList array with the given values
    movl   $0, 20(%esp)
    movl   $13, 24(%esp)
    movl   $0, 28(%esp)
    movl   $0, 32(%esp)
    movl   $2, 36(%esp)
    movl   $12, 40(%esp)
    movl   $0, 44(%esp)
    movl   $1, 48(%esp)
    movl   $0, 52(%esp)
    movl   $3, 56(%esp)
    movl   $2, 60(%esp)
    movl   $1, 64(%esp)
    movl   $11, 68(%esp)
    movl   $0, 72(%esp)
    movl   $1, 76(%esp)
    movl   $0, 140(%esp)
    jmp   L2

    L4:
    movl   140(%esp), %eax         // Load the loop index into eax
    movl   80(%esp,%eax,4), %eax   // Load the current membership level into eax
    cmpl   $4, %eax                // Compare with 4
    jne   L3                       // If not equal, jump to the end of the loop

    movl   140(%esp), %eax         // Load the loop index into eax again
    movl   20(%esp,%eax,4), %eax   // Load the current officer position into eax
    testl   %eax, %eax             // Test if officer position is 0 (not an officer)
    jle   L3                       // If less than or equal to 0, jump to the end of the loop
    cmpl   $9, %eax                // Compare with 9
    jg   L3                        // If greater than 9, jump to the end of the loop

    // If the member meets the criteria, print the member number
    movl   140(%esp), %eax         // Load the loop index into eax once again
    addl   $1, %eax                // Increment eax by 1 (since member numbers start from 1)
    movl   %eax, 4(%esp)           // Move the member number into the argument for printf
    movl   $LC0, (%esp)            // Move the format string into the argument for printf
    call   _printf                 // Call the printf function to print the member number

    L3:
    addl   $1, 140(%esp)           // Increment the loop index
    L2:
    cmpl   $14, 140(%esp)          // Compare the loop index with 14
    jle   L4                       // If less than or equal to 14, repeat the loop

    
    leave                         // Function epilogue - clean up the stack frame
    ret                            // Return from the function
    
};
