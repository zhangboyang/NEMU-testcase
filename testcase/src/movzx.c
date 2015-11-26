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

#define CHAR_DATA {0, 0xff, 0xfe, 0x01, 0x02, 0x7f, 0x80, 0x7e, 0xab, 0x1f, 0xf1}
unsigned char mychar[] = CHAR_DATA;
unsigned short mychar_to_short[] = CHAR_DATA;
unsigned int mychar_to_int[] = CHAR_DATA;
int mychar_len = sizeof(mychar) / sizeof(mychar[0]);

#define SHORT_DATA {0, 0xffff, 0xfffe, 0x0001, 0x0002, 0x7fff, 0x8000, 0xaabb, 0xff11, 0x11ff, 0x1f1f, 0xf1f1}
unsigned short myshort[] = SHORT_DATA;
unsigned int myshort_to_int[] = SHORT_DATA;
int myshort_len = sizeof(myshort) / sizeof(myshort[0]);

int main()
{
    int i;
    
    /* char to int/short */
    for (i = 0; i < mychar_len; i++) {
        unsigned char a = mychar[i];
        unsigned int b = a;
        unsigned short c = a;
        nemu_assert(b == mychar_to_int[i]);
        nemu_assert(c == mychar_to_int[i]);
    }
    
    /* short to int */
    for (i = 0; i < myshort_len; i++) {
        unsigned short a = myshort[i];
        unsigned int b = a;
        nemu_assert(b == myshort_to_int[i]);
    }
    
    HIT_GOOD_TRAP;
    return 0;
}
