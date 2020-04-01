// AUTHOR:: MOHAMMAD FAISAL
// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
#include<bits/stdc++.h>
using namespace std;
const int mod = 10000003;
int validpainter(vector<int>&v, int ans)
{
    int painter = 1;
    int timeReq=0;
    for(int i=0;i<(int)v.size();i++)
    {
        timeReq+=v[i];
        if(timeReq>ans)
        {
            painter++;
            timeReq = v[i];
        }
    }
    return painter;
}
int binarySearch(vector<int>&v,int painters, int time)
{
    int lowerTime = *max_element(v.begin(),v.end());
    int higherTime = 0;
    for(int i=0;i<(int)v.size();i++)
    {
        higherTime+=v[i];
    }
    int ans = 0;
    while(lowerTime<=higherTime)
    {
        int midTime = lowerTime+(higherTime-lowerTime)/2;
        if(validpainter(v,midTime)<=painters)
        {
            ans = midTime;
            higherTime = midTime-1;
        }
        else{
            lowerTime = midTime+1;
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
    int painters,time;
    cin >> painters >> time;
    vector<int> v;
    for(int i=0;i<n;i++)
    {
        int x;
        cin >> x;
        v.push_back(x);
    }
    
    int ans = binarySearch(v,painters,time);
    cout<< (((ans%mod)*(time%mod))%mod);
    return 0;
}




