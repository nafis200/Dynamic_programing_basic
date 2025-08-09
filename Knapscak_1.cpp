// #include<bits/stdc++.h>
// using namespace std;
// const long long N = 105;
// long long a[N];
// long long w[N];
// long long dp[N][100007];
// long long n, v;
// const long long inf = -1e9;
// long long knapsack(long long i, long long weight){
//     if(i == n){
//         return 0;
//     }
//     if(dp[i][weight] != -1){
//         return dp[i][weight];
//     }
//     long long sum = knapsack(i + 1, weight);
//     if(weight + w[i] <= v){
//         sum = max(sum, knapsack(i + 1, w[i] + weight) + a[i]);
//     }
//     return dp[i][weight] = sum;
// }
// int32_t main(){
//     memset(dp,-1,sizeof(dp));
//     cin >> n >> v;
//     for(long long i = 0; i < n; i++){
//         cin >> w[i] >> a[i];
//     }

//     long long ans = knapsack(0, 0);
//     cout << ans << "\n";
// }


// iterative way

#include<bits/stdc++.h>
using namespace std;
const long long N = 105;
long long a[N];
long long w[N];
long long dp[N][100007];
long long n, v;
const long long inf = -1e9;

int32_t main(){
    memset(dp,0,sizeof(dp));
    cin >> n >> v;
    for(long long i = 0; i < n; i++){
        cin >> w[i] >> a[i];
    }

    for(int i = n - 1; i >= 0; i--){
        for(int weight = 0; weight <= v; weight++){
            dp[i][weight] = dp[i + 1][weight];
            if(w[i] + weight <= v){
                dp[i][weight] = max(dp[i][weight], dp[i + 1][weight + w[i]] + a[i]);
            }
        }
    }

    cout << dp[0][0] << "\n";

    
}