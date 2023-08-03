//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;


// } Driver Code Ends
//User function template for C++
class Solution{
public:	
	int findKRotation(int arr[], int n) {
	    // code here
	    int temp = INT_MAX,store=-1;
	    int l=0,h=n-1;
	    
	    while(l<=h){
	       int m = (l+h)/2;
	       temp = min(temp,arr[m]);
	       if(temp==arr[m]){store=m;}
	       
	       if(arr[l]<arr[m]){
	           temp = min(temp,arr[l]);
	           if(temp==arr[l]){store=l;}
	           l=m+1;
	       }
	       else{
	           temp = min(temp,arr[h]);
	           if(temp==arr[h]){store=h;}
	           h=m-1;
	       }
	       
	       //cout<<temp<<endl;
	    }
	    
	    return store;
	}

};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, i;
        cin >> n;
        int a[n];
        for (i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findKRotation(a, n);
        cout << ans << "\n";
    }
    return 0;
}

// } Driver Code Ends