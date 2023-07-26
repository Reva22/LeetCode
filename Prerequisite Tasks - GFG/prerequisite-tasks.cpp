//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution {
public:
	bool isPossible(int n,int p, vector<pair<int, int> >& pre) {
	    // Code here
	    vector<int>adj[n];
	    vector<int>tadj[n];
	    
	    for(int i=0;i<pre.size();i++){
	        adj[pre[i].first].push_back(pre[i].second);
	        tadj[pre[i].second].push_back(pre[i].first);
	    }
	    
	   // for(int i=0;i<n;i++){
	   //     for(int j=0;j<adj[i].size();j++){
	   //         cout<<adj[i][j]<<" ";
	   //     }
	   //     cout<<endl;
	   // }
	    
	    vector<int>innodes(n,0);
	    queue<int>q;
	    
	    for(int i=0;i<n;i++){
	        innodes[i]=adj[i].size();
	        if(innodes[i]==0){
	            q.push(i);
	        }
	       // cout<<innodes[i]<<" ";
	    }
	   // cout<<endl;
	    
	    int c=0;
	    
	    while(!q.empty()){
	        c++;
	        for(int i=0;i<tadj[q.front()].size();i++){
	            innodes[tadj[q.front()][i]]--;
	            if(innodes[tadj[q.front()][i]]==0){
	                q.push(tadj[q.front()][i]);
	            }
	        }
	        
	       // for(int i=0;i<n;i++){
	       //     cout<<innodes[i]<<" ";
	       // }
	       // cout<<endl;
	    
	        q.pop();
	    }
	    
	   // cout<<c<<endl;
	    
	    if(c==n){
	        return true;
	    }
	    
	    return false;
	    
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
    	int N, P;
        vector<pair<int, int> > prerequisites;
        cin >> N;
        cin >> P;
        for (int i = 0; i < P; ++i) {
            int x, y;
            cin >> x >> y;
            prerequisites.push_back(make_pair(x, y));
        }
        // string s;
        // cin>>s;
        Solution ob;
        if (ob.isPossible(N,P, prerequisites))
            cout << "Yes";
        else
            cout << "No";
        cout << endl;
	}
	return 0;
}
// } Driver Code Ends