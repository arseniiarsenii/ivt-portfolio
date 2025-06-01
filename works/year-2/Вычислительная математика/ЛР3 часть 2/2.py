from itertools import count

e = 10 ** -5
cnt = 0

for x0, y0 in [(17.32, 0.24), (0.464, 1.5)]:
    x, y = x0, y0
    print(f"{x=}, {y0=}")

    for i in count(1):
        y1 = y * (3 - x * y ** 2) / 2
        u = y1 - y
        y = y1
        cnt = i
        
        if abs(u) <= e:
            break

    print(f"{y=}, i={cnt}\n")

