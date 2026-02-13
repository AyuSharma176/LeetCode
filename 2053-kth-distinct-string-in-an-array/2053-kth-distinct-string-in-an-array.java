class Solution {
    public String kthDistinct(String[] arr, int k) {
        HashMap<String,Integer> map = new HashMap<>();
        for(String s: arr){
            map.put(s,map.getOrDefault(s,0)+1);
        }
        System.out.println(map);
        int count =0;
        // for(Map.Entry<String,Integer> entry: map.entrySet()){
        //     if(entry.getValue()==1){
        //         count++;
        //     }
        //     if(count==k){
        //         return entry.getKey();
        //     }
        // }
        for(int i=0;i<arr.length;i++){
            if(map.get(arr[i])==1){
                count++;
            }
            if(count==k){
                return arr[i];
            }
        }
        return "";
    }
}