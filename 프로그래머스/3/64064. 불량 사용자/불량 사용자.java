import java.util.*;

class Solution {
    Set<Integer> answerSet = new HashSet<>();
    List<List<Integer>> candidates = new ArrayList<>();

    void dfs(int idx, int bitmask, String[] banned_id) {
        if (idx == banned_id.length) {
            answerSet.add(bitmask);  // 고유 조합
            return;
        }
        for (int user : candidates.get(idx)) {
            if ((bitmask & (1 << user)) != 0) continue; // 이미 사용된 사용자
            dfs(idx + 1, bitmask | (1 << user), banned_id);
        }
    }

    public int solution(String[] user_id, String[] banned_id) {
        for (String ban : banned_id) {
            List<Integer> list = new ArrayList<>();
            for (int i = 0; i < user_id.length; i++) {
                if (user_id[i].length() != ban.length()) continue;
                boolean match = true;
                for (int k = 0; k < ban.length(); k++) {
                    if (ban.charAt(k) != '*' && ban.charAt(k) != user_id[i].charAt(k)) {
                        match = false;
                        break;
                    }
                }
                if (match) list.add(i);
            }
            candidates.add(list);
        }

        dfs(0, 0, banned_id);
        return answerSet.size();
    }
}
