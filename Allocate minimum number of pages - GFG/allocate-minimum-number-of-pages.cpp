//{ Driver Code Starts
// Initial template for C++

#include<bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template in C++

class Solution 
{
    public:
    //Function to find minimum number of pages.
    
    bool check(int p, int arr[], int n, int m){
        
        int c = 1, sum = 0;
        
        for(int i=0;i<n;i++){
            if(sum+arr[i]>p){
                sum=0;
                c++;
            }
            if(sum+arr[i]<=p){
                sum+=arr[i];
                
            }
            else{
                return false;
            }
        }
        
        return c<=m;
    }
    
    int findPages(int arr[], int n, int m) 
    {
        //code here
        if(m>n) {return -1;}
        
        int ans = INT_MAX, l = *min_element(arr,arr+n), h = 0;
        for(int i=0;i<n;i++){
            h+=arr[i];
        }
        
        while(l<=h){
            int mid = (l+h)/2;
            
            if(check(mid,arr,n,m)){
                ans=min(ans,mid);
                h=mid-1;
            }
            else{
                l=mid+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        int A[n];
        for(int i=0;i<n;i++){
            cin>>A[i];
        }
        int m;
        cin>>m;
        Solution ob;
        cout << ob.findPages(A, n, m) << endl;
    }
    return 0;
}

// } Driver Code Ends