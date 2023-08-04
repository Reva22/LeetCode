//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function Template for C++

class Solution {
  public:
  
    bool func(int arr[], int n, int d, int mini){
        int s = 0, temp = 0;
        for(int i=0;i<n;i++){
            if(temp + arr[i]>mini){
                s++;
                temp=0;
            }
            temp+=arr[i];
        }
        s++;
        // cout<<mini<<" "<<s<<endl;
        return s<=d;
    }
  
    int leastWeightCapacity(int arr[], int n, int d) {
        // code here
        
        int sum=0,l=-1;
        for(int i=0;i<n;i++){
            sum+=arr[i];
            l=max(l,arr[i]);
        }
        int ans = INT_MAX;
        int h = sum;
        while(l<=h){
            int m = (l+h)/2;
            
            if(func(arr,n,d,m)){
                ans=min(ans,m);
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N,D;
        cin>>N;
        
        int arr[N];
        for(int i=0; i<N; i++)
            cin>>arr[i];
        cin>>D;

        Solution ob;
        cout << ob.leastWeightCapacity(arr,N,D) << endl;
    }
    return 0;
}
// } Driver Code Ends