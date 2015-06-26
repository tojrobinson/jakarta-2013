#include <iostream>
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
 
vector<int> adj[20010];
bool seen[20010];
const int MAX_VAL = 1e9+7;
long long best;
int N;
 
int opt(int r) {
   if (seen[r]) return 0;
   seen[r] = true;
   int s = 0;
   int c;
   long long paths = 0;
   vector<int> w;
   vector<int> sm;
 
   for (int i = 0; i < adj[r].size(); ++i) {
      c = opt(adj[r][i]);
      w.push_back(c);
      s += c;
   }
 
   w.push_back(N-s-1);

   sm.resize(w.size());

   sm[0] = w[0];

   for (int i = 1; i < w.size(); ++i) {
      sm[i] = w[i] + sm[i-1];
   }

   for (int i = 0; i < w.size(); ++i) {
      paths += w[i]*(sm[w.size()-1] - sm[i]);
   }

   if (paths > best) best = paths;

   return s + 1;
}
 
int main(int argc, char** argv) {
   int T, a, b, c = 1;
   long long total;
 
   cin >> T;
 
   while (T--) {
      cin >> N;
      total = 0;
      best = -1;
 
      for (int i = 1; i <= N; ++i) {
         adj[i].clear();
      }
 
      for (int i = 1; i < N; ++i) {
         cin >> a >> b;
 
         adj[a].push_back(b);
         adj[b].push_back(a);
      }
 
      memset(seen,false,sizeof(bool)*(N+5));
      opt(1);
 
      cout << "Case #" << c++ << ": " << best << endl;
   }
}
