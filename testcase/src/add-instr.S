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

    mov $0, %eax
    add $1, %eax            // opcode = 83
    
    mov $0, %eax
    add $1, %ax             // opcode = 83
    
    mov $0, %eax
    add $1, %ah             // opcode = 80
    
    mov $0, %eax
    add $1, %al             // opcode = 2c
    
    mov $0, %eax
    add $0xaabbccdd, %eax   // opcode = 2d
    
    mov $0, %ebx
    add $0xaabbccdd, %ebx   // opcode = 81
    
    mov $0, %ebx
    add $0xaabb, %bx        // opcode = 81
    
    
    
    mov $0xaabb, %eax
    
    mov $0, %ebx
    add %al, %bl            // opcode = 28
    
    mov $0, %ebx
    add %ax, %bx            // opcode = 29
    
    mov $0, %ebx
    add %eax, %ebx          // opcode = 29
    
    
    
    mov $0x08000000, %esp
    sub $0x10, %esp
    movl $0xaabbccdd, (%esp)
    
    mov $0, %ebx
    addb (%esp), %bl            // opcode = 28
    
    mov $0, %ebx
    addw (%esp), %bx            // opcode = 29
    
    mov $0, %ebx
    addl (%esp), %ebx          // opcode = 29
    
	HIT_GOOD_TRAP

