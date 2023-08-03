//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int search(int arr[], int n){
	    //code
	    int l=1,h=n-2;
	    
	    if(arr[0]!=arr[1]){
	        return arr[0];
	    }
	    if(arr[n-2]!=arr[n-1]){
	        return arr[n-1];
	    }
	    
	    while(l<=h){
	        int m = (l+h)/2;
	        
	        if(arr[m]!=arr[m-1] && arr[m]!=arr[m+1]){
	            return arr[m];
	        }
	        else if(arr[m]==arr[m-1]){
	            if(m%2==1){
	                l=m+1;
	            }
	            else{
	                h=m-1;
	            }
	        }
	        else{
	            if(m%2==0){
	                l=m+1;
	            }
	            else{
	                h=m-1;
	            }
	        }
	        
	    }
	    
	    return -1;
	}
};

//{ Driver Code Starts.

// Driver program
int main()
{
    int t,len;
    cin>>t;
    while(t--)
    {
        cin>>len;
        int arr[len];
        for(int i=0;i<len;i++){
            cin>>arr[i];
        }
        Solution ob;
        cout<<ob.search(arr, len)<<'\n';
    }
    return 0;
}

// } Driver Code Ends