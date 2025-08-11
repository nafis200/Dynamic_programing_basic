#include<bits/stdc++.h>
using namespace std;
const int N = 25;
int dp[N][N];
int a[N][4];
int n;
int Neighbour_house(int i, int previous){
     if(i == n){
        return 0;
     }
     if(dp[i][previous] != -1){
        return dp[i][previous];
     }
     int ans = 1e8;
     for(int j = 0; j < 3; j++){
         if(previous != j){
            ans = min(ans, Neighbour_house(i + 1, j) + a[i][j]);
         }
     }
     return dp[i][previous] = ans;
}
int main(){
    memset(dp, -1, sizeof(dp));
    cin >> n;
    for(int i = 0; i < n; i++){
        for(int j = 0; j < 3; j++){
            cin >> a[i][j];
        }
    }

    int ans = Neighbour_house(0,3);
    cout << ans << "\n";
}