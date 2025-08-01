class Solution {
    public String normalize(String s) {
        return s.replaceAll("C#", "c")
                .replaceAll("B#", "b")
                .replaceAll("D#", "d")
                .replaceAll("F#", "f")
                .replaceAll("G#", "g")
                .replaceAll("A#", "a");
    }
    public String solution(String m, String[] musicinfos) {
        String answer = "";
        int temp_answer_time = 0;
        
        m = normalize(m);
        int t = m.length();
        for(int i = 0; i<musicinfos.length; i++){
            String[] musicinfo = musicinfos[i].split(",");
            String start = musicinfo[0];
            String end = musicinfo[1];
            String music = musicinfo[2];
            String sing = normalize(musicinfo[3]);
            int time = 0;
            for(int j = 0; j<sing.length(); j++){
                if(sing.charAt(j)==m.charAt(0)){
                    time = j;
                    int m_start = 0;
                    int music_start = j;
                    while(m_start<m.length()){
                        if(sing.charAt(music_start)==m.charAt(m_start)){
                            music_start = (music_start+1)%sing.length();
                            m_start++;
                            time++;
                        }
                        else{
                            break;
                        }
                    }
                    
                    if(m_start==m.length()){
                        String[] start_time = start.split(":");
                        String[] end_time = end.split(":");
                        int total_time = (Integer.parseInt(end_time[0])*60+Integer.parseInt(end_time[1])) - (Integer.parseInt(start_time[0])*60+Integer.parseInt(start_time[1]));
                        if(total_time>temp_answer_time && t<=total_time && time<=total_time){
                            temp_answer_time = total_time;
                            answer = music;
                        }
                    }
                }
            }
        }
        if(answer.equals("")){
            return "(None)";
        }
        return answer;
    }
}