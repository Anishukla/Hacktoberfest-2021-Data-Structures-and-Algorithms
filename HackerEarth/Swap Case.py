def swap_case(s):
    new = ""
    for i in range(0,len(s)):
        if s[i].isupper() == True:
            new += s[i].lower()
        else:
            new += s[i].upper()
            
    return new

if __name__ == '__main__':
    s = input()
    result = swap_case(s)
    print(result)