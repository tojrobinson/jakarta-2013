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

#define MAX 50010

using namespace std;

typedef long long ll;

const int B = 137;
string s;
ll P[MAX];
ll H[MAX];
int n;

ll hash(int i, int j) {
   return (H[j + 1] - H[i]) * P[n - j];
}

int longest() {
   int front = 0;
   int curr_front = front;
   int back = n - 1;
   int curr_back = back;
   int len = 0;

   while (curr_back >= front) {
      if (hash(front, curr_front) == hash(curr_back, back)) {
         if (curr_back == front) {
            len++;
         } else {
            len += 2;
         }

         curr_front++;
         front = curr_front;
         curr_back--;
         back = curr_back;
      } else {
         curr_front++;
         curr_back--;
      }
   }

   return len;
}

int main(int argc, char* argv[]) {
   int T,c=1;

   cin >> T;

   while (T--) {
      cin >> s;

      n = s.size();

      P[0] = 1;
      for (int i = 1; i <= n; i++)
         P[i] = P[i - 1] * B;

      H[0] = 0;
      for (int i = 1; i <= n; i++)
         H[i] = H[i - 1] + s[i - 1] * P[i - 1];

      cout << "Case #" << c++ << ": " << longest() << endl;
   }
}
