# TỔNG EULER.
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


# Tìm [ah, ph, qh] sao cho các điểm r[i]=(ph[i], qh[i]) tạo thành
# bao lồi trên của các điểm lưới trên 0 <= x <= N và 0 <= y <= r * x,
# trong đó r = [a0, a1, a2, ...] và có ah[i]-1 điểm nguyên trên
# đoạn giữa r[i] và r[i+1].
def hull(a, N):
    p, q = convergents(a)
    t = N // q[-1]
    ah = [t]
    ph = [0, t * p[-1]]
    qh = [0, t * q[-1]]
    for i in reversed(range(len(q))):
        if i % 2 == 1:
            while qh[-1] + q[i - 1] <= N:
                t = (N - qh[-1] - q[i - 1]) // q[i]
                dp = p[i - 1] + t * p[i]
                dq = q[i - 1] + t * q[i]
                k = (N - qh[-1]) // dq
                ah.append(k)
                ph.append(ph[-1] + k * dp)
                qh.append(qh[-1] + k * dq)
    return ah, ph, qh


# Tìm tổng floor(k * x) với k trong [1, N] và x = [a0; a1, a2, ...]
def sum_floor(a, N):
    N += 1
    ah, ph, qh = hull(a, N)

    # Số điểm lưới trong hình thang vuông đứng có các điểm
    # (0; 0) - (0; y1) - (dx; y2) - (dx; 0), với a+1 điểm nguyên
    # trên đoạn (0; y1) - (dx; y2), nhưng không tính số điểm trên
    # đường thẳng đứng bên phải.
    def picks(y1, y2, dx, a):
        b = y1 + y2 + a + dx
        A = (y1 + y2) * dx
        return (A + b) // 2 - y2  # = (A - b + 2) // 2 + b - (y2 + 1)

    ans = 0
    for i in range(1, len(qh)):
        ans += picks(ph[i - 1], ph[i], qh[i] - qh[i - 1], ah[i - 1])
    return ans - N


# --8<-- [start:core]
def solve(p, q, N):
    return p * N * (N + 1) // 2 - q * sum_floor(fraction(p, q), N)


# --8<-- [end:core]
if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        p, q, N = map(int, input().split())
        print(solve(p, q, N))
