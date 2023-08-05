//{ Driver Code Starts
// Initial Template for C++
#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
public:

    bool check(int m, vector<int> &v, int k){
        int temp = v[0];
        int c = 1;
        for(int i=0;i<v.size();i++){
            if(v[i]-temp>=m){
                temp=v[i];
                c++;
            }
        }
        
        return c>=k;
    }

    int solve(int n, int k, vector<int> &v) {
    
        // Write your code here
        sort(v.begin(),v.end());
        
        int l = 0, h = v[n-1]-v[0], ans = 0;
        
        while(l<=h){
            int m = (l+h)/2;
            
            if(check(m,v,k)){
                ans=max(ans,m);
                l=m+1;
            }
            else{
                h=m-1;
            }
        }
        
        return ans;
    }
};

//{ Driver Code Starts.

int main() {
    int t = 1;
    cin >> t;

    // freopen ("output_gfg.txt", "w", stdout);

    while (t--) {
        // Input

        int n, k;
        cin >> n >> k;

        vector<int> stalls(n);
        for (int i = 0; i < n; i++) {
            cin >> stalls[i];
        }
        // char ch;
        // cin >> ch;

        Solution obj;
        cout << obj.solve(n, k, stalls) << endl;

        // cout << "~\n";
    }
    // fclose(stdout);

    return 0;
}
// } Driver Code Ends