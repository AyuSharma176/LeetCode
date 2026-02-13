class Solution {
    public String kthDistinct(String[] arr, int k) {
        Set<String> notDistinct = new HashSet<>();
        Set<String> all = new HashSet<>();
        for (String str : arr) if (!all.add(str)) notDistinct.add(str);
        for (String str : arr) if (!notDistinct.contains(str) && --k == 0) return str;
        return "";
    }
}