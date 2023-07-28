class Solution {
public:
    int search(vector<int>& nums, int target) {
        int l=0;
        int r=nums.size()-1;
        while(l<=r){
            int mid = (l+r)/2;
            if(nums[mid]==target){
                return mid;
            }
            else if(nums[l]<nums[mid]){
                if(nums[l]<=target && nums[mid]<target){
                    r=mid-1;
                }
                else{
                    l=mid+1;
                }
            }
            else{
                if (nums[mid] < target && target <= nums[r]) {
                    l=mid+1;
                } else {
                    r=mid-1;
                }
            }
        }
        for(int i=0;i<nums.size();i++){
            if(nums[i]==target){
                return i;
            }
        }
        
        return -1;
    }
};