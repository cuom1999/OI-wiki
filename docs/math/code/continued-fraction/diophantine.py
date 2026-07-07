# BỘ GIẢI PHƯƠNG TRÌNH DIOPHANTINE.
# --8<-- [start:fraction]
# Tìm biểu diễn phân số liên tục của P/Q.
def fraction(p, q):
    a = []
    while q:
        a.append(p // q)
        p, q = q, p % q
    return a


# --8<-- [end:fraction]
# --8<-- [start:convergents]
# Tìm các phân số hội tụ của phân số liên tục A.
# Tử số và mẫu số được lưu riêng trong P và Q.
def convergents(a):
    p = [0, 1]
    q = [1, 0]
    for it in a:
        p.append(p[-1] * it + p[-2])
        q.append(q[-1] * it + q[-2])
    return p, q


# --8<-- [end:convergents]
# --8<-- [start:dio]
# Trả về (x, y) sao cho Ax+By=C.
# Giả sử một cặp (x, y) như vậy tồn tại.
def dio(A, B, C):
    p, q = convergents(fraction(A, B))
    C //= A // p[-1]  # chia cho gcd(A, B)
    t = (-1) if len(p) % 2 else 1
    return t * C * q[-2], -t * C * p[-2]


# --8<-- [end:dio]
if __name__ == "__main__":
    A, B, C = map(int, input().split())
    x, y = dio(A, B, C)
    print(A * x + B * y - C)  # Kết quả phải là 0
