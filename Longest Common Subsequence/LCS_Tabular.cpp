// Author:: Mohammad Faisal
// Email:: mohammad.faisal78612@gmail.com
// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH.
// bottom UP approach
#include<bits/stdc++.h>
using namespace std;
int solve(string x, string y,int m, int n)
{
	// int a=x.size();
	// int b=y.size();
	int table[m+1][n+1];
	
	for(int i=0;i<=m;i++)
		table[i][0] = 0;
		
	for(int j=0;j<=n;j++)
		table[0][j] = 0;
		
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<=n;j++)
		{
			if(x[i-1]==y[j-1])
				table[i][j] = table[i-1][j-1]+1;
			else
				table[i][j] = max(table[i-1][j],table[i][j-1]);
		}
	}
	return table[m][n];
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
