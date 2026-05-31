class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        long sum=mass;
        sort(asteroids.begin(),asteroids.end());
        for(int asteroid:asteroids){
            if(asteroid>sum)return 0;
            sum+=asteroid;
        }
        return 1;
    }
};