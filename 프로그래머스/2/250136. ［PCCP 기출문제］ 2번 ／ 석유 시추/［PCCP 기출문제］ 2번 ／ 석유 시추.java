import java.util.*;

class Solution {
    
    int[] dr = {-1,1,0,0};
    int[] dc = {0,0,-1,1};
    
    boolean[][] visited;
    int n, m;
    int[][] land;
    int answer;
    
    int[] sum;
    
    public int solution(int[][] land) {
        this.land = land;
        n = land.length;
        m = land[0].length;
        visited = new boolean[n][m];
        sum = new int[m];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(land[i][j] == 1 && visited[i][j] == false){
                    visited[i][j] = true;
                    Deque<int[]> q = new ArrayDeque<>();
                    Set<Integer> s = new HashSet<>();
                    s.add(j);
                    int cnt = 1;
                    q.offer(new int[]{i,j});
                    
                    while(!q.isEmpty()){
                        int[] node = q.poll();
                        int r = node[0], c = node[1];
                        
                        for(int d=0; d<4; d++){
                            int nr = r + dr[d];
                            int nc = c + dc[d];
                            
                            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                            if(visited[nr][nc] == true) continue;
                            if(land[nr][nc] == 0) continue;
                            
                            visited[nr][nc] = true;
                            s.add(nc);
                            cnt++;
                            q.offer(new int[]{nr,nc});
                        }
                    }
                    
                    for(int s_index : s) sum[s_index] += cnt;
                }
            }
        }
        
        for(int i=0; i<m; i++) answer = Math.max(answer,sum[i]);
        
        return answer;
    }
}