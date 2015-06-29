#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <limits>

using namespace std;

const long kMAX_M = 20005;

int T;
long N;
int M;
long coins[kMAX_M];

int main() {
    scanf("%d", &T);
    for(int t = 1; t <= T; ++t) {
        scanf("%li%d", &N, &M);

        for(int m = 0; m < M; ++m) {
            scanf("%li", &coins[m]);
        }

        sort(coins, coins + M);

        long max_dist = numeric_limits<long>::min();
        long min_dist = numeric_limits<long>::max();

        long gap = N / M;
        for(long m = 0, pos = 0; m < M; ++m, pos += gap) {
            long amount = pos - coins[m];

            max_dist = max(max_dist, amount);
            min_dist = min(min_dist, amount);
        }

        long cost = (max_dist - min_dist + 1) / 2;
        printf("Case #%d: %li\n", t, cost);
    }
    return EXIT_SUCCESS;
}

