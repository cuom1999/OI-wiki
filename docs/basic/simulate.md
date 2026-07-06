Trang này giới thiệu ngắn gọn về thuật toán mô phỏng.

## Giới thiệu

Mô phỏng là dùng máy tính để mô phỏng các thao tác mà đề bài yêu cầu.

Các bài mô phỏng thường có đặc điểm là lượng mã lớn, nhiều thao tác và luồng xử lý phức tạp. Vì lượng mã lớn nên lỗi thường khó tìm; nếu viết sai trong phòng thi thì sẽ rất tốn thời gian.

## Kỹ thuật

Khi làm bài mô phỏng, làm theo các gợi ý sau có thể giúp tăng tốc độ giải bài:

-   Trước khi bắt tay viết mã, nên ghi càng rõ càng tốt luồng xử lý cần cài đặt ra giấy nháp.
-   Trong mã, cố gắng mô-đun hóa từng phần thành hàm, struct hoặc class.
-   Với một số khái niệm có thể lặp lại nhiều lần, nên chuyển đổi thống nhất để dễ xử lý. Ví dụ, nếu đề bài cho `"YY-MM-DD giờ:phút"`, nên tách việc xử lý này thành một hàm và chuyển thành giây; làm vậy sẽ giảm nhầm lẫn giữa các khái niệm.
-   Khi gỡ lỗi, nên gỡ lỗi theo từng khối. Lợi ích của việc mô-đun hóa là có thể kiểm tra riêng từng phần một cách thuận tiện.
-   Khi viết mã, cần giữ mạch suy nghĩ mạch lạc; không nên nghĩ đến đâu viết đến đó, mà nên viết theo các bước đã ghi trên giấy.

Thực tế, các bước trên cũng rất hữu ích khi giải những dạng bài khác.

## Phân tích ví dụ

???+ note "[Climbing Worm](https://open.kattis.com/problems/climbingworm)"
    Một con sâu có chiều dài không đáng kể đang ở đáy một cái giếng sâu $n$ inch. Mỗi lần nó bò lên $u$ inch, nhưng phải nghỉ một lần trước khi có thể bò tiếp. Trong lúc nghỉ, nó trượt xuống $d$ inch. Sau đó nó lặp lại quá trình bò lên và nghỉ. Con sâu cần bò ít nhất bao nhiêu lần để ra khỏi miệng giếng? Nếu sau một lần bò, con sâu vừa đúng chạm tới đỉnh giếng, vẫn xem như nó đã ra khỏi miệng giếng.

??? note "Ý tưởng giải"
    Chỉ cần dùng chương trình mô phỏng trực tiếp quá trình con sâu bò trong giếng. Dùng một vòng lặp để lặp lại quá trình bò; khi độ cao đã bò được lớn hơn hoặc bằng độ sâu của giếng thì thoát vòng lặp.

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

-   [「NOIP2014」Oẳn tù tì phiên bản Big Bang Theory - Universal Online Judge](https://uoj.ac/problem/15)
-   [「OpenJudge 3750」World of Warcraft](http://bailian.openjudge.cn/practice/3750/)
-   [「SDOI2010」Sát Tam Quốc - LibreOJ](https://loj.ac/problem/2885)
