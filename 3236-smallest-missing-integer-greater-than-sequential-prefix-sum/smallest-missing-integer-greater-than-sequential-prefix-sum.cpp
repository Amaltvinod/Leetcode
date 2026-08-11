class Solution {
public:
    int missingInteger(vector<int>& nums) {
        int ans=1;
        int sum=nums[0];
        int n=nums.size();
        for(int i=1;i<n;i++){
            if(nums[i]-1==nums[i-1]){
                sum+=nums[i];
            }else{
                break;
            } 
            
         
        }
        unordered_map<int,int>map;
        for(int a:nums){
            map[a]++;
        }
        while(sum){
            if(map.count(sum))sum++;
            else return sum;
        }
        return sum;
    
    }
};