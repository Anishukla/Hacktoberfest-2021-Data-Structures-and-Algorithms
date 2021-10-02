"""
Problem Statement:
Given an array of intervals intervals where intervals[i] = [starti, endi], 
return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.

Example:
Input: intervals = [[1,2],[2,3],[3,4],[1,3]]
Output: 1
Explanation: [1,3] can be removed and the rest of the intervals are non-overlapping.
"""

'''
Greedy Approach:
- sort the intervals based on starting time
- Let us say that we do not remove the first interval always
- Taking the ith and (i+1)th intervals, there are three possibilities
    Case 1. ith = [1,2] (i+1)th = [>=2, 5] 
            here the (i+1)th interval is starting after ith is completed. 
            Hence no need to remove (i+1)th interval
    Case 2. ith = [1,5] (i+1)th = [2, <=5] 
            here the (i+1)th interval is totally inside the ith interval.
            Hence, we should remove that (i+1)th interval to remove overlappingness
    Case 3. ith = [1,5] (i+1)th = [2, >5]
            here the (i+1)th interval is overlapping with ith interval for some length. 
            Hence, we remove the (i+1)th interval because, it may overlap with some other interval for the rest of length.
            and We want to find minimum removals. Hence we will remove (i+1)th interval
'''
class Solution:
    def eraseOverlapIntervals(self, intervals: List[List[int]]) -> int:
        intervals.sort()
        n=len(intervals)
        count=0
        l,r = 0,1
        while(r<len(intervals)):
            # Case #1
            if (intervals[l][1]<=intervals[r][0]):
                l=r
                r+=1
            else:
                # Case #2
                if (intervals[r][1]<intervals[l][1]):
                    count+=1
                    
                    l=r
                    r+=1
                # Case #2
                elif (intervals[r][1]==intervals[l][1]):
                    count+=1
                    
                    l=r
                    r+=1
                # Case #3
                else:
                    
                    count+=1
                    r+=1
                    
        return count