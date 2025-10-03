import java.util.*;

class Solution {
    public String solution(int n, int t, int m, String[] timetable) {
        PriorityQueue<Person> pq = new PriorityQueue<>();
        for(int i = 0; i<timetable.length; i++){
            String[] time = timetable[i].split(":");
            int h = Integer.parseInt(time[0]);
            int minute = Integer.parseInt(time[1]);
            
            pq.offer(new Person(h,minute));
        }
        
        int start_h = 9;
        int start_m = 0;
        int bus_count = 1;
        int max_h = 0;
        int max_m = 0;
        int person_count=0;
        while(bus_count<=n){
            person_count = 0;
            while(person_count<m && pq.size()!=0){
                Person p = pq.peek();
                if(p.hour>start_h || (p.hour==start_h && p.minute>start_m)){
                    break;
                }
                max_h = p.hour;
                max_m = p.minute;
                pq.poll();
                person_count++;
            }
            bus_count++;
            if(bus_count==n+1){
                break;
            }
            if(start_m+t>=60){
                start_h += 1;
                start_m = start_m+t-60;
            }
            else{
                start_m += t;
            }
        }

        if(person_count<m){
            max_h = start_h;
            max_m = start_m;
        }
        else{
            if(max_m==0){
                max_h -= 1;
                max_m = 59;
            }
            else{
                max_m--;
            }
        }
        return String.format("%02d", max_h)+":"+String.format("%02d", max_m);
    }
    
    class Person implements Comparable<Person>{
        int hour;
        int minute;
        public Person(int hour, int minute){
            this.hour = hour;
            this.minute = minute;
        }
        
        @Override
        public int compareTo(Person o){
            if(this.hour == o.hour){
                return this.minute-o.minute;
            }
            return this.hour - o.hour;
        }
    }
}