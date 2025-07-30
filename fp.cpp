//1 March, 2025

//2460. Apply Operations to an Array

class Solution {
public:
    vector<int> applyOperations(vector<int>& nums) {
        int size = nums.size();
        for(int i = 0; i < size-1; i++) {
            if(nums[i]==nums[i+1]) {
                nums[i] = nums[i]*2;
                nums[i+1] = 0;
            }
        }
        int posOfZero = 0; 

        for (int i = 0; i < size; i++) {
            if (nums[i] != 0) {
                swap(nums[i], nums[posOfZero]); 
                posOfZero++;
            }
        }
        return nums;
    }
        
};


//git pull origin main --rebase

//git push -u origin main