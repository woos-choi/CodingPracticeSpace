import java.util.*;

class Solution {
    int[] dr = {-1,1,0,0};
    int[] dc = {0,0,1,-1};
    boolean[][] visited;
    int n, m;
    int answer = -1;
    Deque<int[]> q = new ArrayDeque<>();
    int cnt = 0;
    
    public int solution(int[][] maps) {
        n = maps.length;
        m = maps[0].length;
        
        visited = new boolean[n][m];
        
        q.offer(new int[]{0,0,1});
        while(!q.isEmpty()){
            int[] node = q.poll();
            int r = node[0], c = node[1], distance = node[2];
            
            if(r == n-1 && c == m-1) answer = Math.max(answer,distance);
            
            for(int i=0; i<4; i++){
                int nr = r + dr[i];
                int nc = c + dc[i];
                
                if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                if(visited[nr][nc]) continue;
                if(maps[nr][nc] == 0) continue;
                
                visited[nr][nc] = true;
                q.offer(new int[]{nr,nc, distance + 1});
            }
        }
        
        
        return answer;
    }
}