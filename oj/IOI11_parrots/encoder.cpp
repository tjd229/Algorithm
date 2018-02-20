//category : math

#include "encoder.h"
#include "encoderlib.h"
#include <memory.h>
//const int bnde = 264 + 256;
const int bnde = 64*5 + 256;
int ce[bnde][bnde][64];
void add(int dst[], int src1[], int src2[]){
	int nxt = 0;
	for (int i = 63; i >=0; i--){
		dst[i] = src1[i] + src2[i]+nxt;		
		nxt = dst[i] / 256;
		if (i)
			dst[i] %= 256;
		
	}
}
void subtract(int dst[],int src1[], int src2[]){
	for (int i = 0; i < 64; i++){
		dst[i] = src1[i] - src2[i];
	}
	for (int i = 63; i>0 ; i--){
		while (dst[i] < 0){
			dst[i] += 256;
			dst[i - 1]--;
		}
	}
}
int cmp(int a1[], int a2[]){
	for (int i = 0; i<64; i++){
		if (a1[i] > a2[i]) return -1;
		if (a1[i] < a2[i]) return 1;
	}
	return 0;
}
void set(){
	int i, j;
	for (i = 1; i < bnde; i++){
		ce[i][0][63] = ce[i][i][63] = 1;
	}
	for (i = 2; i < bnde; i++){
		for (j = 1; j < i; j++){	
			add(ce[i][j], ce[i - 1][j - 1], ce[i - 1][j]);
		}
	}
}
void encode(int N, int M[])
{
	static int flage = 0;
	int i,j;
	if (flage++ == 0) set();
	
	int msg[64] = { 0 };
	for (j = 64 - N, i = 0; i < N; i++,j++) msg[j] = M[i];
	//for (i = 0; i < N; i++) msg[i] = M[i];
	
	int parrot=262;
	for (i = 1; i < 320; i++){
		if (cmp(ce[i+256-1][i], msg) == -1){
			
			parrot = i;
			break;
		}
	}
	

	//int out[64] = { 0 };
	//int cnt[256] = { 0 };
	for (i = 0; i < 256&&parrot; i++){
		int a[64] = { 0 };
		int last[64] = { 0 };
		for (j = 0; j < 261&&parrot; j++){
			add(a, last, ce[parrot + 256 - i - 1 - 1][parrot]);
			
			if (cmp(a,msg) == -1) break;
			memcpy(last, a, sizeof(last));
			send(i);
			//cnt[i]++;
			parrot--;
		}
		memcpy(a, msg, sizeof(a));
		subtract(msg, a, last);
	}

}
