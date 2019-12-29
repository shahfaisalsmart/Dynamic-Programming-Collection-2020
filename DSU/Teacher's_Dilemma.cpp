// Teacher's Dilemma
// BEGINNING WITH NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
// MY IVth DISJOINT UNION FIND PROBLEM
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
#include<math.h>
#define long long int ll
#define mo 1000000007
using namespace std;
//long long m = 1000000007;
ll root(ll* arr,ll val)
{
    while(arr[val]!=val)
    {
        val = arr[arr[val]];
    }
    return val;
}
void start(ll * arr, ll*size, ll n)
{
    for(ll i=1;i<=n;i++)
    {
        arr[i] = i;
        size[i] = 1;
    }
}
void friendShip(ll * arr, ll *size, ll a, ll b)
{
    ll CR1 = root(arr,a);
    ll CR2 = root(arr,b);
    if(CR1==CR2) return;
    if(size[CR2] < size[CR1]){
    arr[CR2] = CR1;
    size[CR1] +=size[CR2];
    size[CR2]  = 0;
    }
    else{
        arr[CR1] = CR2;
        size[CR2]+=size[CR1];
        size[CR1] =0;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flush();
    ll n,m;
    cin >> n >> m;
    ll * arr = new ll[n+1];
    ll * size = new ll[n+1];
    
    start(arr, size, n);
    
    while(m--)
    {
        ll a,b;
        cin >> a >> b;
        friendShip(arr, size, a, b);
    }
//    for(int i=1;i<=n;i++)
//        cout<<arr[i]<<" ";
//    cout<<endl;
//
//    for(int i=1;i<=n;i++)
//        cout<<size[i]<<" ";
//
//    cout<<m<<endl;
    ll res = 1;
    for(ll i=1;i<=n;i++)
    {
        if(size[i]!=0)
            res = (res%mo * size[i]%mo)%mo;
//            res = res*size[i];
    }
    cout<<res%mo<<endl;
    delete[] size;
    delete[] arr;
    return 0;
    // Bye Bye 2019
}


