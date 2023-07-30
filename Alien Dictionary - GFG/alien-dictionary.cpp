//{ Driver Code Starts
// Initial Template for C++

#include <bits/stdc++.h>
using namespace std;

// } Driver Code Ends
// User function Template for C++

class Solution{
    public:
    string findOrder(string dict[], int n, int k) {
        //code here
        string s = "";
        
        vector<pair<char,char>>vec;
        
        vector<vector<char>>in(k),ou(k);
        
        for(int i=0;i<n-1;i++){
            int st = 0;
            while(dict[i][st]==dict[i+1][st]){
                st++;
            }
            if(st<dict[i].size() && st<dict[i+1].size()){
                vec.push_back(make_pair(dict[i][st],dict[i+1][st]));
                in[dict[i+1][st]-'a'].push_back(dict[i][st]);
                ou[dict[i][st]-'a'].push_back(dict[i+1][st]);
            }
        }
        
        vector<int>no(k,-1);
        // priority_queue<pair<int,char>, vec<pair<int,char>>, greater<pair<int,char>>>q;
        queue<char>q;
        
        for(int i=0;i<k;i++){
            no[i]=in[i].size();
            if(no[i]==0){
                q.push(char('a'+i));
            }
        }
        
        while(!q.empty()){
            char ch = q.front();
            int z = ch-'a';
            s+=ch;
            
            for(int i=0;i<ou[z].size();i++){
	            no[ou[z][i]-'a']--;//cout<<ou[int(ch-'a')][i]<<endl;
	            if(no[ou[z][i]-'a']==0){
	                q.push(ou[z][i]);
	            }
	        }
	        q.pop();
        }
        
        // cout<<s<<endl;
        return s;
    }
};

//{ Driver Code Starts.
string order;
bool f(string a, string b) {
    int p1 = 0;
    int p2 = 0;
    for (int i = 0; i < min(a.size(), b.size()) and p1 == p2; i++) {
        p1 = order.find(a[i]);
        p2 = order.find(b[i]);
        //	cout<<p1<<" "<<p2<<endl;
    }

    if (p1 == p2 and a.size() != b.size()) return a.size() < b.size();

    return p1 < p2;
}

// Driver program to test above functions
int main() {
    int t;
    cin >> t;
    while (t--) {
        int N, K;
        cin >> N >> K;
        string dict[N];
        for (int i = 0; i < N; i++) cin >> dict[i];
        
        Solution obj;
        string ans = obj.findOrder(dict, N, K);
        order = "";
        for (int i = 0; i < ans.size(); i++) order += ans[i];

        string temp[N];
        std::copy(dict, dict + N, temp);
        sort(temp, temp + N, f);

        bool f = true;
        for (int i = 0; i < N; i++)
            if (dict[i] != temp[i]) f = false;

        if(f)cout << 1;
        else cout << 0;
        cout << endl;
    }
    return 0;
}

// } Driver Code Ends