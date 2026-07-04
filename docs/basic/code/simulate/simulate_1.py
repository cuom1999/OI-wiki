u, d, n = map(int, input().split())
time = dist = 0
while True:  # Dùng vòng lặp vô hạn để liệt kê.
    dist += u
    time += 1
    if dist >= n:  # Thoát vòng lặp vô hạn khi thỏa điều kiện.
        break
    dist -= d
print(time)  # In kết quả thu được.
