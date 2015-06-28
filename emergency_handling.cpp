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

#define MAX 110

using namespace std;

typedef struct Patient {
   int t0,s,r;
   Patient(int t0, int s, int r) : t0(t0), s(s), r(r) {}
} patient;

struct Cmp {
   bool operator()(const patient &a, const patient &b) const {
      return (a.s - a.r*a.t0 + a.r * 100) < (b.s - b.r*b.t0 + b.r * 100);
   }
};

priority_queue<patient, vector<patient>, Cmp> queues[MAX];

int urgency(const patient &p, int t) {
   return p.s + p.r*(t - p.t0);
}

patient find_patient(int t) {
   int num;

   patient p(0, 0, 0);
   patient curr(0, 0, 0);

   for (int i = 0; i < MAX; i++) {
      if (!queues[i].empty()) {
         curr = queues[i].top();

         if (urgency(curr, t) == urgency(p, t) && curr.r > p.r) {
            p = curr;
            num = i;
         } else if (urgency(curr, t) > urgency(p, t)) {
            p = curr;
            num = i;
         }
      }
   }

   queues[num].pop();

   return p;
}

int main(int argc, char* argv[]) {      
   int T,N,s,r,t,c=1;
   char next;

   cin >> T;

   patient curr(0, 0, 0);

   while (T--) {
      for (int i = 0; i < MAX; i++) {
         queues[i] = priority_queue<patient, vector<patient>, Cmp>();
      }

      cin >> N;

      cout << "Case #" << c++ << ":" << endl;

      for (int j = 0; j < N; j++) {
         cin >> next;

         if (next == 'P') {
            cin >> t >> s >> r;
            queues[r].push(patient(t, s, r));
         } else {
            cin >> t;
            curr = find_patient(t);
            cout << urgency(curr,t) << " " << curr.r << endl;
         }
      }
   }
}
