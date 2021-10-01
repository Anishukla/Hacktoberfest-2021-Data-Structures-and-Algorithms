def isSame(x):
    z = x[0]
    for i in x:
        if i == 0:
          continue
        if i == z:
            continue
        else :
            return False
    return True
def isValid(s):
    freq = []
    aRepeatingNumberExist = False
    noOfCharacters = 0
    alphaNumeric = {
        'a': 0,
        'b': 1,
        'c': 2,
        'd': 3,
        'e': 4,
        'f': 5,
        'g': 6,
        'h': 7,
        'i': 8,
        'j': 9,
        'k': 10,
        'l': 11,
        'm': 12,
        'n': 13,
        'o': 14,
        'p': 15,
        'q': 16,
        'r': 17,
        's': 18,
        't': 19,
        'u': 20,
        'v': 21,
        'w': 22,
        'x': 23,
        'y': 24,
        'z': 25,

    }
    for i in range(26):
        freq.append(0)

    for x in s:
        freq[alphaNumeric[x]] += 1
    
    if isSame(freq):
        return "YES"
    else:
        for e in range(len(freq)):
            freq[e] -= 1
            if isSame(freq):
                return "YES"
            else:
                freq[e] +=1
    return "NO"    