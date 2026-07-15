class Solution {
public:
    int __gcd(int a, int b) {
        while (b != 0) {
            int rem = a % b;
            a = b;
            b = rem;
        }

        return a;
    }

    int recGCD(int a, int b) {
        if (b == 0)
            return a;

        return recGCD(b, a % b);
    }
    int gcdOfOddEvenSums(int n) {
        // here sum of AP -> S(n) = n/2[a+(n-1)d]  or n/2[a+l]

        // for n odd = n^2
        // for n even = n^2+n
        int a = n * n;
        int b = a + n;

        // return __gcd(a, b);
        return recGCD(a, b);
    }
};