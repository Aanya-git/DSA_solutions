class Solution {
public:
    int maxArea(vector<int>& height) {
        int lp=0;
        int rp = height.size() - 1;
        int maxWater = 0;
        while(lp<rp){
            int w = rp-lp;
            int ht = min(height[lp],height[rp]);
            int currntWater = w * ht;
            maxWater = max(maxWater , currntWater);

            height[lp]<height[rp]?lp++:rp--;
        }
        return maxWater;


        
    }
};