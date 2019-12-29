// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n,k;
    cin >> n >> k;
    int temp = k;
    while(k--)
    {
        int a,b;
        cin >> a >> b;
    }
    cout<<n-temp;
    return 0;
}

// Method 2: Using DSU
// More Efficient and understandable.

// BEGINNING WITH NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
// MY IIIrd DISJOINT UNION FIND PROBLEM 
#include<bits/stdc++.h>
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

void start(int* arr, int* si,int n)
{
    for(int i=1;i<=n;i++)
    {
        arr[i] = i;
        si[i] = 1;
    }
}
void relationShip(int* arr ,int* size, int a, int b)
{
    int parent1 = root(arr,a);
    int parent2 = root(arr,b);
    if(parent1==parent2) return ;
    
    if(size[parent1] > size[parent2])
    {
        arr[parent2] = parent1;
        size[parent1] +=size[parent2];
    }
    else{
        arr[parent1] = parent2;
        size[parent2]+=size[parent1];
    }
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flush();
    int n,m;cin >> n >> m;
    int * arr = new int[n+1];
    int * si = new int[n+1];
    
    start(arr,si,n);
    while(m--)
    {
        int a,b;
        cin >> a >> b;
//        relationShip(arr,si,a,b);
        int town1 = root(arr,a);
        int town2 = root(arr,b);
        
        arr[town2] = town1;
    }
//    for(int i=1;i<=n;i++)
//        cout<<arr[i]<<" ";
//    cout<<endl;
    int distinct = 0;
    for(int i=1;i<=n;i++)
    {
        if(arr[i]==i) distinct++;
    }
    cout<<distinct;
    delete[] si;
    delete[] arr;
    return 0;
    // Bye Bye 2019
}



