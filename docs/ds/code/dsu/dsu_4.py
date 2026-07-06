# Code này chỉ dùng để minh họa; không qua được bài gốc vì quá thời gian.
class Dsu:
    def __init__(self, size, m):
        self.id = size * 2
        # Cho i trỏ đến nút ảo i + size_; mọi nút ảo trỏ đến chính nó.
        self.pa = list(range(size, size * 2)) + list(range(size, size * 2 + m))
        # Nửa đầu của size không được dùng; chỉ để tính chỉ số đơn giản hơn.
        self.size = [1] * (size * 2 + m)

    def find(self, x):
        if self.pa[x] != x:
            self.pa[x] = self.find(self.pa[x])
        return self.pa[x]

    def unite(self, x, y):
        x, y = self.find(x), self.find(y)
        if x == y:
            return
        if self.size[x] < self.size[y]:
            x, y = y, x
        self.pa[y] = x
        self.size[x] += self.size[y]

    def erase(self, x):
        y = self.find(x)
        self.size[y] -= 1
        self.pa[x] = self.id
        self.id += 1


if __name__ == "__main__":
    case_id = 0
    while True:
        n, m = map(int, input().split())
        if not n:
            break
        dsu = Dsu(n, m)
        for _ in range(m):
            op = input().split()
            if op[0] == "M":
                x = int(op[1])
                y = int(op[2])
                dsu.unite(x, y)
            elif op[0] == "S":
                x = int(op[1])
                dsu.erase(x)
        res = 0
        for i in range(n, dsu.id):
            if dsu.size[i] and i == dsu.find(i):
                res += 1
        case_id += 1
        print(f"Case #{case_id}: {res}")
        input()
