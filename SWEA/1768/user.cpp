//category : implementation

#define N 4


typedef struct {

	int strike;

	int ball;

} Result;

struct Hist{
	int strike, ball, sum;
	int digit[4];
}hist[1000000];
int ix;
const int perm[24][4] = {
	{ 0, 1, 2, 3 }, { 0, 1, 3, 2 }, { 0, 2, 1, 3 },
	{ 0, 2, 3, 1 }, { 0, 3, 1, 2 }, { 0, 3, 2, 1 },
	{ 1, 0, 2, 3 }, { 1, 0, 3, 2 }, { 1, 2, 0, 3 },
	{ 1, 2, 3, 0 }, { 1, 3, 0, 2 }, { 1, 3, 2, 0 },
	{ 2, 0, 1, 3 }, { 2, 0, 3, 1 }, { 2, 1, 0, 3 },
	{ 2, 1, 3, 0 }, { 2, 3, 0, 1 }, { 2, 3, 1, 0 },
	{ 3, 0, 1, 2 }, { 3, 0, 2, 1 }, { 3, 1, 0, 2 },
	{ 3, 1, 2, 0 }, { 3, 2, 0, 1 }, { 3, 2, 1, 0 }
};

// API

extern Result query(int guess[]);


bool call_query(int *guess){
	Result r = query(guess);
	if (r.strike == 4) return true;
	for (int i = 0; i < 4; i++) hist[ix].digit[i] = guess[i];
	hist[ix].strike = r.strike;
	hist[ix].ball = r.ball;
	hist[ix].sum = hist[ix].strike + hist[ix].ball;
	ix++;
	return false;
}
void swap(int &a, int &b){
	a ^= b ^= a ^= b;
}
bool last2(int *p1,int *p3,int cnt, bool pre){
	int digit[4];
	int ix1, ix2,i;
	ix1 = ix2 = 0;
	digit[0] = p1[0]; digit[1] = p1[1];
	digit[2] = p3[0]; digit[3] = p3[1];
	if (pre){
		if (call_query(digit)){
			for (i = 0; i < 4; i++) p1[i] = digit[i];
			return true;
		}
		if (hist[ix - 1].sum != cnt + 1){
			ix1 = cnt + 2 - hist[ix - 1].sum;
			if (ix1!=0)
				for (i = 0; i < 2; i++) swap(p1[ix1 + i], p1[i]);
			return false;
		}
		//else -> nxt cond.
	}
	digit[1] = p1[2]; digit[2] = p1[3];
	if (call_query(digit)){
		for (i = 0; i < 4; i++) p1[i] = digit[i];
		return true;
	}
	if (hist[ix - 1].sum == cnt/2+1) digit[0] = p1[1];
	digit[2] = p3[0];
	if (call_query(digit)){
		for (i = 0; i < 4; i++) p1[i] = digit[i];
		return true;
	}
	if (hist[ix - 1].sum != cnt + 2) digit[1] = p1[3];
	p1[0] = digit[0]; p1[1] = digit[1];
	p1[4] = 2;
	return false;
}
void get_hint(int s,int candi,int *fix,int *anti_stat,int *cnt){
	int i, j;
	int n_strk;
	for (i = 0; i < ix; i++){
		if (hist[i].strike == hist[i].sum){
			for (j = 0; j < 4; j++){
				if (candi & (1 << hist[i].digit[j]))
					fix[j] = hist[i].digit[j];
			}
		}
		else if (hist[i].ball == hist[i].sum){
			for (j = 0; j < 4; j++){
				if (candi & (1 << hist[i].digit[j])){
					cnt[j] += (anti_stat[j] & (1 << hist[i].digit[j]) == 0);
					anti_stat[j] |= 1 << hist[i].digit[j];
				}
			}
		}
		else{
			n_strk = 0;
			for (j = 0; j < 4; j++)
				n_strk += (fix[j] == hist[i].digit[j]);
			if (hist[i].strike - n_strk == 0&&hist[i].ball){
				for (j = 0; j < 4; j++){
					if (candi & (1 << hist[i].digit[j])
						&&fix[j]!=hist[i].digit[j]){
						cnt[j] += (anti_stat[j] & (1 << hist[i].digit[j]) == 0);
						anti_stat[j] |= 1 << hist[i].digit[j];
					}
				}
			}
		}
	}
}
void answer(int *guess,int *p){
	int i, j;
	int fix[4] = {-1,-1,-1,-1};
	int anti_stat[4] = { 0 };
	int candi = 0;
	int cnt[4] = { 0 };
	
	for (i = 0; i < 4; i++) candi |= 1 << p[i];
	get_hint(0, candi, fix, anti_stat, cnt);
	for (i = 0; i < 4; i++){
		if (cnt[i] == 3){
			for (j = 0; j < 4; j++){
				if (!(anti_stat[i] & (1 << p[j])))
					fix[i] = p[j];
			}
		}
	}
	get_hint(0, candi, fix, anti_stat, cnt);
	for (i = 0; i < 4; i++){
		if (cnt[i] == 3){
			for (j = 0; j < 4; j++){
				if (!(anti_stat[i] & (1 << p[j])))
					fix[i] = p[j];
			}
		}
	}
	/*for (i = 0; i < 4; i++)
		printf("%d ",fix[i]);
	printf("-fix\n");*/
	for (i = 0; i < 24; i++){
		for (j = 0; j < 4; j++){
			guess[j] = p[perm[i][j]];
			if (fix[j] != -1 && fix[j] != guess[j]) j = 100;
			if (anti_stat[j] & 1 << guess[j]) j = 100;
		}
		if (j > 100) continue;
		/*for (j = 0; j < 4; j++)
			printf("%d ",guess[j]);
		printf("\n");*/
		if (call_query(guess)) return;
		
	}
}
void doUserImplementation(int guess[]) {
	ix = 0;
	int g1[5] = { 0, 1, 2, 3,0 };
	int g2[5] = { 4,5,6,7 ,0};
	int g3[2] = { 8,9 };
	int digit[4];
	int priority[10] = { -1, -1, -1, -1, -1, -1, -1, -1, -1, -1 };
	int cnt1, cnt2, cnt3;
	int *p1, *p2, *p3;
	int back = 10;
	int ix1, ix2;
	int i;

	if (call_query(g1)){
		for (i = 0; i < 4; i++) guess[i] = g1[i];
		return;
	}
	if (call_query(g2)){
		for (i = 0; i < 4; i++) guess[i] = g2[i];
		return;
	}
	cnt1 = hist[0].sum;
	cnt2 = hist[1].sum;
	
	g1[4] = cnt1;
	g2[4] = cnt2;
	if (cnt1 < cnt2){
		p1 = g2;
		p2 = g1;
	}
	else{
		p1 = g1;
		p2 = g2;
	}
	p3 = g3;
	if (p2[4] == 1){
		ix1 = ix2 = 0;
		switch (p1[4]){
		case 1: //(1,1,2)->(2,0,2), q_cnt+2
			digit[0] = p1[0]; digit[1] = p1[1];
			digit[2] = p3[0]; digit[3] = p3[1];
			if (call_query(digit)){
				for (i = 0; i < 4; i++)
					guess[i] = digit[i];
				return;
			}
			if (hist[ix-1].sum>2) ix1 = 2;
			digit[0] = p2[0]; digit[1] = p2[1];
			if (call_query(digit)){
				for (i = 0; i < 4; i++)
					guess[i] = digit[i];
				return;
			}
			if (hist[ix-1].sum==2) ix2 = 2;
			for (i = 0; i < 2; i++) swap(p1[ix1 + i], p2[ix2 + i]);
			p1[4] = 2;
			p2[4] = 0;
			break;
		case 2://(2,1,1)->(2,2,0), q_cnt+1
			digit[0] = p2[0]; digit[1] = p2[1];
			digit[2] = p3[0]; digit[3] = p3[1];
			call_query(digit);
			if (hist[ix - 1].sum>1) ix1 = 2;
			for (i = 0; i < 2; i++) swap(p2[ix1 + i], p3[ix2 + i]);
			p2[4] = 2;
			break;
		case 3://(3,1,0)->(3,0,1), q_cnt+1
			digit[0] = p2[0]; digit[1] = p2[1];
			digit[2] = p3[0]; digit[3] = p3[1];
			call_query(digit);
			if (hist[ix - 1].sum==0) ix1 = 2;
			for (i = 0; i < 2; i++) swap(p2[ix1 + i], p3[ix2 + i]);
			p2[4] = 0;
			
			break;
		}
	}
	/*for (i = 0; i < 4; i++) printf("%d ", p1[i]);
	for (i = 0; i < 4; i++) printf("%d ", p2[i]);
	printf("\n");*/
	cnt3 = 4 - p1[4] - p2[4];
	if (p1[4] != 4){
		ix1 = ix2 = 0;
		switch (cnt3){
		case 0://(2,2,0)->(4,0,0)
			last2(p2, p3, 0,ix==2); //(1),(1) case
			last2(p1, p3, 0,true); // ? case

			ix1 = 2;
			for (i = 0; i < 2; i++) swap(p1[ix1 + i], p2[ix2 + i]);
			p1[4] = 4;
			p2[4] = 0;
			break;

		case 1://(3,0,1)
			
			digit[0] = p3[0]; digit[1] = p2[0];
			digit[2] = p2[1]; digit[3] = p2[2];
			call_query(digit);
			if (hist[ix - 1].sum == 0) digit[0] = p3[1];
			ix2++;
			while (ix2 < 4){
				digit[ix2] = p1[ix1++];
				if (call_query(digit)){
					for (i = 0; i < 4; i++)
						guess[i] = digit[i];
					return;
				}
				if (hist[ix - 1].sum == ix2){
					while (ix2 != 4) digit[ix2++] = p1[ix1++];
				}
				ix2++;
			}
			for (i = 0; i < 4; i++) p1[i] = digit[i];
			p1[4] = 4;
			break;

		case 2://(2,0,2)->(4,0,0), q_cnt+ 1 ~ 3
			if (last2(p1, p3, 2, ix == 2)){
				for (i = 0; i < 4; i++) guess[i] = p1[i];
				return;
			}
			p1[2] = p3[0]; p1[3] = p3[1];
			p1[4] = 4;
			break;
		}
		p1[4] = 4;
	}
	//for (i = 0; i < 4; i++) guess[i] = p1[i];
	answer(guess,p1);
	//for (i = 0; i < 4; i++) guess[i] = p1[i];
}
