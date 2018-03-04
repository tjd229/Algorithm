//category : graph, dp

#include <vector>
#include <algorithm>
#include <stdio.h>
using namespace std;

class TreeAndCycle{
public:
   int n;
   int d[100][2];
   int cut[100];
   vector<int> *costV;

   vector<int> edge[100];
   void dfs(int ix){
      if (edge[ix].empty()){
         d[ix][0] = costV->at(ix);
         d[ix][0] += d[ix][0];
         return;
      }
      int i,j,k;
      for (i = 0; i < edge[ix].size(); i++) dfs(edge[ix][i]);
      for (i = 0; i < edge[ix].size(); i++){
         int to = edge[ix][i];
         int res = d[to][0] - costV->at(to) + costV->at(ix);
         for (j = 0; j < edge[ix].size(); j++){
            if (i == j) continue;
            res += min(d[edge[ix][j]][0], d[edge[ix][j]][1]) + cut[edge[ix][j]];
         }
         d[ix][0] = min(d[ix][0], res);

         for (j = 0; j < edge[ix].size(); j++){
            res = 1e9;
            if (i == j) continue;
            res = min(d[to][0] - costV->at(to), d[to][1] + costV->at(ix) + cut[to]);
            res += min(d[edge[ix][j]][0] - costV->at(edge[ix][j]), d[edge[ix][j]][1] + costV->at(ix) + cut[edge[ix][j]]);
            for (k = 0; k < edge[ix].size(); k++){
               if (k == i || k == j) continue;
               res += min(d[edge[ix][k]][0], d[edge[ix][k]][1]) + cut[edge[ix][k]];
            }

            d[ix][1] = min(d[ix][1], res);
         }

         if (d[to][1] == 1e9) continue;
         res = d[to][1] + costV->at(ix) +costV->at(ix)+cut[to];
         for (j = 0; j < edge[ix].size(); j++){
            if (i == j) continue;
            res += min(d[edge[ix][j]][0], d[edge[ix][j]][1]) + cut[edge[ix][j]];
         }
         d[ix][0] = min(d[ix][0], res);
         
         

      }

      
   }


   
   int minimize(vector<int> costV, vector<int> pre, vector<int> costE){
      int i;
      n = costV.size();
      this->costV = &costV;
      for (i = 0; i < n - 1; i++){
         edge[pre[i]].push_back(i + 1);
         cut[i + 1] = costE[i];
         d[i][0] = d[i][1] = 1e9;
      }
      d[i][0] = d[i][1] = 1e9;
      dfs(0);

      return min(d[0][1], d[0][0]);
   }
};
