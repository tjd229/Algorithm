//category : graph



#include <stdio.h>
#include <vector>
using namespace std;
int edges[100001];
int indegree[100001];
int main(){
	int T, n;
	int i;
	int remain;
	for (scanf("%d", &T); T--;){
		scanf("%d",&n);
		remain = n;
		for (i = 1; i <= n; i++) indegree[i] = 0;
		for (i = 1; i <= n; i++){
			scanf("%d", &edges[i]);
			indegree[edges[i]]++;
		}
		vector<int> v;
		for (i = 1; i <= n; i++){
			if (indegree[i] == 0) v.push_back(i);
		}
		for (i = 0; i < v.size(); i++){
			if (--indegree[edges[v[i]]]==0) v.push_back(edges[v[i]]);
		}
		printf("%d\n",v.size());
		
	}


	return 0;
}