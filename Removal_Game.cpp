#include<bits/stdc++.h> 
using namespace std; 
const int N = 3005; 
int a[N]; 
int n; 
long long dp[N][N]; 
bool vis[N][N]; 
long long dp1[N][N]; 
bool vis1[N][N]; 
long long f2(int ,int); 
long long f1(int l, int r){ 
    if(l > r) return 0; 
    if(vis[l][r]) 
    return dp[l][r]; 
    long long score_left = a[l] + f2(l + 1, r); 
    long long score_right = a[r] + f2(l, r - 1); 
    vis[l][r] = true; 
    return dp[l][r] = max(score_left, score_right); 
} 
long long f2(int l, int r){ 
     if(l > r) return 0; 
     if(vis1[l][r]) 
    return dp1[l][r]; 
    long long score_left = f1(l + 1, r); 
    long long score_right = f1(l, r - 1); 
    vis1[l][r] = true; 
    return dp1[l][r] = min(score_left, score_right); 
} 
int main(){ 
     memset(vis, false, sizeof(vis)); 
     memset(vis1, false, sizeof(vis1)); 
     cin >> n; 
     for(int i = 1; i <= n; i++) 
     cin >> a[i]; 
     cout << f1(1, n) << "\n"; 
} 
 