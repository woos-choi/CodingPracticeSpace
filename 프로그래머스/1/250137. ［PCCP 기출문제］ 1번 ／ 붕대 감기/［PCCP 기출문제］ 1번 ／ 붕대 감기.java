import java.util.*;

/*
조건
1. t초마다 붕대를 감으면서 1초마다 x만틈의 체력 회복
2. t초 연속 붕대 감기 성공시, y만큼의 체력 추가 회복

전제 
1. 최대 체력보다 현재 체력이 커지는 것은 불가능
2. 기술을 쓰는 도중 공격 당하면 기술 취소, 공격 당하는 순간 회복 불가능
3. 공격 당해서 기술 취소, 기술 종료 시 즉시 붕대 감기 시전 후, 연속 성공 시간 0으로 초기화
*/

//1. 몬스터 공격 당하면 count 초기화하기
//2. 최대 count 도달 시 count 초기화하기
//3. 모든 상황에서 최대 체력은 절대 넘지 못하도록 하기

//bandage [ 시전시간, 초당 회복량, 추가 회복량 ] = [t, x, y]
//health = 최대체력
//attacks = [공격시간, 피해량] - 공격시간이 걸리는 시간이 아니라, 그냥 시점임을 이해할 것

class Solution {
    public int solution(int[] bandage, int health, int[][] attacks) {
        int answer = health;
        int t = bandage[0];
        int x = bandage[1];
        int y = bandage[2];
        
        int n = attacks.length;
        int time = attacks[n-1][0];
        
        int t_cnt = 0;
        int a_index = 0;
        for(int i=1; i<=time; i++){
            if(attacks[a_index][0] != i){
                t_cnt++;
                if(t_cnt == t){
                    t_cnt = 0;
                    if(answer + x + y <= health) answer += x + y;
                    else answer = health;
                }
                
                else{
                    if(answer + x <= health) answer += x;
                    else answer = health;
                }
            }
            
            else{
                t_cnt = 0;
                if(answer - attacks[a_index][1] > 0) {
                    answer -= attacks[a_index][1];
                    a_index++;
                }
                else return -1;
            }
        }
        return answer;
    }
}