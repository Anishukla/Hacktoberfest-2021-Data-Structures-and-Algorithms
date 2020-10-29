class Solution {
    
    boolean result = true;
    int[] visited;
    
    public boolean canFinish(int numCourses, int[][] prerequisites) {
        
        visited = new int[numCourses];
        
        // Making an adjacency list
        ArrayList<ArrayList<Integer>> adjacencyList = new ArrayList<ArrayList<Integer>>();
        
        for (int i = 0; i < numCourses; i++) {
            adjacencyList.add(new ArrayList<Integer>());
        }
        
        for (int i = 0; i < prerequisites.length; i++) {
            int x = prerequisites[i][0];
            int y = prerequisites[i][1];
            
            adjacencyList.get(x).add(y);
        }
             
        for (int i = 0; i < numCourses; i++) {
            if (visited[i] == 0) {
                detectCycle(i, new HashSet<Integer>(), adjacencyList);
            }            
        }
        
        return result;
        
    }
    
    public void detectCycle(int node, HashSet path, ArrayList<ArrayList<Integer>> adjacencyList){
        visited[node] = 1;
        
        path.add(node);
        
        for (int i = 0; i < adjacencyList.get(node).size(); i++) {
            int connectedNode = adjacencyList.get(node).get(i);
            
            if (path.contains(connectedNode)) {
                result = false;
                return;
            }
            
            if (visited[connectedNode] == 0) {
                detectCycle(connectedNode, path, adjacencyList);
            }
        }
        
        path.remove(node);
    }
}