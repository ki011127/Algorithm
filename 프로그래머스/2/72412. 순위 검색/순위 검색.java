import java.util.*;

class Solution {
    public int[] solution(String[] info, String[] query) {
        int[] answer = new int[query.length];
        
        ArrayList<Integer>[] arr = new ArrayList[24];
        String[] languages = {"cpp", "java", "python"};
        String[] jobs = {"backend", "frontend"};
        String[] years = {"junior", "senior"};
        String[] foods = {"chicken", "pizza"};
        for (int i = 0; i < arr.length; i++) {
            arr[i] = new ArrayList<>();
        }
        
        for(int i = 0; i<info.length; i++){
            String[] person_info = info[i].split(" ");
            String language = person_info[0];
            String job = person_info[1];
            String year = person_info[2];
            String food = person_info[3];
            int score = Integer.parseInt(person_info[4]);
            int index = 0;
            for(int j = 0; j<languages.length; j++){
                if(language.equals(languages[j])){
                    index+=(8*j);
                    break;
                }
            }
            for(int j = 0; j<jobs.length; j++){
                if(job.equals(jobs[j])){
                    index+=(4*j);
                    break;
                }
            }
            for(int j = 0; j<years.length; j++){
                if(year.equals(years[j])){
                    index+=(2*j);
                    break;
                }
            }
            for(int j = 0; j<foods.length; j++){
                if(food.equals(foods[j])){
                    index+=j;
                    break;
                }
            }
            arr[index].add(score);
        }
        for (int i = 0; i < arr.length; i++) {
            Collections.sort(arr[i]);
        }

        
        for(int i = 0; i<query.length; i++){
            String[] parts = query[i].replaceAll(" and ", " ").split(" ");
            String language = parts[0];
            String job = parts[1];
            String year = parts[2];
            String food = parts[3];
            int score = Integer.parseInt(parts[4]);
            ArrayList<Integer> idxs = new ArrayList<>();
            for (int li = 0; li < 3; li++) {
                if (!language.equals("-") && !language.equals(languages[li])) continue;
                for (int ji = 0; ji < 2; ji++) {
                    if (!job.equals("-") && !job.equals(jobs[ji])) continue;
                    for (int yi = 0; yi < 2; yi++) {
                        if (!year.equals("-") && !year.equals(years[yi])) continue;
                        for (int fi = 0; fi < 2; fi++) {
                            if (!food.equals("-") && !food.equals(foods[fi])) continue;
                            int idx = li*8 + ji*4 + yi*2 + fi;
                            idxs.add(idx);
                        }
                    }
                }
            }
            int count = 0;
            for (int idx : idxs) {
                ArrayList<Integer> scores = arr[idx];
                int pos = lowerBound(scores, score);
                count += scores.size() - pos;
            }
            answer[i] = count;
        }
        
        
        
        return answer;
    }
    public int lowerBound(List<Integer> list, int key) {
        int left = 0, right = list.size();
        while (left < right) {
            int mid = (left + right) / 2;
            if (list.get(mid) >= key) {
                right = mid;
            } else {
                left = mid + 1;
            }
        }
        return left;
    }
}