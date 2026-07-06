## Dẫn nhập

Cách bền vững hóa Trie tương tự cách bền vững hóa cây phân đoạn:
mỗi lần chỉ sửa các nút được thêm vào hoặc có giá trị bị thay đổi,
còn các nút không bị sửa thì được giữ lại.
Các cạnh được nối dựa trên phiên bản trước,
để khi duyệt từ gốc của từng phiên bản, Trie thu được vẫn hoàn chỉnh và chứa đầy đủ thông tin.

Trong phần lớn bài về Trie bền vững, Trie xuất hiện dưới dạng [01-Trie](../string/trie.md).

??? note "Bài ví dụ [Tổng XOR lớn nhất](https://www.luogu.com.cn/problem/P4735)"
    Duy trì các thao tác sau trên một mảng $a$ có độ dài $n$:
    
    1.  Thêm một số $x$ vào cuối mảng, độ dài mảng $n$ tăng thêm $1$.
    2.  Cho khoảng truy vấn $[l,r]$ và một giá trị $k$,
        tìm giá trị lớn nhất của $k \oplus \bigoplus^{n}_{i=p} a_i$ khi $l\le p\le r$.

## Quy trình

Giá trị cần tìm có vẻ hơi rắc rối.
Dùng cách xử lý XOR liên tiếp quen thuộc, đặt $s_x=\bigoplus_{i=1}^x a_i$,
khi đó biểu thức ban đầu tương đương với $s_{p-1}\oplus s_n\oplus k$.
Nhận thấy $s_n \oplus k$ là cố định trong quá trình truy vấn,
bài toán chuyển thành truy vấn giá trị lớn nhất khi XOR một hằng số ($s_n\oplus k$)
với một phần tử trong khoảng $[l-1,r-1]$.

Tiếp tục theo ý tưởng tương tự cây phân đoạn bền vững,
xem mỗi truy vấn là truy vấn trên cả một khoảng.
Chỉ cần xây một Trie cho khoảng này, thêm từng giá trị trong khoảng vào Trie đó;
khi truy vấn, cố gắng đi sang nhánh có bit khác với bit hiện tại.

Để truy vấn một khoảng, chỉ cần dùng tư tưởng tiền tố và hiệu:
lấy hai Trie tiền tố (tức hai phiên bản lịch sử sau khi thêm số theo thứ tự) trừ nhau
là thu được Trie của khoảng đó.
Đồng thời dùng tư tưởng cấp phát nút động,
không tạo những nút chưa cần dùng, để giảm không gian sử dụng.

```cpp
--8<-- "docs/ds/code/persistent-trie/persistent-trie_1.cpp"
```
