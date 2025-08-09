// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1e5 + 9;
// int a[N][4];
// int dp[N][4];
// int n;
// int vacation(int i, int last){
//      if(i == n){
//         return 0;
//      }
//      if(dp[i][last] != -1){
//         return dp[i][last];
//      }
//      int ans = 0;
//      for(int k = 0; k < 3; k++){
//          if(k != last){
//             ans = max(ans,vacation(i + 1, k) + a[i][k]);
//          }
//      }
//     return dp[i][last] = ans;
// }

// int main(){
//    memset(dp,-1,sizeof(dp));
//     cin >> n;
//    for(int i = 0; i < n; i++){
//      for(int j = 0; j < 3; j++){
//         cin >> a[i][j];
//      }
//    }

//    int ans = vacation(0, 3);
//    cout << ans << "\n";

// }

// iterative

#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 9;
int a[N][4];
int dp[N][4];
int n;

int main()
{
    memset(dp, 0, sizeof(dp));
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = 0; i <= 3; i++){
        dp[n][i] = 0;
    }

    for(int i = n - 1; i >= 0; i--){
        for(int j = 0; j < 3; j++){
            for(int k = 0; k < 3; k++){
               if(j != k){
                 dp[i][j] = max(dp[i][j],dp[i + 1][k] + a[i][j]);
               }
            }
        }
    }
    cout << max({dp[0][0],dp[0][1],dp[0][2]}) << "\n";
}