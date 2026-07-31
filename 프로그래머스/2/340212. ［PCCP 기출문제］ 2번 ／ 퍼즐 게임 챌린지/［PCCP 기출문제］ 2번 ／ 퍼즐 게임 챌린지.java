import java.util.*;

/*
이분 탐색(파라매트릭 서치) 하라는것 같음
n개의 퍼즐을 제한 시간 내에 풀어라
난이도와 소요 시간이 정해져 있다
개인 자체의 숙련도에 따라 틀린 횟수도 달라진다

diff - 퍼즐 자체의 낭이도, level - 내 숙련도

1. diff <= level이면 틀리지 않고 time_cur만큼의 시간 사용하여 해결
2. diff > level이면 diff -level 만큼 틀리고, time_cur 만큼의 시간을 사용, time_prev 만큼의 시간을 사용해 이전 퍼즐을 다시 풀어라
3. 다시 풀때는 무조건 맞춘다

ex) 
diff = 3 time_cur=2 time_prev=4
level = 1
 3 * time_cur + 2 * time_prev
level = 2
 2 * time_cur + 1 * time_prev
 
 전체 제한 시간이 걸려있는데 limit안에 풀 수 있는 level의 최솟값을 구한다
*/

//diff에는 퍼즐 자체의 난이도, times에는 해당 퍼즐 단계의 소요 시간
class Solution {
    public long solution(int[] diffs, int[] times, long limit) {
        long answer = 300001;
        
        long left = 1, right = 300000;
        
        while(left <= right){
            long mid = (left + right) / 2;
            
            long temp = 0;
            for(int i=0; i<diffs.length; i++){
                if(diffs[i] <= mid) temp += times[i];
                else temp += ((diffs[i] - mid + 1) * times[i] + (diffs[i] - mid) * times[i - 1]);
                
            }
            
            //System.out.println("left : " + left + " right : " + right + " temp : " + temp + " answer : " + answer); 
            
            if(temp <= limit){
                answer = Math.min(answer, mid);
                right = mid - 1;
            }
            
            else left = mid + 1;
        }
        
        return answer;
    }
}