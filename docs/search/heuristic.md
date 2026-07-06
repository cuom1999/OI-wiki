Trang này giới thiệu ngắn gọn tìm kiếm theo kinh nghiệm và cách sử dụng.

## Định nghĩa

Tìm kiếm theo kinh nghiệm (tiếng Anh: heuristic search) là một loại thuật toán tìm kiếm
đưa thêm hàm đánh giá theo kinh nghiệm (heuristic function) vào trên nền các thuật toán tìm kiếm thông thường.

Vai trò của hàm đánh giá theo kinh nghiệm là dựa trên thông tin đã có để đánh giá từng lựa chọn
nhánh trong quá trình tìm kiếm, rồi từ đó chọn nhánh. Nói đơn giản, tìm kiếm
theo kinh nghiệm phân tích cả hai khả năng chọn và không chọn, từ đó lấy lời giải tốt
hơn hoặc loại bỏ lời giải không hợp lệ.

## Ví dụ

Vì khái niệm này khá trừu tượng, phần này dùng ví dụ để giải thích.

???+ note "[NOIP2005 Phổ cập - Hái thuốc](https://www.luogu.com.cn/problem/P1048)"
    Tóm tắt đề bài: có $N$ loại vật phẩm và một ba lô dung tích $W$. Mỗi vật
    phẩm có hai thuộc tính là trọng lượng $w_i$ và giá trị $v_i$. Cần chọn một
    số vật phẩm (mỗi loại chỉ được chọn một lần) cho vào ba lô sao cho tổng giá
    trị lớn nhất, đồng thời tổng trọng lượng không vượt quá dung tích ba lô.

??? note "Ý tưởng giải"
    Viết một hàm đánh giá $f$ để cắt bỏ mọi nhánh $0$ vô ích (tức cắt bỏ rất
    nhiều nhánh không chọn không cần thiết).
    
    Quá trình chạy của hàm đánh giá $f$ như sau:
    
    Khi chọn một vật phẩm, kiểm tra xem có vượt quá dung tích quy định hay không
    (cắt tỉa tính khả thi). Khi không chọn một vật phẩm, kiểm tra xem tổng
    "giá trị của toàn bộ thuốc còn lại + giá trị hiện có" có lớn hơn lời giải
    tốt nhất đã tìm được hay không (cắt tỉa tính tối ưu).

??? note "Mã ví dụ"
    ```cpp
    --8<-- "docs/search/code/heuristic/heuristic_1.cpp"
    ```
