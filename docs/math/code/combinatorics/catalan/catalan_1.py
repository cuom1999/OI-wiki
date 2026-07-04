f = [0] * 25
f[0] = 1
n = int(input())
for i in range(1, n + 1):
    f[i] = f[i - 1] * (4 * i - 2) // (i + 1)
    # Dùng dạng thường gặp 4.
print(f[n])
