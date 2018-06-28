//category : math, line sweeping

#include <stdio.h>
#include <algorithm>
using namespace std;
#define ll long long
int x[500001];
ll s[500001];
int main(){
	int i;
	int Q;
	int type;
	int e = 0;
	int pt = 1;
	for (scanf("%d", &Q); Q--;){
		scanf("%d",&type);
		if (type == 1){
			++e;
			scanf("%d",x+e);
			s[e] = s[e - 1] + x[e];
		}
		else{
			if (e == 1) printf("%.10lf\n",0.0);
			else{
				double m = (s[pt]+x[e])/(1.0+pt);
				while (pt<e && m>x[pt + 1]){
					pt++;
					m = (s[pt] + x[e]) / (1.0 + pt);
				}
				printf("%.10lf\n", x[e]-m);
			}
		}
	}

	return 0;
}
