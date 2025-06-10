class Solution {
    private List<String> result = new ArrayList<>();
    public void letterCombinations(int idx, String digits, Map<Integer, List<Character>> letterMap, String ans) {
        if(idx == digits.length()) {
            result.add(ans);
            return;
        }

        int ch = digits.charAt(idx) - '0';
        for(int i=0; i<letterMap.get(ch).size(); i++) {
            letterCombinations(idx + 1, digits, letterMap, ans + letterMap.get(ch).get(i));
        }
    }

    public List<String> letterCombinations(String digits) {
        if(digits.length() == 0) {
            return result;
        }
        
        Map<Integer, List<Character>> letterMap = Map.of(
            2, List.of('a', 'b', 'c'),
            3, List.of('d', 'e', 'f'),
            4, List.of('g', 'h', 'i'),
            5, List.of('j', 'k', 'l'),
            6, List.of('m', 'n', 'o'),
            7, List.of('p', 'q', 'r', 's'),
            8, List.of('t', 'u', 'v'),
            9, List.of('w', 'x', 'y', 'z')
        );

        letterCombinations(0, digits, letterMap, "");

        return result;
    }
}
