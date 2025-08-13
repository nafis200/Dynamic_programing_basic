#include<bits/stdc++.h> 
using namespace std; 
const int N = 105, inf = 1e9; 
int col[N], dp[N][N], pref[N]; 
int get_sum(int l, int r){ 
  int sum = 0; 
  // for(int i = 1; i <= r; i++){ 
  //   sum += col[i]; 
  //   sum %= 100; 
  // } 
  sum = (pref[r] - pref[l - 1]) % 100; 
  return sum; 
} 
 
int f(int l, int r){ 
  if(l == r) 
  return 0; 
  int &ans = dp[l][r]; 
  if(ans != -1) 
  return ans; 
  ans = inf; 
  for(int i = l; i < r; i++){ 
    int a = get_sum(l, i), b = get_sum(i + 1, r); 
    int cost = a * b; 
    ans = min(ans, cost + f(l, i) + f(i + 1, r)); 
  } 
  return ans; 
} 
int main(){ 
  int n; 
  while(cin >> n){ 
    for(int i = 1; i <= n; i++) 
    cin >> col[i]; 
    for(int i = 1; i <= n; i++){ 
      pref[i] = pref[i - 1] + col[i]; 
    } 
    memset(dp, -1, sizeof(dp)); 
    cout << f(1, n) << "\n"; 
  } 
} 