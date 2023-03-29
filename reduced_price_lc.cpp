/*tle in the given code of this in this as u were seen all these*/
//this is based on recursion and knapsack based problems

/*class Solution {
public:
    in solve(vector <int>& satisfaction,int index,int time)
    {
        if(index>satisfaction.size())
        {
            return 0;
        }
        int included=satisfaction[index]*time+solve(satisfaction,index+1,time+1);
        int excluded=0+solve(satisfaction,index+1,time);
        return max(included,excluded);
    }
    int maxSatisfaction(vector<int>& satisfaction) {

        sort(satisfaction.begin(),satisfaction.end());

        return(satisfaction,0,0);

        
    }
};*/

/* after all these i come s to conclusion that index and time both changing so the question is absed on the dynamic programming*/

/* above part is done on the knapsack with recurssions*/

class Solution {
public:
    int solve(vector<int>& satisfaction, int index, int time) {
        if(index>=satisfaction.size()) {
            return 0;
        }
        int included = satisfaction[index] * time + solve(satisfaction, index+1, time+1);
        int excluded = 0 + solve(satisfaction, index+1, time);
        return max(included, excluded);
    }
    
    int solvemem(vector<int>& satisfaction, int index, int time, vector<vector<int>>& dp) {
        if(index>=satisfaction.size()) {
            return 0;
        }
        if(dp[index][time] != -1) {
            return dp[index][time];
        }
        int included = satisfaction[index] * time + solvemem(satisfaction, index+1, time+1, dp);
        int excluded = 0 + solvemem(satisfaction, index+1, time, dp);
        return dp[index][time] = max(included, excluded);
    }
    
    int maxSatisfaction(vector<int>& satisfaction) {
        vector<vector<int>> dp(satisfaction.size()+1, vector<int>(satisfaction.size()+1, -1));
        return solvemem(satisfaction, 0, 1, dp);
    }
};

everthing done in this code dynamic programming,memonization,recurssion,top down approach