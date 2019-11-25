/*

Given an integer N, print the factorial of the N (mod 1000000007).

Input:
First line contains one integer, T, number of test cases.
Each test case contains one integer, N.

Output:
For each test case you need to print the factorial of N (mod 1000000007).

Constraints:

1<=T<=10^5
0<=n<=10^5

SAMPLE INPUT 
5
1
2
3
4
5
SAMPLE OUTPUT 
1
2
6
24
120
*/
// Author:: Mohammad Faisal
// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
#include<bits/stdc++.h>
using namespace std;
int * dp = new int[100006];
void In()
{
    dp[0] = 1;
    dp[1] = 1;
    for(int i=2;i<=100006;i++)
        dp[i] = (dp[i-1]%1000000007)*(i%10000000007)%1000000007;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    
    In();
    
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        cout<<dp[n]%1000000007<<endl;
    }
    return 0;
}
