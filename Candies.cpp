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

// #include <bits/stdc++.h>
// using namespace std;
// const int N = 105;
// int dp[N + 5][10005];
// int n, k;
// int a[N];
// int prefix[100][10005];
// const int mod = 1e9 + 7;

// int main()
// {
//     memset(dp, 0, sizeof(dp));
//     memset(prefix, 0, sizeof(prefix));
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     dp[n + 1][k] = 1;
   

//     for (int i = n; i >= 1; i--)
//     {
//         for (int cnt = k; cnt >= 0; cnt--)
//         {
//             cout << "[" << i << "]" << "[" << cnt << "]" << "\n";
//             for (int c = 0; c <= a[i]; c++)
//             {
//                 if (cnt + c <= k)
//                 {
//                     dp[i][cnt] = (dp[i][cnt] % mod + dp[i + 1][cnt + c] % mod) % mod;
//                     cout << "[" << i + 1 << "]" << "[" << (cnt + c) << "]" << " ";
//                 }
//             }
//             cout << "\n";
            
//         }
    
//     }
   
//     cout << "final..................\n";
//     for(int i = n + 1; i >= 0; i--){
//         for(int cnt = k; cnt >= 0; cnt--){
//             cout << dp[i][cnt] << " ";
//         }
//         cout << "\n";
//     }

//     cout << dp[1][0] << "\n";
// }









// #include <bits/stdc++.h>
// using namespace std;
// const int N = 105;
// int dp[N + 5][10005];
// int n, k;
// int a[N];
// int prefix[100][10005];
// const int mod = 1e9 + 7;

// int main()
// {
//     memset(dp, 0, sizeof(dp));
//     memset(prefix, 0, sizeof(prefix));
//     cin >> n >> k;
//     for (int i = 1; i <= n; i++)
//     {
//         cin >> a[i];
//     }
//     dp[n + 1][k] = 1;
//     prefix[n + 1][k] = 1;
   

//     for (int i = n; i >= 1; i--)
//     {
//         for (int cnt = k; cnt >= 0; cnt--)
//         {
            
//             // for (int c = 0; c <= a[i]; c++)
//             // {
//             //     if (cnt + c <= k)
//             //     {
//             //         dp[i][cnt] = (dp[i][cnt] % mod + dp[i + 1][cnt + c] % mod) % mod;
                    
//             //     }
//             // }
//             int mn = min(k, cnt + a[i]);
//             dp[i][cnt] = dp[i][cnt] + (prefix[i + 1][mn] - (cnt == 0 ? 0 : prefix[i + 1][cnt - 1])) % mod;
          
//         }
//         for(int j = 0; j <= k; j++){
//             prefix[i][j] = (j == 0 ? 0 : prefix[i][j - 1]) + dp[i][j];
//         }
    
//     }

//     for(int i = 1; i <= n + 1; i++){
//         for(int cnt = 0; cnt <= k; cnt++){
//             cout << prefix[i][cnt] << " ";
//         }
//         cout << "\n";
//     }

//     // for(int i = 1; i <= n + 1; i++){
//     //     for(int cnt = 0; cnt <= k; cnt++){
//     //         cout << dp[i][cnt] << " ";
//     //     }
//     //     cout << "\n";
//     // }
   
   

//     cout << dp[1][0] << "\n";
// }



// Now optimise way

#include <bits/stdc++.h>
using namespace std;
const int N = 105;
int dp[N + 5][100005];
int n, k;
int a[N];
int prefix[N + 5][100005];
const int mod = 1e9 + 7;

int main()
{
    memset(dp, 0, sizeof(dp));
    memset(prefix, 0, sizeof(prefix));
    cin >> n >> k;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    dp[n + 1][k] = 1;
    prefix[n + 1][k] = 1;
   

    for (int i = n; i >= 1; i--)
    {
        for (int cnt = k; cnt >= 0; cnt--)
        {
            int mn = min(k, cnt + a[i]);
            if(cnt == 0){
                dp[i][cnt] = (dp[i][cnt] % mod + (prefix[i + 1][mn])) % mod;
            }
            else{
                dp[i][cnt] = (dp[i][cnt] % mod + ((prefix[i + 1][mn] - prefix[i + 1][cnt - 1]) + mod) % mod) % mod;
            }
          
        }
        for(int j = 0; j <= k; j++){
            prefix[i][j] = ((j == 0 ? 0 : prefix[i][j - 1]) % mod + dp[i][j] % mod) % mod;
        }
    
    }

    cout << dp[1][0] << "\n";
}