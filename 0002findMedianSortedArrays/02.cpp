class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        /*
        定义两个指针 i , j 分别指向nums1 的第一个元素 和nums2 的第一个元素
        排除两个数组非空
        寻找中位数
        两个数组有两种情况
        偶数 奇数
        两个数组的长度和是偶数时
        两个数组的长度和时奇数时

        时间复杂度:O(m+n)
        空间复杂度:O(1)
        */
        int m = nums1.size();
        int n = nums2.size();
        int i,j,l,r;
        l = r = 0;
        i = j = 0;
        for(int x = 0;x <= (m + n) / 2;x++){
            l = r ;
            r = (i < m && (j >= n || nums1[i] < nums2[j])) ? nums1[i++] : nums2[j++];
        }
        return (m + n) & 1 ? r : (l + r) / 2.0;
    }
};