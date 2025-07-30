class Solution {
public:
    int countHillValley(vector<int>& nums) {
        int i = 0, j = 1, size = nums.size();
        int count = 0;

        while(j<size-1){
            if((nums[i]<nums[j] && nums[j]>nums[j+1]) || (nums[i]>nums[j] && nums[j]<nums[j+1]))
            {count++; i = j;}
            j++;
        }

        return count;
    }
};