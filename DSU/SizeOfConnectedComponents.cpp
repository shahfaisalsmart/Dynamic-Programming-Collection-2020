// BEGINNING WITH NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
// MY FIRST DISJOINT UNION FIND PROBLEM
//#include<bits/stdc++.h>
#include<iostream>
#include<vector>
using namespace std;
int root(int* arr, int ele)
{
    while(arr[ele]!=ele)
    {
        ele = arr[arr[ele]];
    }
    return ele;
}
void start(int* arr, int*s,int n)
{
    for(int i=1;i<=n;i++)
    {
        arr[i] = i;
        s[i] = 1;
    }
}
void merge(int* arr, int* s, int x, int y)
{
    int parent1 = root(arr,x);
    int parent2 = root(arr,y);
    
    if(s[parent1] < s[parent2])
    {
        arr[parent1] = parent2;
        s[parent2]+=s[parent1];
        s[parent1] *= -1;
    }
    else{
        arr[parent2] = parent1;
        s[parent1]+=s[parent2];
        s[parent2] *= -1;
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flush();
    int n,m;cin >> n >> m;
    int * arr = new int[n+1];
    int * s = new int[n+1];
    
    start(arr,s,n);

//    for(int i=1;i<=n;i++)
//        cout<<arr[i]<<" ";
//    cout<<endl;
//
//    for(int i=1;i<=n;i++)
//        cout<<s[i]<<" ";
//    cout<<endl;
    while(m--)
    {
        int a,b;
        cin >> a >> b;
        vector<int> copy;
        merge(arr,s,a,b);
        for(int i=1;i<=n;i++)
            if(s[i]>0) copy.push_back(s[i]);
        
        sort(copy.begin(),copy.end());
        for(auto &k: copy)
            cout<<k<<" ";
        cout<<endl;
    }
    return 0;
    // Bye Bye 2019
}


