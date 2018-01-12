//category : hashing, bs
#define MAX 30000
#define ll long long
const int base = 8;
struct Block{
	int min, max;
	ll h1;
	ll h2[4];
	bool use;
	bool operator<(Block b) const{
		if (max == b.max) return min<b.min;
		return max > b.max;
	}
}block[MAX],tmpB[MAX];
struct Candi{
	int ix, min;
	bool operator<(Candi c) const{
		if (min == c.min) return ix>c.ix;
		return min > c.min;
	}
}tmpC[MAX*5];
ll arr[MAX * 5+1];
ll tmpL[MAX * 5];
Candi *partner[MAX*5],*link[MAX*5];
int cnt[MAX * 5],c_ix[MAX*5];
int len;
template <typename T>
void mergeSort(int s,int e,T *arr, T *tmp ){
	
	if (s >= e) return;
	int i;
	int m = (s + e) >> 1;
	int cnt = e - s+1;
	int ix1 = s;
	int ix2 = m + 1;
	int pt;
	mergeSort(s, m, arr,tmp);
	mergeSort(ix2,e, arr,tmp);
	for (i = 0; i < cnt; i++){
		if (ix1 > m){
			pt = ix2++;
		}
		else if (ix2 > e) pt = ix1++;
		else{
			pt = arr[ix1] < arr[ix2] ? ix1++ : ix2++;
		}
		tmp[s + i] = arr[pt];
	}
	for (i = 0; i < cnt; i++)
		arr[s + i] = tmp[s + i];
}
void compress(int &len){
	int l, r;
	ll last = arr[0];
	l = r = 0;
	for (r = 0; r <= len; r++){
		if (arr[r] != last){
			arr[l++] = last;
			last = arr[r];
		}
	}
	len = l;
}
void makeHash(int ix, const int module[][4][4]){
	int i, j;
	ll h = 0;
	int min = block[ix].min;
	int max = block[ix].max;
	for (i = 0; i < 4; i++){
		for (j = 0; j < 4; j++){
			h *= base;
			h += module[ix][i][j] - min;
		}
	}
	block[ix].h1 = h;
	h = 0;
	for (i = 0; i < 4; i++){
		for (j = 3; j >= 0; j--){
			h *= base;
			h += max - module[ix][i][j];
		}
	}
	block[ix].h2[0] = h;
	h = 0;
	for (j = 3; j >= 0; j--){
		for (i = 3; i >= 0; i--){
			h *= base;
			h += max - module[ix][i][j];
		}
	}
	block[ix].h2[1] = h;
	h = 0;
	for (i = 3; i >= 0; i--){
		for (j = 0; j < 4; j++){
			h *= base;
			h += max - module[ix][i][j];
		}
	}
	block[ix].h2[2] = h;
	h = 0;
	for (j = 0; j < 4; j++){
		for (i = 0; i < 4; i++){
			h *= base;
			h += max - module[ix][i][j];
		}
	}
	block[ix].h2[3] = h;

}
void swap(int &a, int &b){
	a ^= b ^= a ^= b;
}
int getPos(ll val,int r){
	int l = 0;
	int m;
	while (l <= r){
		m = (l + r) >> 1;
		if (arr[m] == val) return m;
		else if (arr[m] > val) r = m - 1;
		else l = m + 1;
	}
	return -1;
}
int makeBlock(int module[][4][4])
{
	int i, j, k,l;
	int max, min;
	int res = 0;
	
	len = 0;
	for (i = 0; i < MAX; i++){
		max = -1;
		min = 100;
		for (j = 0; j < 4; j++){
			for (k = 0; k < 4; k++){
				if (min > module[i][j][k]) min = module[i][j][k];
				if (max < module[i][j][k]) max = module[i][j][k];
			}
		}
		block[i].min = min;
		block[i].max = max;
		block[i].use = false;
		makeHash(i,module);
		arr[len++] = block[i].h1;
		for (j = 0; j < 4; j++)
			arr[len++] = block[i].h2[j];
	}
	for (i = 0; i < len; i++) c_ix[i]=cnt[i] = 0; //len = MAX*5
	arr[len] = -1;
	mergeSort(0,len-1,arr,tmpL);
	compress(len);
	mergeSort(0,MAX-1,block,tmpB);
	for (i = 0; i < MAX; i++){
		j=block[i].h1 = getPos(block[i].h1, len - 1);
		cnt[j]++;
		for (j = 0; j < 4;j++)
			block[i].h2[j] = getPos(block[i].h2[j], len - 1);
	}
	for (i = 0; i < len; i++)
		partner[i] = new Candi[cnt[i]];
	for (i = 0; i < MAX; i++){
		j = block[i].h1;
		partner[j][c_ix[j]].ix = i;
		partner[j][c_ix[j]++].min = block[i].min;
	}
	for (i = 0; i < len; i++) mergeSort(0, cnt[i] - 1, partner[i], tmpC),link[i]=partner[i];

	for (i = 0; i < MAX; i++){
		if (block[i].use) continue;
		k = -1;
		min = 0;
		for (j = 0; j < 4; j++){
			l = block[i].h2[j];
			while (cnt[l] != 0 && (block[link[l][0].ix].use || link[l][0].ix == i)){
				if (block[link[l][0].ix].use){
					++link[l];
					cnt[l]--;
				}
				else if (link[l][0].ix == i){
					if (cnt[l] < 2) break;
					swap(link[l][0].ix, link[l][1].ix);
					swap(link[l][0].min, link[l][1].min);					
				}
			}
			if (cnt[l] != 0 && link[l][0].ix != i&&min < link[l][0].min){
				k = l;
				min = link[l][0].min;
			}
		}
		if (k != -1){
			res += min + block[i].max;
			block[i].use = block[link[k][0].ix].use = true;
			++link[k];
			cnt[k]--;
		}
	}

	for (i = 0; i < len; i++)
		delete[] partner[i];
	return res;

}
