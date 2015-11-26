/*
The MIT License (MIT)

Copyright (c) 2015 Zhang Boyang

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files (the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.

*/

#include "trap.h"

.globl start
start:

    mov $0, %ebp
    mov $0x08000000, %esp
    sub $0x10, %esp
    
    
    // use this nemu command to test:
    //      si; x (0x8000000-$esp) $esp
    
    
    
    push $0x11                      // opcode = 6a
    push $0x22
    push $0x33
    push $0x44
    
    pushw $0xaabb                   // opcode = 68
    pushw $0xccdd
    pushl $0xaabbccdd
    
    mov $0x1234aaaa, %eax           // opcode = 50
    mov $0x5678bbbb, %ebx
    push %eax
    push %ebx
    push %ax
    push %bx
    
    push $0xdeadbeef
    mov %esp, %eax
    pushw (%eax)                    // opcode = FF/6
    pushw 2(%eax)
    pushl (%eax)
    
    push %eax
    push %ecx
    push %edx
    push %ebx
    push %esp
    push %ebp
    push %esi
    push %edi
    
    push %ax
    push %cx
    push %dx
    push %bx
    push %sp
    push %bp
    push %si
    push %di
    
	HIT_GOOD_TRAP

