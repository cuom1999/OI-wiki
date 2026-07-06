## Giới thiệu

RMQ là viết tắt của Range Maximum/Minimum Query, nghĩa là truy vấn giá trị lớn nhất (nhỏ nhất) trên một đoạn.

Trong các phần mô tả dưới đây, mặc định kích thước ban đầu của mảng là $n$ và số lượng truy vấn là $m$.

Trong các phần mô tả dưới đây, mặc định ký hiệu độ phức tạp thời gian có dạng $O(A) \sim O(B)$, trong đó $O(A)$ là độ phức tạp tiền xử lý, còn $O(B)$ là độ phức tạp cho một truy vấn.

## Ngăn xếp đơn điệu

Vì **OI Wiki** đã có phần mô tả cho nội dung này, bài viết này chỉ đưa ra [liên kết](../ds/monotonic-stack.md). Phần này sẽ không trình bày thêm.

Độ phức tạp thời gian $O(m\log m) \sim O(\log n)$, độ phức tạp không gian $O(n)$.

## Bảng ST

Vì **OI Wiki** đã có phần mô tả cho nội dung này, bài viết này chỉ đưa ra [liên kết](../ds/sparse-table.md). Phần này sẽ không trình bày thêm.

Độ phức tạp thời gian $O(n\log n) \sim O(1)$, độ phức tạp không gian $O(n\log n)$.

## Cây đoạn

Vì **OI Wiki** đã có phần mô tả cho nội dung này, bài viết này chỉ đưa ra [liên kết](../ds/seg.md). Phần này sẽ không trình bày thêm.

Độ phức tạp thời gian $O(n) \sim O(\log n)$, độ phức tạp không gian $O(n)$.

## Thuật toán Four Russians

Four Russians là một thuật toán dựa trên bảng ST, do bốn nhà khoa học máy tính người Nga đề xuất.

Cải tiến mà thuật toán Four Russians thực hiện trên nền bảng ST là chia dãy thành các khối.

Cụ thể, chia mảng gốc, gọi là mảng A, thành các khối có kích thước $S$, tổng cộng $n/S$ khối.

Với mỗi khối, tiền xử lý giá trị nhỏ nhất trong khối để xây dựng một mảng B có độ dài $n/S$, rồi tiền xử lý mảng B theo cách của bảng ST.

Đồng thời, với mỗi khối rời rạc của mảng A, cũng xây dựng một bảng ST.

Khi truy vấn, có thể chia đoạn truy vấn thành không quá 1 đoạn khối liên tiếp trên mảng B và không quá 2 đoạn liên tiếp nằm trọn trong một khối trên mảng A. Các bài toán này đều có thể được giải bằng truy vấn đoạn trên bảng ST.

Khi $S=\log n$, độ phức tạp tiền xử lý đạt tối ưu, bằng $O((n / \log n)\log n+(n / \log n)\times\log n\times\log \log n)=O(n\log \log n)$.

Độ phức tạp thời gian $O(n\log \log n) \sim O(1)$, độ phức tạp không gian $O(n\log \log n)$.

Tuy nhiên, vì mỗi truy vấn phải chạy trên ba bảng ST, cách cài đặt này có hằng số khá lớn.

??? note "Một vài cải tiến thuật toán nhỏ"
    Khi hai đầu mút của truy vấn thuộc hai khối khác nhau trong mảng A, các truy vấn nội bộ khối trong mảng A đều là truy vấn trên tiền tố hoặc hậu tố của mỗi khối.
    
    Các truy vấn này có thể được giải trong $O(n)$ bằng cách tiền xử lý đáp án.
    
    Như vậy, khi truy vấn chỉ cần thực hiện nhiều nhất một phép truy vấn trên bảng ST.

??? note "Một vài cải tiến thuật toán mang tính kinh nghiệm"
    Vì thuật toán Four Russians dựa trên bảng ST, mà trong lập trình thi đấu thường không có yêu cầu độ phức tạp thời gian quá khắt khe, nên thuật toán Four Russians nhìn chung có thể được thay bằng bảng ST và không thực dụng lắm trong lập trình thi đấu. Phần này đưa ra một biến thể cải tiến của Four Russians thực dụng hơn trong lập trình thi đấu.
    
    Đặt kích thước khối là $\sqrt n$, sau đó tiền xử lý RMQ trên tiền tố và hậu tố trong mỗi khối, rồi tiền xử lý vét cạn RMQ giữa hai khối nguyên liên tiếp bất kỳ; độ phức tạp thời gian là $O(n)$.
    
    Khi truy vấn, với truy vấn có hai đầu mút không nằm trong cùng một khối, có thể lấy trực tiếp trong $O(1)$ ba giá trị: RMQ hậu tố của khối chứa đầu mút trái, RMQ của các khối nguyên liên tiếp nằm giữa đầu mút trái và đầu mút phải, và RMQ tiền tố của khối chứa đầu mút phải. Đáp án chính là giá trị cực trị trong ba giá trị đó.
    
    Còn với truy vấn có hai đầu mút nằm trong cùng một khối, có thể vét cạn để tìm RMQ giữa hai điểm, với độ phức tạp thời gian $O(\sqrt n)$. Tuy nhiên, xác suất kỳ vọng để hai đầu mút của một truy vấn nằm trong cùng một khối là $O(\frac{\sqrt n}{n})$, nên độ phức tạp thời gian của phương pháp này là kỳ vọng $O(n)$.
    
    Trong lập trình thi đấu, không cần quá lo việc người ra đề cố tình làm thuật toán này bị kẹt, vì có thể tinh chỉnh ngẫu nhiên kích thước khối quanh $\sqrt n$ để phần lớn tránh trường hợp xấu nhất trên dữ liệu được dựng theo một kích thước khối cụ thể. Hơn nữa, nếu người ra đề muốn chặn phương pháp này, lời giải vét cạn cũng có thể vượt qua được.
    
    Đây là một thuật toán đạt cận dưới về độ phức tạp thời gian kỳ vọng, đồng thời có độ khó cài đặt và hằng số thuật toán đều nhỏ, nên khá thực dụng trong lập trình thi đấu.
    
    Cách làm trên tham khảo lời giải của bài [P3793 Yuno cứu ông nội](https://www.luogu.com.cn/problem/P3793).

## RMQ cộng trừ 1

Nếu dãy thỏa mãn hai phần tử kề nhau chênh lệch đúng 1, thì RMQ trên dãy đó có thể được gọi là RMQ cộng trừ 1. Dựa vào tính chất này, có thể cải tiến thuật toán Four Russians để đạt độ phức tạp thời gian $O(n) \sim O(1)$ và độ phức tạp không gian $O(n)$.

Vì điểm nghẽn của thuật toán Four Russians nằm ở bài toán RMQ trong khối, phần này tập trung thảo luận cách tối ưu bài toán RMQ trong khối.

Do hiệu của hai số kề nhau là $\pm 1$, nên khi cố định số ở đầu mút trái, số loại dãy bên phải có độ dài không vượt quá $\log n$ là $\sum_{i=1}^{\log n} 2^{i-1}$, và biểu thức này không vượt quá $n$.

Điều này gợi ý rằng có thể tiền xử lý giá trị "giá trị nhỏ nhất - phần tử đầu tiên" cho tất cả không quá $n$ trường hợp.

Khi tiền xử lý, cần tiền xử lý hiệu giữa hai số kề nhau trong cùng một khối và biểu diễn hiệu đó bằng nhị phân.

Khi truy vấn, tìm biểu diễn nhị phân tương ứng với đoạn truy vấn, rồi tra bảng để lấy đáp án.

Như vậy, độ phức tạp tiền xử lý của Four Russians được tối ưu xuống $O(n)$.

## Ứng dụng cây Cartesian trong RMQ

Nếu chưa quen với cây Cartesian, xem [cây Cartesian](../ds/cartesian-tree.md).

Min/max giữa hai điểm trên dãy ban đầu bằng trọng số của LCA của hai điểm đó trên cây Cartesian. Dựa vào điều này, có thể mượn lời giải LCA giữa hai điểm trên cây với độ phức tạp $O(n) \sim O(1)$ để giải RMQ. LCA trên cây với $O(n) \sim O(1)$ đã được mô tả trong [LCA - RMQ chuẩn](../graph/lca.md#rmq-chuẩn), nên phần này không trình bày thêm.

Tóm lại, ứng dụng cây Cartesian trong RMQ là chuyển bài toán RMQ thông thường thành bài toán LCA, rồi tiếp tục chuyển thành bài toán RMQ cộng trừ 1 để giải, với độ phức tạp thời gian $O(n) \sim O(1)$. Do có nhiều bước chuyển đổi, RMQ $O(n) \sim O(1)$ có hằng số khá lớn.

Nếu dữ liệu ngẫu nhiên, cũng có thể tìm kiếm vét cạn trên cây Cartesian. Khi đó độ phức tạp thời gian là kỳ vọng $O(n) \sim O(\log n)$, và trong thực tế hằng số của thuật toán này thường rất nhỏ.

### Bài ví dụ [Luogu P3865 [Mẫu] bảng ST](https://www.luogu.com.cn/problem/P3865)

## Thuật toán RMQ tuyến tính dựa trên nén trạng thái

### Yêu cầu ngầm

-   Độ dài dãy $n$ thỏa mãn $\log_2{n} \leq 64$.

### Kiến thức chuẩn bị

-   [Sparse Table](../ds/sparse-table.md)

-   Các thao tác bit cơ bản

-   Cực trị tiền tố và hậu tố

### Nguyên lý thuật toán

Chia dãy gốc $A[1\cdots n]$ thành $O(\frac{n}{\log_2{n}})$ khối, mỗi khối có độ dài $O(\log_2{n})$.

> Nghe nói khi đặt độ dài khối là $1.5\times \log_2{n}$ thì hằng số nhỏ hơn.

Ghi lại giá trị lớn nhất của mỗi khối, và dùng bảng ST để duy trì giá trị lớn nhất giữa các khối; độ phức tạp là $O(n)$.

Ghi lại giá trị lớn nhất theo tiền tố và hậu tố tại mỗi vị trí trong khối, $Pre[1\cdots n], Sub[1\cdots n]$ ($Pre[i]$ là giá trị lớn nhất từ $A[i]$ đến đầu khối chứa nó); độ phức tạp là $O(n)$.

Nếu $l,r$ của truy vấn nằm trên hai khối khác nhau, lần lượt ký hiệu là khối thứ $bl,br$, thì giá trị lớn nhất là giá trị lớn nhất giữa ba số: giá trị lớn nhất giữa các khối trong $[bl+1,br-1]$, $Sub[l]$ và $Pre[r]$.

Vấn đề còn lại là xử lý trường hợp $l,r$ nằm trong cùng một khối.

Lần lượt chèn $A[1\cdots r]$ vào ngăn xếp đơn điệu, ghi lại chỉ số và giá trị, sao cho giá trị giảm dần từ đáy lên đỉnh ngăn xếp. Khi đó giá trị lớn nhất trong $A[l,r]$ là giá trị đầu tiên trên ngăn xếp đơn điệu, tính từ đáy đi lên, có chỉ số $p \geq l$.

Vì $A[p]$ là giá trị lớn nhất trong $A[l,r]$, nên khi chèn $A[p]$, các phần tử $A[l\cdots p-1]$ đều bị bật ra, và khi chèn $A[p+1\cdots r]$ thì không thể bật $A[p]$ ra.

Nếu dùng $0/1$ để biểu diễn mỗi số có đang ở trong ngăn xếp hay không, có thể dùng một số nguyên để nén trạng thái. Khi đó $p$ là vị trí đầu tiên có bit $1$ sau vị trí thứ $l$.

Vì kích thước khối là $O(\log_2{n})$, nên nhiều nhất không vượt quá $64$ bit và có thể lưu bằng một số nguyên (đây cũng là nguyên nhân của điều kiện ngầm).

??? note "Mã tham khảo"
    ```cpp
    #include <algorithm>
    #include <cmath>
    #include <cstdio>
    
    constexpr int MAXN = 1e5 + 5;
    constexpr int MAXM = 20;
    
    struct RMQ {
      int N, A[MAXN];
      int blockSize;
      int S[MAXN][MAXM], Pow[MAXM], Log[MAXN];
      int Belong[MAXN], Pos[MAXN];
      int Pre[MAXN], Sub[MAXN];
      int F[MAXN];
    
      void buildST() {
        int cur = 0, id = 1;
        Pos[0] = -1;
        for (int i = 1; i <= N; ++i) {
          S[id][0] = std::max(S[id][0], A[i]);
          Belong[i] = id;
          if (Belong[i - 1] != Belong[i])
            Pos[i] = 0;
          else
            Pos[i] = Pos[i - 1] + 1;
          if (++cur == blockSize) {
            cur = 0;
            ++id;
          }
        }
        if (N % blockSize == 0) --id;
        Pow[0] = 1;
        for (int i = 1; i < MAXM; ++i) Pow[i] = Pow[i - 1] * 2;
        for (int i = 2; i <= id; ++i) Log[i] = Log[i / 2] + 1;
        for (int i = 1; i <= Log[id]; ++i) {
          for (int j = 1; j + Pow[i] - 1 <= id; ++j) {
            S[j][i] = std::max(S[j][i - 1], S[j + Pow[i - 1]][i - 1]);
          }
        }
      }
    
      void buildSubPre() {
        for (int i = 1; i <= N; ++i) {
          if (Belong[i] != Belong[i - 1])
            Pre[i] = A[i];
          else
            Pre[i] = std::max(Pre[i - 1], A[i]);
        }
        for (int i = N; i >= 1; --i) {
          if (Belong[i] != Belong[i + 1])
            Sub[i] = A[i];
          else
            Sub[i] = std::max(Sub[i + 1], A[i]);
        }
      }
    
      void buildBlock() {
        static int S[MAXN], top;
        for (int i = 1; i <= N; ++i) {
          if (Belong[i] != Belong[i - 1])
            top = 0;
          else
            F[i] = F[i - 1];
          while (top > 0 && A[S[top]] <= A[i]) F[i] &= ~(1 << Pos[S[top--]]);
          S[++top] = i;
          F[i] |= (1 << Pos[i]);
        }
      }
    
      void init() {
        for (int i = 1; i <= N; ++i) scanf("%d", &A[i]);
        blockSize = log2(N) * 1.5;
        buildST();
        buildSubPre();
        buildBlock();
      }
    
      int queryMax(int l, int r) {
        int bl = Belong[l], br = Belong[r];
        if (bl != br) {
          int ans1 = 0;
          if (br - bl > 1) {
            int p = Log[br - bl - 1];
            ans1 = std::max(S[bl + 1][p], S[br - Pow[p]][p]);
          }
          int ans2 = std::max(Sub[l], Pre[r]);
          return std::max(ans1, ans2);
        } else {
          return A[l + __builtin_ctz(F[r] >> Pos[l])];
        }
      }
    } R;
    
    int M;
    
    int main() {
      scanf("%d%d", &R.N, &M);
      R.init();
      for (int i = 0, l, r; i < M; ++i) {
        scanf("%d%d", &l, &r);
        printf("%d\n", R.queryMax(l, r));
      }
      return 0;
    }
    ```

### Bài tập

[\[BJOI 2020\] Phong ấn](https://loj.ac/problem/3298): SAM+RMQ
