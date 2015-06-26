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

const int MAX_VAL = 1e9+7;
int num[102];
int dp[102][102][102];

int main(int argc, char** argv) {
   int T,N,M,c=1;

   cin >> T;

   while (T--) {
      cin >> N >> M;
      memset(dp,-1,sizeof(dp));
      for (int i = 0; i < N; ++i) cin >> num[i];
      sort(num, num+N);

      for (int m = 1; m <= M; ++m) {
         for (int i = 0; i < N; ++i) {
            for (int j = i; j < N; ++j) {
               if (m == 1) {
                  dp[i][j][m] = num[j]-num[i];
                  continue;
               }

               dp[i][j][m] = MAX_VAL;
               for (int k = i; k < j; ++k) {
                  dp[i][j][m] = min(dp[i][j][m], num[k]-num[i] + dp[k+1][j][m-1]);
               }
            }
         }
      }

      cout << "Case #" << c++ << ": " << dp[0][N-1][M] << endl;
   }
}
