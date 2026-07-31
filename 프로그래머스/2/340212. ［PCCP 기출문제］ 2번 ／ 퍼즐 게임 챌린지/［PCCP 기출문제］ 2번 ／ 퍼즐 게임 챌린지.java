import java.util.*;

/*

*/

class Solution {
    
    int n;
    long answer = 300001;
    
    public long solution(int[] diffs, int[] times, long limit) {
        n = diffs.length;
        
        
        long left = 1, right = 300000;
        while(left <= right){
            long mid = (left + right) / 2;
            
            long sum = 0;
            for(int i=0; i<n; i++){
                if(diffs[i] <= mid) sum += times[i];
                else sum += (diffs[i] - mid + 1) * times[i] + (diffs[i] - mid) * times[i-1];
            }
            
            
            if(sum <= limit) {
                answer = Math.min(answer,mid);
                right = mid - 1;
            }
            
            else left = mid + 1;
            
        }
        
        return answer;
    }
}