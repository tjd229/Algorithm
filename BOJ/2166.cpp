//category : geometry, math



#include <stdio.h>
int main(){
	int N;
	double x, y;
	double lx, ly;
	double x0, y0;
	double s = 0.f;
	scanf("%d",&N);
	for (int i = 0; i < N; i++){
		scanf("%lf%lf",&x,&y);
		if (i == 0) x0 = x, y0 = y;
		else{
			s += ((lx*y)/2.f) - ((x*ly)/2.f);
		}
		lx = x, ly = y;
	}
	s += (x*y0 / 2.f) - (x0*y / 2.f);
	if (s < 0) s = -s;
	printf("%.1lf",s);
	return 0;
}