.file   "assembly.c"
.def   ___main;   .scl   2;   .type   32;   .endef
.section .rdata,"dr"
LC0:
   .ascii "%d, \0" ; The format string for the `printf` function

.text
.globl   _main
.def   _main;   .scl   2;   .type   32;   .endef

_main:
   ; Function prologue - setting up the stack frame
   pushl   %ebp
   movl   %esp, %ebp
   andl   $-16, %esp
   subl   $144, %esp ; Allocating space for local variables on the stack

   call   ___main ; Call the startup code (equivalent to C's main function)

   ; Initialize the memberLvl array with the given values
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

   ; Initialize the officerList array with the given values
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

   movl   $0, 140(%esp) ; Initialize loop index variable to 0

   jmp   L2 ; Jump to the loop start

L4:
   ; Load the current index from the loop variable into register eax
   movl   140(%esp), %eax

   ; Check if the current membership level at index eax is equal to 4
   movl   80(%esp,%eax,4), %eax
   cmpl   $4, %eax
   jne   L3 ; If not, jump to the end of the loop

   ; Check if the current officer position at index eax is greater than 0 and less than 10
   movl   140(%esp), %eax
   movl   20(%esp,%eax,4), %eax
   testl   %eax, %eax
   jle   L3 ; If not, jump to the end of the loop
   movl   140(%esp), %eax
   movl   20(%esp,%eax,4), %eax
   cmpl   $9, %eax
   jg   L3 ; If not, jump to the end of the loop

   ; If both conditions are met, print the current index (member number)
   movl   140(%esp), %eax
   addl   $1, %eax ; Increment the index (since member numbers start at zero)
   movl   %eax, 4(%esp) ; Move the index into the argument for `printf`
   movl   $LC0, (%esp) ; Load the address of the format string into the argument for `printf`
   call   _printf ; Call the `printf` function to print the member number

L3:
   ; Increment the loop index and jump back to the loop start
   addl   $1, 140(%esp)
   jmp   L2

L2:
   ; Check if the loop index is less than or equal to 14 (15 members - 1 since it's zero-based)
   cmpl   $14, 140(%esp)
   jle   L4 ; If the condition is true, continue the loop

   nop ; No operation (just a placeholder)

   ; Function epilogue - cleanup and return
   leave
   ret

; The version of GCC used for compilation
.ident   "GCC: (tdm-1) 5.1.0"
.def   _printf;   .scl   2;   .type   32;   .endef
