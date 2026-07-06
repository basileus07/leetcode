class Solution {
public:
    vector<vector<int>>dp;
    int mx;
    int rec(int i, int j, string &s1, string &s2){

        //base case 
         if(i>=s1.length()) return s2.length() - j;
         if(j>=s2.length()) return s1.length() - i;

        //memo
        if(dp[i][j] != -1){
            return dp[i][j];
        }


        if(s1[i] == s2[j]){
            return dp[i][j] =  rec(i+1, j+1, s1, s2);
        }

        return dp[i][j] = 1 + min({rec(i+1, j, s1, s2), rec(i, j+1, s1, s2), rec(i+1, j+1, s1, s2)});

    }
    int minDistance(string word1, string word2) {
        int i = word1.length();
        int j = word2.length();

        mx = max(i,j);

        dp.assign(i+1, vector<int>(j+1, -1));
    

        return rec(0, 0, word1, word2);


    }
};