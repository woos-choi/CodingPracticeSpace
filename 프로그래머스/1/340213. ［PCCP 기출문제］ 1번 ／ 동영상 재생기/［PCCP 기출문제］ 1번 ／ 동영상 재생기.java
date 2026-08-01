class Solution {
    
    public int convert(String data){
        return Integer.parseInt(data.substring(0,2)) * 60 + Integer.parseInt(data.substring(3,5));
    }
    
    public String solution(String video_len, String pos, String op_start, String op_end, String[] commands) {
        String answer ="";
    
        int pos_result = convert(pos);
        int video_result = convert(video_len);
        int op_start_result = convert(op_start);
        int op_end_result = convert(op_end);
        
        int n = commands.length;
        for(int i=0; i<n; i++){
            if(pos_result >= op_start_result && pos_result < op_end_result) pos_result = op_end_result;
            
            if(commands[i].equals("prev")){
                pos_result -= 10;
                if(pos_result < 0) pos_result = 0;
                if(pos_result >= op_start_result && pos_result < op_end_result) pos_result = op_end_result;
            }
            
            else if(commands[i].equals("next")){
                pos_result += 10;
                if(pos_result > video_result) pos_result = video_result;
                if(pos_result >= op_start_result && pos_result < op_end_result) pos_result = op_end_result;
            }
        }
        
        StringBuilder sb = new StringBuilder();
        int temp_min = pos_result / 60;
        int temp_sec = pos_result % 60;
        
        if(temp_min < 10) sb.append("0");
        sb.append(Integer.toString(temp_min));
        sb.append(":");
        if(temp_sec < 10) sb.append("0");
        sb.append(Integer.toString(temp_sec));
        
        answer = sb.toString();
        
        return answer;
    }
}