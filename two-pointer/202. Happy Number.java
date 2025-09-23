class Solution {
    public boolean isHappy(int n) {
        int tortoise = n;
        int hare = n;

        do {
            tortoise = squareSum(tortoise);
            hare = squareSum(squareSum(hare));
        } while(tortoise != hare);

        return tortoise == 1;
    }

    public int squareSum(int num) {
        int sum = 0;
        String n = String.valueOf(num);
        
        for(int i=0; i<n.length(); i++) {
            int t = n.charAt(i) - '0';
            sum += t * t;
        }

        return sum;
    }
}
