//2438. Range Product Queries of Powers
/* by using Bit manipulation.. compute powers of 2..
    store it in vector power..
    then usng queries vector compute product bet that range..
    strie it in vector result..*/

class Solution {
public:
    int M = 1e9 + 7;
    vector<int> productQueries(int n, vector<vector<int>>& queries) {
        vector<int> power;
        vector<int> result;
        int num = n;

        for(int i = 0; i<32; i++){
            if(num & 1){
                power.push_back(pow(2,i));
            }
            num = num >> 1;
        }

        for(auto &query :queries){
            int start = query[0];
            int end = query[1];
            long product = 1;

            for(int i = start; i<= end; i++){
                product = (product * power[i]) % M; 
            }
            result.push_back(product);
        }

        return result;
    }
};