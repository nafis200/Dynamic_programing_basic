// #include<bits/stdc++.h>
// using namespace std;
// string s;
// const int N = 1005;
// int dp[N][N];

// int Palindrome(int i, int j){
//     if(i == j){
//         return 1;
//     }
//     if(i > j){
//         return 0;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }
//     int ans = 0;
//     ans = Palindrome(i + 1, j);
//     ans = max(ans, Palindrome(i, j - 1));
//     if(s[i] == s[j]){
//         ans = max(ans, 2 + Palindrome(i + 1, j - 1));
//     }
//     return dp[i][j] = ans;
// }

// int main(){
//     int t;
//     cin >> t;
//     while(t--){
//          cin >> s;
//          memset(dp, -1, sizeof(dp));
//          int ans = Palindrome(0, (s.size() - 1));
//          cout << ans << "\n";
//     }
// }


// iteartive way
//     ans = Palindrome(i + 1, j);
//     ans = max(ans, Palindrome(i, j - 1));
//     if(s[i] == s[j]){
//         ans = max(ans, 2 + Palindrome(i + 1, j - 1));
//     }
#include<bits/stdc++.h>
using namespace std;
string s;
const int N = 1005;
int dp[N][N];

int main(){
    int t;
    cin >> t;
    while(t--){
         cin >> s;
         memset(dp, 0, sizeof(dp));
         for(int i = 0; i < N; i++){
            dp[i][i] = 1;
         }
         int n = (int)s.size();
         for(int i = n - 2; i >= 0; i--){
            for(int j = i + 1; j < n; j++){
              dp[i][j] = dp[i + 1][j];
              dp[i][j] = max(dp[i][j], dp[i][j - 1]);
              if(s[i] == s[j]){
                dp[i][j] = max(dp[i][j], 2 + dp[i + 1][j - 1]);
              }
            }
         }
         cout << dp[0][n - 1] << "\n";
    }
}