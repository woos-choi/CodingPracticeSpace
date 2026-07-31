/*
1. 최단거리니까 BFS
2. 격자는 끽해봐야 100*100
*/
import java.util.*;

class Solution {
    int[] dr = {-1,1,0,0};
    int[] dc = {0,0,-1,1};
    
    int n, m;
    int answer = -1;
    int[][] maps;
    Deque<int[]> q = new ArrayDeque<>();
    boolean [][] visited;
    
    public int solution(int[][] maps) {
        this.maps = maps;
        n = maps.length;
        m = maps[0].length;
        visited = new boolean[n][m];
        
        q.offer(new int[]{0,0,1});
        visited[0][0] = true;
        
        while(!q.isEmpty()){
            int[] node = q.poll();
            int r = node[0], c = node[1], distance = node[2];
            
            if(r == n-1 && c == m-1)  answer = node[2];
               
        
            
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(visited[nr][nc] == true) continue;
                if(maps[nr][nc] == 0) continue;
                
                visited[nr][nc] = true;
                q.offer(new int[]{nr,nc,distance + 1});
            }
        }
        
        System.out.println(answer);
        return answer;
    }
}