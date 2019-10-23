// Author:: Mohammad Faisal
// Email:: mohammad.faisal78612@gmail.com
// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH.
#include<bits/stdc++.h>
using namespace std;
int solve(string x, string y,int m, int n)
{
	// int a=x.size();
	// int b=y.size();
	if(m==0 || n==0)
		return 0;
	if(x[m-1] == y[n-1])
	{
		return solve(x,y,m-1,n-1)+1;
	}
	
	return max(solve(x,y,m-1,n),solve(x,y,m,n-1));
}
int main()
{
	string x,y;
	cin >> x;
	cin >> y;
	int m=x.length();
	int n= y.length();
	cout<<solve(x,y,m,n)<<endl;
	return 0;
}
