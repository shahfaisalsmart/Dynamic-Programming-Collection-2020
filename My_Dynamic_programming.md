# Beginning with the name of ALLAH-SUBHANA-WATA-ALLAH

## My Dynamic Programming kickstart

- AUTHOR:: **MOHAMMAD FAISAL**
- This is a series of **dynamic programming** classical with is very helpful during interview preparation.


## Dynamic Programming - `1`
### Longest Increasing Subsequence 

Find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.

#### `Input Format`
First line is giving as N as Number of total element in an array.
second line contains a<sub>1</sub>,a<sub>2</sub>,a<sub>3</sub>,a<sub>4</sub>,......a<sub>N</sub> as elements.

#### `Output Format`
Single integer which represent the length of the longest increasing subsequence.

#### Input 1

5

[3, 10, 2, 1, 20]

#### Output 1
3

## C++ code with O(N<sup>2</sup>) time complexity

```cpp
// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
#include<bits/stdc++.h>
using namespace std;
int solve(int * arr, int n)
{
    int * dp = new int[n];

    dp[0] = 1;

    for(int i=1;i<n;i++)
    {
        dp[i] = 1;
        for(int j=0;j<i;j++)
        {
            if(arr[i]<arr[j] && dp[i] < dp[j]+1)
                dp[i] = dp[j] +1;
        }
    }
    int res = *max_element(dp,dp+n);
    delete[] dp;
    return res;
}
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flush();

    int n;
    cin >> n;

    int * arr = new int[n];

    for(int i=0;i<n;i++)
    {
        cin >> arr[i];
    }

    int result = solve(arr,n);
    cout<<"length is: "<< result;
    return 0;
}
```
