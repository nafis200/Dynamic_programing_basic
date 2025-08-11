#include<bits/stdc++.h>
using namespace std;
const int N = 105;
string s,t;
int dp[N][N];
string new_string;

int LCS(int i, int j){
  if(i == s.size() or j == t.size()){
     return 0;
  }
  if(dp[i][j] != -1){
    return dp[i][j];
  }
  int ans = 0;
  ans = LCS(i + 1, j);
  ans = max(ans, LCS(i, j + 1));
  if(s[i] == t[j]){
    ans = max(ans, LCS(i + 1, j + 1) + 1);
  }
  return dp[i][j] = ans;

}

string path(int i, int j){
    if(i == s.size() or j == t.size()){
        return "";
    }
    if(s[i] == t[j]){
       return new_string = s[i] + path(i + 1, j + 1);
    }
    int first = LCS(i + 1, j);
    int second = LCS(i, j + 1);

    if(first > second){
       return path(i + 1, j);
    }
    else if(first < second){
       return path(i, j + 1);
    }
    else if(first == second){
        string s1 = path(i + 1, j);
        string s2 = path(i, j + 1);
        return min(s1,s2);
    }
    return new_string;
}

int main(){
    memset(dp, -1, sizeof(dp));

    cin >> s >> t;

   int ans = LCS(0, 0);
   cout << ans << "\n";
   new_string = "";
   string smallest_string = path(0, 0);
   cout << smallest_string << "\n";


}

