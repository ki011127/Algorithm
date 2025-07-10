import java.util.*;

class Solution {
    public int[] solution(String[] genres, int[] plays) {
        Map<String, Integer> genreTotalMap = new HashMap<>();
        Map<String, List<Song>> genreSongMap = new HashMap<>();

        for (int i = 0; i < genres.length; i++) {
            String genre = genres[i];
            int play = plays[i];

            genreTotalMap.put(genre, genreTotalMap.getOrDefault(genre, 0) + play);

            genreSongMap.putIfAbsent(genre, new ArrayList<>());
            genreSongMap.get(genre).add(new Song(i, play));
        }

        List<String> sortedGenres = new ArrayList<>(genreTotalMap.keySet());
        sortedGenres.sort((a, b) -> genreTotalMap.get(b) - genreTotalMap.get(a));

        List<Integer> answerList = new ArrayList<>();
        for (String genre : sortedGenres) {
            List<Song> songList = genreSongMap.get(genre);

            songList.sort((s1, s2) -> {
                if (s1.plays != s2.plays)
                    return s2.plays - s1.plays;
                else
                    return s1.id - s2.id;
            });

            for (int i = 0; i < Math.min(2, songList.size()); i++) {
                answerList.add(songList.get(i).id);
            }
        }

        return answerList.stream().mapToInt(i -> i).toArray();
    }

    // Song 클래스
    static class Song {
        int id;
        int plays;

        Song(int id, int plays) {
            this.id = id;
            this.plays = plays;
        }
    }
}