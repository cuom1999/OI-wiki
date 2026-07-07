# BAO LỒI DƯỚI ĐƯỜNG THẲNG.
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


# --8<-- [end:core]
if __name__ == "__main__":
    p, q, N = map(int, input().split())
    ah, ph, qh = hull(fraction(p, q), N)
    for i in range(1, len(ph)):
        print(qh[i], ph[i], ah[i - 1])
