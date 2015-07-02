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
#include <limits>

using namespace std;

typedef long long ll;
int T,M;
ll N;
ll coins[20005];

int main() {
   ll cost,gap,max_dist,min_dist,amount;
   int c = 1;

   scanf("%d", &T);

   while (T--) {
      scanf("%lli%d", &N, &M);

      for(int m = 0; m < M; ++m) {
         scanf("%lli", &coins[m]);
      }

      sort(coins,coins+M);

      max_dist = numeric_limits<ll>::min();
      min_dist = numeric_limits<ll>::max();
      gap = N/M;

      for(int m = 0, pos = 0; m < M; ++m, pos += gap) {
         amount = pos - coins[m];
         max_dist = max(max_dist, amount);
         min_dist = min(min_dist, amount);
      }

      cost = (max_dist - min_dist + 1)/2;

      printf("Case #%d: %lli\n", c++, cost);
   }
}
