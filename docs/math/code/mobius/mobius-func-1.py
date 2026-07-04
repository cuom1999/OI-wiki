# --8<-- [start:core]
def mu(n):
    res = 1
    i = 2
    while i * i <= n:
        if n % i == 0:
            n //= i
            # Kiem tra n co chua binh phuong cua so nguyen to hay khong
            if n % i == 0:
                return 0
            res = -res
        i += 1
    # Thua so con lai neu co thi phai la so nguyen to
    if n > 1:
        res = -res
    return res


# --8<-- [end:core]
if __name__ == "__main__":
    n = int(input())
    for i in range(1, n + 1):
        print(mu(i))
