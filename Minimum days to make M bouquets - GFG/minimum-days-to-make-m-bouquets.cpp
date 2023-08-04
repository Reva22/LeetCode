//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
  
    bool check(int M, int K, vector<int> &arr,int n,int mid){
          int count=0,num=0;
          for(int i=0;i<n;i++){
              if(arr[i]<=mid) count++;
              else {
                  num=num+(count/K);
                  count=0;
                }
          }
          num+=(count/K);
          return num>=M;
     }
    
    int solve(int m, int k, vector<int> &arr){
      // Code here
        int n=arr.size();
        int low=-1,high=*max_element(arr.begin(),arr.end());
        if(m*1LL*k>n) return -1;
        while(low<=high){
            int mid=(low+high)/2;
            if(check(m,k,arr,n,mid)) high=mid-1;
            else low=mid+1;
        }
        
        return low;
      
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int m, k;
    cin >> m >> k;
    string s;
    getline(cin, s);
    getline(cin, s);
    int n = s.length();
    int num = 0;
    bool f = 0;
    vector<int> bloomDay;
    for (int i = 0; i < n; i++)
    {
      if (s[i] == ' ')
      {
        if (!f)
          continue;
        bloomDay.push_back(num);
        num = 0;
        f = 0;
      }
      else
      {
        num = (num * 10) + (s[i] - '0');
        f = 1;
      }
    }
    if (f)
    {
      bloomDay.push_back(num);
    }
    Solution obj;
    cout<<obj.solve(m, k, bloomDay)<<endl;
    }
    return 0;
}
// } Driver Code Ends