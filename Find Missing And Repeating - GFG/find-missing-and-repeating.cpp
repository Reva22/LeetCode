//{ Driver Code Starts
#include <bits/stdc++.h>

using namespace std;

// } Driver Code Ends
class Solution{
public:
    int *findTwoElement(int *arr, int n) {
        // code here
        int *ans = new int[2];
        int mini = 1;
        map<int,int>mp;
        sort(arr,arr+n);
        for(int i=0;i<n;i++){
            mp[arr[i]]++;
            if(arr[i]==mini){
                mini++;
            }
        }
        ans[1] = mini;
        for(int i=0;i<n;i++){
            if(mp[arr[i]]==2){
                ans[0] = arr[i];
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
        int n;
        cin >> n;
        int a[n];
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        Solution ob;
        auto ans = ob.findTwoElement(a, n);
        cout << ans[0] << " " << ans[1] << "\n";
    }
    return 0;
}
// } Driver Code Ends