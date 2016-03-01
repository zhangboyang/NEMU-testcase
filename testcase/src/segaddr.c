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


/* use this file to test if 'rm->sreg' set properly */
/* use 'si' to single step through this file */


#define OP "leal "
//#define OP "movl "

int main()
{
    
    /*__asm__ __volatile__ (
        "int3\n\t"
        // DS
        OP "%%ds:(%%eax), %%eax\n\t"
        OP "%%ds:(%%ecx), %%eax\n\t"
        OP "%%ds:(%%edx), %%eax\n\t"
        OP "%%ds:(%%ebx), %%eax\n\t"
        OP "%%ds:(%%esi), %%eax\n\t"
        OP "%%ds:(%%edi), %%eax\n\t"
        OP "%%ds:(,%%eax,4), %%eax\n\t"
        OP "%%ds:(%%eax,%%ebp), %%eax\n\t"
        OP "%%ds:5(%%ebx,%%eax,8), %%eax\n\t"
        
        "nop\n\t"
        "nop\n\t"
        "nop\n\t"
        
        // SS
        OP "%%ss:(%%esp), %%eax\n\t"
        OP "%%ss:(%%ebp), %%eax\n\t"
        OP "%%ss:20(%%esp), %%eax\n\t"
        OP "%%ss:(%%esp), %%eax\n\t"
        OP "%%ss:(%%ebp), %%eax\n\t"
        OP "%%ss:(%%ebp,%%ebp), %%eax\n\t"
        OP "%%ss:(%%esp,%%ebp), %%eax\n\t"
        
    :::"eax");
    */
    HIT_GOOD_TRAP;
    return 0;
}
