import java.util.*;

class Solution {
    private int topoBFS(int V, List<List<Integer>> adj) {
        int[] indegree = new int[V];

        for (int i = 0; i < V; i++) {
            for (int nbr : adj.get(i)) {
                indegree[nbr]++;
            }
        }

        Queue<Integer> q = new LinkedList<>();
        for (int i = 0; i < V; i++) {
            if (indegree[i] == 0) {
                q.add(i);
            }
        }

        int count = 0;
        while (!q.isEmpty()) {
            int node = q.poll();
            count++;

            for (int nbr : adj.get(node)) {
                indegree[nbr]--;
                if (indegree[nbr] == 0) {
                    q.add(nbr);
                }
            }
        }

        return count; 
    }

    public boolean canFinish(int numCourses, int[][] prerequisites) {
        List<List<Integer>> adj = new ArrayList<>();
        for (int i = 0; i < numCourses; i++) {
            adj.add(new ArrayList<>());
        }

        for (int[] pre : prerequisites) {
            int course = pre[0];
            int prereq = pre[1];
            adj.get(prereq).add(course);
        }
        int completed = topoBFS(numCourses, adj);

        return completed == numCourses;
    }
}
