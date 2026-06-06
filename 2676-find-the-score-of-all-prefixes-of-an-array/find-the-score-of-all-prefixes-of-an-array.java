class Solution {
    public long[] findPrefixScore(int[] nums) {
        int n=nums.length;
        long mx=Long.MIN_VALUE;
        long ans[]=new long[n];
        for(int i=0;i<n;i++){
            mx=Math.max(mx,nums[i]);
            ans[i]=nums[i]+mx;
            
        }
        for(int i=1;i<n;i++){
            ans[i]+=ans[i-1];
        }
        return ans;
    }
}