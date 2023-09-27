class Solution {
public:

    int dp[500][250][2];

    int solve(vector<int>& slices, int i, int cnt, bool first){
        if(i>=slices.size()-first || cnt==slices.size()/3) return 0;
        
        if(dp[i][cnt][first]!=-1) return dp[i][cnt][first];

        int take=0,notake=0;
        if(i==0) take = slices[i] + solve(slices,i+2,cnt+1,1);
        else take = slices[i] + solve(slices,i+2,cnt+1,first);
        notake = solve(slices,i+1,cnt,first);

        return dp[i][cnt][first]=max(take,notake);
    }

    int maxSizeSlices(vector<int>& slices) {
        memset(dp,-1,sizeof(dp));
        return solve(slices,0,0,0);
    }
};