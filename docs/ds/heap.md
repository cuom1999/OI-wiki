author: ouuan, HeRaNO

Heap là một cây mà mỗi nút có một khóa, và khóa của mỗi nút đều lớn hơn hoặc bằng / nhỏ hơn hoặc bằng khóa của cha nó.

Heap trong đó khóa của mỗi nút đều lớn hơn hoặc bằng khóa của cha được gọi là heap nhỏ; ngược lại gọi là heap lớn. [`priority_queue` trong STL](../lang/csl/container-adapter.md#hàng-đợi-ưu-tiên) thực chất là một heap lớn.

Heap nhỏ chủ yếu hỗ trợ các thao tác: chèn một số, truy vấn giá trị nhỏ nhất, xóa giá trị nhỏ nhất, hợp nhất hai heap, và giảm khóa của một phần tử.

Một số heap mạnh hơn (heap có thể hợp nhất) còn hỗ trợ hiệu quả các thao tác như `merge`.

Một số heap mạnh hơn nữa còn hỗ trợ tính bền vững, tức là có thể truy vấn hoặc thao tác trên bất kỳ phiên bản lịch sử nào và sinh ra phiên bản mới.

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

[^ref1]: Độ phức tạp của một lần chèn đơn lẻ là $O(\log n)$, nhưng nếu có $k$ lần chèn liên tiếp, có thể tạo một heap nhị thức chỉ chứa các phần tử cần chèn rồi hợp nhất heap này với heap nhị thức ban đầu; độ phức tạp khấu hao là $O(1)$.

[^ref2]: Có thể lưu một con trỏ tới phần tử nhỏ nhất và cập nhật con trỏ này khi thực hiện các thao tác khác, nhờ đó truy vấn được trong $O(1)$.

[^ref3]: Độ phức tạp là độ phức tạp khấu hao.

[^ref4]: Bảng lấy từ [Wikipedia](https://en.wikipedia.org/wiki/Priority_queue#Summary_of_running_times).

Theo thói quen, khi nhắc đến "heap" mà không nói rõ thêm, thường mặc định là heap nhị phân.
