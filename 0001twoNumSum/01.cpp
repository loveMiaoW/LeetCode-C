class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*爆破
            时间复杂度 O(n^2)
            空间复杂度 O(1)
        */
        int len = nums.size();
        for(int i = 0;i < len;i++){
            int tmp = nums[i];
            for(int j = i + 1;j < len;j++){
                if(nums[j] == target - nums[i]){
                    return {i,j};
                }
            }
        } 
        return {};
    }
};