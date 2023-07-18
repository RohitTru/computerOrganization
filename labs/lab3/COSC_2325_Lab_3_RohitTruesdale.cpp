#include <iostream>
using namespace std;
void main ()
{
FS1 short = 0;
FS2 short = 1;
FS3 short;
FS4 short;
FS5 short;
FS6 short;
FS7 short;
FS8 short;
FS9 short;
FS10 short;

__asm{
    mov cl, 8

    loop_start:

    mov al, FS1
    add al, FS2

    mov FS1, FS2
    mov FS2, al

    mov bx, cx
    add bx, 3
    mov byte ptr [FS1 + bx], al

    loop loop_start



}

}