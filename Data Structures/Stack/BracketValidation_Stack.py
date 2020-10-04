def checkBalanced(expr):
    s = []
    for char in expr:
        if char in '({[':
            s.append(char)
        elif char is ')':
            if(not s or s[-1]!='('):
                return False
            s.pop()
        elif char is '}':
            if(not s or s[-1]!='{'):
                return False
            s.pop()
        elif char is ']':
            if(not s or s[-1]!='['):
                return False
            s.pop()
    if(not s):
        return True
    return False
exp=input()
if checkBalanced(exp):
    print('true')
else:
    print('false')
