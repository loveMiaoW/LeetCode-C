class Solution {
public:
    int getKthElement(const vector<int>& nums1,const vector<int>& nums2,int k){
        /*
            时间复杂度:O(log(m+n))      二分
            空间复杂度:O(1)

            寻找到第k小的元素，取pivot1 = nums1[k/2 - 1] 和pivot2 = nums2[k/2 - 1]进行比较
            nums1中小于等于pivot1 的元素有nums1[0,1,2,3...,k/2-2] 共计k/2-2 个
            nums2中小于等于pivot2 的元素有nums2[0,1,2,3...,k/2-2] 攻击k/2-2 个
            

        */
        int m = nums1.size();
        int n = nums2.size();
        int index1 = 0,index2 = 0;
        
        while(true){
        //边界情况
            if(index1 == m){
                return nums2[index2 + k - 1];
            }
            if(index2 == n){
                return nums1[index1 + k - 1];
            }
            
            if(k == 1){
                return min(nums1[index1],nums2[index2]);
            }
        //正常情况
            int newIndex1 = min(index1 + k / 2 - 1,m - 1);
            int newIndex2 = min(index2 + k / 2 - 1,n - 1);
            int pivot1 = nums1[newIndex1];
            int pivot2 = nums2[newIndex2];
            if (pivot1 <= pivot2) {
                k -= newIndex1 - index1 + 1;
                index1 = newIndex1 + 1;
            }
            else {
                k -= newIndex2 - index2 + 1;
                index2 = newIndex2 + 1;
            }
        }

    }

    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        int totalLength = nums1.size() + nums2.size();
        if(totalLength % 2 == 1){
            //长度和是奇数 找到第k=(totalLength + 1) / 2 的元素 
            return getKthElement(nums1,nums2,(totalLength + 1) / 2);
        }
        else{
            //长度和是偶数 找到两个求和
            return (getKthElement(nums1,nums2,(totalLength / 2)) + getKthElement(nums1,nums2,(totalLength / 2 + 1))) / 2.0;
        }
    }
};