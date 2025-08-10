class Solution {
public:
    /*Convert num => string
    sort that string and return
    For power of 2: just left shift by 'p' times
    */
    string getSortedNum(int num){
        string s = to_string(num);
        sort(begin(s),end(s));
        return s;
    }
    bool reorderedPowerOf2(int n) {
        string input = getSortedNum(n);

        for(int p = 0; p <= 29; p++){
            if(input == getSortedNum( 1 << p)){
                return true;
            }
        }
        return false;
    }
};


/*just here we stored result of powers in set and 
    then "return st.count(input);"
*/
class Solution {
public:
    unordered_set<string> st;
    void buildSet(){
        for(int i = 0; i <= 29; i++){
            string s = to_string(1 << i);
            sort(begin(s),end(s));
            st.insert(s);
        }
    }
    
    bool reorderedPowerOf2(int n) {
        if(st.empty()){
            buildSet();
        }
        string input = to_string(n);
        sort(begin(input),end(input));
        return st.count(input);
    }
};



/* store digit count in integer.. by using "n += pow(10, num%10);"
and then compare
*/
class Solution {
public:
    int getNumCount(int num){
        int n = 0;
        while(num){
            n += pow(10, num%10);
            num /= 10;
        }
        return n;
    }
    bool reorderedPowerOf2(int n) {
        int input = getNumCount(n);
        for(int i = 0; i <= 29; i++){
            if(input == getNumCount( 1 << i)){
                return true;
            }
        }
        return false;
    }
};