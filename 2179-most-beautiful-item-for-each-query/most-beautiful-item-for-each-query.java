class Solution {
    int binary_search(int[][] items,int target){
        int ans=0;
        int l=0,r=items.length-1;
        while(l<=r){
            int mid=l+(r-l)/2;
            if(items[mid][0]<=target){
                ans=Math.max(ans,items[mid][1]);
                l=mid+1;
            }else{
                r=mid-1;
            }
        }
        return ans; 
    }
    public int[] maximumBeauty(int[][] items, int[] queries) {
        int n=items.length;
        Arrays.sort(items,(a,b)->{
            return a[0]-b[0];
        });
        for(int i=1;i<n;i++){
            items[i][1]=Math.max(items[i][1],items[i-1][1]);
        }
        int len=queries.length;
        int ans[]=new int[len];
        for(int i=0;i<len;i++){
            ans[i]=binary_search(items,queries[i]);
        }

        return ans;
    }
}