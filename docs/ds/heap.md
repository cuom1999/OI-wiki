author: ouuan, HeRaNO

Heap (đống) là một cây mà mỗi nút có một khóa.
Tùy theo loại heap, khóa của mỗi nút luôn lớn hơn hoặc bằng, hoặc luôn nhỏ hơn hoặc bằng, khóa của nút cha.

Heap trong đó khóa của mỗi nút đều lớn hơn hoặc bằng khóa của nút cha được gọi là heap nhỏ;
trường hợp ngược lại được gọi là heap lớn.
[`priority_queue` trong STL](../lang/csl/container-adapter.md#hàng-đợi-ưu-tiên) thực chất là một heap lớn.

Heap nhỏ chủ yếu hỗ trợ các thao tác:
chèn một số, truy vấn giá trị nhỏ nhất, xóa giá trị nhỏ nhất,
hợp nhất hai heap, và giảm khóa của một phần tử.

Một số biến thể mạnh hơn, thường gọi là heap có thể hợp nhất, còn hỗ trợ hiệu quả thao tác `merge`.

Một số biến thể khác còn hỗ trợ tính bền vững,
tức có thể truy vấn hoặc thao tác trên bất kỳ phiên bản lịch sử nào và sinh ra phiên bản mới.

<span id="phân-loại-heap"></span>

## Phân loại heap

| Thao tác `\` cấu trúc dữ liệu[^ref4] | Heap ghép cặp | Heap nhị phân | Cây lệch trái | Heap nhị thức | Heap Fibonacci |
| :----------------------------------: | :-----------: | :-----------: | :-----------: | :-----------: | :------------: |
| Chèn (insert) | $O(1)$ | $O(\log n)$ | $O(\log n)$ | $O(\log n)$[^ref1] | $O(1)$ |
| Truy vấn nhỏ nhất (find-min) | $O(1)$ | $O(1)$ | $O(1)$ | $O(1)$[^ref2][^ref3] | $O(1)$ |
| Xóa nhỏ nhất (delete-min) | $O(\log n)$[^ref3] | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(\log n)$[^ref3] |
| Hợp nhất (merge) | $O(1)$ | $O(n)$ | $O(\log n)$ | $O(\log n)$ | $O(1)$ |
| Giảm khóa (decrease-key) | $o(\log n)$ (cận dưới $\Omega(\log \log n)$, cận trên $O(2^{2\sqrt{\log \log n}})$)[^ref3] | $O(\log n)$ | $O(\log n)$ | $O(\log n)$ | $O(1)$[^ref3] |
| Hỗ trợ bền vững | $\times$ | $\checkmark$ | $\checkmark$ | $\checkmark$ | $\times$ |

[^ref1]: Độ phức tạp của một lần chèn đơn lẻ là $O(\log n)$,
    nhưng nếu có $k$ lần chèn liên tiếp,
    có thể tạo một heap nhị thức chỉ chứa các phần tử cần chèn rồi hợp nhất heap này với heap nhị thức ban đầu;
    độ phức tạp khấu hao là $O(1)$.

[^ref2]: Có thể lưu một con trỏ tới phần tử nhỏ nhất
    và cập nhật con trỏ này khi thực hiện các thao tác khác,
    nhờ đó truy vấn được trong $O(1)$.

[^ref3]: Độ phức tạp là độ phức tạp khấu hao.

[^ref4]: Bảng lấy từ [Wikipedia](https://en.wikipedia.org/wiki/Priority_queue#Summary_of_running_times).

Theo thói quen, khi nhắc đến "heap" mà không nói rõ thêm, mặc định thường là heap nhị phân.
