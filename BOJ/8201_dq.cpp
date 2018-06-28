//category : greedy

#include <stdio.h>
#include <deque>
using namespace std;
int a[3000000];
int main(){
	deque<int> maxima, minima;
	int i;
	int t, n;
	int l = -1;
	int ans = 0;
	for (scanf("%d%d", &t, &n), i = 0; i < n; i++) scanf("%d",a+i);
	for (i = 0; i < n; i++){
		while (maxima.size() && a[maxima.front()] - a[i]>t){
			if (l < maxima.front()) l = maxima.front();
			maxima.pop_front();
		}
		while (minima.size() && a[i]-a[minima.front()]>t){
			if (l < minima.front()) l = minima.front();
			minima.pop_front();
		}
		if (ans < i - l) ans = i - l;
		while (maxima.size() && a[maxima.back()] < a[i]) maxima.pop_back();
		while (minima.size() && a[minima.back()] > a[i]) minima.pop_back();
		maxima.push_back(i);
		minima.push_back(i);
	}
	printf("%d",ans);

	return 0;
}
