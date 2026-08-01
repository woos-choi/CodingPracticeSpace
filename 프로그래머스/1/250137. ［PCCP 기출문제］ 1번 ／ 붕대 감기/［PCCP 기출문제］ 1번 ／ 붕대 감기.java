import java.util.*;

/*
1. t초 동안 1초마다 x 회복, t초 연속 성공시 y만큼의 체력 추가 회복
2. 최대 체력보다 커지는 것은 불가능
3. 공격 당할때는 연속이 초기화
*/

class Solution {
    
    //bandage [시전 시간, 초당 회복량, 추가 회복량]
    //attacks [공격을 시행하는 시간, 피해량]
    public int solution(int[] bandage, int health, int[][] attacks) {
        int n = attacks[attacks.length - 1][0];
        int time = bandage[0], health_sec = bandage[1], health_extra = bandage[2];
        int answer = health;
        
        int attack_index = 0;
        int cnt = 0;
        for(int i=1; i<=n; i++){
            if(i == attacks[attack_index][0]){
                cnt = 0;
                answer -= attacks[attack_index++][1];
                if(answer <= 0) return -1;
            }
            
            else{
                cnt++;
                if(cnt == time) {
                    answer += health_extra + health_sec;
                    cnt = 0;
                }
                else answer += health_sec;
                if(answer >= health) answer = health;
            }
            
            //System.out.println(answer);
        }
        
        return answer;
    }
}