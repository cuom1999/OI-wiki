# --8<-- [start:core]
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


# --8<-- [end:core]
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        a, m = map(int, input().split())
        print(inverse(a, m))
