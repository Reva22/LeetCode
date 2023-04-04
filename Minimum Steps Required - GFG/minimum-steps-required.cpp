//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

int minSteps(string str) {
    // Write your code here.
    int counta=0,countb=0;
    int n=str.length();
    int i=0;
    while(i<str.length())
    {
        if(str[i]=='a')
        {
            while(str[i]=='a' and i<n)
            {
                i++;
            }
            counta++;
        }
        else{
            while(str[i]=='b' and i<n)
            {
                i++;
            }
            countb++;
        }
    }
    return min(counta,countb)+1;
}

//{ Driver Code Starts.

int main() {

    int t;
    cin >> t;
    while (t--) {
        string str;
        cin >> str;
        cout << minSteps(str) << endl;
    }
}

// } Driver Code Ends