import math

e = 6 * (10 ** -9)
n = 5
a = [
    1.000000002,
    -0.166666589,
    0.008333075,
    -0.000198107,
    0.000002608,
]
x = math.pi / 6
c = a[0] * x
p = 1
cnt = 1

print(f"{e=}, {n=}, {x=}\n")

for k in range(1, n):
    p *= x ** 2
    u = p * a[k]
    print(f"{u=}")
    c += u
    cnt = k
    
    if abs(u) <= e:
        break

print(f"\n{c=}, k={cnt}")

