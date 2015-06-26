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

typedef struct Edge {
   int u, v, w;
   Edge(int u, int v, int w) : u(u), v(v), w(w) {}
   Edge() {}
} edge;

int parent[405];
int rank[405];
int plants[405];
int adj[405][405];
bool seen[405];
vector<edge> edges;
vector<edge> mst;

int find(int a) {
   if (parent[a] == a) return a;
   parent[a] = find(parent[a]);
   return parent[a];
}

void unify(int a, int b) {
   a = find(a);
   b = find(b);

   if (rank[a] < rank[b]) {
      parent[a] = b;
   } else {
      if (rank[a] == rank[b]) ++rank[a];  
      parent[b] = a;
   }
}

bool cmp(const edge &a, const edge &b) {
   return a.w < b.w;
}

int reachable(int p, int n) {
   if (seen[p]) return 0;

   int found = 1;
   queue<int> q;
   q.push(p);

   seen[p] = true;

   while (!q.empty()) {
      int curr = q.front();
      q.pop();

      if(!seen[curr]) ++found;
      seen[curr] = true;

      for (int i = 1; i <= n; ++i) {
         if (adj[curr][i] < 0) continue;

         if (!seen[i]) q.push(i);
      }
   }

   return found;
}

int main(int argc, char** argv) {
   int T, N, M, K, n, u, v, w, best;
   int total, c = 1;
   long long cost;

   cin >> T;

   while (T--) {
      cin >> N >> M >> K;

      cost = 0;
      edges.clear();
      mst.clear();
      memset(adj, -1, sizeof(adj));

      n = N + K;

      for (int i = 0; i < K; ++i) {
         cin >> plants[i];
      }

      for (int i = 1; i < n; ++i) {
         parent[i] = i;
         rank[i] = 0;
      }

      for (int i = 0; i < M; ++i) {
         cin >> u >> v >> w;
         edges.push_back(edge(u,v,w));
      }

      sort(edges.begin(), edges.end(), cmp);

      for (int i = 0; i < M; ++i) {
         u = edges[i].u;
         v = edges[i].v;
         w = edges[i].w;

         if (find(u) != find(v)) {
            mst.push_back(edges[i]);
            unify(u,v);
            adj[u][v] = adj[v][u] = w;
         }
      }

      for (int i = mst.size()-1; i >= 0; --i) {
         total = 0;
         adj[mst[i].u][mst[i].v] = -1;
         adj[mst[i].v][mst[i].u] = -1;

         memset(seen, false, sizeof(seen));
         for (int j = 0; j < K; ++j) {
            total += reachable(plants[j], n);
         }

         if (total != N) {
            adj[mst[i].u][mst[i].v] = mst[i].w;
            adj[mst[i].v][mst[i].u] = mst[i].w;
            cost += mst[i].w;
         }
      }

      cout << "Case #" << c++ << ": " << cost <<  endl;
   }
}
