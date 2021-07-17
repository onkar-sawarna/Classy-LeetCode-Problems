class Solution {
public:
    string getPermutation(int n, int k) {
        //as we are planning for 0 index solution
        k=k-1;
        vector<int> numbers;
        int fact=1;
        //compute the factorial and store the numbers in a vector
        for(int i=1;i<n;i++){
            fact*=i;
            numbers.push_back(i);
        }
        numbers.push_back(n);
        string ans="";
        while(1){
            ans+=to_string(numbers[k/fact]);
            numbers.erase(numbers.begin()+ k/fact);
            if(numbers.size()==0)
                break;
            k=k%fact;
            //if fact was of n then Our target is to get fact(n-1)
            //as every time the size of number gets decreased by 1 so its how we compute
            fact=fact/numbers.size();
        }
        return ans;
    }
};