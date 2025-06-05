import java.util.*;

public class WordFrequencyTreeMap {
    // Counts word frequency using TreeMap
    public static Map<String, Integer> countFrequencies(String text) {
        TreeMap<String, Integer> wordFreq = new TreeMap<>();
        String[] words = text.toLowerCase().split("\\W+");

        for (String word : words) {
            wordFreq.put(word, wordFreq.getOrDefault(word, 0) + 1);
        }
        return wordFreq;
    }

    public static void main(String[] args) {
        String text = "TreeMap is used to store words and count frequency of each word in text";
        Map<String, Integer> result = countFrequencies(text);
        result.forEach((k, v) -> System.out.println(k + ": " + v));
    }
}
