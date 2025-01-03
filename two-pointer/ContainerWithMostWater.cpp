class Solution {
public:
    int maxArea(vector<int>& height) {
        int lo = 0, hi = (int)height.size() - 1;

        int max_area = -1, area = 0;
        while(lo < hi) {
            area = min(height[lo], height[hi]) * (hi - lo);

            if(area > max_area)
                max_area = area;

            if(height[lo] < height[hi]) {
                lo++;
            } else {
                hi--;
            }
        }

        return max_area;
    }
};
