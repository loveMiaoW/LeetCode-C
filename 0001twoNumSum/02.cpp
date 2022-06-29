class Solution {
public:
    vector<int> twoSum(vector<int>& nums, int target) {
        /*哈希表*/
        unordered<int,int> hashTable;/*创建一个哈希表*/
        for(int i = 0; i < nums.size();i++){
            auto it = hashTable.find(target - nums[i]);//寻找插值 哈希表中有返回 插值索引 和差数索引

            if(it != hashTable.end()){                  //it 不位哈希表最后元素
                return {it->second,i};                      
            }
            hashTable[nums[i]] = i;                     //将当前元素插入哈希表
        }
        return {};
    }
};