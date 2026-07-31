import java.util.*;

/*
1. prev를 입력할 경우 10초전으로 이동, 현재 위치가 10초 미만인 경우 처음 위치로 이동
2. next를 입력할 경우 10초 후로 이동, 현재 위치가 끝에서 10초 이내일 경우 마지막 위치로 이동
3. 오프닝 건너뛰기, 현재 재생 위치가 오프닝 구간에 있으면 자동으로 오프닝 끝나는 위치로 이동
*/


//video_len : 동영상 길이, pos : 기능 수행전 직전 위치
class Solution {
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer = "";
        
        int op_start_min = Integer.parseInt(op_start.substring(0,2));
        int op_start_sec = Integer.parseInt(op_start.substring(3,5));
        int op_start_t = op_start_min * 60 + op_start_sec;
        
        int op_end_min = Integer.parseInt(op_end.substring(0,2));
        int op_end_sec = Integer.parseInt(op_end.substring(3,5));
        int op_end_t = op_end_min * 60 + op_end_sec;
        
        int pre_min = Integer.parseInt(pos.substring(0,2));
        int pre_sec = Integer.parseInt(pos.substring(3,5));
        int pre = pre_min * 60 + pre_sec;
        
        int video_min = Integer.parseInt(video_len.substring(0,2));
        int video_sec = Integer.parseInt(video_len.substring(3,5));
        int video = video_min * 60 + video_sec;
        
        
        for(int i=0; i<commands.length; i++){
            
            if(pre >= op_start_t && pre < op_end_t) pre = op_end_t;
            
            if(commands[i].equals("prev")){
                pre -= 10;
                if(pre < 0) pre = 0;
            }
            
            else if(commands[i].equals("next")){
                pre += 10;
                if(pre > video) pre = video;
            }
        }
        
        if(pre >= op_start_t && pre < op_end_t) pre = op_end_t;
        int result_min = pre / 60;
        int result_sec = pre % 60;
        
        StringBuilder sb = new StringBuilder();
        if(result_min < 10) sb.append("0");
        sb.append(String.valueOf(result_min));
        sb.append(":");
        if(result_sec < 10) sb.append("0");
        sb.append(String.valueOf(result_sec));
        
        answer = sb.toString();
        
        return answer;
    }
}