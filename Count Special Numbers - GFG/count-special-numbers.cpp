//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution {
  public:
    int countSpecialNumbers(int n, vector<int> arr) {
        // Code here
        int count = 0;
        sort(arr.begin(),arr.end());
        vector<int>s;
        vector<int>v;v.push_back(arr[0]);

        map<int,int>mp;
        for(int i=0;i<n;i++){
            if(mp[arr[i]]==0){s.push_back(arr[i]);}
            mp[arr[i]]++;
        }
        if(mp[s[0]]>1){
            count+=mp[s[0]];
        }
        for(int i=1;i<s.size();i++){
            int c = count;
            if(mp[s[i]]>1){
                count+=mp[s[i]];v.push_back(s[i]);
                v.push_back(s[i]);
            }
            else{
            for(int j=0;j<v.size();j++){
                if(s[i]%v[j] ==0){
                    count++;
                    break;
                }
            }
            if(c==count){
                v.push_back(s[i]);
            }
            }
        }
        
        return count;
    }
};


//{ Driver Code Starts.

int main() {
    int t;
    cin >> t;
    while (t--) {
        int N;
        cin >> N;
        vector<int> arr(N);
        for (int i = 0; i < N; i++) {
            cin >> arr[i];
        }

        Solution ob;
        cout << ob.countSpecialNumbers(N, arr) << endl;
    }
    return 0;
}
// } Driver Code Ends