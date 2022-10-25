import java.util.HashMap;

class Solution {
    public boolean canConstruct(String ransomNote, String magazine) {
        HashMap<Character, Integer> freq = new HashMap<Character, Integer>();
        for (int i = 0; i < magazine.length(); ++i) {
            char c = magazine.charAt(i);
            if (freq.containsKey(c)) {
 
                // If char is present in charCountMap,
                // incrementing it's count by 1
                freq.put(c, freq.get(c) + 1);
            }
            else {
 
                // If char is not present in charCountMap,
                // putting this char to charCountMap with 1 as it's value
                freq.put(c, 1);
            }
        }
        for (int j = 0; j < ransomNote.length(); ++j) {
            char d = ransomNote.charAt(j);
            if (freq.containsKey(d)) {
                int i = freq.get(d);
                if (i > 0) {
                  freq.put(d, i-1);
                } else {
                    return false;
                }
            } else {
                return false;
            }
        }
        return true;
    }
}