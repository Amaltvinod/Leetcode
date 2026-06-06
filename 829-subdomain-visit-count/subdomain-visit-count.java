class Solution {
    public List<String> subdomainVisits(String[] cpdomains) {
        List<String>arr=new ArrayList<>();
        HashMap<String,Integer>map=new HashMap<>();
        for(String s:cpdomains){
            String []subdomain=s.split(" ");
            
            for(int i=0;i<subdomain[1].length();i++){
                 int cnt=Integer.parseInt(subdomain[0]);
                if(subdomain[1].charAt(i)=='.'){
                    String curDomain=subdomain[1].substring(i+1,subdomain[1].length());
                    map.put(curDomain,map.getOrDefault(curDomain,0)+cnt);
                }else if(i==0){
                    map.put(subdomain[1],map.getOrDefault(subdomain[1],0)+cnt);
                }
            }
        }

        for(Map.Entry<String,Integer>entry:map.entrySet()){
            arr.add(Integer.toString(entry.getValue())+" "+entry.getKey());
        }
        return arr;
    }
}