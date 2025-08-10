// #include<bits/stdc++.h>
// using namespace std;
// const int N = 105;
// int dp[N][10005];
// int n, k;
// int a[N];
// const int mod = 1e9 + 7;
// int candies(int i, int cnt){
//      if(i == n + 1){
//         if(cnt == k){
//             return 1;
//         }
//         return 0;
//      }
//      if(dp[i][cnt] != -1){
//         return dp[i][cnt];
//      }
//      int ans = 0;
//      for(int c = 0; c <= a[i]; c++){
//         ans += candies(i + 1, cnt + c) % mod;
//      }
//      return dp[i][cnt] = ans % mod;
// }
// int main(){
//     memset(dp, -1, sizeof(dp));
//     cin >> n >> k;
//     for(int i = 1; i <= n; i++){
//         cin >> a[i];
//     }
//     int candy = candies(1, 0);
//     cout << candy << "\n";

// }

// ans += candies(i + 1, cnt + c) % mod;

#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N + 5][10005];
int n, k;
int a[N];
const int mod = 1e9 + 7;

int main()
{
    memset(dp, 0, sizeof(dp));
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[n + 1][k] = 1;
    for (int i = n; i >= 1; i--)
    {
        for (int cnt = k; cnt >= 0; cnt--)
        {
            for (int c = 0; c <= a[i]; c++)
            {
                if (cnt + c <= k)
                {
                    dp[i][cnt] = (dp[i][cnt] % mod + dp[i + 1][cnt + c] % mod) % mod;
                }
            }
        }
    }

    cout << dp[1][0] << "\n";
}