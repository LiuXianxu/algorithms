#include <iostream>  
#include <stdio.h> 
#include <cmath>  
#include <complex>  
#include <cstring>  
using namespace std;  
  
const double PI = acos(-1);
typedef complex<double> cp;  
typedef long long int64;  
  
const int N = 1 << 16;  
int64 a[N], b[N], c[N << 1];  
  
void bit_reverse_copy(cp a[], int n, cp b[])  
{  
    int i, j, k, u, m;  
    for (u = 1, m = 0; u < n; u <<= 1, ++m);  
    for (i = 0; i < n; ++i)  
    {  
        j = i; k = 0;  
        for (u = 0; u < m; ++u, j >>= 1)  
            k = (k << 1) | (j & 1);  
        b[k] = a[i];  
    }  
}  
  
void FFT(cp _x[], int n, bool flag)  
{  
    static cp x[N << 1];  
    bit_reverse_copy(_x, n, x);  
    int i, j, k, kk, p, m;  
    for (i = 1, m = 0; i < n; i <<= 1, ++m);  
    double alpha = 2 * PI;  
    if (flag) alpha = -alpha;  
    for (i = 0, k = 2; i < m; ++i, k <<= 1)  
    {  
        cp wn = cp(cos(alpha / k), sin(alpha / k));  
        for (j = 0; j < n; j += k)  
        {  
            cp w = 1, u, t;  
            kk = k >> 1;  
            for (p = 0; p < kk; ++p)  
            {  
                t = w * x[j + p + kk];  
                u = x[j + p];  
                x[j + p] = u + t;  
                x[j + p + kk] = u - t;  
                w *= wn;  
            }  
        }  
    }  
    memcpy(_x, x, sizeof(cp) * n);  
}  
  
void polynomial_multiply(int64 a[], int na, int64 b[], int nb, int64 c[], int &nc)  
{  
    int i, n;  
    i = max(na, nb) << 1;  
    for (n = 1; n < i; n <<= 1);  
    static cp x[N << 1], y[N << 1];  
    for (i = 0; i < na; ++i) x[i] = a[i];  
    for (; i < n; ++i) x[i] = 0;  
    FFT(x, n, 0);  
    for (i = 0; i < nb; ++i) y[i] = b[i];  
    for (; i < n; ++i) y[i] = 0;  
    FFT(y, n, 0);  
    for (i = 0; i < n; ++i) x[i] *= y[i];  
    FFT(x, n, 1);  
    for (i = 0; i < n; ++i)   
    {  
        c[i] =(int64)(x[i].real() / n + 0.5);
    }  
    for (nc = na + nb - 1; nc > 1 && !c[nc - 1]; --nc);  
}  
  
const int LEN = 5, MOD = 100000;  
void convert(char *s, int64 a[], int &n)  
{  
    int len = strlen(s), i, j, k;  
    for (n = 0, i = len - LEN; i >= 0; i -= LEN)  
    {  
        for (j = k = 0; j < LEN; ++j)  
            k = k * 10 + (s[i + j] - '0');  
        a[n++] = k;  
    }  
    i += LEN;  
    if (i)  
    {  
        for (j = k = 0; j < i; ++j)  
            k = k * 10 + (s[j] - '0');  
        a[n++] = k;  
    }  
}  
  
void print(int64 a[], int n)  
{  
    printf("%I64d", a[--n]);  
    while (n) printf("%05I64d", a[--n]);  
    puts("");  
}  
  
char buf[N + 10];  
  
int main()  
{  
    int na, nb, nc;  
      
    while (scanf("%s", buf) != EOF)  
    {  
        bool sign = false;  
        if (buf[0] == '-')  
        {  
            sign = !sign;   
            convert(buf + 1, a, na);  
        }  
        else convert(buf, a, na);  
        scanf("%s", buf);  
        if (buf[0] == '-')  
        {  
            sign = !sign;  
            convert(buf + 1, b, nb);  
        }  
        else convert(buf, b, nb);  
        polynomial_multiply(a, na, b, nb, c, nc);  
        int64 t1, t2;  
        t1 = 0;  
        for (int i = 0; i < nc; ++i)  
        {  
            t2 = t1 + c[i];  
            c[i] = t2 % MOD;  
            t1 = t2 / MOD;  
        }  
        for (; t1; t1 /= MOD) c[nc++] = t1 % MOD;  
        if (sign) putchar('-');  
        print(c, nc);  
    }  
    return 0;  
}

