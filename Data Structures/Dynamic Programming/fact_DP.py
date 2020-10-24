def fact(n):
    table=[]
    for i in range(n+1):
        if i==0:
            table.append(1)
        else:
            table.append(table[i-1]*i)
    print(table[n])
print(fact(4))


def fact1(n):
    a=1 
    for i in range(1,n+1):
        a=a*i
    return a
print(fact1(4))


