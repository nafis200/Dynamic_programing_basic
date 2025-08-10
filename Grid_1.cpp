// #include<bits/stdc++.h>
// using namespace std;
// const int N = 1005;
// int dp[N][N];
// char a[N][N];
// const int inf = -1e9;
// int h,w;
// const int mod = 1e9 + 7;

// int grid(int i, int j){
//     if(i == h and j == w){
//         return 1;
//     }
//     if(i > h or j > w){
//         return 0;
//     }
//     if(a[i][j] == '#'){
//         return 0;
//     }
//     if(dp[i][j] != -1){
//         return dp[i][j];
//     }

//     int ans = 0;
//     ans = (ans % mod + grid(i + 1, j) % mod) % mod;
//     ans = (ans % mod + grid(i, j + 1) % mod) % mod;
//     return dp[i][j] = ans % mod;;
    
// }

// int main(){
//     memset(dp, -1, sizeof(dp));
//     cin >> h >> w;
//     for(int i = 1; i <= h; i++){
//         for(int j = 1; j <= w; j++){
//             cin >> a[i][j];
//         }
//     }
//     int ans = grid(1 ,1);
//     cout << ans << "\n";

// }

//     ans = (ans % mod + grid(i + 1, j) % mod) % mod;
//     ans = (ans % mod + grid(i, j + 1) % mod) % mod;

#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
int dp[N][N];
char a[N][N];
const int inf = -1e9;
int h,w;
const int mod = 1e9 + 7;

int main(){
    memset(dp, 0, sizeof(dp));
    cin >> h >> w;
    for(int i = 1; i <= h; i++){
        for(int j = 1; j <= w; j++){
            cin >> a[i][j];
        }
    }
    dp[h][w] = 1;
    for(int i = h; i >= 1; i--){
        for(int j = w; j >= 1; j--){
            if(a[i][j] == '#'){
                continue;
            }
            if (i + 1 <= h) dp[i][j] = (dp[i][j] + dp[i + 1][j]) % mod;
            if (j + 1 <= w) dp[i][j] = (dp[i][j] + dp[i][j + 1]) % mod;
        }
    }

    cout << dp[1][1] << "\n";
}

