author: Lyccrius, AtomAlpaca

## Tổng quan

Đôi khi ta gặp những bài toán nhìn qua rất phù hợp để xử lý bằng thuật toán Mo, nhưng mỗi lần chuyển trạng thái của chúng không phải $O(1)$. Khi đó nếu dùng trực tiếp Mo, dù điều chỉnh độ dài khối, độ phức tạp vẫn không đúng.

Lúc này, nếu đóng góp của mỗi lần chuyển trạng thái vào đáp án có thể sai phân, ta có thể tách các chuyển trạng thái đó ra và xử lý ngoại tuyến, rồi dùng thuật toán khác để xử lý hàng loạt.

Ta dùng $f(x, l, r)$ để biểu diễn đóng góp do $x$ tạo ra đối với đoạn $[l, r]$.

Ví dụ, khi mở rộng đoạn hiện tại $[l, r]$ thành $[l, r + 1]$, ta cần tính $f(a_{r + 1}, l, r)$. Nếu có thể sai phân, ta có thể viết nó thành $f(a_{r + 1}, 1, r) - f(a_{r + 1}, 1, l - 1)$. Trong đó, hạng đầu có thể được tiền xử lý cho mỗi $r$; hạng sau có thể được xử lý ngoại tuyến bằng cách lưu từng hạng như vậy vào vị trí $l - 1$ tương ứng, rồi duyệt tăng dần và xử lý bằng đường quét. Các hướng chuyển trạng thái khác cũng có thể xử lý tương tự.

Kỹ thuật tiếp tục ngoại tuyến hóa các chuyển trạng thái trên nền thuật toán Mo ngoại tuyến được gọi là Mo ngoại tuyến lần hai.

Ta sẽ hiểu kỹ thuật này qua các bài toán cụ thể.

## Ví dụ

???+ note "[Luogu P5047 \[Ynoi2019 Simulation Contest\] Yuno loves sqrt technology II](https://www.luogu.com.cn/problem/P5047)"
    Cho một dãy $a$ độ dài $n$ và $m$ truy vấn, mỗi truy vấn hỏi số cặp nghịch thế trong một đoạn.

    Giới hạn dữ liệu: $1 \leq n,m \leq 10^5$, $0 \leq a_i \leq 10^9$.

Nếu dùng Mo trực tiếp, mỗi lần chuyển trạng thái ít nhất là $O(\log n)$. Quan sát thấy thông tin cần cho mỗi chuyển trạng thái là "thứ hạng của một số trong một đoạn", và thông tin này có thể sai phân theo đoạn, nên ta xét ngoại tuyến lần hai.

Khi mở rộng $[l, r]$ thành $[l, r + 1]$, ta cần biết trong đoạn $[l, r]$ có bao nhiêu số lớn hơn $a_{r + 1}$.
Gọi $f(x, r)$ là số phần tử lớn hơn $a_x$ trong đoạn $[1, r]$, và $g(x, r)$ là số phần tử nhỏ hơn $a_x$ trong đoạn $[1, r]$. Khi đó lượng thay đổi của đáp án có thể viết là $f(r + 1, r) - f(r + 1, l - 1)$.

Tương tự, lượng thay đổi khi thu hẹp $[l, r]$ thành $[l, r - 1]$ có thể viết là $-f(r, r - 1) + f(r, l - 1)$; khi mở rộng $[l, r]$ thành $[l - 1, r]$ có thể viết là $g(l - 1, r) - g(l - 1, l - 2)$; khi thu hẹp $[l, r]$ thành $[l + 1, r]$ có thể viết là $- g(l, r) + g(l, l - 1)$.

Với các hạng $f(x, x - 1)$ và $g(x, x - 1)$ trong những công thức trên, ta có thể dùng cây Fenwick để tiền xử lý trước trong $O(n \log n)$; với các hạng $f(x, p)$ và $g(x, p)$ còn lại, ta lưu $x$ ngoại tuyến tại $l$ để xử lý hàng loạt.

Ở đây có một mẹo tối ưu bộ nhớ: khi xử lý mỗi truy vấn, các $x$ được lưu ngoại tuyến vào $p$ luôn là một đoạn liên tiếp. Vì vậy ta không cần lưu từng lần di chuyển, chỉ cần lưu đoạn cần điều chỉnh. Nhờ đó bộ nhớ giảm từ tổng số lần $O(n\sqrt{m})$ xuống số truy vấn $O(m)$.

Bây giờ ta xử lý bài toán thu được sau ngoại tuyến lần hai: thêm số vào một tập hợp và truy vấn thứ hạng của một số trong tập hợp. Tổng số lần Mo di chuyển các đầu mút là $O(n\sqrt{m})$, còn độ dài mảng chỉ là $O(n)$, nên ta dùng chia khối theo miền giá trị với thao tác thêm $O(\sqrt{n})$ và truy vấn $O(1)$ để giải bài toán này.

Đến đây, ta giải được bài này với độ phức tạp thời gian $O(n \sqrt{m} + n \sqrt{n})$ và độ phức tạp bộ nhớ $O(n + m)$.

Cuối cùng cần chú ý rằng ta tính được lượng thay đổi của đáp án ở mỗi lần, chứ không phải bản thân đáp án, nên cần lấy tổng tiền tố để thu được đáp án cuối cùng.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/misc/code/mo-algo-secondary-offline/mo-algo-secondary-offline_1.cpp"
    ```

???+ note "[Luogu P5501 \[LnOI2019\] Không từ chối người đến, không đuổi người đi](https://www.luogu.com.cn/problem/P5501)"
    Nhiều lần truy vấn tổng "giá trị Abbi" của tất cả các số trong đoạn $[l, r]$.

    Giá trị Abbi được định nghĩa như sau: nếu $a_i$ là số nhỏ thứ $k$ trong đoạn truy vấn $[l,r]$, thì "giá trị Abbi" của nó bằng $ka_i$.

Ta có thể đặt $f(x,r)$ là tổng các số lớn hơn $a_x$ trong $[1,r]$, và $g(x,r)$ là số lượng các số lớn hơn $a_x$ trong $[1,r]$. Khi di chuyển đầu phải sang phải, đóng góp sinh ra là $f(r,r-1)-f(r,l-1) + a_r(r-l+ 1-(g(r,r-1)-g(r,l-1)))$. Các hướng còn lại có thể viết tương tự, nên không trình bày thêm ở đây.

Các hạng $f(r, r - 1)$ và $g(r, r - 1)$ trong công thức trên vẫn có thể tiền xử lý; các hạng còn lại được lưu ngoại tuyến ở đầu mút kia rồi xử lý bằng đường quét. Không khó nhận thấy bài toán cần xử lý vẫn là $O(n)$ lần thêm và $O(n\sqrt{m})$ lần truy vấn thứ hạng, nên cũng dùng chia khối theo miền giá trị để giải.

??? note "Mã mẫu"
    ```cpp
    --8<-- "docs/misc/code/mo-algo-secondary-offline/mo-algo-secondary-offline_2.cpp"
    ```
