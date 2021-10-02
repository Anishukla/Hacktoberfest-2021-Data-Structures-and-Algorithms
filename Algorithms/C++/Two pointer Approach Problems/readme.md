## Given a sorted array (ascending) , you have to find pairs of numbers which form a gievn sum.


### Similar Question Link[https://leetcode.com/problems/two-sum/]


## Approach

Example - {1,4,5,6,8,10}  ,  target = 11

{**1** , 4 , 5 , 6 , 8 , **10**}

1 + 10 = 11         one pair found, start++ , end--

{1 , **4** , 5 , 6 , **8** , 10}

4 + 8 > 11          end-- , because start++ will further increase the sum leading to no benefit

{1 , **4**, 5 , **6** , 8 , 10}

4 + 6 < 11          start++ , because end-- will further decrease the sum leading to no benefit         

{1 , 4, **5** , **6** , 8 , 10}

5 + 6 = 11          one more pair found, start++ , end--

This process goes on for the time only when **start < end** , because moving further it will give repeating pairs.



