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

/* NOTE:
    if you fail this testcase, it's not your fault.
    PA says there's no need to update EFLAGS when executing NEG instruction
    but it's not true!
    
    negating a long long int will be compiled to these instructions:
  800031:	f7 d8                	neg    %eax
  800033:	83 d2 00             	adc    $0x0,%edx // *** ADC uses CF ! ***
  800036:	f7 da                	neg    %edx

    so, please update CF when executing NEG instruction
*/

long long LLneg(long long x)
{
    return -x; // neg, adc
}

int main()
{
    int n = 6;
    long long a[] = {5, 6, 7, -5, -6, -7};
    long long b[] = {-5, -6, -7, 5, 6, 7};
    int i;
    for (i = 0; i < n; i++)
        nemu_assert(LLneg(a[i]) == b[i]);
    HIT_GOOD_TRAP;
    return 0;
}

