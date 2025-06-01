e = 2 * (10 ** -7)
n = 7
a = [
    0.9999998,
    1.0,
    0.5000063,
    0.1666674,
    0.0416350,
    0.0083298,
    0.0014393,
    0.0002040,
]
x = 0.5
c = a[0]
p = 1
cnt = 1

print(f"{e=}, {n=}, {x=}\n")

for k in range(1, n):
    p *= x
    u = p * a[k]
    print(f"{u=}")
    c += u
    cnt = k
    
    if abs(u) <= e:
        break

print(f"\n{c=}, k={cnt}")

