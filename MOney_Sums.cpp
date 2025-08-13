#include <bits/stdc++.h>
using namespace std;
int n;
const int N = 105;
bool dp[N][100001];
int a[N];
vector<int> v;

void Money_sum(int i, int sum)
{
    if (i == n + 1)
    {
        if (sum != 0)
        {
            v.push_back(sum);
        }
        return;
    }
    if (dp[i][sum] == true)
    {
        return;
    }
    dp[i][sum] = true;
    Money_sum(i + 1, sum);
    Money_sum(i + 1, sum + a[i]);

    return;
}

int main()
{
    memset(dp, false, sizeof(dp));
    cin >> n;
    for (int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }

    Money_sum(1, 0);
    sort(v.begin(), v.end());
    auto it = unique(v.begin(), v.end());
    v.erase(it, v.end());
    cout << v.size() << "\n";
    for (auto x : v)
    {
        cout << x << " ";
    }
}