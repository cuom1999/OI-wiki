# --8<-- [start:core]
# Trả về nghịch đảo modulo của a theo modulo nguyên tố p.
# Dùng hàm pow dựng sẵn.
def inverse(a, p):
    return pow(a, p - 2, p)


# --8<-- [end:core]

if __name__ == "__main__":
    t = int(input())
    for _ in range(t):
        a, p = map(int, input().split())
        print(inverse(a, p))
