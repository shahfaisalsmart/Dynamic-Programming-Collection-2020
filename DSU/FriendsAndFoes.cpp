// BEGINNING WITH NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
// MY VIth DISJOINT UNION FIND PROBLEM
// HackerEarth Problems
#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<math.h>
#include<map>
#include<algorithm>
#define ll long long
#define mo 1000000007
using namespace std;
//long long m = 1000000007;
void start(ll* arr,ll * size, ll n)
{
    for(ll i=1;i<=n;i++)
    {
        arr[i] = i;
        size[i] = 1;
    }
}
ll root(ll* arr,ll val)
{
    while(arr[val]!=val)
    {
        val = arr[arr[val]];
    }
    return val;
}
void friendShip(ll * arr, ll* size, ll a, ll b)
{
    ll parent1 = root(arr, a);
    ll parent2 = root(arr, b);
    
    if(parent1 == parent2)
        return;
    
    if(size[parent1] > size[parent2])
    {
        arr[parent2] = parent1;
        size[parent1]+= size[parent2];
        size[parent2]=0;
    }
    else
    {
        arr[parent1] = parent2;
        size[parent2]+= size[parent1];
        size[parent1] =0;
    }
}
ll isEnemy(ll * parent, ll c, ll d)
{
    ll person1 = root(parent,c);
    ll person2 = root(parent,d);
    
    if(person1!=person2)
        return -1;
    else
        return person1;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flush();
    ll n,m;
    cin >> n >> m;
    ll* parent = new ll[n+1];
    ll* size = new ll[n+1];
    start(parent,size,n);
    while(m--)
    {
        ll a,b;
        cin >> a >> b;
        friendShip(parent, size, a, b);
    }
//    for(int i=1;i<=n;i++)
//    {
//        cout<<parent[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=1;i<=n;i++)
//    {
//        cout<<size[i]<<" ";
//    }
//    cout<<endl;
    ll k;
    cin >> k;
    while(k--)
    {
        ll c,d;
        cin >> c >> d;
        if(isEnemy(parent, c, d) == -1)
            continue;
        else
            size[isEnemy(parent, c, d)] = 0;
    }
//    for(int i=1;i<=n;i++)
//    {
//        cout<<parent[i]<<" ";
//    }
//    cout<<endl;
//    for(int i=1;i<=n;i++)
//    {
//        cout<<size[i]<<" ";
//    }
//    cout<<endl;
    ll member = 0;
    for(ll i=1;i<=n;i++)
        member = max(member,size[i]);
    cout<<member<<endl;
    delete[] size;
    delete[] parent;
//    mp.clear();
    return 0;
    // Bye Bye 2019
}


