//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{

	public:
	int findSwapValues(int a[], int n, int b[], int m)
	{
        // Your code goes here
        int s1=0,s2=0;
        for(int i=0;i<n;i++) s1+=a[i];
        for(int i=0;i<m;i++) s2 += b[i];
        
        int d = abs(s1-s2);
        if(d==0) return 1;
        
        sort(a,a+n);
        sort(b,b+m);
        
        int i=0,j=0;
        
        while(i<n && j<m){
            if(s1-a[i]+b[j] == s2-b[j]+a[i]) return 1;
            else if(s1-a[i]+b[j] > s2-b[j]+a[i]) i++;
            else j++;
        }
        return -1;
    }
 

};

//{ Driver Code Starts.

int main() 
{
   	
   	int t;
    cin >> t;
    while (t--)
    {
    	int n,m;
        cin>>n>>m;
        int a[n];
        int b[m];
        for(int i=0;i<n;i++)
            cin>>a[i];
        for(int i=0;i<m;i++)
            cin>>b[i];
        

        Solution ob;
        cout <<  ob.findSwapValues(a, n, b, m);
	    cout << "\n";
	     
    }
    return 0;
}






// } Driver Code Ends