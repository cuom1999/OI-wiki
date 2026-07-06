Trang này giới thiệu ngắn gọn về các thuật toán sắp xếp.

## Định nghĩa

**Thuật toán sắp xếp** (sorting algorithm) là thuật toán sắp xếp một tập dữ liệu
nhất định theo một thứ tự nào đó. Có nhiều thuật toán sắp xếp, và tính chất
của chúng cũng thường khác nhau.

## Tính chất

### Tính ổn định

Tính ổn định nói đến việc thứ tự tương đối của các phần tử bằng nhau có thay đổi
sau khi sắp xếp hay không.

Một thuật toán có tính ổn định sẽ giữ nguyên thứ tự tương đối của các bản ghi
vốn có khóa bằng nhau. Nói cách khác, nếu một thuật toán sắp xếp là ổn định, với
hai bản ghi $R$ và $S$ có khóa bằng nhau, và $R$ đứng trước $S$ trong danh sách
ban đầu, thì $R$ cũng sẽ đứng trước $S$ trong danh sách sau khi sắp xếp.

Sắp xếp cơ số, sắp xếp đếm, sắp xếp chèn, sắp xếp nổi bọt và sắp xếp trộn là các
thuật toán sắp xếp ổn định.

Sắp xếp chọn, sắp xếp vun đống, sắp xếp nhanh và sắp xếp Shell không phải là các
thuật toán sắp xếp ổn định.

### Độ phức tạp thời gian

Trang chính: [Độ phức tạp](./complexity.md)

Độ phức tạp thời gian dùng để đo quan hệ giữa thời gian chạy của thuật toán và kích thước đầu vào, thường được biểu diễn bằng ký hiệu $O$.

Cách tính độ phức tạp đơn giản thường là đếm số lần thực hiện các "thao tác đơn giản"; đôi khi cũng có thể ước lượng gần đúng bằng cách đếm số tầng vòng lặp.

Độ phức tạp thời gian thường được xét theo ba trường hợp: tốt nhất, trung bình và bất lợi nhất. Trong các kỳ thi OI, thường cần xét độ phức tạp trong trường hợp bất lợi nhất, vì nó thể hiện mức bảo đảm của thuật toán; trong quá trình chấm, sẽ không có kết quả tệ hơn mức này.

Cận dưới độ phức tạp thời gian của các thuật toán sắp xếp dựa trên so sánh là $O(n\log n)$.

Cũng có những thuật toán không có độ phức tạp $O(n\log n)$. Ví dụ, [sắp xếp đếm](./counting-sort.md) có độ phức tạp thời gian là $O(n+w)$, trong đó $w$ là kích thước miền giá trị của dữ liệu đầu vào.

Sau đây là phần so sánh một số thuật toán sắp xếp.

![So sánh một số thuật toán sắp xếp](images/sort-intro-1.apng)

### Độ phức tạp bộ nhớ

Tương tự độ phức tạp thời gian, độ phức tạp bộ nhớ dùng để mô tả mức tiêu thụ không gian nhớ của thuật toán. Độ phức tạp bộ nhớ càng nhỏ thì thuật toán thường càng tốt.

## Liên kết ngoài

-   [Sorting algorithm - Wikipedia](https://en.wikipedia.org/wiki/Sorting_algorithm)
