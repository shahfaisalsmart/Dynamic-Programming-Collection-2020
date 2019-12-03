//
//  main.cpp
//  SegmentTree Notes
//
//  Created by Faisal on 02/12/19.
//  Copyright © 2019 Faisal Programming. All rights reserved.
//
//  BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
//  AUTHOR:: MOHAMMAD FAISAL

#include <iostream>
#include <bits/stdc++.h>
using namespace std;
#define INF 999999999
int arr[1000006];
int tree[20000008];
void buildTree(int node, int start, int end)
{
    if(start == end)
    {
        // when only one node is present
        tree[node] = arr[start];
    }
    else
    {
        int mid = (start+end)/2;
        // left tree
        buildTree(2*node,start,mid);
        // right tree
        buildTree(2*node+1, mid+1,end);
        
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
}
void updateTree(int node,int start,int end, int ind, int val)
{
    if(start==end)
    {
        arr[ind] =val;
        tree[node]  =val;
    }
    else{
        int mid = (start+end)/2;
        if(ind>=start && ind<=mid)
        {
            updateTree(2*node, start, mid, ind, val);
        }
        else{
            updateTree(2*node+1, mid+1, end, ind, val);
        }
        tree[node] = min(tree[2*node],tree[2*node+1]);
    }
    
}
int queryTree(int node, int start, int end,int l, int r)
{
    // completely outside
    if(r<start || l>end)
    {
        return INF;
    }
    // completely inside
    if(l<=start && end<=r)
    {
        return tree[node];
    }
    int mid = (start+end)/2;
    
    int p1 = queryTree(2*node, start, mid, l, r);
    int p2 = queryTree(2*node+1, mid+1, end, l, r);
    
    return min(p1,p2);
}
int main(int argc, const char * argv[])
{
    
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
    // insert code here...
    // vector<int> v;
    // v.push_back(3);
    // cout<<v.size()<<endl;
    // cout << "Program starts now!\n";
    int n,q;
    cin >> n >> q;
    
    for(int i=1;i<=n;i++)
    {
        cin >> arr[i];
    }
    buildTree(1, 1, n);
    while(q--)
    {
        char c;
        cin >> c;
        if(c=='q'){
        int l,r;
        cin >> l >> r;
        int res = queryTree(1,1,n,l,r);
            cout<<res<<endl;
//            cout<<"FFF"<<endl;
        }
        else{
            int ind,vl;
            cin >> ind >> vl;
            updateTree(1,1,n,ind,vl);
        }
    }
    
    // cout <<"Bye Bye Faisal"<<endl;
    
    return 0;
}
