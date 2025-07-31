//898. Bitwise ORs of Subarrays

class Solution {
public:
    int subarrayBitwiseORs(vector<int>& arr) {
        unordered_set<int> prev;
        unordered_set<int> curr;
        unordered_set<int> result;
        
        for(int &num : arr){
            curr.insert(num);
            result.insert(num);
            for(const int &x : prev){
                curr.insert(x | num);
                result.insert(x | num);
            }

            prev = curr;
            curr.clear();
        }

        return result.size();
    }
};

/*
arr [] = {1,2,3}
then pairs will be:
1

2, 1 | 2

3, 2 | 3, 1|2|3 
*/