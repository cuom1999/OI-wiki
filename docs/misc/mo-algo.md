author: StudyingFather, Backl1ght, countercurrent-time, Ir1d, greyqz, MicDZ, ouuan

## Dạng bài

Giả sử $n=m$. Với bài toán truy vấn đoạn trên dãy, nếu từ đáp án của $[l,r]$ ta có thể mở rộng trong $O(1)$ để thu được đáp án của $[l-1,r],[l+1,r],[l,r+1],[l,r-1]$ - tức các đoạn kề với $[l,r]$ - thì có thể tính đáp án của tất cả truy vấn trong độ phức tạp $O(n\sqrt{n})$.

## Giải thích

Sau khi đưa các truy vấn về dạng offline, ta sắp xếp rồi xử lý lần lượt từng truy vấn, chuyển đáp án từ đoạn trước sang đoạn sau một cách trực tiếp bằng cách di chuyển từng bước.

## Cách sắp xếp

Với đoạn $[l,r]$, sắp xếp tăng dần theo khóa thứ nhất là chỉ số khối chứa $l$, và khóa thứ hai là $r$.

## Cài đặt

```cpp
void move(int pos, int sign) {
  // update nowAns
}

void solve() {
  BLOCK_SIZE = int(ceil(pow(n, 0.5)));
  sort(querys, querys + m);
  for (int i = 0; i < m; ++i) {
    const query &q = querys[i];
    while (l > q.l) move(--l, 1);
    while (r < q.r) move(++r, 1);
    while (l < q.l) move(l++, -1);
    while (r > q.r) move(r--, -1);
    ans[q.id] = nowAns;
  }
}
```

## Phân tích độ phức tạp

Phần dưới đây xét trong giả thiết $n$ và $m$ cùng bậc.

Trước hết là bước chia khối, có độ phức tạp thời gian $O(\sqrt{n}\cdot\sqrt{n}\log\sqrt{n}+n\log n)=O(n\log n)$.

Tiếp theo là phần cốt lõi của thuật toán Mo. Dưới đây ta dùng một cách chứng minh sơ cấp, dễ hiểu để chỉ ra độ phức tạp thời gian là $O(n\sqrt{n})$.

???+ note "Chứng minh"
    Chứng minh: Gọi giá trị lớn nhất của $L$ trong từng khối lần lượt là $\max_1,\max_2,\max_3, \cdots , \max_{\lceil\sqrt{n}\rceil}$.
    
    Từ lần sắp xếp thứ nhất, ta có $\max_1 \le \max_2 \le \cdots \le \max_{\lceil\sqrt{n}\rceil}$.
    
    Hiển nhiên, với mỗi khối, thời gian để tính trực tiếp truy vấn đầu tiên là $O(n)$.
    
    Xét trường hợp xấu nhất: trong mỗi khối, giá trị lớn nhất của $R$ đều là $n$, và mỗi thao tác sửa đổi đều phải chuyển $L$ từ $\max_{i - 1}$ sang $\max_i$, hoặc từ $\max_i$ sang $\max_{i - 1}$.
    
    Xét $R$: vì $R$ đã được sắp xếp trong cùng một khối, tổng thời gian thay đổi $R$ trong một khối là $O(n)$. Với tất cả các khối, phần này là $O(n\sqrt{n})$.
    
    Trọng tâm là phân tích $L$: vì độ phức tạp của mỗi lần thay đổi là $O(\max_i-\max_{i-1})$, nên trong cùng một khối, độ phức tạp thời gian là $O(\sqrt{n}\cdot(\max_i-\max_{i-1}))$.
    
    Cộng độ phức tạp theo $L$ của từng khối lại, ta được:
    
    Tổng độ phức tạp thời gian đối với $L$ là
    
    $$
    \begin{aligned}
    & O(\sqrt{n}(\max{}_1-1)+\sqrt{n}(\max{}_2-\max{}_1)+\sqrt{n}(\max{}_3-\max{}_2)+\cdots+\sqrt{n}(\max{}_{\lceil\sqrt{n}\rceil}-\max{}_{\lceil\sqrt{n}\rceil-1))} \\
    = \phantom{} & O(\sqrt{n}\cdot(\max{}_1-1+\max{}_2-\max{}_1+\max{}_3-\max{}_2+\cdots+\max{}_{\lceil\sqrt{n}\rceil-1}-\max{}_{\lceil\sqrt{n}\rceil-2}+\max{}_{\lceil\sqrt{n}\rceil}-\max{}_{\lceil\sqrt{n}\rceil-1)}) \\
    = \phantom{} & O(\sqrt{n}\cdot(\max{}_{\lceil\sqrt{n}\rceil}-1))\\
    \end{aligned}
    $$
    
    Phép cộng khử dạng telescoping.
    
    Theo đề bài, giá trị lớn nhất của $\max_{\lceil\sqrt{n}\rceil}$ là $n$, nên trong trường hợp xấu nhất, tổng độ phức tạp thời gian của $L$ là $O(n\sqrt{n})$.

Tóm lại, độ phức tạp thời gian của thuật toán Mo là $O(n\sqrt{n})$.

Tuy nhiên, với các giá trị khác của $m$, chẳng hạn $m<n$, cần thay đổi cách chia khối để đạt kết quả tốt hơn.

Vậy chia khối như thế nào?

Đặt độ dài khối là $S$. Với một số lượng bất kỳ truy vấn nằm trong cùng một khối, quãng đường di chuyển là $n$; tổng cộng có $\displaystyle \frac{n}{S}$ khối, nên tổng số lần di chuyển là $\displaystyle \frac{n^2}{S}$. Việc di chuyển có thể vượt qua biên khối, vì vậy cần cộng thêm độ phức tạp $mS$. Tổng độ phức tạp là $\displaystyle O\left(\frac{n^2}{S}+mS\right)$. Để giá trị này nhỏ nhất, ta muốn hai hạng tử xấp xỉ bằng nhau, từ đó thấy rằng chọn $S=\displaystyle \frac{n}{\sqrt{m}}$ là tối ưu. Khi đó độ phức tạp là $\displaystyle O\left(\frac{n^2}{\displaystyle \frac{n}{\sqrt{m}}}+m\left(\frac{n}{\sqrt{m}}\right)\right)=O(n\sqrt{m})$.

Thực tế, nếu đặt độ dài khối không chính xác, độ phức tạp thời gian của Mo sẽ bị ảnh hưởng đáng kể. Ví dụ, nếu $m$ cùng bậc với $\sqrt n$ nhưng lại đặt nhầm độ dài khối là $\sqrt n$, ta có thể dễ dàng dựng một bộ dữ liệu khiến độ phức tạp trở thành $O(n \sqrt n)$ thay vì giá trị đúng $O(n^{5/4})$.

Thuật toán Mo trông khá trực tiếp, phần lớn vì cách sắp xếp theo khối của nó có vẻ thô. Ta có thể nghĩ đến việc dùng một cách sắp xếp tinh vi hơn cho mọi đoạn. Một cách là xem mỗi đoạn $[l, r]$ như một điểm $(l, r)$ trên mặt phẳng, dựng cây khung nhỏ nhất theo khoảng cách Manhattan trên tất cả các điểm, rồi mỗi lần chuyển đáp án giữa các truy vấn dọc theo cạnh của cây đó. Cách này trông có vẻ cải thiện được độ phức tạp của thuật toán Mo, nhưng thực tế cận trên độ phức tạp của cách sắp xếp truy vấn theo khối đã là tối ưu.

Giả sử $n, m$ cùng bậc và $n$ là số chính phương. Xét các đoạn có dạng $[a \sqrt n, b \sqrt n](1 \le a, b \le \sqrt n)$; có tổng cộng $n$ đoạn như vậy. Nếu xem mọi đoạn là điểm trên mặt phẳng, khoảng cách Manhattan giữa hai điểm đúng bằng chi phí chuyển giữa hai đoạn, và khoảng cách Manhattan nhỏ nhất giữa hai đoạn bất kỳ là $\sqrt n$. Do đó độ phức tạp thời gian tối thiểu để xử lý tất cả truy vấn là $O(n \sqrt n)$. Cách dựng dữ liệu cho các trường hợp khác cũng tương tự.

Thuật toán Mo còn có một đặc điểm: khi $n$ không đổi, $m$ càng lớn thì chi phí chuyển trung bình cho mỗi truy vấn càng nhỏ. Một số thuật toán offline khác cũng có đặc điểm tương tự, chẳng hạn thuật toán Tarjan để tìm LCA, nhưng với thuật toán Mo, chi phí chuyển trung bình thay đổi theo $m$ rõ rệt nhất.

## Bài mẫu & mã nguồn

???+ note "Bài mẫu [Đội tuyển tập huấn quốc gia - Tất của Tiểu Z](https://www.luogu.com.cn/problem/P1494)"
    Tóm tắt đề bài:
    
    Cho một dãy $\{c_i\}$ có độ dài $n$. Có $m$ truy vấn, mỗi truy vấn cho hai số $l,r$. Chọn ngẫu nhiên hai số khác nhau trong các số có chỉ số từ $l$ đến $r$, hãy tính xác suất hai số đó bằng nhau.

### Quy trình

Ý tưởng: đây là bài mẫu của thuật toán Mo.

Với đoạn $[l,r]$, sắp xếp tăng dần theo khóa thứ nhất là chỉ số khối chứa $l$, và khóa thứ hai là $r$.

Sau đó bắt đầu tính đáp án từ truy vấn đầu tiên trong thứ tự đã sắp xếp. Truy vấn đầu tiên được tính trực tiếp với độ phức tạp $O(n)$; các truy vấn sau được tính dựa trên đáp án của truy vấn trước.

Cách làm cụ thể:

Với đoạn $[i,i]$, vì đoạn chỉ có một phần tử nên ta dễ dàng biết đáp án. Sau đó từng bước dịch chuyển từ đoạn hiện tại, nơi đáp án đã biết, sang đoạn tiếp theo.

Đặt $col[i]$ là số lần màu $i$ xuất hiện trong đoạn hiện tại, và $ans$ là số cách ghép cặp hợp lệ hiện tại, tức số cách chọn được một đôi tất cùng màu. Mỗi lần di chuyển, ta cập nhật đáp án như sau: giả sử màu hiện tại là $k$. Nếu đoạn được mở rộng, cộng vào $ans$ giá trị $\dbinom{col[k]+1}{2}-\dbinom{col[k]}{2}$; nếu đoạn bị thu hẹp, trừ khỏi $ans$ giá trị $\dbinom{col[k]}{2}-\dbinom{col[k]-1}{2}$. Đáp án của truy vấn này là $\displaystyle \frac{ans}{\dbinom{r-l+1}{2}}$.

Ở đây có một tối ưu: $\displaystyle \dbinom{a}{2}=\frac{a (a-1)}{2}$.

Do đó $\displaystyle \dbinom{a+1}{2}-\dbinom{a}{2}=\frac{(a+1) a}{2}-\frac{a (a-1)}{2}=\frac{a}{2}\cdot (a+1-a+1)=\frac{a}{2}\cdot 2=a$.

Vì vậy $\dbinom{col[k]+1}{2}-\dbinom{col[k]}{2}=col[k]$.

Tổng độ phức tạp của thuật toán: $O(n\sqrt{n} )$

Trong đoạn mã dưới đây, `deno` biểu thị mẫu số của đáp án (denominator), `nume` biểu thị tử số (numerator), `sqn` biểu thị kích thước khối: $\sqrt{n}$, `arr` là mảng đầu vào, `node` là cấu trúc lưu truy vấn, `tab` là dãy truy vấn sau khi sắp xếp, và `col` giống như đã mô tả ở trên.

**Chú ý: do có `++l` và `--r`, vị trí của 4 vòng lặp while dùng để di chuyển đoạn trong đoạn mã dưới đây là rất quan trọng; không được tùy tiện thay đổi quan hệ thứ tự giữa chúng.**

??? note "Thảo luận về vị trí của bốn vòng lặp"
    Quá trình di chuyển đoạn trong Mo tương đương với việc thêm các phần tử của $[1,r]$ và xóa các phần tử của $[1,l-1]$. Vì vậy,
    
    -   Với trường hợp $l\le r$, các phần tử của $[1,l-1]$ tương đương với việc được thêm một lần rồi bị xóa một lần, các phần tử của $[l,r]$ được thêm một lần, còn các phần tử của $[r+1,+\infty)$ không được thêm. Đây là một đoạn hợp lệ.
    -   Với trường hợp $l=r+1$, các phần tử của $[1,r]$ tương đương với việc được thêm một lần rồi bị xóa một lần, còn các phần tử của $[r+1,+\infty)$ không được thêm. Khi đó đoạn này biểu diễn đoạn rỗng.
    -   Với trường hợp $l>r+1$, các phần tử của $[r+1,l-1]$ - một đoạn không rỗng - đã bị xóa một lần nhưng chưa được thêm, nên số lần phần tử đó được thêm là số âm.
    
    Vì vậy, nếu tại một thời điểm nào đó xuất hiện $l>r+1$, sẽ tồn tại một phần tử có số lần được thêm là âm. Điều này gây lỗi trong một số bài toán; ví dụ nếu dùng một `set` để duy trì tất cả các số trong đoạn, ta sẽ gặp tình huống cần xóa một phần tử không tồn tại trong `set`.
    
    Bốn vòng lặp while trong mã có tổng cộng $4!=24$ thứ tự sắp xếp. Giả sử vòng lặp đầu tiên thao tác với đầu trái, ta có $12$ thứ tự sau; $12$ thứ tự còn lại là đối xứng. Bảng dưới đây liệt kê tính đúng đắn của 12 cách viết này và đưa ra phản ví dụ cho các cách sai.
    
    | Thứ tự vòng lặp  | Tính đúng | Phản ví dụ hoặc ghi chú |
    | ----------------- | --------- | ----------------------- |
    | `l--,l++,r--,r++` | Sai       | $l<r<l'<r'$             |
    | `l--,l++,r++,r--` | Sai       | $l<r<l'<r'$             |
    | `l--,r--,l++,r++` | Sai       | $l<r<l'<r'$             |
    | `l--,r--,r++,l++` | Đúng      | Chứng minh khá dài      |
    | `l--,r++,l++,r--` | Đúng      |                         |
    | `l--,r++,r--,l++` | Đúng      |                         |
    | `l++,l--,r--,r++` | Sai       | $l<r<l'<r'$             |
    | `l++,l--,r++,r--` | Sai       | $l<r<l'<r'$             |
    | `l++,r++,l--,r--` | Sai       | $l<r<l'<r'$             |
    | `l++,r++,r--,l--` | Sai       | $l<r<l'<r'$             |
    | `l++,r--,l--,r++` | Sai       | $l<r<l'<r'$             |
    | `l++,r--,r++,l--` | Sai       | $l<r<l'<r'$             |
    
    Trong toàn bộ 24 thứ tự, chỉ có 6 thứ tự đúng. Trong đó có 2 thứ tự có chứng minh khá dài, nên ở đây chỉ đưa ra chứng minh cho 4 thứ tự.
    
    Điểm chung của 4 cách viết đúng này là hai bước đầu mở rộng đoạn trước (`l--` hoặc `r++`), hai bước sau mới thu hẹp đoạn (`l++` hoặc `r--`). Viết như vậy thì hai bước đầu là mở rộng đoạn, có thể giữ $l\le r+1$; sau khi thực hiện xong hai bước đầu, chắc chắn có $l\le l'\le r'\le r$, và hai bước sau chỉ thu hẹp đoạn về $[l',r']$, vẫn giữ được $l\le r+1$. Do đó cách viết này là đúng.

### Cài đặt

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/misc/code/mo-algo/mo-algo_1.cpp"
    ```

## Tối ưu Mo thông thường

### Quy trình

Hãy xét bộ dữ liệu sau:

```text
// Gia su kich thuoc khoi la 2
1 1
2 100
3 1
4 100
```

Mô phỏng thủ công sẽ thấy con trỏ r di chuyển khoảng 300 lần. Sau khi xử lý xong khối đầu tiên, $l = 2, r = 100$; lúc này chỉ cần di chuyển con trỏ l hai lần là có thể thu được đáp án của truy vấn thứ tư. Tuy nhiên, ta lại đưa con trỏ r về 1 để lấy đáp án của truy vấn thứ ba, rồi lại đưa r đến 100 để lấy đáp án của truy vấn thứ tư, dẫn đến thêm hơn 90 lần di chuyển con trỏ. Làm sao tối ưu chỗ này? Ta sẽ dùng sắp xếp chẵn lẻ.

Sắp xếp chẵn lẻ là gì? Nghĩa là với các truy vấn thuộc khối lẻ, sắp xếp r tăng dần; với các truy vấn thuộc khối chẵn, sắp xếp r giảm dần. Nhờ vậy, sau khi con trỏ r xử lý xong một khối lẻ, nó sẽ xử lý các truy vấn của khối chẵn trên đường quay lại, rồi lại di chuyển về phía n để xử lý khối lẻ tiếp theo. Cách này tối ưu số lần di chuyển của con trỏ r; thông thường tối ưu này có thể giúp chương trình nhanh hơn khoảng 30%.

### Cài đặt

Mã sắp xếp:

=== "Bản viết gọn"
    ```cpp
    // clang-format off
    // Có một chi tiết nhỏ sẽ được nói ở phần sau
    int unit; // kích thước khối
    struct node {
      int l, r, id;
      bool operator < (const node &x) const {
        return l / unit == x.l / unit ? (r == x.r ? 0 : ((l / unit) & 1) ^ (r < x.r)) : l < x.l;
      }
    };
    ```

=== "Bản viết rõ"
    ```cpp
    struct node {
      int l, r, id;
    
      bool operator<(const node &x) const {
        if (l / unit != x.l / unit) return l < x.l;
        // Chú ý hai dòng dưới không được viết <= hoặc >=, nếu không sẽ lỗi
        if ((l / unit) & 1) return r < x.r;
        return r > x.r;
      }
    };
    ```

???+ warning "Chi tiet nho"
    Khi dùng `sort` để so sánh hai cấu trúc, không được để xảy ra trường hợp $a < b$ và $b < a$ cùng đúng; nếu không chương trình sẽ lỗi khi chạy. Xem thêm [lỗi thường gặp](../contest/common-mistakes.md#lỗi-dẫn-đến-re).

Với bản viết gọn, nếu không có trường hợp đặc biệt `r == x.r`, khi l thuộc cùng một khối lẻ và r bằng nhau, vấn đề trong chi tiết nhỏ ở trên sẽ xuất hiện; bạn có thể tự mô phỏng thủ công. Với bản viết rõ, nếu viết thành nhỏ hơn hoặc bằng, hoặc lớn hơn hoặc bằng, thì cũng sẽ xuất hiện vấn đề tương tự.

## Tài liệu tham khảo

-   [Ghi chú học thuật toán Mo | Sengxian's Blog](https://blog.sengxian.com/algorithms/mo-s-algorithm)
