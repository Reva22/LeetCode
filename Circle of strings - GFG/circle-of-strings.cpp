//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution
{
    public:
    void BFS(vector<vector<int>>&adj,vector<bool> &vis,int start){
        queue<int> q;
        q.push(start);
        vis[start]=1;
        while(!q.empty()){
            int curr=q.front();
            q.pop();
            for(int it : adj[curr]){
                if(!vis[it]){
                    vis[it]=1;
                    q.push(it);
                }
            }
        }
    }
    int isCircle(int N, vector<string> A)
    {
        // code here
        vector<vector<int>>innodes(26);
        vector<vector<int>>outnodes(26);
        
        for(int i=0;i<A.size();i++){
            innodes[A[i][0]-'a'].push_back(A[i].back()-'a');
            outnodes[A[i].back()-'a'].push_back(A[i][0]-'a');
        }
        
        int start=A[0][0]-'a';
        vector<bool> vis(26,0);
        BFS(innodes,vis,start);
        for(int i=0;i<26;i++){
            if(innodes[i].size()>0){
                if(vis[i]==0) return 0;
            }
        }
        
        for(int i=0;i<26;i++){
            if(innodes[i].size()!=outnodes[i].size()){
                return 0;
            }
        }
        
        return 1;
    }
};

//{ Driver Code Starts.
int main()
{
    int t;
    cin>>t;
    while(t--){
        int N;
        cin>>N;
        vector<string> A;
        string s;
        
        for(int i = 0;i < N; i++)
        {
            cin>>s;
            A.push_back(s);
        }
        
        Solution ob;
        cout<<ob.isCircle(N, A)<<endl;
    }
    return 0;
}
// } Driver Code Ends