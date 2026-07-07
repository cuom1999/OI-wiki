## Mở đầu

Mô phỏng luyện kim, hay simulated annealing, là một thuật toán ngẫu nhiên. Khi một bài toán có số lượng phương án cực lớn, thậm chí vô hạn, và không phải là một hàm đơn đỉnh, thường dùng mô phỏng luyện kim để giải.

## Giải thích

Dựa trên quá trình của [thuật toán leo đồi](./hill-climbing.md), nhận thấy rằng với một nghiệm không tối ưu nằm gần nghiệm tốt nhất hiện tại, thuật toán leo đồi sẽ loại bỏ trực tiếp nghiệm đó. Nhưng trong nhiều trường hợp, cần chấp nhận nghiệm không tối ưu này để thoát khỏi nghiệm tối ưu cục bộ. Đó chính là thuật toán mô phỏng luyện kim.

??? note "Ủ là gì? Trích từ [Baidu Baike](https://baike.baidu.com/item/%E9%80%80%E7%81%AB/1039313)"
    Ủ là một công nghệ xử lý nhiệt kim loại, trong đó kim loại được làm nóng chậm tới một nhiệt độ cho trước, giữ trong một khoảng thời gian đủ dài, rồi được làm nguội với tốc độ thích hợp. Mục đích là giảm độ cứng, cải thiện khả năng gia công cắt gọt, khử ứng suất dư, ổn định kích thước, giảm xu hướng biến dạng và nứt, làm mịn hạt tinh thể, điều chỉnh tổ chức vật liệu và loại bỏ khuyết tật tổ chức. Nói chính xác, ủ là một công nghệ xử lý nhiệt vật liệu, bao gồm cả vật liệu kim loại và phi kim loại. Mục đích ủ của vật liệu mới cũng có điểm giống và khác so với ủ kim loại truyền thống.

Do quy luật ủ đưa vào nhiều yếu tố ngẫu nhiên hơn, xác suất thu được nghiệm tối ưu sẽ tăng đáng kể. Vì vậy có thể mô phỏng quá trình này, coi hàm mục tiêu là hàm năng lượng.

### Quá trình

Tóm tắt trong một câu: nếu nghiệm của trạng thái mới tốt hơn thì cập nhật đáp án, nếu không thì chấp nhận trạng thái mới với một xác suất phụ thuộc vào nhiệt độ.

Gọi nhiệt độ hiện tại là $T$, hiệu năng lượng, hay hiệu giá trị, giữa trạng thái mới $S'$ và trạng thái đã biết $S$, trong đó trạng thái mới được sinh ngẫu nhiên từ trạng thái đã biết, là $\Delta E$ với $\Delta E\geqslant 0$. Khi đó xác suất xảy ra chuyển trạng thái, tức là sửa nghiệm tối ưu, là

$$
P(\Delta E)=
\begin{cases}
1,                              & S' \text{ tốt hơn } S,\\
\mathrm{e}^\frac{-\Delta E}{T}, & \text{ngược lại}.
\end{cases}
$$

**Lưu ý**: Đôi khi để nghiệm thu được có chất lượng tốt hơn, sau khi mô phỏng luyện kim kết thúc, có thể dùng nhiệt độ hiện tại để sinh ngẫu nhiên nhiều trạng thái gần nghiệm đã thu được, thử tìm nghiệm tốt hơn. Quá trình này tương tự mô phỏng luyện kim.

### Cách ủ, hay hạ nhiệt

Trong mô phỏng luyện kim, có ba tham số: nhiệt độ ban đầu $T_0$, hệ số hạ nhiệt $d$ và nhiệt độ kết thúc $T_k$. Trong đó $T_0$ là một số tương đối lớn, $d$ là một số rất gần $1$ nhưng nhỏ hơn $1$, còn $T_k$ là một số dương gần $0$.

Trước hết đặt nhiệt độ $T=T_0$, sau đó thực hiện một lần thử chuyển trạng thái theo các bước trên, rồi đặt $T=d\cdot T$. Khi $T<T_k$, quá trình mô phỏng luyện kim kết thúc, và nghiệm tốt nhất hiện tại là nghiệm tối ưu cuối cùng.

Lưu ý rằng để nghiệm chính xác hơn, thông thường không lấy trực tiếp nghiệm hiện tại làm đáp án, mà duy trì giá trị tốt nhất trong tất cả các nghiệm đã gặp trong quá trình ủ.

Dưới đây là một hình từ [Simulated annealing - Wikipedia](https://en.wikipedia.org/wiki/Simulated_annealing). Khi nhiệt độ giảm, các bước nhảy ngày càng ít ngẫu nhiên hơn và nghiệm tối ưu cũng ngày càng ổn định hơn.

![](./images/simulated-annealing.gif)

## Cài đặt

Đoạn mã trong phần này lấy [BZOJ 3680 - Đánh bại XXX](https://hydro.ac/p/bzoj-P3680), bài toán tìm điểm Fermat dạng có trọng số của $n$ điểm, làm ví dụ.

```cpp
--8<-- "docs/misc/code/simulated-annealing/simulated-annealing_1.cpp"
```

## Một số kỹ thuật

### Mô phỏng luyện kim theo từng đoạn

Đôi khi hàm có rất nhiều đỉnh, khiến mô phỏng luyện kim khó chạy ra nghiệm tối ưu.

Khi đó có thể chia toàn bộ miền giá trị thành vài đoạn, chạy mô phỏng luyện kim một lần trên mỗi đoạn, rồi lấy nghiệm tốt nhất.

### Khống chế thời gian

Có hàm `clock()` trả về thời gian chạy của chương trình.

Có thể thay `simulateAnneal();` trong chương trình chính bằng `while ((double)clock()/CLOCKS_PER_SEC < MAX_TIME) simulateAnneal();`. Như vậy chương trình sẽ liên tục chạy mô phỏng luyện kim cho đến khi thời gian sử dụng sắp vượt quá giới hạn.

Trong đó, `MAX_TIME` là một số tự định nghĩa, hơi nhỏ hơn giới hạn thời gian, tính bằng giây.

## Bài tập

-   [BZOJ 3680 - Đánh bại XXX](https://hydro.ac/p/bzoj-P3680)
-   [JSOI 2016 - Tấn công bom](https://loj.ac/problem/2076)
-   [HAOI 2006 - Chia đều dữ liệu](https://www.luogu.com.cn/problem/P2503)
