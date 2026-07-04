# --8<-- [start:mul]
def mulPowerOfTwo(n, m):  # Tính n*(2^m)
    return n << m


def divPowerOfTwo(n, m):  # Tính n/(2^m)
    return n >> m


# --8<-- [end:mul]
# --8<-- [start:abs]
def Abs(n):
    return (n ^ (n >> 31)) - (n >> 31)
    """
    n>>31 lấy dấu của n; nếu n dương thì n>>31 bằng 0, nếu n âm thì bằng -1.
    Nếu n dương thì n^0=n, giá trị không đổi; nếu n âm thì có n^(-1).
    Cần tính mã bù hai của n và -1, rồi thực hiện phép XOR.
    Kết quả đổi dấu n và bằng giá trị tuyệt đối của n trừ 1; trừ tiếp -1 sẽ ra giá trị tuyệt đối.
    """


# --8<-- [end:abs]
# --8<-- [start:minmax]
# Nếu a >= b, (a - b) >> 31 bằng 0; ngược lại bằng -1.
def max(a, b):
    return b & ((a - b) >> 31) | a & (~(a - b) >> 31)


def min(a, b):
    return a & ((a - b) >> 31) | b & (~(a - b) >> 31)


# --8<-- [end:minmax]
# --8<-- [start:sgn]
# Ngoại trừ trường hợp có 0
def isSameSign(x, y):
    return (x ^ y) >= 0


# --8<-- [end:sgn]
# --8<-- [start:get_bit]
# Lấy bit thứ b của a, bit thấp nhất có chỉ số 0
def getBit(a, b):
    return (a >> b) & 1


# --8<-- [end:get_bit]
# --8<-- [start:unset_bit]
# Đặt bit thứ b của a thành 0, bit thấp nhất có chỉ số 0
def unsetBit(a, b):
    return a & ~(1 << b)


# --8<-- [end:unset_bit]
# --8<-- [start:set_bit]
# Đặt bit thứ b của a thành 1, bit thấp nhất có chỉ số 0
def setBit(a, b):
    return a | (1 << b)


# --8<-- [end:set_bit]
# --8<-- [start:flap_bit]
# Đảo bit thứ b của a, bit thấp nhất có chỉ số 0
def flapBit(a, b):
    return a ^ (1 << b)


# --8<-- [end:flap_bit]


if __name__ == "__main__":
    a, b = map(int, input().split())

    for i in range(16):
        print(f"{mulPowerOfTwo(a, i)} {divPowerOfTwo(a, i)}")

    assert Abs(-a) == a
    assert Abs(a) == a

    assert max(a, b) == (a if a > b else b)
    assert min(a, b) == (a if a < b else b)

    print(int(isSameSign(a, b)))

    for i in range(32):
        print(f"{getBit(a, i)} {unsetBit(a, i)} {setBit(a, i)} {flapBit(a, i)}")
