// #include <bits/stdc++.h>
// using namespace std;
// const long long N = 105;
// long long dp[N][100006];
// long long a[N];
// long long n, x;
// const long long inf = 1e18;
// long long minimise_coin(long long i, long long sum)
// {
//     if (i == n + 1)
//     {
//         if (sum == x)
//         {
//             return 0;
//         }
//         return inf;
//     }
//     if (dp[i][sum] != -1)
//     {
//         return dp[i][sum];
//     }
//     long long ans = minimise_coin(i + 1, sum);
//     if (sum + a[i] <= x)
//     {
//         ans = min(ans, minimise_coin(i, sum + a[i]) + 1);
//     }
//     return dp[i][sum] = ans;
// }

// int32_t main()
// {
//     memset(dp, -1, sizeof(dp));
//     n, x;
//     cin >> n >> x;
//     for (long long i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     long long ans = minimise_coin(1, 0);
//     if(ans == inf){
//        cout << -1 << "\n";
//     }
//     else{
//         cout << ans << "\n";
//     }
// }

// #include <bits/stdc++.h>
// using namespace std;
// const long long N = 105;
// long long dp[N][100006];
// long long a[N];
// long long n, x;
// const long long inf = 1e17;

// int32_t main()
// {
//     for(int i = 0; i < N; i++){
//         for(int j = 0; j < 100006; j++){
//             dp[i][j] = inf;
//         }
//     }
//     cin >> n >> x;
//     for (long long i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     dp[n + 1][x] = 0;
//      for(int sum = 0; sum < x; sum++){ 
//         dp[n + 1][sum] = inf; 
//     } 

//     for(int i = n; i >= 1; i--){
//         for(int sum = x; sum >= 0; sum--){
//             dp[i][sum] = dp[i + 1][sum];
//             if(sum + a[i] <= x){
//                 dp[i][sum] = min(dp[i][sum], dp[i][sum + a[i]] + 1);
//             }
//         }
//     }
//     long long ans = dp[1][0];
//     cout << (ans >= inf ? -1 : ans) << "\n"; 
// }


#include<bits/stdc++.h> 
using namespace std; 
const int N = 105, X = 1e6 + 9, inf = 1e9; 
int n, x, a[N]; 
int dp[N][X]; 
#define ll long long 

int32_t main(){ 
    ios_base::sync_with_stdio(0); 
    cin.tie(0); 
    cin >> n >> x;     
    for(int i = 1; i <= n; i++) 
    cin >> a[i]; 
    dp[n + 1][x] = 0; 
    for(int sum = 0; sum < x; sum++){ 
        dp[n + 1][sum] = inf; 
    } 
    for(int i = n; i >= 1; i--){ 
        for(int sum = x; sum >= 0; sum--){ 
            int &ans = dp[i][sum]; 
            ans = dp[i + 1][sum]; 
            if(sum + a[i] <= x){ 
                ans = min(ans, dp[i][sum + a[i]] + 1); 
            } 
        } 
    } 
     cout << (dp[1][0] >= inf ? -1 : dp[1][0]) << "\n"; 
}