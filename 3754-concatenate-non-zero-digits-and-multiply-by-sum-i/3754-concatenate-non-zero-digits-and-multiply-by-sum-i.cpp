class Solution {
public:
    long long sumAndMultiply(int n) {
        int x = 0, sum = 0, fact = 1;
        while (n > 0) {
            int rem = n % 10;
            if (rem != 0) {
                sum += rem;
                x += (rem * fact);
                fact *= 10;
            }
            n = n/10;
        }

        cout << "x : sum" << x << " " << sum << endl;
        return 1LL * sum * x;
        return -1;
    }
};