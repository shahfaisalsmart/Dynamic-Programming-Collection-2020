Method: 1 Partially Accepted

// BEGINNING WITH NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
// MY VIIth DISJOINT UNION FIND PROBLEM
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<math.h>
#define ll long long
#define mo 1000000007
using namespace std;
//long long m = 1000000007;
struct Men{
    ll mn;
    ll wn;
};
ll root(ll* arr, ll val)
{
    while(arr[val]!=val)
    {
        val = arr[arr[val]];
    }
    return val;
}
void relationship(ll* arr,ll* size, ll a, ll b)
{
    ll parent1 = root(arr,a);
    ll parent2 = root(arr,b);
    if(parent1==parent2)
        return ;
//    cout<<"Root: "<<a<<" : "<<parent1<<" "<<"Root: "<<b<<" : "<<parent2<<endl;
    if(size[parent1] < size[parent2])
    {
        arr[parent1] = parent2;
        size[parent2]+=size[parent1];
        size[parent1] = 0;
    }
    else{
        arr[parent2] = parent1;
        size[parent1]+=size[parent2];
        size[parent2] =0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flush();
    ll n,m;
    cin >> n >> m;
    ll temp2=m;
    ll * arr = new ll[n+1];
    ll * wrr = new ll[m+1];
    Men * parent = new Men[n+1];
    ll * women = new ll[m+1];
    ll * men = new ll[n+1];
    for(ll i=1;i<=n;i++)
    {
        arr[i] = i;
        men[i] = 1;
    }
    for(ll i=1;i<=m;i++)
    {
        wrr[i] = i;
        women[i] = 1;
    }
    int q1,q2,q3;
    cin >> q1;
    while(q1--)
    {
        ll a,b;
        cin >> a >> b;
        relationship(arr, men, a, b);
    }
    for(int i=1;i<=n;i++)
    {
        parent[i].mn = men[i];
        parent[i].wn = 0;
    }
    cin >> q2;
    
    while(q2--)
    {
        ll a,b;cin >> a >> b;
        relationship(wrr, women, a, b);
    }
    
    cin >> q3;
    ll unique_Marriage = 0;
    while(q3--)
    {
        
        ll m,w;
        cin >> m >> w;
        ll parent1 = root(arr,m);
        ll parent2 = root(wrr,w);
        
        parent[parent1].mn = men[parent1];
        if(parent[parent1].wn>=temp2)
            continue;
        parent[parent1].wn += women[parent2];
    }
//    for(int i=1;i<=n;i++)
//        cout<<arr[i]<<" size: "<<men[i]<<endl;
//    cout<<"womens:: "<<endl;
//    for(int i=1;i<=n;i++)
//        cout<<wrr[i]<<" size: "<<women[i]<<endl;
//    cout<<"Groups:: "<<endl;
//    for(int i=1;i<=n;i++)
//    {
//        cout<<"men: "<<parent[i].mn<<" women: "<<parent[i].wn<<endl;
//    }
    for(int i=1;i<=n;i++)
    {
        unique_Marriage += (parent[i].mn)*(temp2-parent[i].wn);
    }
    cout<<unique_Marriage<<endl;
    return 0;
    // Bye Bye 2019
}

