# --8<-- [start:full-text]
# --8<-- [start:core]
n, m = 0, 0
a = []  # (n+1) x (m+1)
ps = []  # mảng tổng tiền tố


# Tính tổng tiền tố của mảng 2 chiều.
def prefix_sum():
    global ps
    ps = [row[:] for row in a]  # Sao chép sâu a
    for i in range(1, n + 1):
        for j in range(1, m + 1):
            ps[i][j] += ps[i - 1][j] + ps[i][j - 1] - ps[i - 1][j - 1]


# Tìm tổng các phần tử trong ma trận con từ [x1, y1] đến [x2, y2].
def query(x1, y1, x2, y2):
    return ps[x2][y2] - ps[x1 - 1][y2] - ps[x2][y1 - 1] + ps[x1 - 1][y1 - 1]


# --8<-- [end:core]
if __name__ == "__main__":
    n, m = map(int, input().split())

    # Khởi tạo với phần đệm 0 để đánh số từ 1
    a = [[0] * (m + 1)]
    for _ in range(n):
        row = list(map(int, input().split()))
        a.append([0] + row)

    prefix_sum()
    ans = 0

    for l in range(1, min(n, m) + 1):
        for i in range(l, n + 1):
            for j in range(l, m + 1):
                if query(i - l + 1, j - l + 1, i, j) == l * l:
                    ans = max(ans, l)

    print(ans)

# --8<-- [end:full-text]
