class Edge:
    def __init__(self, u, v, w):
        self.u = u
        self.v = v
        self.w = w


fa = [0] * 1010  # Định nghĩa mảng cha.
g = []


def add(u, v, w):
    g.append(Edge(u, v, w))


# DSU chuẩn.
def findroot(x):
    if fa[x] == x:
        return x
    fa[x] = findroot(fa[x])
    return fa[x]


def Merge(x, y):
    x = findroot(x)
    y = findroot(y)
    fa[x] = y


# Thuật toán Kruskal.
def kruskal():
    tot = 0  # Lưu số cạnh đã chọn.
    ans = 0  # Lưu tổng chi phí.
    for e in g:
        x = findroot(e.u)
        y = findroot(e.v)
        if x != y:  # Nếu hai gốc khác nhau.
            fa[x] = y  # Hợp nhất.
            tot += 1  # Tăng số cạnh.
            ans += e.w  # Tăng chi phí.
            if tot == n - k:  # Kiểm tra số cạnh đã chọn có thỏa k kẹo bông không.
                print(ans)
                return
    print("No Answer")  # Không thể nối thành công.


if __name__ == "__main__":
    n, m, k = map(int, input().split())
    if n == k:  # Xử lý riêng trường hợp biên.
        print("0")
        exit()
    for i in range(1, n + 1):  # Khởi tạo.
        fa[i] = i
    for i in range(1, m + 1):
        u, v, w = map(int, input().split())
        add(u, v, w)  # Thêm cạnh.
    g.sort(key=lambda edge: edge.w)  # Trước hết sắp xếp theo trọng số cạnh.
    kruskal()
