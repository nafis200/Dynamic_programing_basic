#include<bits/stdc++.h>
using namespace std;
const int N = 205;
int m,d;
int a[N];
int dp[N][N][N];
int n, q;
int divisible_sum(int i, int cnt, int sum){
      if(i == n + 1){
         if(cnt == m and sum % d == 0){
            return 1;
         }
         return 0;
      }
      if(dp[i][cnt][sum] != -1){
        return dp[i][cnt][sum];
      }
      int ans = divisible_sum(i + 1, cnt, sum % d);
      ans = ans + divisible_sum(i + 1, cnt + 1, ((sum + a[i]) % d));
      return dp[i][cnt][sum] = ans;
}

int main(){
    
    int t; cin >> t;
    int Case = 1;
    while(t--){
        cin >> n >> q;
    for(int i = 1; i <= n; i++){
        cin >> a[i];
    }
 
    cout << "Case " << Case++ << ":" << "\n";
    while(q--){
        memset(dp, -1, sizeof(dp));
        cin >> d >> m;
        int ans = divisible_sum(1, 0, 0);
        cout << ans << "\n";
    }
    }
}