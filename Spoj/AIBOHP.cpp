// AUTHOR:: MOHAMMAD FAISAL
// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
#include<bits/stdc++.h>
using namespace std;
int solve(string s)
{
    int n = s.size();
    int dp[n][n];
 
    for(int i=0;i<n;i++)
        for(int j=0;j<n;j++)
            dp[i][j] = 0;
 
    for(int i=1;i<n;i++)
    {
        for(int l=0,h=i; h<n;l++,h++)
        {
            dp[l][h] = (s[l]==s[h]) ? dp[l+1][h-1]: (min(dp[l][h-1],dp[l+1][h])+1);
        }
    }
    int res = dp[0][n-1];
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flush();
 
    int n;
    cin >>n;
    while(n--){
    string s;
    cin >> s;
    // int dp[n][n];
    int res = solve(s);
    cout<<res<<endl;
    }
    return 0;
 
}
 
