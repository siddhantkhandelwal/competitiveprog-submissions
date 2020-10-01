def computeLPS(s, n, lps):
    length = 0
    i = 1
    lps[0] = 0
    while i < n:
        if(s[i] == s[length]):
            length += 1
            lps[i] = length
            i = i + 1
        else:
            if(length != 0):
                length = lps[length-1]
            else:
                lps[i] = 0
                i = i + 1


def solution(s):
    n = len(s)
    if(n == 1):
        return 1
    lps = [0]*n
    computeLPS(s, n, lps)
    length = lps[n-1]
    if length > 0 and n % (n-length) == 0:
        return n/(n-length)
    return 1
