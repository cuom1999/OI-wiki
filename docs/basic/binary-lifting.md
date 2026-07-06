author: Ir1d, ShadowsEpic, Fomalhauthmj, siger-young, MingqiHuang, Xeonacid, hsfzLZH1, orzAtalod, NachtgeistW

Trang này giới thiệu ngắn gọn về kỹ thuật nhảy nhị phân.

## Định nghĩa

Nhảy nhị phân (binary lifting) là kỹ thuật nhảy theo các bước có độ dài tăng
theo lũy thừa, thường là lũy thừa của 2.

Khi thực hiện truy hồi, nếu không gian trạng thái lớn và cách truy hồi tuyến
tính thông thường không đáp ứng được yêu cầu về thời gian hoặc bộ nhớ, ta có thể
chỉ lưu các giá trị đại diện ứng với độ dài là lũy thừa của một số $k$. Khi cần
giá trị ở độ dài khác, dùng tính chất "mọi số nguyên đều có thể biểu diễn thành
tổng của một số lũy thừa của $k$" để ghép từ các giá trị đã tính trước.

Vì vậy, để áp dụng nhảy nhị phân, không gian trạng thái của bài toán phải có thể
chia tách theo các lũy thừa của $k$. Thông thường ta chọn $k=2$.[^ref1]

Kỹ thuật này xuất hiện trong nhiều thuật toán. Hai ứng dụng phổ biến nhất là
bài toán RMQ và tìm [LCA (tổ tiên chung gần nhất)](../graph/lca.md).

## Ứng dụng

### Bài toán RMQ

Xem thêm: [chuyên đề RMQ](../topic/rmq.md)

RMQ là viết tắt của Range Maximum/Minimum Query, nghĩa là truy vấn giá trị lớn
nhất hoặc nhỏ nhất trên một đoạn. Một cách dùng tư tưởng nhảy nhị phân để giải
RMQ là [bảng ST](../ds/sparse-table.md).

### Nhảy nhị phân trên cây để tìm LCA

Xem thêm: [tổ tiên chung gần nhất](../graph/lca.md)

## Bài ví dụ

### Bài 1

???+ note "Bài ví dụ"
    Làm thế nào để dùng ít quả cân nhất có thể để cân mọi khối lượng trong
    đoạn $[0,31]$? Chỉ được đặt quả cân ở một bên của cân thăng bằng.

??? note "Ý tưởng giải"
    Đáp án là dùng năm quả cân có khối lượng 1, 2, 4, 8, 16. Chúng có thể cân
    được mọi khối lượng trong $[0,31]$. Tương tự, nếu cần cân mọi khối lượng
    trong $[0,127]$, có thể dùng bảy quả cân 1, 2, 4, 8, 16, 32, 64. Mỗi quả
    cân có khối lượng là một lũy thừa của 2, nhờ đó có thể dùng ít quả cân để
    tạo ra bất kỳ khối lượng cần thiết nào.

    Vì sao gọi là ít? Nếu cần đo mọi khối lượng trong $[0,1023]$, 10 quả cân là
    đủ; nếu cần đo mọi khối lượng trong $[0,1048575]$, 20 quả cân là đủ. Khi
    phạm vi khối lượng mục tiêu tăng gấp đôi, số quả cân chỉ tăng thêm 1. Đây
    là tốc độ tăng "cấp logarit", vì số quả cân cần dùng tỉ lệ với logarit của
    phạm vi khối lượng mục tiêu.

### Bài 2

???+ note "Bài ví dụ"
    Cho một vòng độ dài $n$ và một hằng số $k$. Mỗi lần nhảy từ điểm thứ $i$
    sang điểm thứ $(i+k)\bmod n+1$, tổng cộng nhảy $m$ lần. Mỗi điểm có một
    trọng số $a_i$. Tính tổng trọng số của các điểm xuất phát trong $m$ lần
    nhảy, lấy modulo $10^9+7$.

    Giới hạn: $1\leq n\leq 10^6$, $1\leq m\leq 10^{18}$,
    $1\leq k\leq n$, $0\leq a_i\leq 10^9$.

??? note "Ý tưởng giải"
    Không thể mô phỏng vét cạn $m$ lần nhảy. Vì $m$ có thể lớn đến $10^{18}$,
    mô phỏng trực tiếp sẽ không đáp ứng được giới hạn thời gian.

    Do đó cần tiền xử lý một số thông tin và gộp sẵn dữ liệu để trả lời nhanh
    hơn khi truy vấn. Nếu ghi lại kết quả cho mọi số lần nhảy có thể, cả thời
    gian lẫn bộ nhớ đều không khả thi.

    Vậy nên tiền xử lý thế nào? Nhìn lại bài ví dụ đầu tiên sẽ thấy hướng làm.

    Quay lại bài này. Ta cần tiền xử lý một lượng thông tin không quá lớn, rồi
    dùng thông tin đó để ghép đáp án nhanh nhất có thể. Vì vậy có thể tiền xử lý
    thông tin theo các đơn vị là lũy thừa của 2. Khi đó, tiền xử lý chỉ cần lưu
    một số lớp thông tin nhỏ, và bước ghép đáp án cũng không phức tạp.

    Cụ thể trong bài này, tiền xử lý kết quả khi bắt đầu từ mỗi điểm rồi nhảy
    1, 2, 4, 8,... bước; mỗi kết quả gồm điểm kết thúc và tổng trọng số. Nếu cần
    nhảy 13 bước, có thể tách thành $1+4+8$ bước: đầu tiên nhảy 1 bước từ điểm
    xuất phát, sau đó nhảy 4 bước từ điểm vừa đến, rồi tiếp tục nhảy 8 bước,
    đồng thời cộng các tổng trọng số đã tiền xử lý. Như vậy ta biết được tổng
    trọng số của 13 bước nhảy.

    Với mỗi điểm và mỗi độ dài $2^i$, đặt `go[i][x]` là điểm kết thúc sau khi
    nhảy $2^i$ bước từ điểm $x$, còn `sum[i][x]` là tổng trọng số nhận được khi
    nhảy $2^i$ bước từ điểm $x$. Khi tiền xử lý, dùng hai vòng lặp. Thông tin
    của $2^i$ bước có thể xem là nhảy $2^{i-1}$ bước rồi nhảy tiếp $2^{i-1}$
    bước, vì $2^{i-1}+2^{i-1}=2^i$. Do đó
    `sum[i][x] = sum[i-1][x]+sum[i-1][go[i-1][x]]` và
    `go[i][x] = go[i-1][go[i-1][x]]`.

    Vẫn có vài chi tiết cài đặt cần lưu ý. Để tránh đếm thiếu hoặc đếm trùng,
    thường tiền xử lý tổng trọng số theo đoạn "đóng trái, mở phải". Nghĩa là
    khi nhảy 1 bước, chỉ ghi trọng số của điểm hiện tại; khi nhảy 2 bước, chỉ
    ghi trọng số của điểm hiện tại và điểm kế tiếp. Nói cách khác, điểm kết thúc
    không được tính vào `sum`. Nhờ vậy khi tiền xử lý, chỉ cần cộng trực tiếp
    hai phần tổng trọng số, không phải lo điểm cuối của đoạn đầu và điểm đầu của
    đoạn sau bị tính lặp.

    Trong bài này $m\leq 10^{18}$ trông có vẻ lớn, nhưng thực tế tiền xử lý $i$
    đến khoảng $65$ là đủ để giải, nhanh hơn đáng kể so với liệt kê vét cạn.
    Theo thuật ngữ độ phức tạp, cách làm này có
    [độ phức tạp thời gian](./complexity.md) tiền xử lý $\Theta(n\log m)$ và
    mỗi truy vấn $\Theta(\log m)$.

??? note "Mã tham khảo"
    ```cpp
    #include <cstdio>
    using namespace std;

    constexpr int mod = 1000000007;

    int modadd(int a, int b) {
      if (a + b >= mod) return a + b - mod;  // dùng phép trừ thay modulo để chạy nhanh hơn
      return a + b;
    }

    int vi[1000005];

    int go[75][1000005];  // mở mảng lớn hơn một chút để tránh vượt biên; chiều nhỏ nên đặt trước
    int sum[75][1000005];

    int main() {
      int n, k;
      scanf("%d%d", &n, &k);
      for (int i = 1; i <= n; ++i) {
        scanf("%d", vi + i);
      }

      for (int i = 1; i <= n; ++i) {
        go[0][i] = (i + k) % n + 1;
        sum[0][i] = vi[i];
      }

      constexpr int LOG = 61;  // đủ để xử lý m <= 1e18
      for (int i = 1; i < LOG; ++i) {
        for (int j = 1; j <= n; ++j) {
          go[i][j] = go[i - 1][go[i - 1][j]];
          sum[i][j] = modadd(sum[i - 1][j], sum[i - 1][go[i - 1][j]]);
        }
      }

      long long m;
      scanf("%lld", &m);

      int ans = 0;
      int curx = 1;
      for (int i = 0; m; ++i) {
        if (m & (1ll << i)) {  // xem phần thao tác bit: bit thứ i của m có bằng 1 hay không
          ans = modadd(ans, sum[i][curx]);
          curx = go[i][curx];
          m ^= 1ll << i;  // đặt bit thứ i về 0
        }
      }

      printf("%d\n", ans);
    }
    ```

[^ref1]: Trích từ mục 0x06 "Binary lifting" trong *Advanced Guide to Algorithmic Contests* của Li Yudong.
