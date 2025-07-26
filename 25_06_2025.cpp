//3487. Maximum Unique Subarray Sum After Deletion

class Solution {
public:
    //sum = 0 => all elements are negative => ans = maxNegNum
    //sum != 0=> positive nums are there => put pos nums in SET => ans = sumOf(elePresentInSet)
    //for +: 1 <= nums[i] <= 100 => here also we can use "vactor<int> UniqueNums (101, -1)"
        int maxSum(vector<int>& nums) {
            //Using bool vector
        vector<bool> unique (101, false);
        int sum = 0, maxNeg = INT_MIN;
        for(int &num : nums){
            if(num <= 0){
                maxNeg = max(maxNeg, num);
            } else if(! unique[num]){
                sum += num;
                unique[num] = true;
            }
        }

        return sum == 0 ? maxNeg : sum;
    }
};


/*
    By using SET Concept
            int maxSum(vector<int>& nums) {
        unordered_set <int> st;
        int sum = 0, maxNeg = INT_MIN;

        for(int &num : nums){
            if(num <= 0){
                maxNeg = max(maxNeg, num);
            } else if(!st.count(num)) {
                sum += num;
                st.insert(num);
            }
        }

        return sum == 0 ? maxNeg : sum;
    }
};

*/