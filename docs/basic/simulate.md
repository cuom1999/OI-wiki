Trang này giới thiệu ngắn gọn về thuật toán mô phỏng.

## Giới thiệu

Mô phỏng là dùng chương trình để thực hiện đúng các thao tác được đề bài mô tả.

Các bài mô phỏng thường có lượng mã lớn, nhiều thao tác và luồng xử lý phức
tạp. Vì vậy lỗi thường khó tìm; nếu viết sai trong phòng thi, việc sửa lỗi có
thể tốn rất nhiều thời gian.

## Kỹ thuật

Khi làm bài mô phỏng, các gợi ý sau có thể giúp tăng tốc độ giải bài:

-   Trước khi bắt tay viết mã, nên ghi luồng xử lý cần cài đặt ra giấy nháp càng
    rõ càng tốt.
-   Trong mã, cố gắng mô-đun hóa từng phần bằng hàm, `struct` hoặc `class`.
-   Với những dữ liệu hoặc khái niệm xuất hiện nhiều lần, nên chuẩn hóa cách
    biểu diễn để dễ xử lý. Ví dụ, nếu đề bài cho `"YY-MM-DD giờ:phút"`, nên tách
    việc xử lý này thành một hàm riêng và chuyển thời điểm thành số giây; cách
    làm đó giúp giảm nhầm lẫn giữa các khái niệm thời gian.
-   Khi gỡ lỗi, nên gỡ lỗi theo từng khối. Lợi ích của việc mô-đun hóa là có thể
    kiểm tra riêng từng phần.
-   Khi viết mã, cần giữ mạch suy nghĩ mạch lạc. Không nên nghĩ đến đâu viết
    đến đó; hãy bám theo các bước đã ghi trên giấy.

Thực tế, các bước trên cũng hữu ích khi giải những dạng bài khác.

## Phân tích ví dụ

???+ note "[Climbing Worm](https://open.kattis.com/problems/climbingworm)"
    Một con sâu có chiều dài không đáng kể đang ở đáy một cái giếng sâu $n$
    inch. Mỗi lần nó bò lên $u$ inch, nhưng phải nghỉ một lần trước khi có thể
    bò tiếp. Trong lúc nghỉ, nó trượt xuống $d$ inch. Sau đó nó lặp lại quá
    trình bò lên và nghỉ. Con sâu cần bò ít nhất bao nhiêu lần để ra khỏi miệng
    giếng? Nếu sau một lần bò, con sâu vừa đúng chạm tới đỉnh giếng, vẫn xem như
    nó đã ra khỏi miệng giếng.

??? note "Ý tưởng giải"
    Dùng chương trình mô phỏng quá trình con sâu bò trong giếng. Một vòng lặp sẽ
    lặp lại hai bước bò lên rồi trượt xuống; khi độ cao đã bò được lớn hơn hoặc
    bằng độ sâu của giếng thì thoát vòng lặp.

??? note "Mã tham khảo"
    === "C++"
        ```cpp
        --8<-- "docs/basic/code/simulate/simulate_1.cpp"
        ```
    
    === "Python"
        ```python
        --8<-- "docs/basic/code/simulate/simulate_1.py"
        ```
    
    === "Java"
        ```java
        --8<-- "docs/basic/code/simulate/simulate_1.java"
        ```

## Bài tập

-   [「NOIP2014」Oẳn tù tì phiên bản Thuyết Big Bang - Universal Online Judge](https://uoj.ac/problem/15)
-   [「OpenJudge 3750」Thế giới Warcraft](http://bailian.openjudge.cn/practice/3750/)
-   [「SDOI2010」Sát Tam Quốc - LibreOJ](https://loj.ac/problem/2885)
