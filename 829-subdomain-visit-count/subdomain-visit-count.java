class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String>arr=new ArrayList<>();
        HashMap<String,Integer>map=new HashMap<>();
        for(String s:cpdomains){
            String []subdomain=s.split(" ");
            String []domain=subdomain[1].split("\\.");
            String cur="";
            int cnt=Integer.parseInt(subdomain[0]);
            for(int i=domain.length-1;i>=0;i--){
                cur=domain[i]+cur;
                map.put(cur,map.getOrDefault(cur,0)+cnt);
                cur="."+cur;
            }
        }

        for(Map.Entry<String,Integer>entry:map.entrySet()){
            arr.add(Integer.toString(entry.getValue())+" "+entry.getKey());
        }
        return arr;
    }
}