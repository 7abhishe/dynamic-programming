// You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.

// Return the minimum number of boats to carry every given person.


class Solution {
public:
    int numRescueBoats(vector<int>& people, int limit) {
        sort(people.begin(),people.end());
        int start=0,end=people.size()-1,count=0;
        while(start<=end)
        {
            if(people[start]+people[end]<=limit)
            {
                start++;
                end--;
            }
            else
             end--;
            count++;
        }
        return count;
        
    }
};