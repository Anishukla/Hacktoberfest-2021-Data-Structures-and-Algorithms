def makeAnagram(a, b):
    freq = []
    count = 0
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
    
    for x in a:
        freq[alphaNumeric[x]] += 1

    for y in b:
        freq[alphaNumeric[y]] -= 1
    
    for z in freq:
        if z != 0:
            count += abs(z)

    return count