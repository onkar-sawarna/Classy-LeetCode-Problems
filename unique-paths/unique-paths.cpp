class Solution {
public:
    int uniquePaths(int m, int n) {
        int N = n+m-2;
        int R = m-1;
        double ans=1;
        for(int i=1;i<=R;i++){
            ans *= (N-R+i);
            ans /= (i);
        }
        return (int)ans;
    }
};