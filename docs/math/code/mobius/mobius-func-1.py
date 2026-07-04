# --8<-- [start:core]
def mu(n):
    res = 1
    i = 2
    while i * i <= n:
        if n % i == 0:
            n //= i
            # Kiểm tra n có chứa bình phương của số nguyên tố hay không
            if n % i == 0:
                return 0
            res = -res
        i += 1
    # Thừa số còn lại nếu có thì phải là số nguyên tố
    if n > 1:
        res = -res
    return res


# --8<-- [end:core]
if __name__ == "__main__":
    n = int(input())
    for i in range(1, n + 1):
        print(mu(i))
