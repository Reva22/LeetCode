//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution{
	public:
	int NthRoot(int n, int x)
	{
	    // Code here.
	    int l=0,h=x;
        if(x==0){
            return 0;
        }
        if(x==1){
            return 1;
        }
        
        while(l<=h){
            int m = (l+h)/2;
            long long int o=1;
            for(int i=0;i<n;i++){
                o*=m;
                if(o>x){
                    break;
                }
            }
            // cout<<o<<endl;
            if(o==x){
                return m;
            }
            if(o<x){
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        
        return -1;
	}  
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		int n, m;
		cin >> n >> m;
		Solution ob;
		int ans = ob.NthRoot(n, m);
		cout << ans << "\n";
	}  
	return 0;
}
// } Driver Code Ends