class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        vector<vector<int>>v;
        vector<int>a,b;
        sort(intervals.begin(), intervals.end());
        
        int maxi = intervals[0][1];
        a.push_back(intervals[0][0]);
        for(int i=0;i<intervals.size()-1;i++){
            if(intervals[i+1][0] <= maxi){
                maxi = max(intervals[i+1][1], maxi);
            }
            else{
                b.push_back(maxi);
                a.push_back(intervals[i+1][0]);
                maxi = intervals[i+1][1];
            }
        }
        b.push_back(maxi);
        for(int i=0;i<a.size();i++){
            vector<int>p;
            p.push_back(a[i]);
            p.push_back(b[i]);
            v.push_back(p);
        }
        
        return v;
    }
};