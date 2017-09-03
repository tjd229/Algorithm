//category : d&c

#include <stdio.h>
#include <math.h>
// pts[][0]:x좌표, pts[][1]:y좌표
int pts[100000][2];		//입력 점들의 배열
int temp[100000][2];	//merge sort용 임시 배열
int min(int a, int b){
	if (a < b) return a;
	return b;
}
// (x1,y1), (x2,y2)의 거리 제곱
int sqdist(int x1, int y1, int x2, int y2){
	return (x1 - x2)*(x1 - x2) + (y1 - y2)*(y1 - y2);
}
// if(xy==0) -> x축에 따라 정렬
// if(xy==1) -> y축에 따라 정렬
void merge(int s, int m, int e, int xy){
	int ix1 = s;
	int ix2 = m;

	for (int i = s; i < e; i++){
		if (ix1 == m){
			temp[i][0] = pts[ix2][0];
			temp[i][1] = pts[ix2][1];
			ix2++;
		}
		else if (ix2 == e){
			temp[i][0] = pts[ix1][0];
			temp[i][1] = pts[ix1][1];
			ix1++;
		}
		else if (pts[ix1][xy] > pts[ix2][xy]){
			temp[i][0] = pts[ix2][0];
			temp[i][1] = pts[ix2][1];
			ix2++;
		}
		else{
			temp[i][0] = pts[ix1][0];
			temp[i][1] = pts[ix1][1];
			ix1++;
		}
	}
	for (int i = s; i < e; i++){
		pts[i][0] = temp[i][0];
		pts[i][1] = temp[i][1];
	}
}
void mergesort(int s, int e, int xy){
	if (e - s <= 1)		//예외처리
		return;
	int m = (s + e) / 2;
	mergesort(s, m, xy);
	mergesort(m, e, xy);
	merge(s, m, e, xy);
}
//[s,e)
int band(int s, int e, int delta){
	int m = (s + e) / 2;
	//cent_x,cent_y : 중점
	int cent_x = pts[m][0];
	int cent_y = pts[m][1];
	int from, to;
	int i, j;

	//중점에서부터 delta범위 내의 점들 탐색(left)
	for (from = m; from >= s; from--){
		if (pts[from][0] < cent_x - delta)
			break;
	}
	//from은 범위내에 들어가야하므로, +1
	from++;
	//중점에서부터 delta범위 내의 점들 탐색(right)
	for (to = m; to < e; to++){
		if (pts[to][0] > cent_x + delta)
			break;
	}
	//y축 정렬
	mergesort(from, to, 1);
	int dist = 900000000;		//초기화로 MAX값을 저장
	for (i = from; i < to; i++){
		for (j = i - 15; j < i + 15; j++){
			if (i == j)		//똑같은 점끼리의 거리인 경우 계산안함
				continue;
			if (j < from || j >= to)	//범위 이탈 예외 처리
				continue;
			dist = min(dist, sqdist(pts[i][0], pts[i][1], pts[j][0], pts[j][1]));
		}
	}
	//다음 단계를 위해 다시 x축 정렬
	mergesort(from, to, 0);
	return dist;
}
//[s,e)
//최단 거리를 반환함
int closest_pair(int s, int e){
	int sqdelta;
	if (e - s < 4){		//점이 2개 이거나 3개일 경우의 예외처리
		sqdelta = sqdist(pts[s][0], pts[s][1], pts[s + 1][0], pts[s + 1][1]);
		if (e - s == 3){	//점이 3개일 경우의 예외처리
			sqdelta = min(sqdelta, sqdist(pts[s + 2][0], pts[s + 2][1], pts[s + 1][0], pts[s + 1][1]));
			sqdelta = min(sqdelta, sqdist(pts[s + 2][0], pts[s + 2][1], pts[s][0], pts[s][1]));
		}
		return sqdelta;
	}
	int m = (s + e) / 2;

	sqdelta = min(closest_pair(s, m), closest_pair(m, e));
	//sqdelta는 거리 제곱이므로 루트적용 후 band함수 호출
	//+1은 float->int 캐스팅중 내림 처리로 인한 값손실 방지
	sqdelta = min(sqdelta, band(s, e, sqrt((float)sqdelta) + 1));
	return sqdelta;
}
int main(){
	int i;
	int n;
	scanf("%d", &n);
	for (i = 0; i < n; i++){
		scanf("%d%d", &pts[i][0], &pts[i][1]);
	}
	//x축 정렬
	mergesort(0, n, 0);
	printf("%d", closest_pair(0, n));
	return 0;
}

