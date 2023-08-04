#include <iostream>

int main() {
    int array[] = {0, 2, 5, 9, 10};
    int size = sizeof(array) / sizeof(array[0]);
    int sum = 0;

    // Inline assembly to calculate the sum of gaps
    __asm{

        mov esi, OFFSET dwarray  ; Set the offset to the start of the DWORD array
        mov ecx, count           ; Set the loop counter to the number of elements in the array
    
        xor eax, eax             ; Clear the register to store the running total
    
        L1:
        mov ebx, [esi]           ; Move the current DWORD value from memory into ebx
        add esi, 4               ; Increment esi by 4 to point to the next DWORD in the array
    
        sub ebx, [esi]           ; Subtract the next DWORD value from ebx
        add eax, ebx             ; Add the difference to the running total in eax
    
        loop L1                  ; Loop until ecx (count) becomes zero, and repeat the process
    
    ; At the end of the loop, eax will contain the total sum of differences between consecutive DWORDs in the array

    };

    std::cout << "The sum of gaps between successive elements in the array is: " << sum << std::endl;

    return 0;
}
