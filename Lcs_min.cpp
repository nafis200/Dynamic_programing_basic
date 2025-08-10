
// TLE
// #include <bits/stdc++.h>
// using namespace std;

// const int N = 3035;
// int dp[N][N];
// string memo[N][N]; 
// string s, t;
// int a, b;

// string path(int i, int j) {
//     if (i == a || j == b) return "";
//     if (!memo[i][j].empty()) return memo[i][j]; 

//     if (s[i] == t[j]) {
//         return memo[i][j] = string(1, s[i]) + path(i + 1, j + 1);
//     }

//     int first = dp[i + 1][j];
//     int second = dp[i][j + 1];

//     if (first > second) {
//         return memo[i][j] = path(i + 1, j);
//     } else if (first < second) {
//         return memo[i][j] = path(i, j + 1);
//     } else {
//         string s1 = path(i + 1, j);
//         string s2 = path(i, j + 1);
//         return memo[i][j] = min(s1, s2);
//     }
// }

// int main() {
//     ios::sync_with_stdio(false);
//     cin.tie(nullptr);

//     cin >> s >> t;
//     a = s.size();
//     b = t.size();

//     for (int i = a - 1; i >= 0; i--) {
//         for (int j = b - 1; j >= 0; j--) {
//             dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
//             if (s[i] == t[j]) {
//                 dp[i][j] = max(dp[i][j], dp[i + 1][j + 1] + 1);
//             }
//         }
//     }

//     cout << path(0, 0) << "\n";
// }


// this code accepted

#include <bits/stdc++.h>
using namespace std;

const int N = 3035;
int dp[N][N];
string s, t;
int a, b;

string getLCS() {
    int i = 0, j = 0;
    string res = "";
    while (i < a && j < b) {
        if (s[i] == t[j]) {
            res += s[i];
            i++; j++;
        }
        else if (dp[i + 1][j] > dp[i][j + 1]) {
            i++;
        }
        else if (dp[i + 1][j] < dp[i][j + 1]) {
            j++;
        }
        else {   
            j++;
        }
    }
    return res;
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cin >> s >> t;
    a = (int)s.size();
    b = (int)t.size();

    for (int i = a; i >= 0; i--) {
        for (int j = b; j >= 0; j--) {
            if (i == a || j == b) {
                dp[i][j] = 0;
            }
            else if (s[i] == t[j]) {
                dp[i][j] = 1 + dp[i + 1][j + 1];
            }
            else {
                dp[i][j] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
    }

    cout << getLCS() << "\n";
}
