class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*暴力归并*/
        /*将第二个数组归并到第一个数组里*/
        /*通过下标 返回数组中位数*/
        /*
            时间复杂度：O(m+n)
            空间复杂度：O(m+n)
        */
        double count;
        for(int i = 0;i < nums2.size();i++){
            nums1.push_back(nums2[i]);
        }
        sort(nums1.begin(),nums1.end());
        if(nums1.size()%2){
                count = nums1[nums1.size()/2];
            }else if(nums1.size()%2 == 0){
                count = (nums1[nums1.size()/2 - 1] + nums1[nums1.size()/2])/2.0;
            }
        return count;
    }
};