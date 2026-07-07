# --8<-- [start:core]
def ex_gcd(a, b):
    """
    Thuật toán Euclid mở rộng.
    Tìm các số nguyên x, y sao cho a*x + b*y = gcd(a, b),
    và trả về (gcd, x, y).
    """
    if b == 0:
        return a, 1, 0
    d, x1, y1 = ex_gcd(b, a % b)
    x = y1
    y = x1 - (a // b) * y1
    return d, x, y


def solve_linear_congruence_equation(a, b, n):
    """
    Giải phương trình đồng dư tuyến tính:
        a * x ≡ b (mod n), với n > 0.
    Trả về nghiệm không âm nhỏ nhất x,
    hoặc -1 nếu không có nghiệm.
    """
    d, x, y = ex_gcd(a, n)
    if b % d != 0:
        return -1
    n //= d
    return (x * (b // d) % n + n) % n


# --8<-- [end:core]


if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        a, b, n = map(int, input().split())
        print(solve_linear_congruence_equation(a, b, n))
