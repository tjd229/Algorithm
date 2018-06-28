//category : math, bs

#include "cmp.h"
void remember(int n) {
	//edit this
	int i;
	int a = n;
	int r[4];
	for (i = 4; i--;){
		r[i] = a % 8;
		a >>= 3;
	}
 
	//[3]:per 1 [2]:per 8 [1]:per 64 [0]:per 512
	for (a = i = 0; i < 4; i++){		
		a += r[i]+1;
		bit_set(a);
		a <<= 3;
	}
 
}
 
int compare(int b) {
	//edit this
	int i;
	int r[4];
	int pt[4];
	int a = b;
	for (i = 4; i--;){
		r[i] = a % 8;
		a >>= 3;
	}
	for (a = i = 0; i < 4; i++){
		pt[i]=a =a+ r[i]+1;
		a <<= 3;
	}
	//bs
	int bnd = 0;
	int lo = 0;
	int hi = 3;
	//while (bit_get(pt[bnd])){
	//	bnd++;
	//	if (bnd == 4) return 0;
	//}
	while (lo <= hi){
		int mid = (lo + hi) >> 1;
		if (bit_get(pt[mid])) lo = mid + 1;
		else hi = mid - 1;
	}
	bnd = lo;
	if (bnd == 4) return 0;
	if (r[bnd] == 7) return 1;
	if (r[bnd] == 0) return -1;
	i = 0;
	if (r[bnd] > 3) i += 4;
	for (a = i + 3; i <= a; i++){ //0~3 or 4~7
		if (r[bnd] == i) continue;
		if (bit_get(pt[bnd] - r[bnd] + i))
			return r[bnd] < i ? -1 : 1;
	}
 
	return r[bnd]>3 ? 1 : -1;
}
