class Solution {
public:
    int maxArea(vector<int>& height) {
        int maxArea =0;
        int i =0; 
        int j = height.size()-1;
        while(i<j){
            int width = j-i;
            int current_height = min(height[i], height[j]);
            int area = width * current_height;
            maxArea = max(area,maxArea);
            if(height[i]<height[j]){
                i++;
            }
            else{
                j--;
            }
        }
        return maxArea;
    }
};