import java.util.*;
class Solution {
    int[] discounts = {10,20,30,40};
    int max_people = 0;
    int max_sales = 0;
    public int[] solution(int[][] users, int[] emoticons) {
        dfs(0, new int[emoticons.length], users, emoticons);
        return new int[]{max_people, max_sales};
    }
    private void dfs(int depth, int[] discountRates, int[][] users, int[] emoticons) {
        if (depth == emoticons.length) {
            evaluate(discountRates, users, emoticons);
            return;
        }
        for (int d : discounts) {
            discountRates[depth] = d;
            dfs(depth + 1, discountRates, users, emoticons);
        }
    }

    private void evaluate(int[] discountRates, int[][] users, int[] emoticons) {
        int subscribers = 0;
        int sales = 0;

        for (int[] user : users) {
            int minDiscount = user[0];
            int priceLimit = user[1];

            int sum = 0;
            for (int i = 0; i < emoticons.length; i++) {
                if (discountRates[i] >= minDiscount) {
                    int discountedPrice = emoticons[i] * (100 - discountRates[i]) / 100;
                    sum += discountedPrice;
                }
            }

            if (sum >= priceLimit) {
                subscribers++;
            } else {
                sales += sum;
            }
        }

        if (subscribers > max_people) {
            max_people = subscribers;
            max_sales = sales;
        } else if (subscribers == max_people) {
            max_sales = Math.max(max_sales, sales);
        }
    }
}