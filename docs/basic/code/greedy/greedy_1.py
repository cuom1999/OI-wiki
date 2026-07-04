from collections import defaultdict
from heapq import heappush, heappop

a = defaultdict(list)
for _ in range(int(input())):
    d, p = map(int, input().split())
    a[d].append(p)  # Lưu lợi nhuận ứng với thời hạn này.

ans = 0  # Ghi lại tổng lợi nhuận.
q = []  # Min-heap duy trì giá trị nhỏ nhất.
l = sorted(a.keys(), reverse=True)
for i, j in zip(l, l[1:] + [0]):
    for k in a.pop(i):
        heappush(q, ~k)
    for _ in range(i - j):
        if q:  # Lấy công việc có lợi nhuận lớn nhất khỏi heap.
            ans += ~heappop(q)
        else:  # Thoát vòng lặp khi heap rỗng.
            break
print(ans)
