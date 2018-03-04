//category : graph, tdp
#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

class TreeAndCycle{
public:
   int n;
   int d[100][3];  //degree
   int cut[100];
   vector<int> *costV;

   vector<int> edge[100];
   void dfs(int ix){
      int i, j, k;
      int t[3];
      d[ix][0] = 0;
      for (i = 0; i < edge[ix].size(); i++){
         int to = edge[ix][i];
         dfs(to);
         t[0] = t[1] = t[2] = 1e9;
         for (j = 0; j < 3; j++){
            for (k = 0; k < 3; k++){
               t[j] = min(t[j], d[ix][j] + d[to][k] + cut[to]);
               if (j > 1 || k > 1) continue;
               t[j + 1] = min(t[j + 1], d[ix][j] + d[to][k] - costV->at(to));               
            }
         }
         for (j = 0; j < 3; j++) d[ix][j] = t[j];
      }
      d[ix][0] += costV->at(ix);
      d[ix][0] += costV->at(ix);
      if (edge[ix].size())
         d[ix][1] += costV->at(ix);
      //printf("%d:%d,%d,%d\n", ix, d[ix][0], d[ix][1], d[ix][2]);
   }
   
   
   int minimize(vector<int> costV, vector<int> pre, vector<int> costE){
      int i;
      n = costV.size();
      this->costV = &costV;
      for (i = 0; i < n - 1; i++){
         edge[pre[i]].push_back(i + 1);
         cut[i + 1] = costE[i];
         d[i][0] = d[i][1]= d[i][2]= 1e9;
      }
      d[i][0] = d[i][1] = d[i][2] = 1e9;
      dfs(0);

      return min(d[0][1], min(d[0][0],d[0][2]));
   }
};
