//category : hashing

#include <stdlib.h>
#include <stdio.h>
#include <stdarg.h>
#include "grader.h"
#include "lang.h"
#define ll long long
#define SZ 100
#define MAXL 56
const int mod = 428957;
static int lnum = -1;
int cnt1[MAXL][mod], cnt2[MAXL][mod];// , cnt3[MAXL][mod];
int cnt4[MAXL][mod];
int ccnt1[mod], ccnt2[mod], ccnt4[mod];
ll hash_func(int n, ...){
	va_list li;
	va_start(li, n);
	ll res = 0;
	for (int i = 0; i < n; i++){
		res <<= 16;
		res %= mod;
		res += va_arg(li, int);
	}
	va_end(li);
	return res;
 
}
void excerpt(int *E) {
	int i, j;
	ll mx=0;
	int l = 0;
	for (i = 0; i <= lnum; i++){
		ll val = 0;
		for (j = 0; j < SZ; j++) if(ccnt1[E[j]]<lnum/4) val += cnt1[i][E[j]];
		for (j = 1; j < SZ; j++){
			ll h = hash_func(2, E[j - 1], E[j]);
			if (ccnt2[h]<lnum/4)
				val += cnt2[i][h] * 30;
		}
		//for (j = 2; j < SZ; j++) val += cnt3[i][hash_func(3, E[j - 2], E[j - 1], E[j])] * 30;
		for (j = 3; j < SZ; j++){
			ll h = hash_func(4, E[j - 3], E[j - 2], E[j - 1], E[j]);
			if (ccnt4[h]<lnum/4)
				val += cnt4[i][h] * 90;
		}
		if (mx < val){
			mx = val;
			l = i;
		}
	}
	int ans = language(l);
	if (ans > lnum) lnum = ans;
	for (i = 0; i < SZ; i++){		
		if (cnt1[ans][E[i]] == 0) ccnt1[E[i]]++;
		cnt1[ans][E[i]] = 1;
		
	}
	for (i = 1; i < SZ; i++){
		ll h = hash_func(2, E[i - 1], E[i]);
		if (cnt2[ans][h] == 0) ccnt2[h]++;
		cnt2[ans][h] = 1;
	}
	//for (i = 2; i < SZ; i++) cnt3[ans][hash_func(3, E[i - 2], E[i - 1], E[i])] = 1;
	for (i = 3; i < SZ; i++){
		ll h = hash_func(4, E[i - 3], E[i - 2], E[i - 1], E[i]);
		if (cnt4[ans][h] == 0) ccnt4[h]++;
		cnt4[ans][h] = 1;
	}
}
