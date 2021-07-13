class Solution {
public:
    int majorityElement(vector<int>& nums) {
        int Element;
        int count=0;
        for(int i=0;i<nums.size();i++){
            if(count == 0){
                Element=nums[i];
            }
            if(nums[i] == Element)count++;
            else count--;
        }
        return Element;
    }
};