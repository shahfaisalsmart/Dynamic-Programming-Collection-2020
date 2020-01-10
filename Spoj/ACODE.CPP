// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
// SPOJ: ALPHACODE
#include<bits/stdc++.h>
using namespace std;

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flush();

    int len;
    int dp[5002];

    while(true)
    {
        string s;
        cin >> s;

        if(s[0] =='0') break;

        len = s.size();

        dp[0]=1;
        dp[1]=1;

        for(int i=2;i<=len;i++)
        {
            dp[i] = 0;

            int a = s[i-2] -'0';
            int b = s[i-1] - '0';

            if(a==1 || (a==2 && b<=6)) dp[i]+=dp[i-2];
            if(b!=0) dp[i]+=dp[i-1];
        }
        
        cout<<dp[len];
        cout<<"\n";
    }
    return 0;
}
