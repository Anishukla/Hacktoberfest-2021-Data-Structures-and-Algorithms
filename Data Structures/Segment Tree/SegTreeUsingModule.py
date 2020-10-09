from segment_tree import SegmentTree

"""
    Here I'm using 'SegmentTree' module. This modules helps to avoid the implementation of 
    segmentation tree as we can directly use segment tree function for performing all operations.
    
    Numpy is used in this SegmentTree Module Hence we need install 'numpy' also(if not installed).
    
    Start with Installing Library:
    pip install segment-tree
    pip install numpy 
"""

# an array with some elements
arr = [1, 2, 3, 4, 5, 6, 7, 8, 9, 10, 11]

"""
    Here we are fitting our array into segment tree where 't' is taken as object of segment 
    tree 't' will be used for performing operations on that segmentTree.
"""

t = SegmentTree(arr)

# here we are finding value
# of maximum number in a range
a = t.query(2, 9, "max")
print("The maximum value of this range is : ", a)


# here we are finding the value
# of mininum number in a range
a = t.query(2, 9, "min")
print("The minimum value of this range is : ", a)

# here we are finding the value
# of sum of a range
a = t.query(2, 7, "sum")
print("The sum of this range is : ", a)

# here we are updating the value
# of a particular index
t.update(2, 25)

# it will replace the value of
# index '2' with 25
print("The updated array is : ", arr)
