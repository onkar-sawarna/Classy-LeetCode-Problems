class Solution {
public:
    int minimumMoves(string s) {
        int n = s.size();
        int c=0;
        for(int i=0;i<n;i++){
            if(s[i] == 'X'){
                i+=2;
                c++;
            }
            else
                continue;
        }
        return c;
    }
};