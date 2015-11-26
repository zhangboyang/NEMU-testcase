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
    int x, y;
    __asm__ __volatile__ (
        "mov $0x1a2b3c4d, %%eax\n\t"
        "clc\n\t"
        "mov $0xdeadbeef, %%edx\n\t"
        "setc %%al\n\t"
        "mov %%eax, %0\n\t"
        
        "mov $0x1a2b3c4d, %%eax\n\t"
        "stc\n\t"
        "mov $0xdeadbeef, %%edx\n\t"
        "setc %%al\n\t"
        "mov %%eax, %1\n\t"
        :"=m"(x), "=m"(y)
        :
        :"eax", "edx");
        
    nemu_assert(x == 0x1a2b3c00);
    nemu_assert(y == 0x1a2b3c01);
    
    HIT_GOOD_TRAP;
    return 0;
}
