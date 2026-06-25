class Solution {
public:
    int countMajoritySubarrays(vector<int>& nums, int target) {
        int n=nums.size();
        int cnt=0;
        
      for(int i=0;i<n;i++){
        map<int,int>map;
        for(int j=i;j<n;j++){
            map[nums[j]]++;
            int len=j-i+1;
            if(map[target]*2>len)cnt++;

        }
      }
      return cnt;
   
    }
};