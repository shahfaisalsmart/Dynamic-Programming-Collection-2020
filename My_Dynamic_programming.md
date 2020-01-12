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


## C++ code with O(NlogN) time complexity `MOST EFFICIENT`

```cpp
// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL

#include<bits/stdc++.h>
using namespace std;
int solve(int * arr, int n)
{
    if(n==0)
        return 0;

    vector<int> dp(n,0);

    int length = 1;

    dp[0] = arr[0];

    for(int i=1;i<n;i++)
    {
        auto l = dp.begin(), r = dp.begin()+length;
        auto smallest_Element = lower_bound(l,r,arr[i]);

        if(smallest_Element == dp.begin() + length)
            dp[length++] = arr[i];
        else
            *smallest_Element = arr[i];
    }
    return length;
}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flush();

    int n; cin >> n;
    int * arr = new int[n];
    
    for(int i=0;i<n;i++)
        cin >> arr[i];

    int res = solve(arr,n);

    cout<<"length is: "<<res;
    delete[] arr;
    return 0;
}
```
---
## Dynamic Programming - `2`
### Minimum number of Fibonacci jumps to reach end

Find the length of the longest subsequence of a given sequence such that all elements of the subsequence are sorted in increasing order.

#### `Input Format`
First line is giving as N as Number of total element in an array.
second line contains a<sub>1</sub>,a<sub>2</sub>,a<sub>3</sub>,a<sub>4</sub>,......a<sub>N</sub> as elements.

#### `Output Format`
Single integer which represent the length of the longest increasing subsequence.

#### Input 1


#### Output 1



## C++ code 

```cpp
    COMING SOON
```
---

## Dynamic Programming - `3`
### Longest Common Subsequence 
Given two sequences, find the length of longest subsequence present in both of them. A subsequence is a sequence that appears in the same relative order, but not necessarily contiguous.

> For example, “abc”, “abg”, “bdf”, “aeg”, ‘”acefg”, .. etc are subsequences of “abcdefg”.

**`Examples`**:
- LCS for input Sequences “ABCDGH” and “AEDFHR” is “ADH” of length 3.
- LCS for input Sequences “AGGTAB” and “GXTXAYB” is “GTAB” of length 4.

#### `Input Format`
First line given first string s, second line given second string t;

#### `Output Format`
Single integer which represent the length of the longest common subsequence.

#### Input 1
abcd
bcde

#### Output 1
3

## C++ code `Recursive`

```cpp
    // BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL

#include<bits/stdc++.h>
using namespace std;
int solve(string s, string t, int n, int m)
{
    if(n==0 || m==0)
        return 0;

    if(s[n-1]==t[m-1])
        return 1+solve(s,t,n-1,m-1);
    else 
        return max(solve(s,t,n,m-1),solve(s,t,n-1,m));

}
int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.flush();

    string s;
    cin >> s;
    int n = s.size();
    string t;
    cin >> t;
    int m = t.size();
    int res = solve(s,t,n,m);
    cout<<res<<endl;
    return 0;
}
```

### C++ code `Iteratative`
```c++


```
---
