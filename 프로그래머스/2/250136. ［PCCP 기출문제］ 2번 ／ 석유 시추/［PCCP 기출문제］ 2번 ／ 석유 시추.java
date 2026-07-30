import java.util.*;

/*
1. 시추를 열에 박는건 확정이니까 열에 박고
2. 박았을 때 열을 스캔해서 석유가 있는 위치를 그냥 queue에 다 박아서 BFS ,DFS 등의 완탐을 진행
3. 이렇게 해서 count를 올리기 그래서 max값을 도출해낼 것

1이 석유가 있는 곳
*/

class Solution {
    int[] dr = {-1,1,0,0};
    int[] dc = {0,0,-1,1};

    public int solution(int[][] land) {
        int answer = 0;
        int n = land.length;
        int m = land[0].length;
        boolean[][] visited = new boolean[n][m];
        
        int[] sum = new int[m];
        
        for(int i=0; i<n; i++){
            for(int j=0; j<m; j++){
                if(visited[i][j] == false && land[i][j] == 1){
                    //System.out.println(i + " " + j +" 에 석유 있음");
                    Deque<int[]> q = new ArrayDeque<>();
                    Set<Integer> s = new HashSet<>();
                    int cnt = 1;
                    s.add(j);
                    
                    visited[i][j] = true;
                    q.offer(new int[]{i,j});
                    
                    while(!q.isEmpty()){
                        int[] node = q.poll();
                        int r = node[0], c = node[1];
                        
                        for(int d=0;d<4;d++){
                            int nr = r + dr[d];
                            int nc = c + dc[d];
                            
                            if(nr < 0 || nc < 0 || nr >= n || nc >= m) continue;
                            if(visited[nr][nc] == true) continue;
                            if(land[nr][nc] == 0) continue;
                            
                            visited[nr][nc] = true;
                            s.add(nc);
                            q.offer(new int[]{nr,nc});
                            cnt++;
                        }
                    }
                    
                    
                    for(int s_index : s) sum[s_index] += cnt;
                }
            }
        }        
        
        for(int i=0; i<sum.length; i++) answer = Math.max(answer,sum[i]);
        
        return answer;
    }
}