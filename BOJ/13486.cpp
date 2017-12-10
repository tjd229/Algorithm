//category : string, graph, tp sort

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;
string arr[101];
int ix[101];
int ind[26];
int outd[26];
int ans[26];
int mat[26][26];
vector<int> q;
bool add_edge(int a, int b){
	int i = 0;
	while (i < (int)arr[a].size() && i < (int)arr[b].size()){
		if (arr[a][i] != arr[b][i]){
			int to = arr[b][i] - 'a';
			int from = arr[a][i] - 'a';
			if (mat[from][to] == 0){
				mat[from][to] = 1;
				ind[to]++;
				outd[from]++;
			}
			return true;
		}
		i++;
	}
	return arr[a].size() < arr[b].size();
}
bool tp_sort(){
	int i, j;
	int r = 0;
	for (i = 0; i < 26; i++){
		if (ind[i] == 0){
			if (outd[i])
				q.push_back(i);
			else r++;
		}

	}
	int curr;
	
	for (i=0; i < q.size(); i++){
		curr = q[i];
		for (j = 0; j < 26; j++){
			if (mat[curr][j] == 1){
				if (--ind[j] == 0) q.push_back(j);
			}

		}
	}
	return (r + q.size() == 26);
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	int i, j;
	int N;
	cin >> N;
	for (i = 1; i <= N; i++) cin >> arr[i];
	for (i = 1; i <= N; i++){
		cin >> j;
		ix[i] = j;
	}
	for (i = 0; i < 26; i++) ans[i] = i;
	for (i = 2; i <= N; i++){
		if (!add_edge(ix[i - 1], ix[i])){
			cout << "NE";
			return 0;
		}
	}
	if (tp_sort()){
		cout << "DA\n";
		vector<int> v = q;
		sort(v.begin(), v.end());
		for (i = 0; i < v.size(); i++) ans[q[i]] = v[i];
		for (i = 0; i < 26; i++) cout << (char)(ans[i] + 'a');
	}
	else cout << "NE";

	return 0;
}
