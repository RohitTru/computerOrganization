#include <iostream>
using namespace std;

/*
Sam Stillwater currently makes $53,520 per year and he would like to increase that to $60,000 so he would have some money for fun stuff.  He discovered that there is a species of frog on his property which has hair.  Not much hair, usually only 6 hairs per frog.  He’s been monitoring sales of this hair on EBay and usually each hair sells for $10.
Write an assembly program that would show Sam how many frogs he would have to capture and de-hair every month to reach his monetary goal.  Output the number of frogs required.
Data declarations and output may be in C.
*/


int main() {
    int currentSalary = 53520;
    int targetSalary = 60000;
    int hairValue = 10;
    int hairsPerFrog = 6;

    _asm{
        ; compute monthly salary target
        mov ax , [targetSalary]
        div word 12                         ; Divide by 12
        mov word [targetSalary], ax

        ; compute monthly sal increment
        mov ax, [targetSalary]
        sub ax, [currentSalary]
        mov word [targetSalary], ax

        ; Calculate the number of frogs required
        mov ax, [targetSalary]
        mov bx, [hairValue]
        imul ax, bx                          ; Multiply targetSalary by hairValue
        mov bx, [hairsPerFrog]
        div bx                               ; Divide by hairsPerFrog
        mov word [targetSalary], ax

        ; Output the result
            mov cx, 10                  ; Number of digits to display
            mov bx, 10                  ; Base 10
            mov ax, [targetSalary]
            xor dx, dx                  ; Clear DX for division
            push ax                     ; Preserve AX
                loop_digit:
                    xor dx, dx              ; Clear DX for division
                    div bx                  ; Divide AX by 10
                    add dl, '0'             ; Convert remainder to ASCII digit
                    push dx                 ; Save the digit on the stack
                    dec cx                  ; Decrement digit counter
                    test ax, ax             ; Check if AX is zero
                    jnz loop_digit          ; Loop until AX is zero

            pop dx                     ; Pop the last digit from the stack

    cout << targetSalary << endl;
    }

}

