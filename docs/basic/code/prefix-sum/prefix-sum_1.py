# --8<-- [start:core]
n = 0  # Kích thước mảng
a = []  # Mảng (đánh chỉ số từ 1)
ps = []  # Mảng tổng tiền tố


# Tính tổng tiền tố
def prefix_sum():
    global ps
    ps = a[:]
    # Hoặc đơn giản là:
    # ps = list(itertools.accumulate(a))
    for i in range(1, n + 1):
        ps[i] += ps[i - 1]


# Truy vấn tổng các phần tử trong [l, r]
def query(l, r):
    return ps[r] - ps[l - 1]


# --8<-- [end:core]
if __name__ == "__main__":
    n = int(input())
    a = [0] + list(map(int, input().split()))  # Đệm 0 để đánh chỉ số từ 1
    prefix_sum()
    t = int(input())
    for _ in range(t):
        l, r = map(int, input().split())
        print(query(l, r))
