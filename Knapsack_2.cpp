// #include<bits/stdc++.h>
// using namespace std;
// const long long N = 105;
// const long long inf = 1e12;
// long long dp[N][N * 1002]; 
// long long w[N];
// long long v[N];
// long long n, W;
// long long knapsack(long long i, long long sum){
//     if(i == n){
//         if(sum == 0){
//             return 0;
//         }
//         return inf;
//     }
//     if(dp[i][sum] != -1){
//         return dp[i][sum];
//     }
//     long long ans = inf;
//     ans = knapsack(i + 1, sum);
//     ans = min(ans,knapsack(i + 1, sum - v[i]) + w[i]);

//     return dp[i][sum] = ans;
// }
// int32_t main(){
//   memset(dp,-1,sizeof(dp));
//   cin >> n >> W;
//   for(long long i = 0; i < n; i++){
//     cin >> w[i] >> v[i];
//   }
//   long long ans = 0;
//   for(long long i = 1; i <= n * 1000; i++){
//       if(knapsack(0, i) <= W){
//          ans = max(ans,i);
//       }
//   }
//   cout << ans << "\n";
// }

// iterative way
//     long long ans = inf;
//     ans = knapsack(i + 1, sum);
//     ans = min(ans,knapsack(i + 1, sum - v[i]) + w[i]);

#include<bits/stdc++.h>
using namespace std;
const long long INF = 1e12;
const int N = 105;
const int MAXV = N * 1000; 

long long dp[N+1][MAXV+1];
long long w[N], v[N];
long long n, W;

int main() {
    cin >> n >> W;
    for (long long i = 0; i < n; i++) {
        cin >> w[i] >> v[i];
    }

    for (int i = 0; i <= n; i++) {
        for (int sum = 0; sum <= MAXV; sum++) {
            dp[i][sum] = INF;
        }
    }


    dp[n][0] = 0;


    for (int i = n - 1; i >= 0; i--) {
        for (int sum = 0; sum <= MAXV; sum++) {
       
            dp[i][sum] = dp[i + 1][sum];
        
            if (sum >= v[i]) {
                dp[i][sum] = min(dp[i][sum], dp[i + 1][sum - v[i]] + w[i]);
            }
        }
    }

    long long ans = 0;
    for (int sum = 0; sum <= MAXV; sum++) {
        if (dp[0][sum] <= W) { 
            ans = sum;
        }
    }

    cout << ans << "\n";
}
