//category : graph, math

#include <vector>
#include <string>
using namespace std;

class TheTips{
public:
	vector<int> back[50];
	double p[50];
	int visit[50];
	double dfs(int ix,int stamp){
		visit[ix] = stamp;
		double res = 1.0 - p[ix];
		for (int i = 0; i < back[ix].size(); i++){
			if (visit[back[ix][i]] == stamp) continue;
			res *= dfs(back[ix][i], stamp);
		}
		return res;
	}
	double solve(vector<string> clues, vector<int> probability){
		double res = 0.f;
		int i, j;
		int sz = clues.size();
		for (i = 0; i < sz; i++){
			p[i] = probability[i]/100.0;
			visit[i] = 0;
			for (j = 0; j < sz; j++){
				if (i != j&&clues[i][j] == 'Y')
					back[j].push_back(i);
			}
		}
		for (i = 0; i < sz; i++){
			res += (1.0-dfs(i, i + 1));
		}
		return res;

	}
};
