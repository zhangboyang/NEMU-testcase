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

// function pointer test


typedef int (*myfp1_t)(int a, int b);

int myadd(int a, int b)
{
    return a + b;
}

typedef void (*myfp2_t)();

void hgt()
{
    HIT_GOOD_TRAP;
}

int main()
{
	volatile myfp1_t fp1 = myadd;
	volatile myfp2_t fp2 = hgt;
	
	volatile int a = 10000100;
	volatile int b = 1234;
	volatile int c = 55555678;
	volatile int d = 10001334;
	
	c = fp1(a, b);
	
	nemu_assert(c == d);
	
	fp2();
	
	HIT_BAD_TRAP;

	return 0;
}



