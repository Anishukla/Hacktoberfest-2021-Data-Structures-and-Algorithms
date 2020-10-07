"""
Python solution to Longest Common Subsequence Problem using recursion
Problem Statement: Given two sequences, in this case stings, find length of 
longest subsequence between them. A subsequence is a series in a sequence that 
appears in same relative order, but not necassarily contigous.
Eg: 'abc', 'abg', 'bdf' are subsequences of 'abcdefg'.

Name of contributor: Amogh Rajesh Desai
"""

"""
X -> string 1
Y -> string 2
m, n -> lengths of strings in consideration right now
"""
def lcs(X, Y, m, n):
    # if the length of atleast one of them is zero, there is no common thing
    if m == 0 or n == 0:
        return 0
    # if the last characters of current lengths match, the result will be
    # 1 <matched character> + lcs(X[m-1], Y[n-1]) <for remaining>
    elif X[m-1] == Y[n-1]:
        return 1 + lcs(X, Y, m - 1, n - 1)
    
    #otherwise, we need longest length, for which we will take max by
    # including the last character of both in combination and consider better one of it :)
    # example -> lcs(“ABCDGH”, “AEDFHR”) = MAX ( lcs(“ABCDG”, “AEDFHR”), lcs(“ABCDGH”, “AEDFH”) )
    else:
        return max(lcs(X, Y, m, n - 1), lcs(X, Y, m - 1, n))

# Driver code
# Hardcoding the strings, you can take it as input

X = "ABCD"
Y = "ABEFD"
# The lcs should be, 'ABD' so answer should be 3
print("lcs length is -> ", lcs(X, Y, len(X), len(Y)))
