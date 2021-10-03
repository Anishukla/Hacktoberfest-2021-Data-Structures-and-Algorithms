// Leetcode 3 - Longest Substring Without Repeating Characters

class Solution {
    public int lengthOfLongestSubstring(String s) {
        int start = 0;
        int max = 0;
        Map<Character, Integer> map = new HashMap<>();
        for(int end = 0; end < s.length(); end++) {
            char c = s.charAt(end);
            increment(map, c);
            while(map.get(c) > 1) {
                decrement(map, s.charAt(start));
                start++;
            }
            int len = end - start + 1;
            max = Math.max(max, len);
        }
        return max;
    }
    
    private void increment(Map<Character, Integer> map, char c) {
        if(map.containsKey(c)) {
            map.put(c, map.get(c) + 1);
        } else {
            map.put(c, 1);
        }
    }
    
    private void decrement(Map<Character, Integer> map, char c) {
        if(map.containsKey(c)) {
            int count = map.get(c);
            if(count == 1) {
                map.remove(c);
            } else {
                map.put(c, count - 1);
            }
        }
    }
}