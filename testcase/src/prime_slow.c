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

int p[] = {
    0x2, 0x3, 0x5, 0x7, 0xb, 0xd, 0x11, 0x13, 0x17, 0x1d, 0x1f, 0x25, 0x29,
    0x2b, 0x2f, 0x35, 0x3b, 0x3d, 0x43, 0x47, 0x49, 0x4f, 0x53, 0x59, 0x61
};

int mod_with_sub(int a, int b)
{
    while (a > 0) a -= b;
    return a ? a + b : 0;
}

int is_prime(int x)
{
    int i;
    for (i = 2; i < x; i++)
        if (mod_with_sub(x, i) == 0)
            return 0;
    return 1;
}

int main()
{
    int i;
    int n = 200;
    int cnt = 0;
    for (i = 2; i <= n; i++)
        if (is_prime(i)) {
            //__asm__ __volatile__ ("int3" :: "a"(i));
            if (cnt < sizeof(p) / sizeof(int)) {
                if (i == p[cnt])
                    cnt++;
                else
                    goto fail;
            }
        }
    
    
    HIT_GOOD_TRAP;
fail:
    HIT_BAD_TRAP;
    return 0;
}
