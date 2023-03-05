class Solution {
public:
    string largestNumber(vector<int>& nums) {
        string s = "";int r=-1;
        sort(nums.begin(),nums.end(),compare);
        for(int i=0;i<nums.size();i++){
            s+=to_string(nums[i]);
        }
        for(int i=0;i<s.size()-1;i++){
            if(s[i]!='0'){
                break;
            }
            r=i;
        }
        
        s.erase(0,r+1);
        return s;
    }
    static bool compare(int a, int b){
        string a1 = to_string(a);
        string b1 = to_string(b);
        
        if (a1.length() != b1.length()){
            string s = a1;s+=b1;
            string t = b1;t+=a1;
            if(s>t){
                return true;
            }
            return false;
        }
        
        return a1>b1;
    }
};