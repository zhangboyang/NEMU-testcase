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

#define CDQ "cltd\n\t"
#define CWD "cwtd\n\t"

#define MAKE_EAX_EDX_ASM(INSTR) \
    __asm__ __volatile__ ("mov %2, %%eax\n\t" \
                          "mov %3, %%edx\n\t" \
                          INSTR \
                          "mov %%eax, %0\n\t" \
                          "mov %%edx, %1\n\t" \
                          :"=m"(newa), "=m"(newd) \
                          :"m"(a), "m"(d) \
                          :"eax", "edx")

void test_cdq(int x)
{
    volatile int a, d, newa, newd;
    
    a = x;
    d = 0xaabbccdd;
    
    MAKE_EAX_EDX_ASM(CDQ);
    
    nemu_assert(newa == a);
    nemu_assert(newd == (a < 0 ? -1 : 0));
}

void test_cwd(int x)
{
    volatile int a, d, newa, newd;
    
    a = x;
    d = 0xaabbccdd;
    
    MAKE_EAX_EDX_ASM(CWD);
    
    nemu_assert(newa == a);
    nemu_assert(((short)newd) == (((short)a) < 0 ? -1 : 0));
    nemu_assert((((unsigned)newd) >> 16) == 0xaabb);
}


int data[] = {
    0, 1, -1, 2, -2, 0x1111ffff, 0xffff1111, 0x11223344, 0x7777777, 0xffff, 0x7fff, 0xff11, 0x11ff
};
int datalen = sizeof(data) / sizeof(data[0]);

int main()
{	
	int i;
	for (i = 0; i < datalen; i++) {
	    test_cdq(data[i]);
	    test_cwd(data[i]);
	}

	HIT_GOOD_TRAP;
	return 0;
}
