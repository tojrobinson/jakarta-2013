#include <iostream>
#include <stdio.h>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <string>
#include <sstream>
#include <vector>
#include <map>
#include <queue>
#include <string.h>

using namespace std;

const int MOD = 1e9+9;
int dp[50005][205];
int a[50005];
int b[50005];
int N, M, D;

int orderings(int i, int j) {
   bool invalid = true;
   while (invalid) {
      invalid = false;
      while (i < N && b[j] - a[i] > D) {
         i++;
         invalid = true;
      }
      while (j < M && a[i] - b[j] > D) {
         j++;
         invalid = true;
      }
   }

   if (i == N || j == M) return 1;
   int diff = a[i]-b[j]+102;

   if (dp[i][diff] != -1) return dp[i][diff];

   dp[i][diff] = 0;
   if (a[i]-b[j] < D) dp[i][diff] = (dp[i][diff] + orderings(i+1,j))%MOD;
   if (b[j]-a[i] < D) dp[i][diff] = (dp[i][diff] + orderings(i,j+1))%MOD;

   return dp[i][diff];
}

int main(int argc, char** argv) {
   int T,c=1;
   cin >> T;

   while (T--) {
      cin >> N >> M >> D;
      memset(dp,-1,sizeof(int)*205*N);
      for (int i = 0; i < N; ++i) cin >> a[i];
      for (int i = 0; i < M; ++i) cin >> b[i];
      cout << "Case #" << c++ << ": " << orderings(0,0) << endl;
   }
}
