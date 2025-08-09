// #include <bits/stdc++.h>
// using namespace std;
// const int N = 3030;
// int dp[N][N];
// string s, t;
// int a, b;

// int lcs(int i, int j)
// {
//     if (i == a or j == b)
//     {
//         return 0;
//     }
//     if (dp[i][j] != -1)
//     {
//         return dp[i][j];
//     }
//     int ans = 0;
//     if (s[i] == t[j])
//     {
//         ans = max(ans, lcs(i + 1, j + 1) + 1);
//     }
//     ans = max(ans, lcs(i + 1, j));
//     ans = max(ans, lcs(i, j + 1));

//     return dp[i][j] = ans;
// }

// void path(int i, int j){
//     if(i == a or j == b){
//         return;
//     }
//     if(s[i] == t[j]){
//         cout << s[i];
//         path(i + 1, j + 1);
//         return;
//     }
//     int first = lcs(i + 1, j);
//     int second = lcs(i, j + 1);
//     if(first >= second){
//         path(i + 1, j);
//     }
//     else{
//         path(i, j + 1);
//     }
// }

// int main()
// {
//     memset(dp, -1, sizeof(dp));
//     cin >> s >> t;
//     a = s.size();
//     b = t.size();
//     int ans = lcs(0, 0);
//     path(0, 0);
// }

// iterative way

//  if (s[i] == t[j])
// //     {
//         ans = max(ans, lcs(i + 1, j + 1) + 1);
//     }
//     ans = max(ans, lcs(i + 1, j));
//     ans = max(ans, lcs(i, j + 1));

//     return dp[i][j] = ans;



#include <bits/stdc++.h>
using namespace std;
const int N = 3030;
int dp[N][N];
string s, t;
int a, b;

void path(int i, int j){
    if(i == a or j == b){
        return;
    }
    if(s[i] == t[j]){
        cout << s[i];
        path(i + 1, j + 1);
        return;
    }
    int first = dp[i + 1][j];
    int second = dp[i][j + 1];
    if(first >= second){
        path(i + 1, j);
    }
    else{
        path(i, j + 1);
    }
}

int main()
{
    memset(dp, 0, sizeof(dp));
    cin >> s >> t;
    a = s.size();
    b = t.size();
    for(int i = a - 1; i >= 0; i--){
        for(int j = b - 1; j >= 0; j--){
           dp[i][j] = max(dp[i][j], dp[i + 1][j]);
           dp[i][j] = max(dp[i][j], dp[i][j + 1]);
           if(s[i] == t[j]){
             dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
           }
        }
    }
    path(0, 0);
}
