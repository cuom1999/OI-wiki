author: CBW2007, ChungZH, Marcythm, abc1763613206, Ir1d

<span id="lời-nói-đầu"></span>
## Lời nói đầu

DFS (tìm kiếm theo chiều sâu) là một thuật toán phổ biến. Phần lớn bài toán đều có thể giải bằng DFS, nhưng trong đa số trường hợp, đó chỉ là cách làm để lấy một phần điểm; rất hiếm bài toán mà vét cạn bằng tìm kiếm lại là lời giải chuẩn, vì độ phức tạp thời gian của DFS đặc biệt cao. Cần nắm DFS trước khi đọc tiếp.

Vì DFS thường không đủ để trở thành lời giải chuẩn, nên cố gắng lấy được nhiều điểm hơn bằng các tối ưu hóa. Bài viết này sẽ giới thiệu một số kỹ thuật tối ưu thực dụng, thường được gọi là "cắt tỉa".

Trước hết là một mẫu tìm kiếm sâu; các mẫu phía sau sẽ được sửa đổi dựa trên mẫu này.

```cpp
int ans = worst_case, now;  // now là lời giải hiện tại

void dfs(input_state) {
  if (reached_goal) ans = best(current_solution, ans);
  for (each_choice)
    if (feasible) {
      apply_choice;
      dfs(smaller_state);
      undo_choice;
    }
}
```

Trong đó `ans` cũng có thể là bản ghi của nghiệm; khi đó thao tác chọn phương án tốt hơn giữa nghiệm hiện tại và nghiệm đã có sẽ trở thành thao tác xuất nghiệm.

<span id="các-phương-pháp-cắt-tỉa"></span>
## Các phương pháp cắt tỉa

Ba dạng cắt tỉa thông dụng nhất là tìm kiếm có ghi nhớ, cắt tỉa tối ưu và cắt tỉa khả thi.

<span id="tìm-kiếm-có-ghi-nhớ"></span>
### Tìm kiếm có ghi nhớ

Trong quá trình tìm kiếm, cùng một giá trị truyền vào thường dẫn đến cùng một nghiệm. Vì vậy, có thể dùng mảng để ghi nhớ; xem thêm tại [Tìm kiếm có ghi nhớ](../dp/memo.md).

**Mẫu:**

```cpp
int g[MAXN];  // Định nghĩa mảng ghi nhớ
int ans = worst_case, now;

void dfs(input_state) {
  if (g[size] != invalid_value) return;  // Hoặc ghi lại nghiệm, tùy bài toán
  if (reached_goal) ans = best(current_solution, ans);  // Xuất nghiệm, tùy bài toán
  for (each_choice)
    if (feasible) {
      apply_choice;
      dfs(smaller_state);
      undo_choice;
    }
}

int main() {
  // ...
  memset(g, invalid_value, sizeof(g));  // Khởi tạo mảng ghi nhớ
  // ...
}
```

<span id="cắt-tỉa-tối-ưu"></span>
### Cắt tỉa tối ưu

Một nguyên nhân khác làm tìm kiếm chạy chậm là vẫn tiếp tục tìm khi lời giải hiện tại đã kém hơn lời giải tốt nhất đã biết. Khi đó, chỉ cần kiểm tra xem lời giải hiện tại có đã tệ hơn lời giải đã có hay không.

**Mẫu:**

```cpp
int ans = worst_case, now;

void dfs(input_state) {
  if (now_is_worse_than_ans) return;
  if (reached_goal) ans = best(current_solution, ans);
  for (each_choice)
    if (feasible) {
      apply_choice;
      dfs(smaller_state);
      undo_choice;
    }
}
```

<span id="cắt-tỉa-khả-thi"></span>
### Cắt tỉa khả thi

Nếu lời giải hiện tại đã không còn khả thi mà vẫn tiếp tục tìm xuống, đó cũng là một nguyên nhân làm chương trình chạy chậm.

**Mẫu:**

```cpp
int ans = worst_case, now;

void dfs(input_state) {
  if (current_solution_is_infeasible) return;
  if (reached_goal) ans = best(current_solution, ans);
  for (each_choice)
    if (feasible) {
      apply_choice;
      dfs(smaller_state);
      undo_choice;
    }
}
```

<span id="ý-tưởng-cắt-tỉa"></span>
## Ý tưởng cắt tỉa

Có rất nhiều hướng suy nghĩ để cắt tỉa; phần lớn cần phân tích theo từng bài toán cụ thể. Dưới đây là một vài ý tưởng cắt tỉa thường gặp.

-   Phương pháp cực hạn: xét trường hợp cực đoan. Nếu ngay cả trường hợp cực đoan, lý tưởng nhất cũng không thể thỏa mãn, thì kết quả tìm kiếm trong thực tế cũng không thể tốt hơn.

-   Phương pháp điều chỉnh: so sánh các cây con để loại bỏ những cây con trùng lặp và những cây con kém "hứa hẹn" nhất.

-   Phương pháp toán học: chẳng hạn trong lý thuyết đồ thị có thể dựa vào các thành phần liên thông, trong số học có thể phân tích phương trình đồng dư, hoặc dùng bất đẳng thức để ước lượng cận dưới, v.v.

<span id="ví-dụ"></span>
## Ví dụ

???+ note "Bài toán phân công công việc"
    Có $n$ ($1 \leq n \leq  15$) công việc cần phân cho $n$ người thực hiện, mỗi người làm đúng một việc. Thời gian người thứ $i$ cần để hoàn thành công việc thứ $k$ là một số nguyên dương $t_{i,k}$ ($1 \leq t_{i,k} \leq 10^4$), trong đó $1 \leq i, k \leq n$. Cần xác định một phương án phân công sao cho tổng thời gian hoàn thành $n$ công việc là nhỏ nhất.

Vì mỗi người đều phải được phân một công việc, có thể tạo một mảng hai chiều `time[i][j]` để biểu diễn thời gian người $i$ cần để hoàn thành công việc số $j$. Dùng một vòng lặp, bắt đầu từ người thứ 1 và lần lượt phân công việc cho đến khi tất cả mọi người đều đã được phân. Khi phân công việc cho người thứ $i$, lại duyệt từng công việc để kiểm tra xem công việc đó đã được phân chưa; nếu chưa thì phân cho người $i$, nếu rồi thì kiểm tra công việc tiếp theo. Có thể dùng một mảng một chiều `is_working[j]` để biểu diễn công việc số $j$ đã được phân hay chưa: chưa phân thì `is_working[j]=0`, ngược lại `is_working[j]=1`. Dùng tư tưởng quay lui: sau khi vòng lặp công nhân kết thúc, quay về công nhân trước đó, hủy công việc đã phân lần này, rồi thử phân công việc tiếp theo cho đến khi có thể phân được. Cứ như vậy, khi quay lui về người thứ 1, có thể thu được tất cả các nghiệm khả thi.

Kiểm tra một phương án phân công là kiểm tra xem, khi thu được nghiệm khả thi, các chỉ số theo chiều thứ nhất của mảng hai chiều đôi một khác nhau và các chỉ số theo chiều thứ hai cũng đôi một khác nhau. Mục tiêu là tổng thời gian nhỏ nhất để hoàn thành $n$ công việc, tức nghiệm khả thi có tổng thời gian nhỏ nhất. Vì vậy cần định nghĩa thêm một biến toàn cục `cost_time_total_min` để biểu diễn tổng thời gian nhỏ nhất trong các nghiệm đã tìm được. Giá trị ban đầu của `cost_time_total_min` là tổng các `time[i][i]`, tức tổng thời gian của các công việc trên đường chéo chính. Khi tất cả mọi người đã được phân việc, so sánh `count` với `cost_time_total_min`; nếu `count` nhỏ hơn `cost_time_total_min`, nghĩa là đã tìm thấy một nghiệm tốt hơn, khi đó gán `count` cho `cost_time_total_min`.

Tuy nhiên, xét về hiệu suất thuật toán, vẫn còn một việc cắt tỉa cần làm. Mỗi khi tính biến chi phí cục bộ `count`, nếu thấy `count` đã lớn hơn `cost_time_total_min`, thì không cần tiếp tục phân công xuống nữa, vì nghiệm thu được khi đó không thể là nghiệm tối ưu.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/search/code/opt/opt_1.cpp"
    ```
