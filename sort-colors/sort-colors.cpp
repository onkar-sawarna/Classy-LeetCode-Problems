class Solution {
public:
    void sortColors(vector<int>& a) {
        int low,high,mid;
        low=mid=0;
        //keep all the zeros on the left of low 
        //and all the two's on the right of high
        high=a.size()-1;
        while(mid<=high){
            if(a[mid] == 0){
                swap(a[low],a[mid]);
                low++;
                mid++;
            }
            else if(a[mid] == 1){
                mid++;
            }
            else{
                swap(a[mid],a[high]);
                high--;
            }
        }
    }
};