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

typedef void (*myfp_t)();

int cnt = 0;

void donothing()
{
}

void addcnt()
{
    cnt++;
}

int main()
{
	volatile myfp_t fp[1000] = {};
	
	fp[3] = addcnt;
	fp[499] = addcnt;
	fp[977] = addcnt;
	fp[976] = donothing;
	
	__asm__ __volatile__ ("call *%0"::"m"(fp[3]));
	__asm__ __volatile__ ("call *%0"::"m"(fp[976]));
	__asm__ __volatile__ ("call *%0"::"m"(fp[499]));
	__asm__ __volatile__ ("call *%0"::"m"(fp[977]));
	
	
	fp[3]();
	fp[499]();
	fp[977]();
	fp[976]();
	
	nemu_assert(cnt == 6);
	
	HIT_GOOD_TRAP;

	return 0;
}

