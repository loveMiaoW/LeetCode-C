class Solution {
public:
     int maxArea(vector<int>& height) {
        /*
            双指针
            一个指向头 一个指向尾
            开辟一个变量存储 ans
            每计算一次 将当前的面积和ans比较并将大的数值赋值给ans
            移动两边较小的那一条边
                                左边 > 右边 右边减一
                                左边 < 右边 左边加一
            时间复杂度:O(n)       两个指针最多遍历一遍数组
            空间复杂度:O(1)        
        */
        int l = 0, r = height.size() - 1;
        int ans = 0;
        while (l < r) {
            int area = min(height[l], height[r]) * (r - l);
            ans = max(ans,area);
            if (height[l] <= height[r]) {
                ++l;
            }
            else {
                --r;
            }
        }
        return ans;
    }
};