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

    // nemu command for testing:
    //    si; p *$esp, $eip
    call 1f
    HIT_BAD_TRAP
    HIT_BAD_TRAP
    HIT_BAD_TRAP
1:

    /* another test */
    mov $0xaaaaaaaa, %eax
    call 1f
    HIT_BAD_TRAP
    HIT_BAD_TRAP
    HIT_BAD_TRAP
    call 2f
1:
    call 1f
1:
    subl $10, (%esp)
    call *(%esp)
    
    HIT_BAD_TRAP
    HIT_BAD_TRAP
    HIT_BAD_TRAP
    
    
    /* another test */
2:
    mov $0xaaaaaaaa, %eax
    call 1f
1:
    movl (%esp), %ebx
    sub $-8, %ebx
    call *%ebx
    call 1f
1:
    sub (%esp), %ebx
    sub $-5, %ebx
    test %ebx, %ebx
    
    jz 1f
    
    HIT_BAD_TRAP
    HIT_BAD_TRAP
    HIT_BAD_TRAP
1:
    HIT_GOOD_TRAP

