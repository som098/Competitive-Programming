/*
 KMP ALGORITHM
 finding LPS array of an string by KMP ALGORITHM
 LCP-LONGEST proper COMMON PREFIX WHICH IS ALSO SUFFIX
 */
#include<iostream>
using namespace std;
#include<bits/stdc++.h>

int main()
{
    string s;
    cin>>s;
    int n=s.length();
    int lcp[n];
    lcp[0]=0;
    int j=0,i=1;
    while(i<n)
    {
        if(s[i]==s[j])
        {
            lcp[i]=j+1;
            i++;j++;
        }
        else
        {
            if(j)
            {
                j=lcp[j-1];
            }
            else
            {
                lcp[i]=0;
                i++;
            }
        }
    }
    
}
