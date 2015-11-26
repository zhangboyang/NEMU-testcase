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


void test_inc(int x)
{
    volatile int a, b;
    a = b = x;
    __asm__ __volatile__ ("incl %1\n\t":"+m"(a));
    __asm__ __volatile__ ("addl $1, %1\n\t":"+m"(b));
    nemu_assert(a == b);
    nemu_assert(a == x + 1);
    
    a = b = x;
    __asm__ __volatile__ ("incl %1\n\t":"+a"(a));
    __asm__ __volatile__ ("addl $1, %1\n\t":"+a"(b));
    nemu_assert(a == b);
    nemu_assert(a == x + 1);
}

void test_dec(int x)
{
    volatile int a, b;
    a = b = x;
    __asm__ __volatile__ ("decl %1\n\t":"+m"(a));
    __asm__ __volatile__ ("subl $1, %1\n\t":"+m"(b));
    nemu_assert(a == b);
    nemu_assert(a == x - 1);
    
    a = b = x;
    __asm__ __volatile__ ("decl %1\n\t":"+a"(a));
    __asm__ __volatile__ ("subl $1, %1\n\t":"+a"(b));
    nemu_assert(a == b);
    nemu_assert(a == x - 1);
}


int data[] = {
    0, 1, -1, 2, -2, 0xaabbccdd, 0xffeeddcc
};
int datalen = sizeof(data) / sizeof(data[0]);

int main()
{	
	int i;
	for (i = 0; i < datalen; i++) {
	    test_inc(data[i]);
	    test_dec(data[i]);
	}

	HIT_GOOD_TRAP;
	return 0;
}
