author: ouuan, Ir1d, Marcythm, Xeonacid

<span id="cách-chia-khối-trên-cây"></span>

## Cách chia khối trên cây

Có thể tham khảo trang [Mo trên cây](../misc/mo-algo-on-tree.md).

Cũng có thể tham khảo
[bài blog của ouuan về Mo, Mo có sửa đổi và Mo trên cây][ouuan-mo-tree].

Các chi tiết về Mo trên cây có thể tham khảo hai bài viết trên.

<span id="ứng-dụng-của-chia-khối-trên-cây"></span>

## Ứng dụng của chia khối trên cây

Ngoài việc áp dụng cho Mo,
chia khối trên cây còn có thể được vận dụng linh hoạt trong một số bài toán trên cây.
Tuy nhiên, những bài có thể giải bằng chia khối trên cây thường vẫn có cách tốt hơn,
nên số bài liên quan không nhiều.

Nhân tiện, cách chia khối trên cây cho bài "gty's tree" có thể bị dữ liệu hình sao đánh bại.

<span id="bzoj4763-tuyết-huy"></span>

### [BZOJ4763 Tuyết Huy](https://hydro.ac/p/bzoj-P4763)

Trước hết thực hiện chia khối trên cây.
Sau đó, với điểm then chốt của mỗi khối, tiền xử lý `bitset` màu trên đường đi từ điểm đó tới từng điểm then chốt tổ tiên,
cũng như điểm then chốt tổ tiên gần nhất của nó.
Độ phức tạp là $O(n\sqrt n+\frac{nc}{32})$,
trong đó $n\sqrt n$ là độ phức tạp của việc nhảy ngược lên bằng vét cạn từ từng điểm then chốt,
còn $\frac{nc}{32}$ là độ phức tạp để lưu $O(n)$ `bitset`.

Khi trả lời truy vấn,
trước hết nhảy vét cạn từ các đầu mút của đường đi lên điểm then chốt của khối chứa chúng.
Sau đó, từ điểm then chốt của khối hiện tại,
nhảy ngược lên theo từng khối cho đến khối chứa $lca$,
rồi lại nhảy vét cạn tới $lca$.
Các `bitset` giữa những điểm then chốt đã được tiền xử lý;
phần còn lại được tính trong quá trình nhảy vét cạn.
Độ phức tạp cho một truy vấn là $O(\sqrt n+\frac c{32})$,
trong đó $\sqrt n$ đến từ việc nhảy vét cạn trong khối và nhảy trực tiếp lên theo khối,
còn $O(\frac c{32})$ là độ phức tạp để hợp nhất kết quả tiền xử lý với kết quả nhảy vét cạn.
Có thể dùng `count()` của `bitset` để đếm số màu,
và dùng `_Find_first()` của `bitset` để tìm $\operatorname{mex}$.

Do đó, tổng độ phức tạp là $O((n+m)(\sqrt n+\frac c{32}))$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/tree-decompose/tree-decompose_1.cpp"
    ```

<span id="bzoj4812-yuno-chơi-poker"></span>

### [BZOJ4812 Yuno chơi poker](https://hydro.ac/p/bzoj-P4812)

Bài này về cơ bản giống bài trước; khác biệt duy nhất nằm ở cách tính đáp án sau khi có `bitset`.

~~Vì BZOJ tính tổng giới hạn thời gian của mọi điểm kiểm thử và khó chặn cách làm này, có thể dùng `_Find_next()` để được chấp nhận.~~

Cách giải chuẩn là xử lý từng nhóm $16$ bit.
Trước hết tiền xử lý cho $2^{16}$ trạng thái có thể:
số lượng bit $1$ liên tiếp ở phần cao,
số lượng bit $1$ liên tiếp ở phần thấp,
và đóng góp ở giữa.
Tuy nhiên cách này cần tự viết `bitset`,
vì `bitset` của thư viện chuẩn không thể lấy trực tiếp một đoạn $16$ bit bất kỳ.

Có thể tham khảo mã ở [bài blog này](https://www.cnblogs.com/FallDream/p/bzoj4763.html).

[ouuan-mo-tree]: https://ouuan.github.io/%E8%8E%AB%E9%98%9F%E3%80%81%E5%B8%A6%E4%BF%AE%E8%8E%AB%E9%98%9F%E3%80%81%E6%A0%91%E4%B8%8A%E8%8E%AB%E9%98%9F%E8%AF%A6%E8%A7%A3/#%E6%A0%91%E4%B8%8A%E8%8E%AB%E9%98%9F
