//{ Driver Code Starts
//Initial template for C++

#include <bits/stdc++.h>
using namespace std;


// } Driver Code Ends
//User function template for C++

// A : given string to search
// B : vector of available strings

class Solution
{
public:

    int solve(string k, string A, vector<string>&B, int i){
        //cout<<k<<endl;
        if(k==A){
            return 1;
        }
        //cout<<k<<endl;
        if(i<B.size()){
        i+=1;//cout<<k<<endl;
        if(k+B[i-1]==A.substr(0,(k+B[i-1]).size())){
        return solve(k+B[i-1],A,B,i) || solve(k,A,B,i);}
        else{
        return solve(k,A,B,i);
        }
        }
        
        return 0;
    }
    
    
    int wordBreak(string A, vector<string> &B) {
        //code here
        string s = "";
        vector<string> C;
        for(int i=0;i<A.size();i++){
            for(int j=0;j<B.size();j++){
                if(B[j]==A.substr(i,B[j].size())){
                    C.push_back(B[j]);
                }
            }
        }
        
        int res=solve(s,A,C,0);
        return res;
    }
};

//{ Driver Code Starts.

int main(){
    int t;
    cin>>t;
    while(t--){
        int n;
        cin>>n;
        vector<string> dict;
        for(int i=0;i<n;i++){
            string S;
            cin>>S;
            dict.push_back(S);
        }
        string line;
        cin>>line;
        Solution ob;
        cout<<ob.wordBreak(line, dict)<<"\n";
    }
}

// } Driver Code Ends