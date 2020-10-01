class GuardGraph:
    def __init__(self, bList):
        self.listLen = len(bList)
        self.graph = list([0] * self.listLen for i in range(self.listLen))
        for i in range(self.listLen):
            for j in range(self.listLen):
                if(i < j):
                    self.graph[i][j] = self.deadlock(bList[i], bList[j])
                    self.graph[j][i] = self.graph[i][j]

    def gcd(self, x, y):
        while(y):
            x, y = y, x % y
        return x

    def deadlock(self, g1, g2):
        if(g1 == g2):
            return 0

        if((g1+g2) % 2 == 1):
            return 1
        l = self.gcd(g1, g2)
        g1, g2 = g1 / l, g2 / l
        g1, g2 = max(g1, g2), min(g1, g2)
        return self.deadlock(g1-g2, 2*g2)

    def biPartiteMatching(self, x, matched, visited):
        for y in range(self.listLen):
            if(self.graph[x][y] and visited[y] == False):
                visited[y] = True

                if(matched[y] == -1 or self.biPartiteMatching(matched[y], matched, visited)):
                    matched[y] = x
                    return True
        return False

    def maxPairs(self):
        matched = [-1] * self.listLen
        result = 0
        for i in range(self.listLen):
            visited = [False] * self.listLen
            if self.biPartiteMatching(i, matched, visited):
                result += 1
        return self.listLen - 2*(result/2)


def solution(bList):
    return GuardGraph(bList).maxPairs()
