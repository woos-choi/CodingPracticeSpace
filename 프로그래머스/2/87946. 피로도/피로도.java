import java.util.*;

/*
1. 입장하기 위한 '최소 필요 피로도'
2. 마쳤을 떄 소모되는 '소모 필요도'

k는 현재 피로도, 2차원 배열은 '최소 필요 피로도 , 소모 필요도'
근데 최대한 많이 돌려면 정렬을 하는게 좋겠지?
*/


class Solution {
    int k;
    int[][] dungeons;
    int answer = 0;
    boolean[] visited;
    
    public int solution(int k, int[][] dungeons) {
        this.k = k;
        this.dungeons = dungeons;
        visited = new boolean[dungeons.length]; //자동 초기화
        
        dfs(0, k);
        
        return answer;
    }
    
    public void dfs(int depth, int sum){
        answer = Math.max(answer,depth);
        
        for(int i=0; i<dungeons.length; i++){
            if(visited[i] == true) continue;
            if(sum < dungeons[i][0]) continue;
            
            visited[i] = true;
            dfs(depth + 1, sum - dungeons[i][1]);
            visited[i] = false;
        }
    }
}