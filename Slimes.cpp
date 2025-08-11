// #include<bits/stdc++.h>
// using namespace std;
// const int N = 420;
// long long a[N];
// long long pref[N];
// long long dp[N][N];

// long long Smiles(long long l, long long r){
//      if(l == r){
//         return 0;
//      }
//      if(dp[l][r] != -1){
//         return dp[l][r];
//      }
//      long long ans = 1e17;
//      long long sum = pref[r] - pref[l - 1];
//      for(int i = l; i < r; i++){
//         ans = min(ans, sum + Smiles(l, i) + Smiles(i + 1, r));
//      }
//      return dp[l][r] = ans;
// }

// int32_t main(){
//     memset(dp, -1, sizeof(dp));
//     int n; cin >> n;
//     for(int i = 1; i <= n; i++){
//          cin >> a[i];
//     }
//     pref[0] = 0;

//     for(int i = 1; i <= n; i++){
//         pref[i] = pref[i - 1] + a[i];
//     }
//     cout << Smiles(1, n) << "\n";

// }

#include <bits/stdc++.h>
using namespace std;
const int N = 420;
long long a[N];
long long pref[N];
long long dp[N][N];
const long long inf = 1e17;

int32_t main()
{
    for(int i = 0; i < N; i++){
        for(int j = 0; j < N; j++){
            dp[i][j] = inf;
        }
    }
    int n;
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    pref[0] = 0;

    for (int i = 1; i <= n; i++)
    {
        pref[i] = pref[i - 1] + a[i];
    }

    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (i == j)
            {
                dp[i][j] = 0;
            }
        }
    }

    for (int l = n - 1; l >= 1; l--) {
    for (int r = l + 1; r <= n; r++) {  
        long long sum = pref[r] - pref[l - 1];
        dp[l][r] = inf;
        for (int i = l; i < r; i++) {
            dp[l][r] = min(dp[l][r], sum + dp[l][i] + dp[i + 1][r]);
        }
    }
}
    cout << dp[1][n] << "\n";
}

