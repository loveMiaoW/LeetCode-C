class Solution {
public:
    int maxArea(vector<int>& height) {
        /*
            爆破
            双重for循环从左到右
            一次计算盛水面积
            时间复杂度:O(n^2)
            空间复杂度:O(1)
            超时54/60
        */
        int maxArea = 0;
        for(int i = 0;i < height.size();i++){
            for(int j = i + 1;j < height.size();j++){
                maxArea = max(maxArea,min(height[i],height[j]) * abs(j - i));
            }
        }
        return maxArea;
    }
};