//math, FFT
//https://www.hackerrank.com/contests/w6/challenges/best-spot/editorial
#include <stdio.h>
#include <math.h>
#include <algorithm>
#include <vector>
#include <complex>
#define cpd complex<double>
using namespace std;
const double PI = acos(-1);
int rearr[1 << 19];
int R, C,H,W;
int sqx[500][500],xy[500][500];
int rev(int n, int k) {
    int r = 0;
    while (k--) {
        r += r + (n & 1);
        n >>= 1;
    }
    return r;
}
void FFT(vector<cpd > &A, bool inv = 0) {
    for (int i = 0; i < A.size(); ++i)
        if (rearr[i]) swap(A[i], A[rearr[i]]);
    int half = 1;
    for (int step = 2; step <= A.size(); step += step) {
        double theta = (PI + PI) / step;
        if (inv) theta = -theta;
        cpd w(cos(theta), sin(theta));
        for (int i = 0; i < A.size(); i += step) {
            cpd x = 1;
            for (int j = 0; j < half; ++j) {
                cpd odd = A[i + j + half]*x;
                A[i + j + half] = A[i + j] - odd;
                A[i + j] += odd;
                x *= w;
            }
        }
        half = step;
    }
    for (int i = 0; inv && i < A.size(); ++i) A[i] /= A.size();
}
int main() {
    int i, j,RC,p=1;
    int k = 0;
    int sqy = 0;
    for (scanf("%d%d", &R, &C), RC = R * C; p < RC + RC; p += p) ++k;
    for (i = 0; i < p; ++i) {
        j = rev(i, k);
        if (i < j) rearr[i] = j;
    }
    vector<cpd > h(p), ps(p);
    int ix = 0;
    for (i = 0; i < R; ++i,ix+=C) {
        for (j = 0; j < C; ++j) {//range sum
            scanf("%d",sqx[i]+j);
            h[ix + j] = h[ix + j + RC] = sqx[i][j];
            sqx[i][j] *= sqx[i][j];
            if (i > 0) sqx[i][j] += sqx[i - 1][j];
            if (j > 0) sqx[i][j] += sqx[i][j - 1];
            if (i > 0 && j > 0) sqx[i][j] -= sqx[i - 1][j - 1];
        }
    }
    for (scanf("%d%d",&H,&W),i = 0,ix=RC; i < H; ++i,ix-=C) {
        for(j = 0; j < W; ++j) {
            int height; scanf("%d",&height);
            ps[ix - j - 1] = height;
            sqy += height * height;
        }
    }
    FFT(h); FFT(ps);
    for (i = 0; i < p; ++i) h[i] *= ps[i];
    FFT(h, 1);
    for (ix = RC-1, i = 0; i < R; ++i) {
        for (j = 0; j <C; ++j, ++ix) {
            double coef = h[ix].real();
            coef += coef > 0 ? 0.5 : -0.5;
            xy[i][j] = coef;
            //printf("%d\n",xy[i][j]);
        }
    }
    int ans = -1;
    int r, c;
    for (i = 0; i <= R-H; ++i) {
        for(j = 0; j <= C-W; ++j) {
            int sum = sqx[i+H-1][j+W-1]+sqy;
            if (i > 0) sum -= sqx[i - 1][j + W - 1];
            if (j > 0) sum -= sqx[i + H - 1][j - 1];
            if (i > 0 && j > 0) sum += sqx[i - 1][j - 1];
            sum -= xy[i][j] + xy[i][j];
            if (ans<0 || ans>sum) {
                ans = sum;
                r = i + 1; c = j + 1;
            }
        }
    }
    printf("%d\n%d %d",ans,r,c);

    return 0;
}
