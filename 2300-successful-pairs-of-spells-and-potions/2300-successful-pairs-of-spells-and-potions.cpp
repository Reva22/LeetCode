class Solution {
public:
    
    vector<int> successfulPairs(vector<int>& spells, vector<int>& potions, long long success) {
        vector<int>pairs;
        sort(potions.begin(),potions.end());
        for(int i=0;i<spells.size();i++){
            long long f=(success/spells[i])+1;
            if(success%spells[i]==0){
                f = success/spells[i];
            }
            int it = lower_bound(potions.begin(),potions.end(),f) - potions.begin();
            pairs.push_back(potions.size()-(it));
        }
        
        return pairs;
    }
};