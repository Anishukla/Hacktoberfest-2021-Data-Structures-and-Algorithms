import re

def correct_path(tag_path, parents):
    tag_path_copy = tag_path[::]
    #print('PATH COPY:', tag_path_copy)
    while True:
        popped = tag_path_copy.pop()
        if not tag_path_copy:
            #print('check:', parents[popped], popped)
            return parents[popped] == popped
        #print('compare:', popped, tag_path_copy[-1])
        if parents[popped] != tag_path_copy[-1]:
            return False
    return True

arr = []
n, q = [int(x) for x in input().split()]
for _ in range(n):
    arr.append(input())
#print(arr)
stack = []
tags = {}
parents = {}
for line in arr:
    #tag_name, *atrs = re.findall(r'\b([\w%]+)\b', line)
    #tag_name, *atrs = re.findall(r'\b([\w%]+)(?=[ ">])', line)
    tag_name, *atrs = re.findall(r'(?<=[ "<\/])([^"\s=\/]+?)(?=[ ">])', line)
    #print(tag_name, atrs)
    if stack and tag_name in stack[-1]:
        stack.pop()
        continue
    tag_attributes = {attr_name : attr_val for attr_name, attr_val in zip(atrs[::2], atrs[1::2])}
    #print(tag_name, tag_attributes)
    tags[tag_name] = tag_attributes
    if not stack:
        parents[tag_name] = tag_name
    else:
        parents[tag_name] = stack[-1]
    stack.append(tag_name)
#print('tags:', tags)
#print('parents:', parents)
for _ in range(q):
    s = input()
    tag_path, *tag_attr = s.split('~')
    if tag_attr:
        tag_attr = tag_attr[0]
    tag_path = tag_path.split('.')
    if tag_path[-1] in tags.keys() and tag_attr in tags[tag_path[-1]] and correct_path(tag_path, parents):
        print(tags[tag_path[-1]][tag_attr])
    else:
        print('Not Found!')
    #print()
    #print(tag_path, tag_attr)
    #print()
