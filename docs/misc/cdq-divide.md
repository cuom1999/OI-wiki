Trang này giới thiệu chia để trị CDQ.

## Giới thiệu

Chia để trị CDQ là một cách tiếp cận chứ không phải một thuật toán cụ thể, tương tự như [quy hoạch động](../dp/index.md). Đến nay, cách tiếp cận này đã được phát triển rộng rãi; tùy theo nguyên lý và cách viết, có thể chia thành ba loại:

-   Giải các bài toán liên quan đến cặp điểm.
-   Tối ưu và chuyển trạng thái cho quy hoạch động 1D.
-   Dùng chia để trị CDQ để chuyển một số bài toán động thành bài toán tĩnh.

Tư tưởng chia để trị CDQ được Chen Danqi, huy chương vàng IOI 2008, hệ thống hóa và tổng kết từ thời trung học, vì vậy tên gọi CDQ ra đời.[^ref1]

## Giải các bài toán liên quan đến cặp điểm

Phần lớn các bài toán dạng này tương tự như "cho một dãy độ dài $n$, đếm số cặp điểm $(i,j)$ có một tính chất cho trước" hoặc "cho một dãy độ dài $n$, tìm một cặp điểm $(i,j)$ sao cho giá trị của một hàm cho trước là lớn nhất".

Quy trình thuật toán dùng chia để trị CDQ để giải loại bài toán này như sau:

1.  Tìm điểm giữa $mid$ của dãy;

2.  Chia tất cả các cặp điểm $(i,j)$ thành 3 loại:

    1.  Các cặp điểm có $1 \leq i \leq mid,1 \leq j \leq mid$;
    2.  Các cặp điểm có $1  \leq i \leq mid ,mid+1 \leq j \leq n$;
    3.  Các cặp điểm có $mid+1 \leq  i \leq n,mid+1 \leq j \leq n$.

3.  Tách dãy $(1,n)$ thành hai dãy $(1,mid)$ và $(mid+1,n)$. Lúc này các cặp điểm loại thứ nhất và loại thứ ba đều nằm trong hai dãy này;

4.  Xử lý đệ quy hai loại cặp điểm đó;

5.  Tìm cách xử lý các cặp điểm loại thứ hai.

Tư tưởng của chia để trị CDQ là liên tục phân phối các cặp điểm vào hai đoạn trái và phải bằng đệ quy.

Trong ứng dụng thực tế, thường dùng một hàm `solve(l,r)` để xử lý các cặp điểm thỏa $l \leq i \leq r,l \leq j \leq r$. Phần đệ quy trong quy trình thuật toán trên được hiện thực bằng `solve(l,mid)` và `solve(mid+1,r)`. Các cặp điểm loại thứ hai còn lại cần được thiết kế thuật toán riêng để xử lý.

### Bài tập ví dụ

???+ example "[Thứ tự riêng phần ba chiều](https://www.luogu.com.cn/problem/P3810)"
    Cho một dãy, mỗi điểm có ba thuộc tính $a_i,b_i,c_i$. Tính trong dãy có bao nhiêu cặp điểm $(i,j)$ thỏa $a_j \leq a_i$, $b_j \leq b_i$, $c_j \leq c_i$ và $j \ne i$.

??? note "Ý tưởng giải"
    Thứ tự riêng phần ba chiều là một bài toán kinh điển của chia để trị CDQ.
    
    Đề bài yêu cầu đếm số cặp điểm trong dãy, vì vậy có thể thử dùng chia để trị CDQ.
    
    Trước hết sắp xếp dãy theo $a$.
    
    Giả sử đã viết xong `solve(l,r)`, và đã xử lý xong bằng đệ quy `solve(l,mid)` cùng `solve(mid+1,r)`. Bước còn lại là thống kê trong các cặp điểm $(i,j)$ thỏa $l \leq i \leq mid$, $mid+1 \leq j \leq r$, có bao nhiêu cặp còn thỏa các ràng buộc $a_{i} \leq a_{j}$, $b_{i} \leq b_{j}$, $c_{i} \leq c_{j}$.
    
    Ràng buộc $a_{i} \leq a_{j}$ không còn đóng vai trò đáng kể: vì $i$ nhỏ hơn $mid$ còn $j$ lớn hơn $mid$, nên $i$ luôn nhỏ hơn $j$; dãy đã được sắp xếp theo $a$, do đó có $a_{i} \leq a_{j}$. Lúc này chỉ còn hai ràng buộc: $b_{i} \leq b_{j}$ và $c_{i} \leq c_{j}$. Dựa trên các ràng buộc này, có thể duyệt $j$ và tính số lượng $i$ thỏa điều kiện.
    
    Để tiện duyệt, sắp xếp tất cả các điểm trong $(l,mid)$ và $(mid+1,r)$ theo giá trị $b$ tăng dần. Sau đó lần lượt duyệt từng $j$, đưa tất cả các điểm $i$ có $b_{i} \leq b_{j}$ vào một cấu trúc dữ liệu, trong lời giải này chọn [cây Fenwick](../ds/fenwick.md). Khi đó chỉ cần truy vấn trong cây Fenwick có bao nhiêu điểm có giá trị $c$ không lớn hơn $c_{j}$, từ đó tính được số lượng $i$ có thể ghép hợp lệ với điểm $j$ này.
    
    Khi chèn một điểm có giá trị $c$ bằng $x$, cộng một tại vị trí $x$ trong cây Fenwick; còn thao tác truy vấn trong cây Fenwick có bao nhiêu điểm nhỏ hơn $x$ là tính [tổng tiền tố](../basic/prefix-sum.md). Sau khi [rời rạc hóa](../misc/discrete.md) tất cả các giá trị $c$ từ trước, độ phức tạp được bảo đảm.
    
    Với mỗi $j$, đều cần chèn tất cả các điểm $i$ có $b_{i} \leq b_{j}$ vào cây Fenwick. Vì tất cả các $i$ và $j$ đều đã được sắp xếp trước theo giá trị $b$, chỉ cần dùng hai con trỏ để chèn điểm vào cây Fenwick, số thao tác chèn lên cây Fenwick có thể giảm từ $O(n^2)$ xuống $O(n)$.
    
    Với quy trình trên, thông tin về các cặp điểm loại thứ hai được xử lý xong trong thời gian $O(n\log n)$. Khi đó độ phức tạp thời gian của thuật toán là $T(n)=T(\lfloor \frac{n}{2} \rfloor)+T(\lceil \frac{n}{2} \rceil)+O(n\log n)=O(n\log^2n)$.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/misc/code/cdq-divide/cdq-divide_1.cpp"
    ```

???+ example "[CQOI2011 Cặp nghịch thế động](https://www.luogu.com.cn/problem/P3157)"
    Với dãy $a$, số cặp nghịch thế của nó được định nghĩa là số phần tử trong tập $\{(i,j)| i < j \wedge a_i > a_j \}$.
    
    Cho một hoán vị của $1\sim n$, lần lượt xóa $m$ phần tử theo một thứ tự cho trước. Nhiệm vụ là trước mỗi lần xóa một phần tử, thống kê số cặp nghịch thế của toàn bộ dãy.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/misc/code/cdq-divide/cdq-divide_2.cpp"
    ```

## Chia để trị CDQ tối ưu chuyển trạng thái của quy hoạch động 1D/1D

Nội dung liên quan: [Chia để trị CDQ tối ưu DP](../dp/opt/dp-opt.md#tối-ưu-dp-bằng-chia-để-trị-cdq)

Quy hoạch động 1D/1D là một lớp bài toán DP cụ thể: mảng DP là một chiều, còn chuyển trạng thái là $O(n)$. Nếu điều kiện đủ tốt, đôi khi có thể dùng chia để trị CDQ để giảm độ phức tạp thời gian từ $O(n^2)$ xuống $O(n\log^2n)$.

Ví dụ, cho một dãy mà mỗi phần tử có hai thuộc tính $a$, $b$. Cần tính giá trị của một công thức DP, với phương trình chuyển trạng thái như sau:

$dp_{i}=1+ \max_{j=1}^{i-1}dp_{j}[a_{j} < a_{i}][b_{j} < b_{i}]$

Đây là phương trình DP của dãy con tăng dài nhất hai chiều, tức là chỉ các điểm $j$ thỏa $j < i,a_{j} < a_{i},b_{j} < b_{i}$ mới có thể cập nhật giá trị DP của điểm $i$.

Chuyển trạng thái trực tiếp có độ phức tạp $O(n^2)$. Phần sau trình bày cách dùng chia để trị CDQ để tối ưu quá trình chuyển trạng thái.

Quan hệ chuyển trạng thái từ $dp_{j}$ sang $dp_{i}$ cũng là một dạng quan hệ giữa các cặp điểm, vì vậy có thể xử lý theo cách tương tự như khi dùng chia để trị CDQ để xử lý quan hệ cặp điểm.

Quá trình chuyển trạng thái này có khuôn mẫu khá rõ. Giả sử đoạn đang xử lý là $(l,r)$, quy trình thuật toán như sau:

1.  Nếu $l=r$, phần $\max$ trong giá trị $dp_{r}$ đã được tính xong; trực tiếp đặt $dp_{r} \gets dp_{r} + 1$ rồi trả về;
2.  Gọi đệ quy `solve(l,mid)`;
3.  Xử lý tất cả các quan hệ chuyển trạng thái có $l \leq j \leq mid$, $mid+1 \leq i \leq r$;
4.  Gọi đệ quy `solve(mid+1,r)`.

Cách làm ở bước thứ ba gần giống với chia để trị CDQ cho thứ tự riêng phần ba chiều. Khi xử lý các quan hệ chuyển trạng thái có $l \leq j \leq mid$, $mid+1 \leq i \leq r$, không cần quan tâm đến ràng buộc $j < i$ nữa. Vì vậy, vẫn sắp xếp tất cả các điểm $i$ và điểm $j$ theo giá trị $a$, sau đó dùng hai con trỏ để chèn các điểm $j$ vào cây Fenwick, cuối cùng truy vấn giá trị lớn nhất trên tiền tố để cập nhật $dp_{i}$.

### Chứng minh tính đúng đắn của quá trình chuyển trạng thái

Khác biệt lớn nhất giữa cách viết CDQ này và cách viết CDQ xử lý quan hệ giữa các cặp điểm nằm ở phần xử lý các cặp điểm có $l \leq j \leq mid$, $mid+1 \leq i \leq r$. Trong cách viết CDQ xử lý quan hệ cặp điểm, phần này có thể đặt ở nhiều vị trí. Nhưng khi dùng chia để trị CDQ để tối ưu DP, quy trình này bắt buộc phải kẹp giữa $solve(l,mid)$ và $solve(mid+1,r)$. Nguyên nhân là chuyển trạng thái của DP là **có thứ tự**, nó phải thỏa hai điều kiện sau, nếu không sẽ sai:

1.  Tất cả các giá trị $dp_{j}$ dùng để tính $dp_{i}$ đều phải đã được tính xong, không được tồn tại "bán thành phẩm";

2.  Tất cả các giá trị $dp_{j}$ dùng để tính $dp_{i}$ đều phải có khả năng cập nhật vào $dp_{i}$, không được tồn tại giá trị $dp_{j}$ chưa cập nhật tới.

Hai điều kiện trên khá dễ bảo đảm khi vét cạn $O(n^2)$, nhưng sau khi dùng chia để trị CDQ, thứ tự chuyển trạng thái đã bị xáo trộn, vì vậy cần kiểm tra tính đúng đắn của các chuyển trạng thái.

Cây đệ quy của chia để trị CDQ được minh họa dưới đây.

![Cây đệ quy của chia để trị CDQ](./images/cdq-divide.svg)

Nếu thực hiện quy trình thuật toán vừa nêu, lấy điểm $8$ làm ví dụ, giá trị DP của nó được cập nhật xong trong 3 hàm `solve(1,8)`, `solve(5,8)`, `solve(7,8)`, và các điểm dùng để cập nhật nó lần lượt đến từ ba đoạn không giao nhau $(1,4)$, $(5,6)$, $(7,7)$. Tương tự, với điểm $5$, giá trị DP của nó được giải quyết trong hàm `solve(1,4)`, đoạn cập nhật nó là $(1,4)$. Giá trị DP của một điểm $i$ được cập nhật $\log$ lần, hơn nữa các đoạn cập nhật nó đúng là $\log$ đoạn được tách ra từ $(1,i)$ trên cây đoạn. Vì vậy, quy trình này bảo đảm rằng mọi $j$ hợp lệ đều đã cập nhật điểm $i$, thỏa điều kiện thứ 2.

Tiếp theo phân tích quy trình thực thi của thuật toán:

1.  Hàm kết thúc đầu tiên là `solve(1,1)`. Lúc này giá trị $dp_{1}$ đã được tính xong;
2.  Hàm đầu tiên thực hiện quá trình chuyển trạng thái là `solve(1,2)`. Lúc này giá trị $dp_{2}$ đã được chuyển trạng thái xong;
3.  Hàm kết thúc thứ hai là `solve(2,2)`. Lúc này giá trị $dp_{2}$ đã được tính xong;
4.  Tiếp theo `solve(1,2)` kết thúc, các giá trị $dp$ trong đoạn $(1,2)$ đều đã được tính xong;
5.  Hàm tiếp theo thực hiện quy trình chuyển trạng thái là `solve(1,4)`. Sau khi lần chuyển trạng thái này kết thúc, giá trị $dp_{3}$ đã được chuyển trạng thái xong;
6.  Hàm kết thúc tiếp theo là `solve(3,3)`. Giá trị $dp_{3}$ đã được tính xong;
7.  Chuyển trạng thái tiếp theo được thực hiện là `solve(3,4)`. Lúc này $dp_{4}$ đã được đoạn $(1,2)$ chuyển trạng thái một lần trong `solve(1,4)`, lần này lại được đoạn $(3,3)$ chuyển trạng thái, do đó giá trị $dp_{4}$ cũng đã được chuyển trạng thái xong;
8.  `solve(4,4)` kết thúc, giá trị $dp_{4}$ đã được tính xong;
9.  `solve(3,4)` kết thúc, các giá trị trong $(3,4)$ đã được tính xong;
10. `solve(1,4)` kết thúc, các giá trị trong $(1,4)$ đã được tính xong.
11. ...

Mô phỏng luồng gọi hàm cho thấy mỗi khi `solve(l,r)` kết thúc, các giá trị DP trong đoạn $(l,r)$ đều đã được tính xong. Vì mỗi lần thực hiện hàm chuyển trạng thái thì `solve(l,mid)` đã kết thúc, nên mọi quá trình chuyển trạng thái đều hợp lệ, thỏa điều kiện thứ 1.

Trong quá trình trên, nếu xem cây đệ quy của chia để trị CDQ như một cây đoạn, thì chia để trị CDQ chính là **hàm duyệt trung thứ tự** của cây đoạn này. Vì vậy, quy trình này tương đương với việc xử lý tất cả các giá trị DP theo thứ tự, chỉ khác ở chỗ thứ tự chuyển trạng thái đã được tách ra, nên thuật toán đúng.

### Bài tập ví dụ

???+ example "[SDOI2011 Chặn tên lửa](https://www.luogu.com.cn/problem/P2487)"
    Một quốc gia, để phòng thủ các đợt tấn công bằng tên lửa của nước địch, đã phát triển một hệ thống chặn tên lửa. Nhưng hệ thống chặn tên lửa này có một khiếm khuyết: mặc dù phát đạn đầu tiên có thể đạt tới độ cao bất kỳ và chặn được tên lửa có tốc độ bất kỳ, từ phát đạn sau trở đi, mỗi phát đạn không được cao hơn phát trước, và tốc độ bay của tên lửa bị chặn cũng không được lớn hơn phát trước. Một ngày nọ, radar bắt được tín hiệu tên lửa của địch đang lao tới. Vì hệ thống này vẫn còn trong giai đoạn thử nghiệm nên chỉ có một bộ hệ thống, do đó có thể không chặn được tất cả tên lửa.
    
    Trong trường hợp không thể chặn tất cả tên lửa, cần chọn phương án làm tổn thất quốc gia nhỏ nhất, tức là chặn được nhiều tên lửa nhất. Nhưng có thể có nhiều phương án tối ưu chặn được số tên lửa nhiều nhất; nếu có nhiều phương án tối ưu, một phương án sẽ được chọn ngẫu nhiên làm kế hoạch hành động chặn tên lửa cuối cùng.
    
    Gián điệp đã lấy được độ cao và tốc độ của tất cả tên lửa địch. Nhiệm vụ là tính xác suất mỗi tên lửa bị chặn khi thực hiện quyết sách nói trên.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/misc/code/cdq-divide/cdq-divide_3.cpp"
    ```

## Chuyển bài toán động thành bài toán tĩnh

Trong hai trường hợp trước, mục đích của việc dùng chia để trị CDQ là chia đôi dãy rồi xử lý đệ quy quan hệ giữa các cặp điểm, để cải thiện độ phức tạp. Tuy nhiên trong mục này, thứ được chia đôi không phải một dãy thông thường, mà là dãy thời gian.

Cách này phù hợp với một số bài cấu trúc dữ liệu dạng "cần hỗ trợ thực hiện sửa đổi xxx rồi thực hiện truy vấn xxx". Loại bài này có hai đặc điểm:

-   Nếu đưa các truy vấn về dạng [ngoại tuyến](offline.md), tất cả thao tác sẽ tự nhiên xếp thành một dãy theo thời gian.
-   Mỗi sửa đổi đều liên quan mật thiết đến các thao tác truy vấn phía sau. Những quan hệ "sửa đổi - truy vấn" như vậy có tổng cộng $O(n^2)$ cặp.

Có thể dùng chia để trị CDQ trên dãy thao tác này để xử lý quan hệ giữa sửa đổi và truy vấn.

Tương tự chia để trị CDQ xử lý quan hệ cặp điểm, giả sử dãy đang chia để trị là $(l,r)$, trước hết xử lý đệ quy các quan hệ sửa đổi - truy vấn trong $(l,mid)$ và $(mid+1,r)$, rồi xử lý tất cả quan hệ sửa đổi - truy vấn có $l \leq i \leq mid$, $mid+1 \leq j \leq r$, trong đó $i$ là một sửa đổi, $j$ là một truy vấn.

Nếu các sửa đổi **độc lập** với nhau, không cần xử lý quan hệ thứ tự thời gian giữa $l \leq i \leq mid$ và $mid+1 \leq j \leq r$, cũng như giữa `solve(l,mid)` và `solve(mid+1,r)`, ví dụ các bài cộng trừ thông thường. Nhưng nếu các sửa đổi không độc lập với nhau, ví dụ thao tác gán giá trị, thì sau khi thực hiện sửa đổi này, trạng thái của dãy có thể phụ thuộc vào trạng thái trước đó. Khi đó bước xử lý tất cả quan hệ sửa đổi - truy vấn vượt qua $mid$ bắt buộc phải đặt giữa `solve(l,mid)` và `solve(mid+1,r)`. Lý do giống với nguyên nhân khi dùng chia để trị CDQ tối ưu quy hoạch động 1D/1D: chỉ khi chia để trị theo thứ tự duyệt trung thứ tự mới có thể bảo đảm mỗi sửa đổi đều được thực hiện nghiêm ngặt theo thứ tự thời gian.

### Bài tập ví dụ

???+ example "Cộng hình chữ nhật, tính tổng hình chữ nhật"
    Duy trì một mảng hai chiều, hỗ trợ cộng một số vào một vùng hình chữ nhật, và mỗi lần truy vấn tổng của một vùng hình chữ nhật.

??? note "Ý tưởng giải"
    Với phiên bản không sửa đổi của bài này, tức "cho một mảng hai chiều, nhiều lần truy vấn tổng của một vùng hình chữ nhật", có một cách làm kinh điển dùng đường quét kết hợp với cây đoạn. Cách làm cụ thể là trước hết tách mỗi hình chữ nhật thành hai thao tác chèn và xóa, tiếp theo tách mỗi truy vấn thành dạng hiệu của các tổng tiền tố hai chiều, cuối cùng xử lý ngoại tuyến. Tuy nhiên đề gốc có sửa đổi, nên không thể trực tiếp dùng cách này.
    
    Có thể áp dụng chia để trị CDQ. Đưa toàn bộ truy vấn và thao tác sửa đổi về ngoại tuyến. Các thao tác này tạo thành một dãy, và có $O(N^2)$ cặp quan hệ sửa đổi - truy vấn. Vẫn dùng quy trình chung của chia để trị CDQ: chia tất cả quan hệ thành ba loại, trong tầng chia để trị này chỉ xử lý các quan hệ sửa đổi - truy vấn vượt qua $mid$, các quan hệ sửa đổi - truy vấn còn lại được giải quyết bằng đệ quy.
    
    Tất cả sửa đổi đều đã hoàn thành trước truy vấn. Khi đó bài toán gốc tương đương với "trên mặt phẳng có một số hình chữ nhật tĩnh, liên tục truy vấn tổng của một vùng hình chữ nhật".
    
    Dùng một đường quét xử lý tất cả quan hệ sửa đổi - truy vấn vượt qua $mid$ trong thời gian $O(n\log n)$, phần việc còn lại là chia để trị đệ quy các quan hệ sửa đổi - truy vấn ở hai phía trái và phải.
    
    Trong cách hiện thực chia để trị CDQ như vậy, cùng một truy vấn được xử lý $O(\log n)$ lần. Điều này không ảnh hưởng đến kết quả, vì các sửa đổi đóng góp cho truy vấn đó ở mỗi lần là rời nhau. Độ phức tạp thời gian của toàn bộ quy trình là $T(n)=T(\lfloor \frac{n}{2} \rfloor)+T(\lceil \frac{n}{2} \rceil)+ O(n\log n)=O(n\log^2n)$.
    
    Quan sát quy trình thuật toán trên, ban đầu chỉ giải được bài toán tĩnh cộng hình chữ nhật, tính tổng hình chữ nhật; nhưng sau khi dùng chia để trị CDQ, có thể giải ngoại tuyến một bài toán động cộng hình chữ nhật, tính tổng hình chữ nhật. Tinh túy của việc chuyển bài toán động thành bài toán tĩnh nằm ở chỗ chia để trị CDQ mỗi lần chỉ xử lý quan hệ sửa đổi và truy vấn vượt qua một điểm nào đó, nhờ vậy chỉ cần xét bài toán đơn giản "mọi truy vấn đều nằm sau các sửa đổi". Chính vì điểm này, chia để trị CDQ được gọi là "công cụ chuyển bài toán động thành bài toán tĩnh".

???+ example "[\[Ynoi2016\] Côn trùng trong gương](https://www.luogu.com.cn/problem/P4690)"
    Duy trì một dãy $a_i$ độ dài $n$, có $m$ thao tác.
    
    1.  Sửa giá trị trên đoạn $[l,r]$ thành $x$;
    2.  Hỏi trên đoạn $[l,r]$ xuất hiện bao nhiêu giá trị khác nhau, nghĩa là cùng một giá trị xuất hiện nhiều lần thì chỉ tính một lần.
    
    Tóm tắt đề bài trong một câu: gán đoạn, đếm số màu trên đoạn.

??? note "Ý tưởng giải"
    Duy trì vị trí điểm cùng màu đầu tiên ở bên trái của mỗi vị trí, ký hiệu là $pre_{i}$. Khi đó bài toán đếm số màu trên đoạn được chuyển thành một bài toán đếm điểm hai chiều kinh điển.
    
    Bằng cách xem một đoạn màu liên tiếp là một điểm, có thể chứng minh lượng thay đổi của $pre$ là $O(n+m)$, tức một thao tác đơn lẻ chỉ gây ra $O(1)$ thay đổi ở giá trị $pre$. Khi đó có thể dùng chia để trị CDQ để giải bài toán động cộng điểm đơn, tính tổng hình chữ nhật.
    
    Các thay đổi cụ thể của mảng $pre$ có thể được xử lý bằng `std::set`. Kỹ thuật dùng set để duy trì các đoạn liên tiếp này còn được gọi là [old driver tree](./odt.md).

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/misc/code/cdq-divide/cdq-divide_4.cpp"
    ```

???+ example "[\[HNOI2010\] Xây dựng thành phố](https://www.luogu.com.cn/problem/P3206)"
    PS là một quốc gia rộng lớn có rất nhiều thành phố. Quốc vương Louis đã suy nghĩ rất nhiều về việc xây dựng giao thông cho các thành phố. Louis có thể xây đường giữa một số thành phố; xây đường giữa các thành phố khác nhau cần chi phí khác nhau.
    
    Louis muốn xây ít đường nhất sao cho tất cả thành phố trong nước liên thông. Nhưng do một số yếu tố, chi phí xây đường giữa các thành phố sẽ thay đổi theo thời gian. Louis sẽ liên tục nhận được tin chi phí xây dựng của một con đường nào đó thay đổi. Ông muốn sau mỗi lần nhận được một thông báo như vậy, có thể lập tức biết tổng chi phí nhỏ nhất để làm cho các thành phố liên thông. Nhiệm vụ là hoàn thành yêu cầu này.
    
    Tóm tắt đề bài trong một câu: cho một đồ thị hỗ trợ sửa động trọng số cạnh, yêu cầu sau mỗi lần sửa trọng số cạnh, xuất ra tổng chi phí nhỏ nhất của cây khung nhỏ nhất của đồ thị đó.

??? note "Ý tưởng giải"
    Một cách giải bài này là dùng chia để trị trên cây đoạn lồng LCT, nhưng cách hiện thực này có hằng số quá lớn, có thể cần kỹ thuật tối ưu hằng số tinh tế mới qua được bài. Vì vậy có thể cân nhắc dùng chia để trị CDQ để giải bài này.
    
    Khác với các bài toán thông thường được giải bằng chia để trị CDQ, khi dùng chia để trị CDQ trong bài này không có quan hệ sửa đổi và truy vấn để chia để trị, vì không thể xét riêng "sửa một cạnh đóng góp gì cho cây khung nhỏ nhất của toàn bộ đồ thị". Cách tiếp cận chia để trị CDQ truyền thống không phù hợp trực tiếp.
    
    Các ví dụ trước cho thấy chia để trị CDQ thông thường có liên hệ đặc biệt với cây đoạn: trong quá trình chia để trị CDQ, một cây đoạn đã được ngầm xây dựng, vì cây đệ quy của chia để trị CDQ chính là một cây đoạn. CDQ thông thường xét liên hệ giữa hai con trái và phải của cây đoạn. Còn với bài này, điều cần xét là quan hệ giữa cha và con; nói cách khác, khi ở đoạn `$solve(l,r)$`, nếu có thể tìm cách làm cho quy mô đồ thị trở thành một biến liên quan đến độ dài đoạn, thì có thể giải được bài toán này.
    
    Cụ thể, thuật toán được thiết kế như sau.
    
    Giả sử đang xây dựng tập cạnh của cây khung nhỏ nhất cho đoạn $(l,r)$, và đã biết tập cạnh cây khung nhỏ nhất của cha nó. Lần lượt gán trọng số $+ \infty$ và $-\infty$ cho các cạnh thay đổi trong đoạn $(l,r)$, rồi mỗi trường hợp chạy Kruskal một lần để tìm các cạnh nằm trong cây khung nhỏ nhất.
    
    Với một cạnh:
    
    -   Nếu tất cả các cạnh có trọng số bị sửa trong cây khung nhỏ nhất đều được gán thành $+\infty$, mà cạnh này không xuất hiện trong cây, thì chứng minh được nó không thể xuất hiện trong cây khung nhỏ nhất của các truy vấn thuộc $(l,r)$. Vì vậy chỉ thêm các cạnh cây của cây khung nhỏ nhất vào tập cạnh của $(l,r)$.
    -   Nếu tất cả các cạnh có trọng số bị sửa trong cây khung nhỏ nhất đều được gán thành $-\infty$, mà cạnh này xuất hiện trong cây, thì chứng minh được nó luôn xuất hiện trong cây khung nhỏ nhất của đoạn $(l,r)$. Như vậy có thể dùng DSU để co các đỉnh tương ứng với những cạnh này, đồng thời cộng trọng số của các cạnh đó vào đáp án.
    
    Như vậy đã xây dựng được tập cạnh cho đoạn $(l,r)$. Cây khung nhỏ nhất tính ra từ các cạnh này tương đương với việc tính trực tiếp cây khung nhỏ nhất của đồ thị gốc.
    
    Vì sao độ phức tạp trên là đúng?
    
    Trước hết, các cạnh đã bị sửa đều được thêm vào tập cạnh, số lượng các cạnh này là $O(len)$.
    
    Tiếp theo cần chứng minh trong tập cạnh sẽ không có quá nhiều cạnh chưa bị sửa. Chỉ thêm các cạnh cây của cây khung nhỏ nhất khi mọi trọng số cạnh lấy $+\infty$, vì vậy số cạnh được thêm sẽ không vượt quá số đỉnh của đồ thị hiện tại.
    
    Tiếp theo chỉ cần chứng minh ở mỗi tầng đệ quy, số đỉnh của đồ thị là $O(len)$, thì có thể suy ra số cạnh của đồ thị cũng là $O(len)$.
    
    Việc chứng minh số đỉnh là bội hằng của $O(len)$ khá đơn giản. Mỗi lần đệ quy xuống, các cạnh bị co là các cạnh chưa bị sửa xuất hiện trong cây khung với $-\infty$; xét theo chiều ngược lại, tức là đã cắt bỏ tất cả các cạnh đã bị sửa xuất hiện trong cây khung với $-\infty$. Do chỉ cắt bỏ nhiều nhất $len$ cạnh, toàn bộ đồ thị tách thành nhiều nhất $O(len)$ thành phần liên thông, vì vậy số đỉnh của đồ thị mới là $O(len)$. Do đó đã chứng minh rằng mỗi lần đồ thị dùng để chạy Kruskal đều là $O(len)$, từ đó độ phức tạp thời gian của mỗi tầng đều là $O(n\log n)$.
    
    Độ phức tạp thời gian là $T(n)=T(\lfloor \frac{n}{2} \rfloor)+T(\lceil \frac{n}{2} \rceil)+ O(n\log n)=O(n\log^2n)$.
    
    Phần hiện thực mã có thể hơi khó. DSU không được dùng nén đường đi, nếu không sẽ không hỗ trợ thao tác quay lui. Khi thực hiện co đỉnh cũng không cần co thật, mà mỗi tầng Kruskal chỉ cần làm trực tiếp trong DSU của tầng trước.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/misc/code/cdq-divide/cdq-divide_5.cpp"
    ```

## Tài liệu tham khảo và chú thích

[^ref1]: [Từ "Cash" bàn về ứng dụng của một lớp thuật toán chia để trị](https://www.cs.princeton.edu/~danqic/papers/divide-and-conquer.pdf)
