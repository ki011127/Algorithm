import java.util.*;

class Solution {
    public int solution(int[] stones, int k) {
        int lo = 1;
        int hi = 0;
        for (int s : stones) hi = Math.max(hi, s);

        int ans = 0;
        while (lo <= hi) {
            int mid = lo + (hi - lo) / 2;
            if (canCross(stones, k, mid)) {
                ans = mid;
                lo = mid + 1;
            } else {
                hi = mid - 1;
            }
        }
        return ans;
    }

    private boolean canCross(int[] stones, int k, int people) {
        int broken = 0;
        for (int s : stones) {
            if (s - people < 0) {
                broken++;
                if (broken >= k) return false;
            } else {
                broken = 0;
            }
        }
        return true;
    }
}
