// #include<bits/stdc++.h>
// using namespace std;
// const int N = 105;
// const int K = 10005;
// int dp[N][K];
// int n, k;
// int a[N];
// int coinChange(int i, int sum){
//     if(i == n + 1){
//         if(sum == k){
//             return 1;
//         }
//         else{
//             return 0;
//         }
//     }
//     if(dp[i][sum] != -1){
//         return dp[i][sum];
//     }
//     int ans = 0;
//     ans = coinChange(i + 1, sum);
//     if(sum + a[i] <= k){
//          ans = ans + coinChange(i, sum + a[i]);
//     }
//     return dp[i][sum] = ans;
  
// }
// // test t = 100  n = 100  k = 10000
// // recursive 10^8 given time limit exceed so try it iterative way
// int main(){
//     memset(dp, -1, sizeof(dp));
//     cin >> n >> k;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     int ans = coinChange(1, 0);
//     cout << ans << "\n";
// }

// iterative way
//     ans = coinChange(i + 1, sum);
//     if(sum + a[i] <= k){
//          ans = ans + coinChange(i, sum + a[i]);
//     }

#include<bits/stdc++.h>
using namespace std;
const int N = 105;
const int K = 10005;
int dp[N][K];
int n, k;
int a[N];
const int mod = 1e7 + 9;


int main(){
    memset(dp, 0, sizeof(dp));
    cin >> n >> k;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
    dp[n + 1][k] = 1;
    for(int i = n; i >= 1; i--){
        for(int sum = k; sum >= 0; sum--){
            dp[i][sum] = dp[i + 1][sum] % mod;
            
            if(sum + a[i] <= k){
                dp[i][sum] = (dp[i][sum] % mod + dp[i][sum + a[i]] % mod) % mod;
            }
        }
    }
    cout << dp[1][0] << "\n";
}