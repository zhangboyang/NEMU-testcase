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

int main()
{
    volatile int a, c;
    
    __asm__ __volatile__ (
        "mov $0xAABBCCDD, %%eax\n\t"
        "mov $0x11223344, %%ecx\n\t"
        "xor %%edx, %%edx\n\t"
        "xor %%ebx, %%ebx\n\t"
        "mov $0xab, %%dh\n\t"
        "mov $0x23, %%bh\n\t"
        "mov $-1, %%esi\n\t"
        "mov $0x22334455, %%edi\n\t"
        
        // you may use esi/edi instead of dh/bh, that's wrong!
        "movzx %%dh, %%eax\n\t"
        "movzx %%bh, %%ecx\n\t"
        
        "mov %%eax, %0\n\t"
        "mov %%ecx, %1\n\t"
        
        :"=m"(a), "=m"(c)
        :
        :"eax", "ecx", "ebx", "edx", "esi", "edi");
    
    nemu_assert(a == 0xab);
    nemu_assert(c == 0x23);
    
    HIT_GOOD_TRAP;
    return 0;
}
