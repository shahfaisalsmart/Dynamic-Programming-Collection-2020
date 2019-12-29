// BEGINNING WITH NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
// MY Vth DISJOINT UNION FIND PROBLEM
// HackerEarth 
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#define ll long long
#define mo 1000000007
using namespace std;
//long long m = 1000000007;
ll power(ll k, ll h)
{
    ll x=1, y=k;
    while(h>0)
    {
        if(h%2==1)
        {
            x = (x*y);
            if(x > mo) x%=mo;
        }
        y = (y*y);
        if(y>mo) y%=mo;
        h/=2;
    }
    return x;
}
void start(ll * arr, ll n)
{
    for(int i=1;i<=n;i++)
    {
        arr[i] = i;
    }
}

ll root(ll* arr, ll val)
{
    while(arr[val]!=val)
    {
        val = arr[arr[val]];
    }
    return val;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flush();
    ll n,m;
    cin >> n >> m;
    ll * arr = new ll[n+1];
//    ll * size = new ll[n+1];
    start(arr, n);
    while(m--)
    {
        ll x,y;
        cin >> x >> y;
        for(ll a=x,b=y;a<b;a++,b--)
        {
            ll parent1 = root(arr,a);
            ll parent2 = root(arr,b);
            
            if(parent1!=parent2)
                arr[parent2] = parent1;
        }
    }
    map<ll,ll> mp;
    for(int i=1;i<=n;i++)
        mp[root(arr,i)]++;
    
    ll temp = mp.size();
    ll res = power(10,temp);
    cout<<res%mo<<endl;
//    delete[] size;
    delete[] arr;
    mp.clear();
    return 0;
    // Bye Bye 2019
}
