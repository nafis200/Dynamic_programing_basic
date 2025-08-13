#include<bits/stdc++.h>
using namespace std;
const int N = 5002;
int dp[N][N];
string s, t;
int n, m;
int Edit_distance(int i, int j){
      if(i == n){
        return m - j;
      }
      if(j == m){
        return n - i;
      }
      if(dp[i][j] != -1){
        return dp[i][j];
      }
      int ans = 1e8;
      if(s[i] == t[j]){
          ans = min(ans, Edit_distance(i + 1, j + 1));
          return dp[i][j] = ans;
      }
      ans = min(ans, Edit_distance(i, j + 1) + 1);
      ans = min(ans,Edit_distance(i + 1, j) + 1);
      ans = min(ans,Edit_distance(i + 1, j + 1) + 1);
      return dp[i][j] = ans;
}
int main(){
    memset(dp, -1 ,sizeof(dp));
    cin >> s >> t;
    n = (int)s.size();
    m = (int)t.size();
    int ans = Edit_distance(0, 0);
    cout << ans << "\n";
}