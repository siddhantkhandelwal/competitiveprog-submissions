from copy import deepcopy

t = int(input())

for _ in range(t):
    s = input()
    p = input()
    s = list(s)
    p = list(p)
    for i in p:
        s.remove(i)
    s.sort()
    ds = deepcopy(s)
    ds.append(p[0])
    ds = sorted(ds, reverse=True)
    if p[0] not in s:
        print(''.join(s[0:len(ds) - ds.index(p[0])-1]) +
              ''.join(p) + ''.join(s[len(ds) - ds.index(p[0])-1:]))
    else:
        temp = ''.join(s[0:s.index(p[0])]) + ''.join(p) + \
            ''.join(s[s.index(p[0]):])
        print(min((temp, ''.join(s[0:len(ds) - ds.index(p(0))-1]) +
                   ''.join(p) + ''.join(s[len(ds) - ds.index(p[0])-1:]))))
