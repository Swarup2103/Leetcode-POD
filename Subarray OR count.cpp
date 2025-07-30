//2044. Count Number of Maximum Bitwise-OR Subsets

class Solution {
public:
    //memo = ith place pai maxXOR value 

    int countSubsets(int i, int currOR, vector<int>& nums, int &maxOR, vector<vector<int>> &t){
        if(i == nums.size()){
            if(currOR == maxOR){ return 1;}
            return 0;
        }

        if(t[i][currOR] != -1){
            return t[i][currOR];
        }
        //Take nums of i
        int takeCount = countSubsets(i+1, currOR | nums[i], nums, maxOR, t);
        //Not taken
        int notTakeCount = countSubsets(i+1, currOR, nums, maxOR, t);

        return t[i][currOR] = takeCount + notTakeCount; 
    }
    int countMaxOrSubsets(vector<int>& nums) {
        int maxOR = 0;
        for(int &num : nums){
            maxOR |= num;
        }
        //Memo array
        int size = nums.size();
        vector<vector<int>> t(size+1, vector<int>(maxOR+1, -1));

        int currOR = 0;
        return countSubsets(0, currOR, nums, maxOR,t);
    }
};