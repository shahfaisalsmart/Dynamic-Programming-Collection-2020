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

## C++ code `Iteratative`
```c++
// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL

#include<bits/stdc++.h>
using namespace std;
int solve(string s, string t, int n, int m)
{

    int dp[n+1][m+1];
    
    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                dp[i][j] =0;
            else if(s[i-1]==t[j-1])
                dp[i][j] = 1+ dp[i-1][j-1];
            else
                dp[i][j] = max(dp[i-1][j], dp[i][j-1]);
        }
    }

    return dp[n][m];
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
---


## Dynamic Programming - `4`
### Longest Common Substring

Given two string 'X' and string 'Y'. Find the length of longest Common substring.
> For example, "faisal","faisalcity" the length of longest common substring is **6** ("faisal").

#### `Input Format`
First line given first string s, second line given second string t;

#### `Output Format`
Single integer which represent the length of the longest common substring.

#### Input 1
zxabcdezy

yzabcdezx

#### Output 1
6

## C++ code `Recursive`

```cpp
// BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL

#include<bits/stdc++.h>
using namespace std;
int solve(string s, string t, int n, int m, int count)
{
    if(n==0 || m==0)
        return count;

    if(s[n-1] == t[m-1])
        count = solve(s,t,n-1,m-1, count+1);
    else
        count = max(count, max(solve(s,t,n-1,m,0),solve(s,t,n,m-1,0)));
    
    return count;
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
    int count =0;
    int res = solve(s,t,n,m,count);
    cout<<res<<endl;
    return 0;
}
```

## C++ code `Iteratative`
```c++
    // BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL

#include<bits/stdc++.h>
using namespace std;
int solve(string s, string t, int n, int m)
{
    int count =0;
    int dp[n+1][m+1];

    for(int i=0;i<=n;i++)
    {
        for(int j=0;j<=m;j++)
        {
            if(i==0 || j==0)
                dp[i][j] = 0;
            else if(s[i-1]==t[j-1])
            {
                dp[i][j] = dp[i-1][j-1] +1;
                count = max(count, dp[i][j]);
            }
            else
                dp[i][j] = 0;
        }
    }
    return count;
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
---
## Dynamic Programming - `4`
### Count Subarrays with equal 1s and 0s

Given an array arr[] of size N containing 0s and 1s only. The task is to count the subarrays having equal number of 0s and 1s.

### `Constraint`
1 <= T <= 100

1 <= N <= 10<sup>6</sup>

0 <= A[i] <= 1

#### `Input Format`
The first line of input contains an integer T denoting the number of test cases. Then T test cases follow. Each test case consists of two lines. First line of each test case contains an Integer N denoting size of array and the second line contains N space separated 0 and 1.

#### `Output Format`
For each test case, print the count of required sub arrays in new line.

#### Input 1
2

7

1 0 0 1 0 1 1

5

1 1 1 1 0

#### Output 1
8

1

## C++ code `Iteratative`
```c++
    // BEGINNING WITH THE NAME OF ALMIGHTY GOD ALLAH
// AUTHOR:: MOHAMMAD FAISAL
#include<bits/stdc++.h>
#define fast ios_base::sync_with_stdio(false); cin.tie(0); cout.tie(0);
using namespace std;
int main()
 {
    fast
    int t;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        int * arr = new int[n];
        for(int i=0;i<n;i++)
        {
            int x;
            cin >> x;
            (x==1) ? arr[i] =1: arr[i] =-1;
        }
        
        int sum = 0;
        int subArray = 0;
        
        unordered_map<int,int> dp;
        for(int i=0;i<n;i++)
        {
            sum +=arr[i];
            if(sum==0) subArray++;
            if(dp[sum]) subArray+=dp[sum];
            if(dp[sum]==0)
                dp[sum] =1;
            else
                dp[sum]++;
        }
        cout<<subArray<<"\n";
        delete[] arr;
    }
	//code
	return 0;
}
```
---
