//category : math
#include "decoder.h"
#include "decoderlib.h"
const int bndd = 64*5 + 256;
int cd[bndd][bndd][64];
void addd(int dst[], int src1[], int src2[]){
	int nxt = 0;
	for (int i = 63; i >= 0; i--){
		dst[i] = src1[i] + src2[i] + nxt;
		nxt = dst[i] / 256;
		if (i)
			dst[i] %= 256;

	}
}
void set_cd(){
	int i, j;
	for (i = 1; i < bndd; i++){
		cd[i][0][63] = cd[i][i][63] = 1;
	}
	for (i = 2; i < bndd; i++){
		for (j = 1; j < i; j++){
			addd(cd[i][j], cd[i - 1][j - 1], cd[i - 1][j]);
		}
	}
}
void decode(int N, int L, int X[])
{
	static int flagd = 0;
	if (flagd++ == 0) set_cd();
	int i,j;
	int cnt[256] = { 0 };
	int recon[64] = { 0 };
	for (i = 0; i < L; i++)
		cnt[X[i]]++;
	int parrot = L;
	for (i = 0; i < 256; i++){
		for (j = 0; j < cnt[i]; j++){
			
			addd(recon, recon, cd[parrot + 256 - i - 1 - 1][parrot]);
			parrot--;
		}
	}
	for (i = 64-N; i < 64; i++){
		output(recon[i]);
	}
	
}
