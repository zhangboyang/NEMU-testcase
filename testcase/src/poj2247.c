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

char input_buffer[] = 
"\x31\x0A\x32\x0A\x33\x0A\x34\x0A\x31\x31"
"\x0A\x31\x32\x0A\x31\x33\x0A\x32\x31\x0A"
"\x32\x32\x0A\x32\x33\x0A\x31\x30\x30\x0A"
"\x31\x30\x30\x30\x0A\x35\x38\x34\x32\x0A"
"\x30\x0A"
;

char answer_buffer[] = 
"\x54\x68\x65\x20\x31\x73\x74\x20\x68\x75"
"\x6D\x62\x6C\x65\x20\x6E\x75\x6D\x62\x65"
"\x72\x20\x69\x73\x20\x31\x2E\x0A\x54\x68"
"\x65\x20\x32\x6E\x64\x20\x68\x75\x6D\x62"
"\x6C\x65\x20\x6E\x75\x6D\x62\x65\x72\x20"
"\x69\x73\x20\x32\x2E\x0A\x54\x68\x65\x20"
"\x33\x72\x64\x20\x68\x75\x6D\x62\x6C\x65"
"\x20\x6E\x75\x6D\x62\x65\x72\x20\x69\x73"
"\x20\x33\x2E\x0A\x54\x68\x65\x20\x34\x74"
"\x68\x20\x68\x75\x6D\x62\x6C\x65\x20\x6E"
"\x75\x6D\x62\x65\x72\x20\x69\x73\x20\x34"
"\x2E\x0A\x54\x68\x65\x20\x31\x31\x74\x68"
"\x20\x68\x75\x6D\x62\x6C\x65\x20\x6E\x75"
"\x6D\x62\x65\x72\x20\x69\x73\x20\x31\x32"
"\x2E\x0A\x54\x68\x65\x20\x31\x32\x74\x68"
"\x20\x68\x75\x6D\x62\x6C\x65\x20\x6E\x75"
"\x6D\x62\x65\x72\x20\x69\x73\x20\x31\x34"
"\x2E\x0A\x54\x68\x65\x20\x31\x33\x74\x68"
"\x20\x68\x75\x6D\x62\x6C\x65\x20\x6E\x75"
"\x6D\x62\x65\x72\x20\x69\x73\x20\x31\x35"
"\x2E\x0A\x54\x68\x65\x20\x32\x31\x73\x74"
"\x20\x68\x75\x6D\x62\x6C\x65\x20\x6E\x75"
"\x6D\x62\x65\x72\x20\x69\x73\x20\x32\x38"
"\x2E\x0A\x54\x68\x65\x20\x32\x32\x6E\x64"
"\x20\x68\x75\x6D\x62\x6C\x65\x20\x6E\x75"
"\x6D\x62\x65\x72\x20\x69\x73\x20\x33\x30"
"\x2E\x0A\x54\x68\x65\x20\x32\x33\x72\x64"
"\x20\x68\x75\x6D\x62\x6C\x65\x20\x6E\x75"
"\x6D\x62\x65\x72\x20\x69\x73\x20\x33\x32"
"\x2E\x0A\x54\x68\x65\x20\x31\x30\x30\x74"
"\x68\x20\x68\x75\x6D\x62\x6C\x65\x20\x6E"
"\x75\x6D\x62\x65\x72\x20\x69\x73\x20\x34"
"\x35\x30\x2E\x0A\x54\x68\x65\x20\x31\x30"
"\x30\x30\x74\x68\x20\x68\x75\x6D\x62\x6C"
"\x65\x20\x6E\x75\x6D\x62\x65\x72\x20\x69"
"\x73\x20\x33\x38\x35\x38\x37\x35\x2E\x0A"
"\x54\x68\x65\x20\x35\x38\x34\x32\x6E\x64"
"\x20\x68\x75\x6D\x62\x6C\x65\x20\x6E\x75"
"\x6D\x62\x65\x72\x20\x69\x73\x20\x32\x30"
"\x30\x30\x30\x30\x30\x30\x30\x30\x2E\x0A"
""
;

#include "trap.h"
#include <stdarg.h>
#include <string.h>

/* TEMPLATE CODE */

char output_buffer[sizeof(answer_buffer) + 0x100];


/* only usable when a >= 0 */
void LLdiv10(unsigned long long a, unsigned long long *q, int *r)
{
    union {
        long long value;
        unsigned short s[4];
    } LL;
    
    int i;
    unsigned int cur, sq, sr = 0;
    LL.value = a;

    for (i = 3; i >= 0; i--) {
        cur = sr * 0x10000 + LL.s[i];
        sq = cur / 10;
        sr = cur % 10;
        LL.s[i] = sq;
    }

    *q = LL.value;
    *r = sr;
}

/* useful functions */

int naive_isdigit(char c)
{
    return '0' <= c && c <= '9';
}

int naive_isspace(char c)
{
    switch (c) {
        case ' ': case '\f': case '\n': case '\r': case '\t': case '\v':
            return 1;
        default:
            return 0;
    }
}

/* write_TYPE(): print TYPE to output buffer
 * return outputed char cnt
 */

char *write_ptr = output_buffer;

void finish_output()
{
    *write_ptr = '\0';
}

int write_char(char c)
{
    *write_ptr++ = c;
    return 1;
}

int write_string(char *s)
{
    int cnt = 0;
    while (*s) cnt += write_char(*s++);
    return cnt;
}

int write_llint(long long lld)
{
    int buf[100];
    int p = 0, ret;
    unsigned long long llu;
    if (lld < 0) { write_char('-'); lld = -lld; }
    llu = lld;
    do {
        LLdiv10(llu, &llu, &buf[p++]);
    } while (llu > 0);
    ret = p;
    while (p > 0) write_char('0' + buf[--p]);
    return ret;
}

int write_int(int d)
{
    char buf[100];
    int p = 0, ret;
    unsigned int u;
    if (d < 0) { write_char('-'); d = -d; }
    u = d;
    do {
        buf[p++] = u % 10;
        u /= 10;
    } while (u > 0);
    ret = p;
    while (p > 0) write_char('0' + buf[--p]);
    return ret;
}

int naive_printf(const char *fmt, ...)
{
    va_list ap;
    long long lld;
    int d;
    char c, *s;
    int cnt = 0;
    
    va_start(ap, fmt);
    while (*fmt) {
        if (*fmt == '%') {
            switch (*++fmt) {
                case 's':
                    s = va_arg(ap, char *);
                    cnt += write_string(s);
                    break;
                case 'd':
                    d = va_arg(ap, int);
                    cnt += write_int(d);
                    break;
                case 'c':
                    c = va_arg(ap, int);
                    cnt += write_char(c);
                    break;
                case 'l':
                    if (*++fmt == 'l' && *++fmt == 'd') {
                        lld = va_arg(ap, long long);
                        cnt += write_llint(lld);
                    }
                    break;
                case '%':
                    cnt += write_char('%');
                    break;
            }
        } else {
            cnt += write_char(*fmt);
        }
        fmt++;
    }
    va_end(ap);
    return cnt;
}


/* read_TYPE(): read TYPE from input buffer
 * return read object count
 */

char *read_ptr = input_buffer;

int read_char(char *cp)
{
    if (*read_ptr) {
        *cp = *read_ptr++;
        return 1;
    } else {
        return 0;
    }
}

void unread_char(char c)
{
    *--read_ptr = c;
}

void read_space()
{
    char c = '\0';
    while (read_char(&c) && naive_isspace(c));
    if (c) unread_char(c);
}

int read_string(char *s)
{
    int flag = 0;
    char c = '\0';
    read_space();
    while (read_char(&c) && !naive_isspace(c)) {
        *s++ = c;
        flag = 1;
    }
    if (c) unread_char(c);
    if (flag) *s = '\0';
    return flag;
}

int read_llint(long long *lldp)
{
    int flag = 0;
    long long lld = 0;
    int f = 0;
    char c = '\0';
    read_space();
    read_char(&c);
    if (c == '-') f = 1; else unread_char(c);
    while (read_char(&c) && naive_isdigit(c)) {
        lld = lld * 10 + (c - '0');
        flag = 1;
    }
    if (c) unread_char(c);
    if (flag) *lldp = f ? -lld : lld;
    if (!flag && f) unread_char('-');
    return flag;
}

int read_int(int *dp)
{
    int flag = 0;
    int d = 0;
    int f = 0;
    char c = '\0';
    read_space();
    read_char(&c);
    if (c == '-') f = 1; else unread_char(c);
    while (read_char(&c) && naive_isdigit(c)) {
        d = d * 10 + (c - '0');
        flag = 1;
    }
    if (c) unread_char(c);
    if (flag) *dp = f ? -d : d;
    if (!flag && f) unread_char('-');
    return flag;
}

int naive_scanf(const char *fmt, ...)
{
    va_list ap;
    long long *lldp;
    int *dp;
    char c, *cp, *s;
    int cnt = 0;
    int flag = 0;
    
    va_start(ap, fmt);
    while (*fmt) {
        if (*fmt == '%') {
            switch (*++fmt) {
                case 's':
                    s = va_arg(ap, char *);
                    cnt += flag = read_string(s);
                    break;
                case 'd':
                    dp = va_arg(ap, int *);
                    cnt += flag = read_int(dp);
                    break;
                case 'c':
                    cp = va_arg(ap, char *);
                    cnt += flag = read_char(cp);
                    break;
                case 'l':
                    if (*++fmt == 'l' && *++fmt == 'd') {
                        lldp = va_arg(ap, long long *);
                        cnt += flag = read_llint(lldp);
                    }
                    break;
                case '%':
                    if (read_char(&c)) flag = (c == '%');
                    else flag = 0;
                    break;
            }
        } else {
            if (read_char(&c)) flag = (c == *fmt);
            else flag = 0;
        }
        if (!flag) goto done;
        fmt++;
    }
done:
    va_end(ap);
    return cnt;
}





int naive_memcmp(void *p1, void *p2, int n)
{
    unsigned char *s1 = p1, *s2 = p2;
    int i;
    for (i = 0; i < n; i++)
        if (s1[i] < s2[i])
            return -1;
        else if (s1[i] > s2[i])
            return 1;
    return 0;
}

void naive_memset(void *p, char c, int n)
{
    unsigned char *s = p;
    int i;
    for (i = 0; i < n; i++)
        s[i] = c;
}








int program_main();

#define FILLCHAR 'E'

int main()
{
    naive_memset(output_buffer, FILLCHAR, sizeof(output_buffer));    
    program_main();
    finish_output();
    nemu_assert(naive_memcmp(output_buffer, answer_buffer, sizeof(answer_buffer)) == 0);
    nemu_assert(memcmp(output_buffer, answer_buffer, sizeof(answer_buffer)) == 0);
    HIT_GOOD_TRAP;
    return 0;
}

#define main program_main
#define scanf naive_scanf
#define printf naive_printf
#define puts(str) naive_printf("%s\n", (str))
#define putchar(ch) naive_printf("%c", (ch))

/* REAL USER PROGRAM */


#include <stdlib.h>

#define MAXN 6000
#define MAXV 2000000000

int list[MAXN];
int sz = 0;
int cmp(const void *a, const void *b)
{
    int x = *(int *)a, y = *(int *)b;
    if (x > y) return 1;
    if (x < y) return -1;
    return 0;
}
void init()
{
    long long n2, n3, n5, n7;
    long long a, b, c;
    for (n2 = 1; n2 <= MAXV; n2 *= 2)
        for (n3 = 1; n3 <= MAXV; n3 *= 3)
            for (n5 = 1; n5 <= MAXV; n5 *= 5)
                for (n7 = 1; n7 <= MAXV; n7 *= 7) {
                    a = n2 * n3;
                    b = n5 * n7;
                    if (a <= MAXV && b <= MAXV && (c = a * b) <= MAXV)
                        list[sz++] = c;
                }
    qsort(list, sz, sizeof(int), cmp);
}
const char *suffix(int n)
{
    n %= 100;
    const char *s123[] = { "th", "st", "nd", "rd" };
    if (n % 10 <= 3 && n / 10 != 1) return s123[n % 10];
    return s123[0];
}
int main()
{
    init();
    int n;
    while (scanf("%d", &n) == 1 && n)
        printf("The %d%s humble number is %d.\n", n, suffix(n), list[n - 1]);
    return 0;
}
