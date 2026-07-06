author: StudyingFather, Backl1ght, countercurrent-time, Ir1d, greyqz, MicDZ, ouuan

`bitset` thường được dùng cho các bài toán phán định và thống kê mà cấu trúc dữ liệu thông thường khó duy trì, còn Mo có thể duy trì thông tin đoạn mà cấu trúc dữ liệu thông thường khó xử lý. Kết hợp hai kỹ thuật này có thể tận dụng ưu điểm của cả hai.

## Ví dụ [Ynoi2016 Rơi vào hang thỏ](https://www.luogu.com.cn/problem/P4688)

Bài này đúng với đặc trưng của việc phối hợp Mo và `bitset` đã nói ở trên. Một hướng tự nhiên là dùng riêng một `bitset` để lưu tất cả trọng số đã xuất hiện trong mỗi đoạn. Đáp án của một nhóm truy vấn bằng tổng độ dài các đoạn trừ đi số phần tử trong hợp của ba tập nhân với $3$.

Tuy nhiên, khi dùng `bitset` trong Mo, cần điều chỉnh thuật toán theo đặc tính của `bitset`:

1.  `bitset` không xử lý tốt trường hợp cùng lúc có nhiều trọng số giống nhau. Có thể lấy tổng của trọng số sau rời rạc hóa của phần tử hiện tại và số lần xuất hiện của nó trong đoạn hiện tại làm đối tượng được chèn vào `bitset`.
2.  Khi dùng Mo thông thường, thứ tự của 4 cách di chuyển con trỏ thường không quan trọng. Vì vậy trong quá trình di chuyển, có thể xảy ra trường hợp đầu trái của đoạn nằm bên phải đầu phải, khiến độ dài đoạn âm và số lượng phần tử cũng âm. Trong các tình huống khác điều này thường không ảnh hưởng, nhưng trong bài này phần tử chèn vào `bitset` liên quan đến số lượng phần tử. Do đó cần lưu ý thứ tự của 4 cách di chuyển con trỏ: đặt các câu lệnh di chuyển con trỏ trái sang trái và con trỏ phải sang phải lên trước, để tránh chèn số âm vào `bitset`.
3.  Tuy `bitset` dùng ít bộ nhớ, nó vẫn khó chịu được quy mô dữ liệu $10 ^ 5 \times 10 ^ 5$. Vì vậy cần chia các truy vấn thành một số khối hằng số và xử lý riêng, để giữ độ phức tạp thời gian không đổi trong khi bộ nhớ vừa đủ.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/mo-algo-with-bitset/mo-algo-with-bitset_1.cpp"
    ```

## Bài tập

-   [Ước nguyện của kẻ tồi tệ tân binh](https://www.luogu.com.cn/problem/P3674)
-   [Ynoi2017 Cánh đồng ngô của Yuno](https://www.luogu.com.cn/problem/P5355)
-   [Ynoi2011 WBLT](https://www.luogu.com.cn/problem/P5313)
