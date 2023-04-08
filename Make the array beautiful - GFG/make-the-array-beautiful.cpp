//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    vector<int> makeBeautiful(vector<int> arr) {
        // code here
        vector<int>ans;
        stack<int>res;
        int i=0;
        for(int i=0;i<arr.size();i++){
            if(res.empty()){
                res.push(arr[i]);
            }
            else{
                if(res.top()*arr[i]>0 || (res.top()>=0 && arr[i]>=0)){
                    res.push(arr[i]);
                }
                else{
                    res.pop();
                }
            }
        }
        while(!res.empty())
        {
            ans.push_back(res.top());
            res.pop();
        }
        reverse(ans.begin(),ans.end());
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
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
        }

        Solution obj;
        vector<int> res = obj.makeBeautiful(arr);
        for (int i = 0; i < res.size(); i++) {
            cout << res[i] << " ";
        }

        cout << "\n";
    }
}
// } Driver Code Ends