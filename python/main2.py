a = int(input())
n = [list(map(int, input().split())) for _ in range(a)]
b = input().split()
k = [0] * a
m = [-1] * a
o = []
o.append(int(b[0]) - 1)
k[int(b[0]) - 1] = 1
m[int(b[0]) - 1] = 0
while o:
    c = o.pop(0)
    for i in range(a):
        if n[c][i] == 1 and not k[i]:
            o.append(i)
            k[i] = 1
            m[i] = m[c] + 1
print(m[int(b[1]) - 1])