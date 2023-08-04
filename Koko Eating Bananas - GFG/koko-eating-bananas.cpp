//{ Driver Code Starts
#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
  public:
    
    bool eat(int m, vector<int>& v, int h){
        int s = 0;
        for(int i=0;i<v.size();i++){
            s+=v[i]/m;
            if(v[i]%m != 0){
                s++;
            }
        }
        
        // cout<<m<<" "<<s<<endl;
        
        if(s<=h){
            return true;
        }
        
       return false; 
    }
  
    int Solve(int n, vector<int>& v, int hr) {
        // Code here
        sort(v.begin(),v.end());
        int l = 1, h = v[v.size()-1];
        int temp = INT_MAX;
        
        while(l<=h){
            int m = (l+h)/2;
            
            if(eat(m,v,hr)){
                temp=min(temp,m);
                h=m-1;
            }
            else{
                l=m+1;
            }
        }
        
        return temp;
        
    }
};

//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n;
        cin >> n;
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            int x;
            cin >> x;
            a.push_back(x);
        }
        int h;
        cin >> h;
        Solution obj;

        cout << obj.Solve(n, a, h);
        cout << "\n";
    }
    return 0;
}
// } Driver Code Ends