class Solution {
public:
    int uniqueXorTriplets(vector<int>& nums) {
        int n = nums.size();

        if (n <= 2)
            return n;
        int msb = 0;
        while (n) {
            n /= 2;
            msb++;
        }

        cout << "msb: " << msb << endl;

        int ans = pow(2, msb);
        return ans;
    }
};