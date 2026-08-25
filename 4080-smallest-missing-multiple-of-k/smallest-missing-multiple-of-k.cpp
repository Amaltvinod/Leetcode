class Solution {
public:
    int missingMultiple(vector<int>& nums, int k) {
        map<int,int>map;
        for(int a:nums){
            map[a]++;
        }
        for(int i=1;i<=1e9;i++){
            if(!map.count(i*k))return i*k;
        }
        return -1;
    }
};