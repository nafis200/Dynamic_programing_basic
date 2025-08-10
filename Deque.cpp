#include<bits/stdc++.h>
using namespace std;
long long n;
const long long N = 3005;
bool vis[N][N];
bool vis1[N][N];
long long dp[N][N];
long long dp1[N][N];
long long a[N];
long long f2(long long,long long);
long long f1(long long l, long long r){
    if(l > r){
        return 0;
    }
    if(vis[l][r] == true){
        return dp[l][r];
    }
    long long ans = a[l] + f2(l + 1, r);
    long long ans1 = a[r] + f2(l, r - 1);
    vis[l][r] = true;
    return dp[l][r] = max(ans,ans1);
}
long long f2(long long l, long long r){
    if(l > r){
        return 0;
    }
    if(vis1[l][r] == true){
        return dp1[l][r];
    }
    long long ans = -a[l] + f1(l + 1, r);
    long long ans1 = -a[r] + f1(l, r - 1);
    vis1[l][r] = true;
    return dp1[l][r] = min(ans,ans1);
}
int32_t main(){
  cin >> n;
  for(long long i = 1; i <= n; i++){
    cin >> a[i];
  }
  memset(dp,0,sizeof(dp));
  memset(dp1,0,sizeof(dp1));
  memset(vis,false,sizeof(vis));
  memset(vis1,false,sizeof(vis1));
  long long ans = f1(1, n);
  cout << ans << "\n";

}