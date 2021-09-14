class Solution {
public:
    vector<int> asteroidCollision(vector<int>& asteroids) {
        vector<int> vec;
        int n = asteroids.size();
        for(int i=0;i<n;i++){
            while(!vec.empty() and vec.back()<-asteroids[i] and vec.back()>0)
                vec.pop_back();
            if(vec.empty() || asteroids[i]>0 || vec.back()<0)
                vec.push_back(asteroids[i]);
            else if(!vec.empty() and vec.back() == -asteroids[i] and asteroids[i] < 0)
                vec.pop_back();
        }
        return vec;
    }
};