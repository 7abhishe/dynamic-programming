// You have planned some train traveling one year in advance. The days of the year in which you will travel are given as an integer array days. Each day is an integer from 1 to 365.

// Train tickets are sold in three different ways:

// a 1-day pass is sold for costs[0] dollars,
// a 7-day pass is sold for costs[1] dollars, and
// a 30-day pass is sold for costs[2] dollars.
// The passes allow that many days of consecutive travel.

// For example, if we get a 7-day pass on day 2, then we can travel for 7 days: 2, 3, 4, 5, 6, 7, and 8.
// Return the minimum number of dollars you need to travel every day in the given list of days.

//i have decided to run only the function how to find minimum cost for it in cpp
class Solution {
public:
    int solve(int n, vector<int>& days, vector<int>& costs, int index, vector<int>& dp)
    {
        //base 
        if(index>=n)
        {
            return 0;
        }
        if(dp[index] != -1) {
            return dp[index];
        }
        //option 1 for the days one
        int option1=costs[0]+solve(n,days,costs,index+1,dp);

        //option 2 for weekly aligning
        int option2=costs[1];
        int j = index;
        while(j < n && days[j] < days[index] + 7) j++;
        option2 += solve(n,days,costs,j,dp);

        //option 3rd days
        int option3=costs[2];
        j = index;
        while(j < n && days[j] < days[index] + 30) j++;
        option3 += solve(n,days,costs,j,dp);

        dp[index] = min(option1,min(option2,option3));
        return dp[index];
    }

    int mincostTickets(vector<int>& days, vector<int>& costs) {
        int n=days.size();
        vector<int> dp(n+1,-1);
        return solve(n,days,costs,0,dp);
    }
};
//code written by me:-abhishek
