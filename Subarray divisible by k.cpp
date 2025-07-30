//974. Subarray Sums Divisible by K
/*sum will calculate Cumulative sum...
if sum1%k = x & sum2%k = x ==> (sum2 - sum1)% k ==0
and also remainder is Negative the add k to get positive remainder...

remainder : count do calulate and if(mp.find(rem) != ,p.end() ==> result += mp[rem]); mp[rem]++;
                                    else{ mp[rem] = 1; i.e. rem not yet get}
*/
class Solution {
public:
    int subarraysDivByK(vector<int>& nums, int k) {
        int result = 0, sum = 0, n = nums.size();
        unordered_map<int, int> mp;
        mp[0] = 1;

        for(int i = 0; i< n; i++){
            sum += nums[i];

            int rem = sum % k;
            if(rem < 0){    rem += k;   }
            if(mp.find(rem) != mp.end()){
                result += mp[rem];
                mp[rem]++;
            }else{
                mp[rem] = 1;
            }
        }

        return result;
    }
};