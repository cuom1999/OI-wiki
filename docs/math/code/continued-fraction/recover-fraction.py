# TÌM Q TRONG [1,N] LÀM NHỎ NHẤT Q*R MOD M.
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


# --8<-- [start:core]
# Tìm Q làm nhỏ nhất Q*r mod m với 1 <= Q <= n < m.
def mod_min(r, n, m):
    a = fraction(r, m)
    p, q = convergents(a)
    for i in range(2, len(q)):
        if i % 2 == 1 and (i + 1 == len(q) or q[i + 1] > n):
            t = (n - q[i - 1]) // q[i]
            return q[i - 1] + t * q[i]
    return 0


# --8<-- [end:core]
if __name__ == "__main__":
    r, n, m = map(int, input().split())
    q = mod_min(r, n, m)
    p = r * q % m
    print(p, q)
