// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL

#include<bits/stdc++.h>
using namespace std;
bool isvalid(vector<int>&v, int ans, int stu)
{
    int n = (int)v.size();
    int count = 1;
    int curr = 0;
    for(int i=0;i<n;i++)
    {
        if(curr+v[i] > ans)
        {
            curr = v[i];
            count++;
            if(count>stu)
                return false;
        }
        else{
            curr+=v[i];
        }
    }
    return true;
}
int binarySearch(vector<int>&v, int m)
{
    int n = (int)v.size();
    if(n<m) return -1;
    int ans = -1;
    int pages = 0;
    for(int i=0;i<n;i++)
        pages+=v[i];
    
    int low = 0, high = pages;
    while(low<=high)
    {
        int mid = low+(high-low)/2;
        if(isvalid(v,mid,m))
        {
            ans = mid;
            high = mid-1;
        }
        else{
            low = mid+1;
        }
    }
    return ans;
}
int main()
{
    #ifdef ONLINE_JUDGE
        freopen("input.txt","r",stdin);
        freopen("output.txt","w",stdout);
    #endif
    int n;cin >> n;
    int k;
    cin >> k;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }

    int ans = binarySearch(v,k);
    cout<<ans<<endl;
    return 0;
}

