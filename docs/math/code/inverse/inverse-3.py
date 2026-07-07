# Thuật toán Euclid mở rộng.
def ex_gcd(a, b):
    if b == 0:
        return 1, 0
    else:
        x1, y1 = ex_gcd(b, a % b)
        x = y1
        y = x1 - (a // b) * y1
        return x, y


# Trả về nghịch đảo modulo của a theo modulo m.
# Giả sử gcd(a, m) = 1, nên nghịch đảo tồn tại.
def inverse(a, m):
    x, y = ex_gcd(a, m)
    return (x % m + m) % m


# --8<-- [start:core]
# Trả về nghịch đảo modulo của từng x trong a theo modulo m.
# Giả sử nghịch đảo của mọi x trong a theo modulo m đều tồn tại.
def batch_inverse(a, m):
    n = len(a)
    prod = [0] * n
    s = 1
    for i in range(n):
        # prod[i] = tích của a[0...i-1]; prod[0] = 1.
        prod[i] = s
        s = s * a[i] % m
    # s = tích của mọi phần tử trong a.
    s = inverse(s, m)
    res = [0] * n
    for i in reversed(range(n)):
        res[i] = s * prod[i] % m
        s = s * a[i] % m
    return res


# --8<-- [end:core]


if __name__ == "__main__":
    p = 10**9 + 7
    n = int(input())
    a = list(map(int, input().split()))
    inv = batch_inverse(a, p)

    res = 0
    for x in inv:
        res = (998244353 * res + x) % p

    print(res)
