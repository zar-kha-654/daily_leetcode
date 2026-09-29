class Solution {
public:
    vector<vector<int>> threeSum(vector<int>& nums) {
        vector<vector<int>>result;
        sort(nums.begin(), nums.end());
        int i = 0;
        for(i=0; i<nums.size()-2; i++){
            if(i>0 && nums[i]== nums[i-1]){
                continue;
            }
            int j = nums.size()-1;
            int k = i+1;

            while(j>k){
                int sum = nums[i]+ nums[j]+ nums[k];
                if(sum>0){
                    j--;
                }
                else if(sum<0){
                    k++;
                }
                else{
                    result.push_back({nums[i], nums[j], nums[k]});
                
                    j--;
                    k++;
                    while(j>k && nums[k]== nums[k-1])
                    k++;
                }
            }
        }
        return result;
    }
};