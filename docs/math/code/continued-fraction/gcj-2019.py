# ĐIỂM TRONG TỐT NHẤT.
# Tìm biểu diễn phân số liên tục của P/Q.
def fraction(p, q):
    a = []
    while q:
        a.append(p // q)
        p, q = q, p % q
    return a


# Tìm các phân số hội tụ của phân số liên tục A.
# Tử số và mẫu số được lưu riêng trong P và Q.
def convergents(a):
    p = [0, 1]
    q = [1, 0]
    for it in a:
        p.append(p[-1] * it + p[-2])
        q.append(q[-1] * it + q[-2])
    return p, q


# Mở rộng [..., n] thành [..., n-1, 1] nếu cần.
def expand(a):
    if a[-1] != 1 or len(a) == 1:
        a[-1] -= 1
        a.append(1)
    return a


# Kiểm tra a có nhỏ hơn b hay không.
def less_than(a, b):
    a = expand(a)
    b = expand(b)
    a = [(-1) ** i * a[i] for i in range(len(a))]
    b = [(-1) ** i * b[i] for i in range(len(b))]
    return a < b


# Lấy X +- EPSILON.
def pm_eps(a):
    # Xử lý phân số liên tục rỗng cho 1/0.
    if not a:
        a.append(float("inf"))
    b = expand(a.copy())
    a.append(float("inf"))
    b.append(float("inf"))
    return (a, b) if less_than(a, b) else (b, a)


# Tìm (q, p) nhỏ nhất theo thứ tự từ điển
#   sao cho p0/q0 < p/q < p1/q1.
def middle(p0, q0, p1, q1):
    a0 = pm_eps(fraction(p0, q0))[1]
    a1 = pm_eps(fraction(p1, q1))[0]
    a = []
    for i in range(min(len(a0), len(a1))):
        if a0[i] == a1[i]:
            a.append(a0[i])
        else:
            a.append(int(min(a0[i], a1[i])) + 1)
            break
    p, q = convergents(a)
    return p[-1], q[-1]


# --8<-- [start:core]
def solve():
    n = int(input())
    C = [0] * n
    J = [0] * n
    # p0/q0 < y/x < p1/q1
    p0, q0 = 0, 1
    p1, q1 = 1, 0
    fail = False
    for i in range(n):
        C[i], J[i] = map(int, input().split())
        if i > 0:
            A = C[i] - C[i - 1]
            B = J[i] - J[i - 1]
            if A <= 0 and B <= 0:
                fail = True
                break
            elif B > 0 and A < 0:  # y/x > (-A)/B if B > 0
                if (-A) * q0 > p0 * B:
                    p0, q0 = -A, B
            elif B < 0 and A > 0:  # y/x < A/(-B) if B < 0
                if A * q1 < p1 * (-B):
                    p1, q1 = A, -B
    if fail or p0 * q1 >= p1 * q0:
        return "IMPOSSIBLE"
    p, q = middle(p0, q0, p1, q1)
    return str(p) + " " + str(q)


# --8<-- [end:core]
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        print(solve())
