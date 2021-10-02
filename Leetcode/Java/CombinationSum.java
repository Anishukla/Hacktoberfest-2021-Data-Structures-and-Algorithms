// Author: Samrat Mitra
// Problem URL: https://leetcode.com/problems/combination-sum/

class Solution {
    public List<List<Integer>> combinationSum(int[] candidates, int target) {
        if(candidates == null) return null;
        // Create the solution matrix
        List<List<Integer>> solution = new ArrayList<>();
        // Call the recursive function
        // the arraylist will contain one set of numbers that make upto target
        dfs(candidates, 0, target, new ArrayList<>(), solution); 
        return solution;
    }
    public void dfs(int[] candidates, int index, int target, List<Integer> current, List<List<Integer>> solution) {
        // Get the base condition
        // When we get target as 0 we know that we have a set of solution
        if(target == 0) {
            // Current list contains the set of nunmbers that sums upto the target
            solution.add(new ArrayList<>(current));
            return;
        }
        for(int i=index; i<candidates.length; i++) {
            if(candidates[i] <= target) {
                current.add(candidates[i]);
                dfs(candidates, i, target - candidates[i], current, solution);
                // Explore the others basically backtrack
                current.remove(new Integer(candidates[i]));
            }
        }
    }
}
