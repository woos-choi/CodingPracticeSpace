import java.util.*;

/*
순열 백트래킹이라는걸 인지하고 들어갈 것
백트래킹도 결국 DFS의 일종임을 계속 인지하고 있을 것
*/

class Solution {
    int answer;
    int[] numbers;
    int target;
    int n;
    
    public int solution(int[] numbers, int target) {
        this.numbers = numbers;
        this.target = target;
        n = numbers.length;
        
        DFS(0,0);
        
        return answer;
    }
    
    public void DFS(int depth, int sum){
        if(depth == n){
            if(sum == target) answer++;
            return;
        }
        
        DFS(depth + 1, sum + numbers[depth]);
        DFS(depth + 1, sum - numbers[depth]);
    }
}