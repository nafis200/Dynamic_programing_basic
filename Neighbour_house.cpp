// #include<bits/stdc++.h>
// using namespace std;
// const int N = 25;
// int dp[N][N];
// int a[N][4];
// int n;
// int Neighbour_house(int i, int previous){
//      if(i == n){
//         return 0;
//      }
//      if(dp[i][previous] != -1){
//         return dp[i][previous];
//      }
//      int ans = 1e8;
//      for(int j = 0; j < 3; j++){
//          if(previous != j){
//             ans = min(ans, Neighbour_house(i + 1, j) + a[i][j]);
//          }
//      }
//      return dp[i][previous] = ans;
// }
// int main(){
//     memset(dp, -1, sizeof(dp));
//     cin >> n;
//     for(int i = 0; i < n; i++){
//         for(int j = 0; j < 3; j++){
//             cin >> a[i][j];
//         }
//     }

//     int ans = Neighbour_house(0,3);
//     cout << ans << "\n";
// }

#include <bits/stdc++.h>
using namespace std;
const int N = 25;
int dp[N][N];
int a[N][4];
int n;

int main()
{
     for (int i = 0; i <= N; i++) {
        for (int j = 0; j < 4; j++) {
            dp[i][j] = 1e8;
        }
    }
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < 3; j++)
        {
            cin >> a[i][j];
        }
    }

    for (int j = 0; j < 3; j++)
    {
        dp[n][j] = 0;
    }

    for (int i = n - 1; i >= 0; i--)
    {
        for (int prev = 0; prev <= 3; prev++)
        {
            for (int j = 0; j < 3; j++)
            {
                if (prev != j)
                {

                    dp[i][prev] = min(dp[i][prev], (dp[i + 1][j] + a[i][j]));
                }
            }
        }
    }

    cout << dp[0][3] << "\n";
}