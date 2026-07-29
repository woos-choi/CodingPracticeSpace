// 이분 탐색을 활용해야하는건가
// 테케가 아무리 해봐야 천만회라 굳이 이분 탐색으로 탐색 범위를 쭐일 필요는 없을것 같음

/*
배열 길이 .size()가 아니라 .length에다가 괄호도 안붙는거였나?
*/
import java.util.*;
import java.io.*;

class Solution {
    public int solution(int[] citations) {
        
        int answer = 0;
        int n = citations.length;
        Arrays.sort(citations);
        
        for(int i=0; i<n; i++){
            int h = n - i;
            if(citations[i] >= h) return h;
        }
        return 0;
        
        
    
    }
}