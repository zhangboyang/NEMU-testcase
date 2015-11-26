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
    
    pushl $0xaabbccdd
    pushl $0xdeadbeef
    
    pop %eax
    pop %cx
    pop %dx
    
    cmp $0xdeadbeef, %eax
    jne bad
    cmp $0xccdd, %cx
    jne bad
    cmp $0xaabb, %dx
    jne bad
    
    
    
    pushl $0x11223344
    pushl $0x55667788
    mov $buf, %eax
    
    popl (%eax)
    cmpl $0x55667788, (%eax)
    jne bad
    
    popw (%eax)
    cmpw $0x3344, (%eax)
    jne bad
    
    popw (%eax)
    cmpw $0x1122, (%eax)
    jne bad
    
    HIT_GOOD_TRAP
bad:
    HIT_BAD_TRAP
buf:
.byte 0xcc
.byte 0xcc
.byte 0xcc
.byte 0xcc
.byte 0xcc
.byte 0xcc
.byte 0xcc
.byte 0xcc


