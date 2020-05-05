//implementation
//https://codingcompetitions.withgoogle.com/codejam/round/000000000019fd27/0000000000209a9e

#include <stdio.h>
int B;
int b[101];
int coin;

int qry(int P) {
	++coin;
	printf("%d\n", P); fflush(stdout);
	int buf; scanf("%d",&buf);
	return buf;
}
void flip() {
	for (int i = 1; i <= B; ++i) b[i] = 1 - b[i];
}
void rev() {
	int l = 1, r = B;
	while (l <= r) {
		b[l] ^= b[r] ^= b[l] ^= b[r];
		++l; --r;
	}
}
int main() {
	int T, i;
	int tc;
	for (scanf("%d%d", &T,&B), tc = 1; tc <= T; ++tc) {
		//scanf("%d",&B);


		
		coin = 0;
		if (B == 10) {
			for (i = 1; i <= 10; ++i)
				b[i] = qry(i);
		}
		else {
			int l = 1, r = B;			
			
			int same=-1, diff=-1;
			for (; l<r; ++l,--r) {
				if (same<0&& diff <0) {
					b[1] = qry(1);
					b[B] = qry(B);
					if (b[1] == b[B]) same = 0;
					else diff = 0;
				}
				else {
					if (coin % 10 == 0) {//coin
						//same chk -> flip
						bool f_f = 0, f_r = 0;
						if (same >= 0) {
							int nb = qry(1 + same);
							if(diff<0 ) qry(B - same);
							if (nb != b[1 + same]) f_f = 1;
						}
						//diff chk -> rev
						if (diff >= 0) {
							int nb = qry(1 + diff);
							if(same<0 ) qry(B - diff);
							if (f_f) nb = 1 - nb;
							if (nb != b[1 + diff]) f_r = 1;
						}
						if (f_f) flip();
						if (f_r) rev();
					}
					b[l] = qry(l);
					b[r] = qry(r);
					if (b[l] == b[r]) same = l - 1;
					else diff = l - 1;
				}
				
			}

		}
		for (i = 1; i <= B; ++i)
			printf("%d", b[i]);
		printf("\n"); fflush(stdout);
		/*for (i = 1; i <= B; ++i)
			printf("%d ", a[i]);
		printf("\n"); fflush(stdout);*/
		//input respon
		char respon; scanf(" %c", &respon);
		if (respon == 'N') break;		
	}
	return 0;
}