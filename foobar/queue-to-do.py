def solution(start, length):
    # Your code here
    from operator import xor

    def findXOR(n):
        mod = n % 4

        # If n is a multiple of 4
        if (mod == 0):
            return n

        # If n % 4 gives remainder 1
        elif (mod == 1):
            return 1

        # If n % 4 gives remainder 2
        elif (mod == 2):
            return n + 1

        # If n % 4 gives remainder 3
        elif (mod == 3):
            return 0

    def findXORFun(l, r):
        return (xor(findXOR(l - 1), findXOR(r)))

    resultxor = 0
    initial = start
    for i in range(length):
        end = initial + length - 1 - i
        Xor = findXORFun(initial, end)
        resultxor = xor(resultxor, Xor)
        initial = initial + length
    return resultxor
