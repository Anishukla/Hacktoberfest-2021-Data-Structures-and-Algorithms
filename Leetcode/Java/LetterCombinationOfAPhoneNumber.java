// Author: Samrat Mitra
// Link to the problem: https://leetcode.com/problems/letter-combinations-of-a-phone-number/

class Solution {
    public List<String> letterCombinations(String digits) {
        List<String> answer = new ArrayList<>();
        // Check for input and call DFS
        if(digits != null && digits.length() > 0) {
            String letters[] = {"", "", "abc", "def", "ghi", "jkl", "mno", "pqrs", "tuv", "wxyz"};
            // Call the DFS Function
            dfs(digits, letters, answer, new StringBuilder(), 0); // 0 is the index,used to keep track of the explored letter
        }
        return answer;
    }
    public void dfs(String digits, String[] letters, List<String> answer, StringBuilder sb, int index) {
        // When we've reached the end of the phone number, we have a valid path (if we consider a tree) and we should have a valid               // letter combination
        if(index == digits.length()) {
            // Add the letter combination onto the answer
            answer.add(sb.toString());
            return;
        }
        // Get the current digit using the index and what it represents
        int digit = Character.getNumericValue(digits.charAt(index));
        String letter = letters[digit];
        
        // try adding each letter to the String we've built so far
        for(int i=0; i<letter.length(); i++) {
            char ch = letter.charAt(i);
            sb.append(ch);
            dfs(digits, letters, answer, sb, index + 1);
            // Take this String and move on to the next digit
            sb.deleteCharAt(sb.length() - 1);
        }
    }
}
