//1590. Make Sum Divisible by P

class Solution {
public:
    int minSubarray(vector<int>& nums, int p) {
        unordered_map<int, int> mp; //prev su%p ko store karega
        int curr = 0; mp[0] = -1;
        int sum = 0, n = nums.size();
        int minLen = n;

        //(a+b)%p = (a%p + b%p)
        for(int j = 0; j < n; j++){
            sum = (sum + nums[j])% p;
        }
        int target = sum % p;

        if(target == 0){
            return 0;
        }

        for(int j = 0; j < n; j++){
            curr = (curr + nums[j]) % p;

            int remain = (curr - target + p) % p;
            if(mp.find(remain) != mp.end()){
                int length = j - mp[remain];
                minLen = min(length, minLen);
                
            } 
            mp[curr] = j;
        }
        return minLen == n ? -1 : minLen;
    }
};