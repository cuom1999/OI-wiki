author: Early0v0, frank-xjh, Great-designer, ksyx, qiqistyle, Tiphereth-A , Saisyc, shuzhouliu, Xeonacid, xyf007

Trang này giới thiệu ngắn gọn về thuật toán liệt kê.

## Giới thiệu

Liệt kê (enumeration) là một chiến lược giải bài toán bằng cách dựa trên thông
tin đã biết để dự đoán đáp án.

Ý tưởng của liệt kê là liên tục thử các khả năng: lần lượt xét từng phần tử
trong tập ứng viên, rồi kiểm tra điều kiện của bài toán có được thỏa mãn hay
không.

## Điểm chính

### Xác định không gian nghiệm

Trước hết cần xây dựng một mô hình toán học rõ ràng.

Khi liệt kê, cần xác định rõ các trường hợp có thể xảy ra và những yếu tố cần
duyệt.

### Thu hẹp không gian liệt kê

Phạm vi cần liệt kê là gì? Có bắt buộc phải duyệt toàn bộ không gian ứng viên
hay không?

Khi giải bài toán bằng phương pháp liệt kê, cần cân nhắc kỹ hai câu hỏi này; nếu
không sẽ phát sinh chi phí thời gian không cần thiết.

### Chọn thứ tự liệt kê phù hợp

Cần quyết định thứ tự duyệt dựa trên yêu cầu của bài toán. Chẳng hạn, nếu đề
bài yêu cầu tìm số nguyên tố lớn nhất thỏa điều kiện, liệt kê từ lớn đến nhỏ sẽ
phù hợp hơn.

## Ví dụ

Sau đây là một ví dụ về cách dùng liệt kê để giải bài và thu hẹp phạm vi liệt
kê.

??? note "Đề bài"
    Cho một mảng có các phần tử đôi một khác nhau và đều khác $0$. Hãy tìm số
    cặp số trong mảng có tổng bằng $0$.

??? note "Ý tưởng giải"
    Có thể viết ngay đoạn mã liệt kê hai số.
    
    === "C++"
        ```cpp
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
            if (a[i] + a[j] == 0) ++ans;
        ```
    
    === "Python"
        ```python
        for i in range(n):
            for j in range(n):
                if a[i] + a[j] == 0:
                    ans += 1
        ```
    
    === "Java"
        ```java
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < n; ++j)
            if (a[i] + a[j] == 0) ++ans;
        ```
    
    Tiếp theo, xét cách thu hẹp phạm vi liệt kê. Vì đề bài không yêu cầu cặp số
    có thứ tự, mỗi cặp hợp lệ sẽ tương ứng với hai cách sắp thứ tự: nếu `(a, b)`
    là một đáp án, thì `(b, a)` cũng là một đáp án. Trong tình huống này, ta có
    thể tự đặt thêm một thứ tự khi đếm, rồi cuối cùng nhân kết quả với $2$.
    
    Chẳng hạn, chỉ đếm những cặp mà số thứ nhất xuất hiện ở vị trí phía sau.
    Đoạn mã như sau:
    
    === "C++"
        ```cpp
        for (int i = 0; i < n; ++i)
          for (int j = 0; j < i; ++j)
            if (a[i] + a[j] == 0) ++ans;
        ans *= 2;
        ```
    
    === "Python"
        ```python
        for i in range(n):
            for j in range(i):
                if a[i] + a[j] == 0:
                    ans += 1
        ans *= 2
        ```
    
    === "Java"
        ```java
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < i; ++j)
                if (a[i] + a[j] == 0) ++ans;
        ans *= 2;
        ```
    
    Phạm vi liệt kê của $j$ đã được giảm, nhờ đó chi phí thời gian của đoạn mã
    cũng giảm theo.
    
    Vẫn có thể cải thiện thêm.
    
    Có nhất thiết phải liệt kê cả hai số không? Sau khi chọn một số, điều kiện
    của bài toán đã xác định số còn lại cần tìm. Nếu có cách kiểm tra nhanh số
    đó có tồn tại hay không, ta có thể bỏ qua vòng liệt kê thứ hai. Tiến thêm
    một bước, khi phạm vi dữ liệu cho phép, có thể dùng thùng[^1] để ghi lại các
    số đã duyệt.
    
    === "C++"
        ```cpp
        --8<-- "docs/basic/code/enumerate/enumerate_1.cpp"
        ```
    
    === "Python"
        ```python
        met = [False] * (MAXN * 2 + 1)
        for i in range(n):
            if met[MAXN - a[i]]:
                ans += 1
            met[a[i] + MAXN] = True
        ans *= 2
        ```
    
    === "Java"
        ```java
        boolean[] met = new boolean[MAXN * 2 + 1];
        for (int i = 0; i < n; ++i) {
            if (met[MAXN - a[i]]) ++ans;
            met[MAXN + a[i]] = true;
        }
        ans *= 2;
        ```

### Phân tích độ phức tạp

-   Phân tích độ phức tạp thời gian: duyệt mảng $a$ một lần là đủ để hoàn thành
    yêu cầu của bài toán; khi $n$ đủ lớn, độ phức tạp thời gian là $O(n)$.
-   Phân tích độ phức tạp bộ nhớ: $O(n+\max\{|x|:x\in a\})$.

## Bài tập

-   [2811: Bài toán tắt đèn - OpenJudge](http://bailian.openjudge.cn/practice/2811/)

## Chú thích

[^1]: [Sắp xếp thùng](../basic/bucket-sort.md), [Bài toán phần tử chính](../misc/main-element.md#thuật-toán-offline)
    và [phần giải thích về cấu trúc dữ liệu thùng trên Stack Overflow](https://stackoverflow.com/questions/42399355/what-is-a-bucket-or-double-bucket-data-structure)
    (tiếng Anh)
