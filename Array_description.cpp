
#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 2;
const int M = 105;
const int MOD = 1e9 + 7;

int n, m;
int a[N];
int dp[N][M];

int Array_description(int i, int prev) {
    if (i > n) return 1; 

    if (dp[i][prev] != -1) return dp[i][prev];

    long long ans = 0;

    if (a[i] != 0) {
      
        if (abs(prev - a[i]) <= 1) {
            ans = (ans + Array_description(i + 1, a[i])) % MOD;
        }
    } 
    else {
      
        if (prev == 0) {
          
            for (int cur = 1; cur <= m; cur++) {
                ans = (ans + Array_description(i + 1, cur)) % MOD;
            }
        } else {
          
            for (int cur = max(1, prev - 1); cur <= min(m, prev + 1); cur++) {
                ans = (ans + Array_description(i + 1, cur)) % MOD;
            }
        }
    }

    return dp[i][prev] = ans % MOD;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> n >> m;
    for (int i = 1; i <= n; i++) cin >> a[i];

    memset(dp, -1, sizeof(dp));

    cout << Array_description(1, a[1]) << "\n";
    return 0;
}
