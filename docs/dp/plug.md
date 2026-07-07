## Định nghĩa

<span id="định-nghĩa"></span>

Một số bài toán [DP nén trạng thái](./state.md) yêu cầu ghi lại thông tin liên thông của trạng thái. Những bài toán như vậy thường được gọi một cách hình tượng là DP đầu nối (plug DP), hay DP nén trạng thái liên thông. Ví dụ: đếm đường đi Hamilton trên đồ thị lưới, đếm số cách tô đen trắng bàn cờ sao cho các ô cùng màu tạo thành một khối liên thông, hoặc đếm cây khung của một số đồ thị đặc biệt. Các bài toán này thường cần mã hóa tính liên thông của trạng thái và phân tích cách tính liên thông thay đổi trong quá trình chuyển trạng thái.

## Mở đầu

<span id="mở-đầu"></span>

### Lát domino và DP đường biên

<span id="lát-domino-và-dp-đường-biên"></span>

Trước khi đi vào DP đầu nối, cần nhắc lại một bài toán kinh điển.

???+ note "Ví dụ [「HDU 1400」Mondriaan’s Dream](https://acm.hdu.edu.cn/showproblem.php?pid=1400)"
    Tóm tắt đề bài: lát kín một bàn cờ $N\times M$ bằng các quân domino $1\times 2$ hoặc $2\times 1$, hỏi có bao nhiêu cách lát.

Khi $n$ hoặc $m$ không quá lớn, dạng bài này có thể giải bằng [DP nén trạng thái](./state.md). Nếu chia giai đoạn theo từng hàng, đặt $dp(i,s)$ là số cách sau khi đã xét $i$ hàng đầu, và trạng thái của hàng thứ $i$ là $s$. Mỗi bit của trạng thái $s$ có thể biểu thị vị trí tương ứng đã được phủ từ hàng trước hay chưa.

![Trạng thái phủ ô trong bài toán lát domino](./images/domino.svg)

Một cách chia giai đoạn khác là DP theo từng ô, còn gọi là DP đường biên. $dp(i,j,s)$ biểu thị số cách khi đã xét đến hàng $i$, cột $j$, và trạng thái hiện tại trên đường biên là $s$.

Mặc dù DP theo từng ô làm trạng thái có thêm một chiều, độ phức tạp của mỗi lần chuyển giảm xuống $O(1)$, nên tổng độ phức tạp thời gian không đổi. Gọi $f_0$ là trạng thái ở giai đoạn hiện tại, $f_1$ là trạng thái ở giai đoạn kế tiếp, và $u = f_0(s)$ là giá trị ứng với trạng thái đang xét. Khi đó có các công thức chuyển trạng thái sau:

```cpp
if (s >> j & 1) {       // Nếu đã được phủ
  f1[s ^ 1 << j] += u;  // Không đặt quân
} else {                // Nếu chưa được phủ
  if (j != m - 1 && (!(s >> j + 1 & 1))) f1[s ^ 1 << j + 1] += u;  // Đặt ngang
  f1[s ^ 1 << j] += u;                                             // Đặt dọc
}
```

Hai công thức "không đặt" và "đặt dọc" có thể gộp lại.

??? note "Cài đặt"
    ```cpp
    #include <algorithm>
    #include <iostream>
    using namespace std;
    constexpr int N = 11;
    long long f[2][1 << N], *f0, *f1;
    int n, m;
    
    int main() {
      while (cin >> n >> m && n) {
        f0 = f[0];
        f1 = f[1];
        fill(f1, f1 + (1 << m), 0);
        f1[0] = 1;
        for (int i = 0; i < n; ++i) {
          for (int j = 0; j < m; ++j) {
            swap(f0, f1);
            fill(f1, f1 + (1 << m), 0);
    #define u f0[s]
            for (int s = 0; s < 1 << m; ++s)
              if (u) {
                if (j != m - 1 && (!(s >> j & 3))) f1[s ^ 1 << j + 1] += u;  // Đặt ngang
                f1[s ^ 1 << j] += u;  // Đặt dọc hoặc không đặt
              }
          }
        }
        cout << f1[0] << endl;
      }
    }
    ```

??? note "Bài tập [「SRM 671. Div 1 900」BearDestroys](https://archive.topcoder.com/ProblemStatement/pm/14069)"
    Tóm tắt đề bài: cho một ma trận $n\times m$, mỗi ô là `E` hoặc `S`.
    Với một ma trận, có một cách tính điểm. Quét từng ô theo thứ tự hàng trước cột sau; nếu ô này đã bị domino chiếm thì bỏ qua.
    Nếu không, thử đặt một quân domino. Nếu hướng đặt vượt ra ngoài ma trận hoặc đã bị domino khác chiếm, lần đặt thất bại, rồi chuyển sang phương án còn lại hoặc bỏ qua.
    Nếu là `E` thì ưu tiên đặt một quân $1\times 2$,
    nếu là `S` thì ưu tiên đặt một quân $2\times 1$.
    Điểm của một ma trận là số quân domino được đặt cuối cùng.
    Hỏi tổng điểm của tất cả $2^{nm}$ ma trận.

### Thuật ngữ

<span id="thuật-ngữ"></span>

Giai đoạn: thứ tự thực hiện quy hoạch động; kết quả của các giai đoạn sau chỉ phụ thuộc vào kết quả của các giai đoạn trước (không có hậu hiệu). Nhiều bài toán DP có thể có nhiều cách chia giai đoạn. Ví dụ trong bài toán ba lô, có thể chia theo vật phẩm hoặc theo dung lượng ba lô (vòng lặp ngoài duyệt gì trước). Còn trong bài toán domino, có thể chia theo hàng, cột, ô, đường chéo và các đặc trưng khác.

Đường biên: ranh giới giữa phần trạng thái đã quyết định và phần chưa quyết định.

![Đường biên giữa phần đã quyết định và chưa quyết định](./images/contour_line.svg)

Đầu nối: nếu một ô có đầu nối ở một hướng nào đó, nghĩa là ô này nối với ô kề nó theo hướng đó.

![Đầu nối giữa các ô kề nhau](./images/plug.svg)

## Mô hình đường đi

<span id="mô-hình-đường-đi"></span>

### Nhiều chu trình

<span id="nhiều-chu-trình"></span>

#### Ví dụ

<span id="ví-dụ"></span>

???+ note "Ví dụ [「HDU 1693」Eat the Trees](https://acm.hdu.edu.cn/showproblem.php?pid=1693)"
    Tóm tắt đề bài: đếm số cách phủ bàn cờ $N\times M$ bằng một số chu trình; một số vị trí có chướng ngại.

Nói nghiêm ngặt, bài toán nhiều chu trình không thuộc DP đầu nối, vì cũng như bài toán lát domino ở trên, chỉ cần ghi lại đầu nối có tồn tại hay không, rồi ghép và sinh đầu nối theo từng cặp.

Với một bàn cờ rộng $m$, độ rộng của đường biên là $m+1$, vì nó gồm $m$ đầu nối phía trên và $1$ đầu nối bên trái. Sau khi duyệt xong một hàng, đầu nối trái ở ngoài cùng bên phải thường là trạng thái không hợp lệ; đồng thời cần bổ sung đầu nối trái đầu tiên của hàng tiếp theo. Vì vậy cần điều chỉnh trạng thái đường biên hiện tại, thường là dịch trái toàn bộ trạng thái; thao tác này gọi là cuộn `roll()`.

??? note "Mã ví dụ"
    ```cpp
    --8<-- "docs/dp/code/plug/plug_1.cpp"
    ```

#### Bài tập

<span id="bài-tập"></span>

??? note "Bài tập [「ZOJ 3466」The Hive II](https://pintia.cn/problem-sets/91827364500/exam/problems/type/7?problemSetProblemId=91827368730)"
    Tóm tắt đề bài: giống bài trên, nhưng các ô trở thành lục giác.

### Một chu trình

<span id="một-chu-trình"></span>

#### Ví dụ

<span id="ví-dụ_1"></span>

???+ note "Ví dụ [「Andrew Stankevich Contest 16 - Bài F」Bố trí đường ống](https://codeforces.com/gym/100220)"
    Tóm tắt đề bài: đếm số cách phủ bàn cờ $N\times M$ bằng đúng một chu trình.

Trong cách biểu diễn trạng thái ở trên, mỗi lần ghép một nhóm đầu nối liên thông, một chu trình độc lập sẽ được tạo ra. Vì vậy ở bài này, còn cần phân biệt tính liên thông giữa các đầu nối (nó đã xuất hiện!). Điều này đòi hỏi mã hóa trạng thái thêm một bước.

#### Mã hóa trạng thái

<span id="mã-hóa-trạng-thái"></span>

Các cách mã hóa thường dùng gồm biểu diễn bằng ngoặc và biểu diễn tối tiểu. Phần này tập trung giới thiệu biểu diễn tối tiểu, vì nó có tính tổng quát tốt hơn. Dùng một mảng số nguyên độ dài $m+1$ để ghi lại trạng thái của từng đầu nối trên đường biên; $0$ nghĩa là không có đầu nối, và quy ước các đầu nối liên thông với nhau được đánh dấu bằng cùng một số.

Khi đó hai cách mã hóa sau biểu diễn cùng một trạng thái:

-   `0 3 1 0 1 3`
-   `0 1 2 0 2 1`

Mọi trạng thái tương đương được ánh xạ về biểu diễn có thứ tự từ điển nhỏ nhất; trong ví dụ trên, `0 1 2 0 2 1` là một biểu diễn tối tiểu.

Dùng mảng `b[]` để biểu diễn trạng thái của các đầu nối trên đường biên. `bb[]` biểu diễn, trong quá trình mã hóa tối tiểu, mỗi số được ánh xạ tới số nhỏ nhất nào. Do $0$ biểu thị đầu nối không tồn tại, giá trị này không được ánh xạ thành giá trị khác.

??? note "Cài đặt mã"
    ```cpp
    int b[M + 1], bb[M + 1];
    
    int encode() {
      int s = 0;
      memset(bb, -1, sizeof(bb));
      int bn = 1;
      bb[0] = 0;
      for (int i = m; i >= 0; --i) {
    #define bi bb[b[i]]
        if (!~bi) bi = bn++;
        s <<= offset;
        s |= bi;
      }
      return s;
    }
    
    void decode(int s) {
      REP(i, m + 1) {
        b[i] = s & mask;
        s >>= offset;
      }
    }
    ```

Các đầu nối luôn xuất hiện theo cặp và biến mất theo cặp. Vì vậy trạng thái như `0 1 2 0 1 2` là không hợp lệ. Các trạng thái hợp lệ tạo thành một dãy ngoặc, và trong thực tế tập trạng thái hợp lệ có thể rất thưa.

#### Tự viết bảng băm

<span id="tự-viết-bảng-băm"></span>

Trong một số bài toán [DP nén trạng thái](./state.md), các trạng thái hợp lệ có thể rất thưa (ví dụ bài này). Để tối ưu độ phức tạp thời gian và bộ nhớ, có thể dùng bảng băm để lưu các trạng thái DP hợp lệ. Với C++, có thể dùng [std::unordered\_map](http://www.cplusplus.com/reference/unordered_map/unordered_map/), hoặc tự viết trực tiếp để linh hoạt đóng gói cả hàm chuyển trạng thái.

???+ note "Cài đặt mã"
    ```cpp
    constexpr int MaxSZ = 16796, Prime = 9973;
    
    struct hashTable {
      int head[Prime], next[MaxSZ], sz;
      int state[MaxSZ];
      long long key[MaxSZ];
    
      void clear() {
        sz = 0;
        memset(head, -1, sizeof(head));
      }
    
      void push(int s) {
        int x = s % Prime;
        for (int i = head[x]; ~i; i = next[i]) {
          if (state[i] == s) {
            key[i] += d;
            return;
          }
        }
        state[sz] = s, key[sz] = d;
        next[sz] = head[x];
        head[x] = sz++;
      }
    
      void roll() { REP(i, sz) state[i] <<= offset; }
    } H[2], *H0, *H1;
    ```

Trong đoạn mã trên:

-   `MaxSZ` biểu thị cận trên của số trạng thái hợp lệ; có thể ước lượng hoặc tiền xử lý để có giá trị chính xác hơn.
-   `Prime` là một số nguyên tố lớn nhỏ hơn `MaxSZ`.
-   `head[]` là con trỏ tới nút đầu của từng bucket.
-   `next[]` là con trỏ tới trạng thái kế tiếp.
-   `state[]` là trạng thái của nút.
-   `key[]` là khóa của nút; trong bài này chính là số phương án.
-   `clear()` là hàm khởi tạo. Tương tự danh sách kề tự viết, chỉ cần khởi tạo con trỏ của các nút đầu.
-   `push()` là hàm chuyển trạng thái; trong đó `d` là một biến toàn cục (để viết nhanh), biểu thị lượng tăng thêm do mỗi lần chuyển trạng thái mang lại. Nếu tìm thấy trạng thái thì `+=`, nếu không thì tạo một nút mới có trạng thái là `s` và khóa là `d`.
-   `roll()` cuộn đường biên sau khi duyệt xong cả một hàng.

Về phân tích độ phức tạp của bảng băm, cũng như sự khác nhau giữa hashing mở và hashing đóng, có thể tham khảo các chương liên quan đến bảng băm trong [Introduction to Algorithms](../contest/resources.md#sách).

#### Chuyển trạng thái

<span id="chuyển-trạng-thái"></span>

???+ note "Cài đặt mã"
    ```cpp
    REP(ii, H0->sz) {
      decode(H0->state[ii]);                  // Lấy trạng thái ra và giải mã
      d = H0->key[ii];                        // Lấy lượng tăng delta
      int lt = b[j], up = b[j + 1];           // Đầu nối trái, đầu nối trên
      bool dn = i != n - 1, rt = j != m - 1;  // Đầu nối dưới, đầu nối phải
      if (lt && up) {                         // Nếu cả trái và trên đều có đầu nối
        if (lt == up) {                       // Đến từ cùng một thành phần liên thông
          if (i == n - 1 &&
              j == m - 1) {  // Chỉ ở ô cuối cùng mới được ghép để khép kín chu trình.
            push(j, 0, 0);
          }
        } else {  // Nếu không, phải ghép hai thành phần liên thông này vì bài yêu cầu phủ bằng chu trình
          REP(i, m + 1) if (b[i] == lt) b[i] = up;
          push(j, 0, 0);
        }
      } else if (lt || up) {  // Nếu trong trái và trên có đúng một đầu nối
        int t = lt | up;      // Lấy đầu nối đó
        if (dn) {             // Nếu có thể kéo dài xuống dưới
          push(j, t, 0);
        }
        if (rt) {  // Nếu có thể kéo dài sang phải
          push(j, 0, t);
        }
      } else {           // Nếu cả trái và trên đều không có đầu nối
        if (dn && rt) {  // Sinh một cặp đầu nối mới
          push(j, m, m);
        }
      }
    }
    ```

??? note "Mã ví dụ"
    ```cpp
    --8<-- "docs/dp/code/plug/plug_2.cpp"
    ```

#### Bài tập

<span id="bài-tập_1"></span>

??? note "Bài tập [「Ural 1519」Formula 1](https://acm.timus.ru/problem.aspx?space=1&num=1519)"
    Tóm tắt đề bài: đếm số cách phủ bàn cờ $N\times M$ bằng đúng một chu trình; một số vị trí có chướng ngại.

??? note "Bài tập [「USACO 5.4.4」Betsy's Tours](https://hydro.ac/d/USACO/p/USACO544)"
    Tóm tắt đề bài: với một hình vuông $N\times N$ ($N\le 7$), đếm số đường đi bắt đầu từ góc trên trái, kết thúc ở góc dưới trái và đi qua mọi ô. Tuy là một đường đi, nhưng vì điểm đầu và điểm cuối cố định, có thể chuyển thành bài toán một chu trình.

??? note "Bài tập [「POJ 1739」Tony's Tour](http://poj.org/problem?id=1739)"
    Tóm tắt đề bài: với một bàn cờ $N\times M$, đếm số đường đi bắt đầu từ góc dưới trái, kết thúc ở góc dưới phải và đi qua mọi ô; một số vị trí có chướng ngại.

??? note "Bài tập [「USACO 6.1.1」Postal Vans](https://vjudge.net/problem/UVALive-2738)"
    Tóm tắt đề bài: đếm số cách phủ bàn cờ $4\times N$ bằng một chu trình có hướng; cần số học độ chính xác cao.

??? note "Bài tập [「HNOI 2007」Công viên kỳ diệu](https://www.luogu.com.cn/problem/P3190)"
    Tóm tắt đề bài: cho một đồ thị lưới $n\times m$, mỗi ô có một trọng số. Tìm một chu trình bất kỳ sao cho tổng trọng số đi qua là lớn nhất.

??? note "Bài tập [「ProjectEuler 393」Migrating ants](https://projecteuler.net/problem=393)"
    Tóm tắt đề bài: phủ một hình vuông $n\times n$ bằng nhiều chu trình; mỗi phương án có $m$ chu trình đóng góp $2^m$ vào đáp án. Tính tổng đóng góp của mọi phương án.

### Một đường đi

<span id="một-đường-đi"></span>

#### Ví dụ

<span id="ví-dụ_2"></span>

???+ note "Ví dụ [「ZOJ 3213」Beautiful Meadow](https://pintia.cn/problem-sets/91827364500/exam/problems/type/7?page=22&problemSetProblemId=91827367895)"
    Tóm tắt đề bài: với một hình vuông $N\times M$ ($N,M\le 8$), mỗi điểm lưới có một trọng số. Tìm một đường đi sao cho tổng trọng số các điểm lưới được đường đi phủ là lớn nhất.

Đây là bài toán một đường đi tiêu chuẩn. Trong bài toán một đường đi, trạng thái mã hóa còn có thể tồn tại các đầu nối độc lập không thể ghép cặp. Hàm chuyển trạng thái cần thảo luận thêm việc sinh, ghép và biến mất của các đầu nối độc lập. Việc sinh và biến mất của đầu nối độc lập tương ứng với một đầu mút của đường đi, nên loại sự kiện này không xảy ra quá hai lần (một lần sinh một lần biến mất, hoặc hai lần sinh một lần ghép); nếu không, kết quả cuối cùng sẽ có nhiều thành phần liên thông.

Cần ghi thêm trong trạng thái tổng số lần loại sự kiện này đã xảy ra. Có thể mã hóa thông tin này vào trạng thái (các thông tin bổ sung kiểu này không cần cuộn theo khi điều chỉnh đường biên), hoặc thêm một chiều bên ngoài mảng `hashTable`. Chương trình mẫu dưới đây dùng cách thứ hai.

#### Chuyển trạng thái

<span id="chuyển-trạng-thái_1"></span>

???+ note "Cài đặt mã"
    ```cpp
    REP(i, n) {
      REP(j, m) {
        checkMax(ans, A[i][j]);  // Cần xử lý riêng trường hợp chỉ có một ô
        if (!A[i][j]) continue;  // Nếu có chướng ngại thì bỏ qua; khi đó mảng trạng thái không cần cuộn
        swap(H0, H1);
        REP(c, 3)
        H1[c].clear();  // c biểu thị tổng số lần xảy ra sự kiện sinh và biến mất, tối đa không quá 2
        REP(c, 3) REP(ii, H0[c].sz) {
          decode(H0[c].state[ii]);
          d = H0[c].key[ii] + A[i][j];
          int lt = b[j], up = b[j + 1];
          bool dn = A[i + 1][j], rt = A[i][j + 1];
          if (lt && up) {
            if (lt == up) {  // Trong bài toán một đường đi, không được ghép hai đầu nối giống nhau.
              // Không thể đặt chuyển trạng thái tại vị trí này...
            } else {  // Hai đầu nối tham gia ghép có thể có đầu nối độc lập, nhưng vẫn xử lý bằng cùng đoạn mã
              REP(i, m + 1) if (b[i] == lt) b[i] = up;
              push(c, j, 0, 0);
            }
          } else if (lt || up) {
            int t = lt | up;
            if (dn) {
              push(c, j, t, 0);
            }
            if (rt) {
              push(c, j, 0, t);
            }
            // Trường hợp một đầu nối biến mất: nếu là đầu nối độc lập thì nghĩa là biến mất,
            // còn nếu là đầu nối xuất hiện theo cặp thì tương đương với việc sinh một đầu nối độc lập.
            // Cả hai loại sự kiện đều cần tăng c thêm 1.
            if (c < 2) {
              push(c + 1, j, 0, 0);
            }
          } else {
            d -= A[i][j];
            H1[c].push(H0[c].state[ii]);
            d += A[i][j];    // Bỏ qua việc sinh đầu nối; bài này không yêu cầu phủ toàn bộ
            if (dn && rt) {  // Sinh một cặp đầu nối
              push(c, j, m, m);
            }
            if (c < 2) {  // Sinh một đầu nối độc lập
              if (dn) {
                push(c + 1, j, m, 0);
              }
              if (rt) {
                push(c + 1, j, 0, m);
              }
            }
          }
        }
      }
      REP(c, 3) H1[c].roll();  // Hết một hàng, điều chỉnh đường biên
    }
    ```

??? note "Mã ví dụ"
    ```cpp
    --8<-- "docs/dp/code/plug/plug_3.cpp"
    ```

#### Bài tập

<span id="bài-tập_2"></span>

??? note "Bài tập [「BZOJ 2310」ParkII](https://hydro.ac/p/bzoj-P2310)"
    Tóm tắt đề bài: bàn cờ $m\times n$, mỗi điểm lưới có một trọng số. Tìm một đường đi phủ sao cho tổng trọng số các điểm mà đường đi đi qua là lớn nhất.

??? note "Bài tập [「NOI 2010 Day2」Tuyến du lịch](https://www.luogu.com.cn/problem/P1933)"
    Tóm tắt đề bài: bàn cờ $n\times m$, mỗi ô của bàn cờ có trọng số 01 là T\[x]\[y]. Cần tìm một đường đi phủ thỏa mãn:
    
    -   Điểm lưới thứ i được thăm (x, y) thỏa mãn T\[x]\[y]= L\[i]
    -   Một đầu của đường đi nằm trên biên bàn cờ
    
    Hỏi số phương án hợp lệ.

## Mô hình tô màu

<span id="mô-hình-tô-màu"></span>

Ngoài mô hình đường đi, còn có một loại mô hình thường gặp khác, trong đó cần tô màu bàn cờ; các nút kề nhau có cùng màu được xem là liên thông. Trong các bài toán dạng đường đi, khi chuyển trạng thái cần liệt kê hướng của đường đi hiện tại; còn trong các bài toán tô màu, cần liệt kê màu sẽ tô cho nút hiện tại. Trong mô hình tô màu, các nút có cùng tính liên thông trong trạng thái có thể không chỉ có hai nút. Nhưng nhìn chung cách xử lý vẫn gần giống nhau. Xét một ví dụ kinh điển.

### Ví dụ「UVa 10572」Black & White

<span id="ví-dụuva-10572black--white"></span>

???+ note "Ví dụ [「UVa 10572」Black & White](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1513)"
    Tóm tắt đề bài: tô đen trắng các điểm lưới chưa tô trong một bàn cờ $N\times M$, yêu cầu toàn bộ vùng đen và toàn bộ vùng trắng đều liên thông, đồng thời màu trong bất kỳ hình chữ nhật con $2\times 2$ nào không được hoàn toàn giống nhau (ví dụ trường hợp trong hình dưới là không hợp lệ). Đếm số phương án hợp lệ và dựng một phương án hợp lệ.
    
    ![Cấu hình 2x2 không hợp lệ trong bài Black & White](./images/black_and_white1.svg)

### Mã hóa trạng thái

<span id="mã-hóa-trạng-thái_1"></span>

Trước hết xét cách mã hóa trạng thái. Nếu không xét tính liên thông thì đây chính là [SGU 197. Nice Patterns Strike Back](https://codeforces.com/problemsets/acmsguru/problem/99999/197), có thể giải trực tiếp bằng [DP nén trạng thái](./state.md). Bây giờ cần thể hiện đồng thời thông tin màu và tính liên thông trong trạng thái. Xét trạng thái của từng vị trí trên đường biên: mỗi `Offset` bit trong biểu diễn nhị phân mô tả một vị trí trên đường biên. Vì chỉ có hai màu đen trắng, dùng tính chẵn lẻ của bit thấp nhất để biểu thị màu, các phần còn lại biểu thị tính liên thông.

Xét các nút phía trên hàng đầu tiên và các nút bên trái cột đầu tiên. Nếu muốn tránh xử lý riêng, có thể đưa thêm màu thứ ba để phân biệt chúng. Thông tin liên thông của các trạng thái biên này luôn bằng 0, nên không cần mã hóa thêm cho màu thứ ba.

Trong bài toán đường đi, đường biên gồm $m$ đầu nối phía trên và $1$ đầu nối bên trái. Ở bài này, vì còn cần kiểm tra hình chữ nhật con $2\times 2$ có ô hiện tại là góc dưới phải có hợp lệ hay không, nên cần ghi lại màu của ô góc trên trái; do đó độ dài đường biên vẫn là $m+1$.

Cách mã hóa này vẫn giữ lại nhiều thông tin dư thừa (các vùng liên thông luôn cùng màu, và ô góc trên trái chỉ cần thông tin màu, không cần thông tin liên thông). Tuy nhiên vì đã dùng bảng băm và biểu diễn tối tiểu, ảnh hưởng đến độ phức tạp thời gian không lớn; để giảm áp lực lập trình, không tinh giản thêm.

Trong trường hợp nhiều nhất (ví dụ hàng đầu tiên đen trắng xen kẽ), thông tin liên thông của mỗi đầu nối đều khác nhau. Vì vậy cần $4$ bit nhị phân để ghi tính liên thông; cộng thêm thông tin màu, `Offset` của bài này là $5$ bit.

???+ note "Cài đặt mã"
    ```cpp
    constexpr int Offset = 5, Mask = (1 << Offset) - 1;
    int c[N + 2];
    int b[N + 2], bb[N + 3];
    
    T_state encode() {
      T_state s = 0;
      memset(bb, -1, sizeof(bb));
      int bn = 1;
      bb[0] = 0;
      for (int i = m; i >= 0; --i) {
    #define bi bb[b[i]]
        if (!~bi) bi = bn++;
        s <<= Offset;
        s |= (bi << 1) | c[i];
      }
      return s;
    }
    
    void decode(T_state s) {
      REP(i, m + 1) {
        b[i] = s & Mask;
        c[i] = b[i] & 1;
        b[i] >>= 1;
        s >>= Offset;
      }
    }
    ```

### Tự viết bảng băm

<span id="tự-viết-bảng-băm_1"></span>

Vì cần dựng một phương án bất kỳ, bảng băm cần thêm một trường `pre[]` để ghi lại một tiền nhiệm bất kỳ của mỗi trạng thái ở giai đoạn trước.

???+ note "Cài đặt mã"
    ```cpp
    constexpr int Prime = 9979, MaxSZ = 1 << 20;
    
    template <class T_state, class T_key>
    struct hashTable {
      int head[Prime];
      int next[MaxSZ], sz;
      T_state state[MaxSZ];
      T_key key[MaxSZ];
      int pre[MaxSZ];
    
      void clear() {
        sz = 0;
        memset(head, -1, sizeof(head));
      }
    
      void push(T_state s, T_key d, T_state u) {
        int x = s % Prime;
        for (int i = head[x]; ~i; i = next[i]) {
          if (state[i] == s) {
            key[i] += d;
            return;
          }
        }
        state[sz] = s, key[sz] = d, pre[sz] = u;
        next[sz] = head[x], head[x] = sz++;
      }
    
      void roll() { REP(ii, sz) state[ii] <<= Offset; }
    };
    
    hashTable<T_state, T_key> _H, H[N][N], *H0, *H1;
    ```

### Dựng phương án

<span id="dựng-phương-án"></span>

Với các thông tin trên, có thể dựng phương án trực tiếp. Trước hết duyệt các trạng thái trong bảng băm hiện tại; nếu số thành phần liên thông không vượt quá $2$ thì cộng vào số phương án. Nếu số phương án khác $0$, dùng mảng `pre` theo thứ tự ngược để dựng phương án. Ở cuối mỗi hàng, vì đã thực hiện thao tác `Roll()`, màu cần lấy từ `c[j+1]`.

???+ note "Cài đặt mã"
    ```cpp
    void print() {
      T_key z = 0;
      int u;
      REP(i, H1->sz) {
        decode(H1->state[i]);
        if (*max_element(b + 1, b + m + 1) <= 2) {
          z += H1->key[i];
          u = i;
        }
      }
      cout << z << endl;
      if (z) {
        DWN(i, n, 0) {
          B[i][m] = 0;
          DWN(j, m, 0) {
            decode(H[i][j].state[u]);
            int cc = j == m - 1 ? c[j + 1] : c[j];
            B[i][j] = cc ? 'o' : '#';
            u = H[i][j].pre[u];
          }
        }
        REP(i, n) puts(B[i]);
      }
      puts("");
    }
    ```

### Chuyển trạng thái

<span id="chuyển-trạng-thái_2"></span>

Ký hiệu:

-   `cc` là màu của ô đang được tô
-   `lf` là màu của ô bên trái
-   `up` là màu của ô bên trên
-   `lu` là màu của ô góc trên trái

Dùng $-1$ để biểu thị màu không tồn tại. Tiếp theo xét chuyển trạng thái, gồm ba trường hợp: ghép, kế thừa và sinh mới.

???+ note "Chuyển trạng thái - mã"
    ```cpp
    void trans(int i, int j, int u, int cc) {
      decode(H0->state[u]);
      int lf = j ? c[j - 1] : -1, lu = b[j] ? c[j] : -1,
          up = b[j + 1] ? c[j + 1] : -1;  // Không có màu cũng là một loại màu!
      if (lf == cc && up == cc) {         // Ghép
        if (lu == cc) return;             // Trường hợp hình chữ nhật con 2x2 cùng màu
        int lf_b = b[j - 1], up_b = b[j + 1];
        REP(i, m + 1) if (b[i] == up_b) { b[i] = lf_b; }
        b[j] = lf_b;
      } else if (lf == cc || up == cc) {  // Kế thừa
        if (lf == cc)
          b[j] = b[j - 1];
        else
          b[j] = b[j + 1];
      } else {                                             // Sinh mới
        if (i == n - 1 && j == m - 1 && lu == cc) return;  // Xử lý riêng
        b[j] = m + 2;
      }
      c[j] = cc;
      if (!ok(i, j, cc)) return;  // Kiểm tra việc sinh thành phần liên thông khép kín có làm trạng thái bất hợp lệ không
      H1->push(encode(), H0->key[u], u);
    }
    ```

Với trường hợp cuối cùng, cần lưu ý: nếu đã sinh ra một vùng liên thông khép kín, không thể tiếp tục dùng màu của vùng đó để tô, nếu không màu này sẽ có hai thành phần liên thông. Có vẻ cần ghi thêm loại sự kiện này; có thể tham khảo cách làm trong [「ZOJ 3213」Beautiful Meadow](#ví-dụ_2), thêm một chiều để ghi lại sự kiện. Tuy nhiên nhờ tính chất đặc biệt của bài này, cũng có thể xử lý riêng.

???+ note "Xử lý riêng - mã"
    ```cpp
    bool ok(int i, int j, int cc) {
      if (cc == c[j + 1]) return true;
      int up = b[j + 1];
      if (!up) return true;
      int c1 = 0, c2 = 0;
      REP(i, m + 1) if (i != j + 1) {
        if (b[i] == b[j + 1]) {  // Tính liên thông giống nhau thì màu luôn giống nhau
          assert(c[i] == c[j + 1]);
        }
        if (c[i] == c[j + 1] && b[i] == b[j + 1]) ++c1;
        if (c[i] == c[j + 1]) ++c2;
      }
      if (!c1) {               // Nếu sẽ sinh một thành phần liên thông khép kín mới
        if (c2) return false;  // Nếu trên đường biên vẫn còn màu giống vậy
        if (i < n - 1 || j < m - 2) return false;
      }
      return true;
    }
    ```

Thảo luận thêm về trường hợp một thành phần liên thông biến mất. Mỗi khi tô màu một ô, nếu không còn ô nào khác liên thông với ô phía trên nó, thì một thành phần liên thông khép kín sẽ được tạo thành. Sự kiện này chỉ được xảy ra ở hai cột cuối của hàng cuối; nếu không, để tránh xuất hiện khối $2\times 2$ cùng màu, màu này sẽ lại xuất hiện về sau, ngoại trừ trường hợp sau:

    2 2
    o#
    #o

Trường hợp này được xử lý riêng. Nhờ vậy trong bài này có thể viết gọn mà không cần ghi lại trước đó đã sinh thành phần liên thông khép kín hay chưa.

??? note "Mã ví dụ"
    ```cpp
    --8<-- "docs/dp/code/plug/plug_4.cpp"
    ```

### Bài tập

<span id="bài-tập_3"></span>

??? note "Bài tập [「Topcoder SRM 312. Div1 khó」Hòn đảo rẻ nhất](https://archive.topcoder.com/ProblemStatement/pm/6482)"
    Tóm tắt đề bài: cho một đồ thị bàn cờ, mỗi ô có trọng số. Tìm một khối liên thông có tổng trọng số nhỏ nhất.

??? note "Bài tập [「JLOI 2009」Sinh vật bí ẩn](https://www.luogu.com.cn/problem/P3886)"
    Tóm tắt đề bài: cho một đồ thị bàn cờ, mỗi ô có trọng số. Tìm một khối liên thông có tổng trọng số lớn nhất.

??? note "Bài tập [「AtCoder Beginner Contest 211. Bài E」Polyomino đỏ](https://atcoder.jp/contests/abc211/tasks/abc211_e)"
    Tóm tắt đề bài: cho một bàn cờ kích thước $N\times N$, mỗi ô ban đầu là đen hoặc trắng. Được chọn đúng $K$ ô trắng và tô chúng thành đỏ. Hỏi có bao nhiêu phương án tô màu sao cho các ô đỏ tạo thành một khối liên thông.

## Mô hình đồ thị

<span id="mô-hình-đồ-thị"></span>

???+ note "Ví dụ [「NOI 2007 Day2」Đếm cây khung](https://www.luogu.com.cn/problem/P2109)"
    Tóm tắt đề bài: đếm cây khung của một lớp đồ thị đặc biệt, trong đó mỗi nút có cạnh nối tới đúng $k$ nút đứng trước nó.

???+ note "Ví dụ [「2015 ACM-ICPC Asia Shenyang Regional Contest - Bài E」Cây hiệu quả](https://acm.hdu.edu.cn/showproblem.php?pid=5513)"
    Tóm tắt đề bài: cho một đồ thị lưới $N\times M$ và trọng số cạnh giữa các ô kề nhau theo bốn hướng.
    Với một cây khung, điểm của mỗi nút là 1+\[có một cạnh nối lên trên]+\[có một cạnh nối sang trái].
    Điểm của cây khung là tích điểm của tất cả các nút.
    
    Cần tính: tổng trọng số cạnh của cây khung nhỏ nhất, và tổng điểm của tất cả các cây khung nhỏ nhất.
    ($n\le 800,m\le 7$)

## Thực chiến

<span id="thực-chiến"></span>

### Ví dụ

<span id="ví-dụ_3"></span>

???+ note "Ví dụ [「HDU 4113」Construct the Great Wall](https://acm.hdu.edu.cn/showproblem.php?pid=4113)"
    Tóm tắt đề bài: dựng một tập chu trình trong bàn cờ $N\times M$ để phân tách tất cả `x` và `o`.

Có một lớp bài toán DP đầu nối yêu cầu dựng một tập tường trên bàn cờ để phân tách một số phần tử trên đó. Có thể tạm gọi đây là bài toán xây tường; loại bài toán này có thể xem như mô hình tô màu, cũng có thể xem như mô hình đường đi.

![Mô hình xây tường để phân tách các phần tử trên bàn cờ](./images/greatwall.svg)

Trong bài này, nếu xem như mô hình tô màu, không chỉ cần thảo luận thêm về chu vi của vùng được tô, mà còn phải kiểm tra trường hợp không hợp lệ do chạm nhau ở góc (hình 2). Ngoài ra, khác với [「UVa 10572」Black & White](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1513), bài này yêu cầu tường là đa giác đơn, nên trường hợp dạng vòng trong vòng dưới đây là không hợp lệ trong bài này.

    3 3
    ooo
    oxo
    ooo

Vì vậy dùng mô hình đường đi và chuyển thành bài toán [một chu trình](#một-chu-trình) để xử lý.

Thực hiện DP dọc theo các giao điểm của bàn cờ (vì vậy chiều dài và chiều rộng cần tăng thêm $1$). Mỗi lần chuyển, cần bảo đảm tất cả `x` nằm ngoài chu trình và `o` nằm trong chu trình. Do đó còn cần duy trì vị trí hiện tại có nằm bên trong chu trình hay không. Với thông tin này, có thể thêm một chiều, hoặc trực tiếp thống kê tính chẵn lẻ của số đầu nối đi xuống đã xuất hiện trên đường biên trước vị trí này (phương pháp tia).

??? note "Mã ví dụ"
    ```cpp
    #include <cstring>
    #include <iostream>
    using namespace std;
    #define REP(i, n) for (int i = 0; i < n; ++i)
    
    template <class T>
    bool checkMin(T &a, const T b) {
      return b < a ? a = b, true : false;
    }
    
    constexpr int N = 10, M = N;
    constexpr int offset = 3, mask = (1 << offset) - 1;
    int n, m;
    int d;
    constexpr int INF = 0x3f3f3f3f;
    int b[M + 1], bb[M + 1];
    
    int encode() {
      int s = 0;
      memset(bb, -1, sizeof(bb));
      int bn = 1;
      bb[0] = 0;
      for (int i = m; i >= 0; --i) {
    #define bi bb[b[i]]
        if (!~bi) bi = bn++;
        s <<= offset;
        s |= bi;
      }
      return s;
    }
    
    void decode(int s) {
      REP(i, m + 1) {
        b[i] = s & mask;
        s >>= offset;
      }
    }
    
    constexpr int MaxSZ = 16796, Prime = 9973;
    
    struct hashTable {
      int head[Prime], next[MaxSZ], sz;
      int state[MaxSZ];
      int key[MaxSZ];
    
      void clear() {
        sz = 0;
        memset(head, -1, sizeof(head));
      }
    
      void push(int s) {
        int x = s % Prime;
        for (int i = head[x]; ~i; i = next[i]) {
          if (state[i] == s) {
            checkMin(key[i], d);
            return;
          }
        }
        state[sz] = s, key[sz] = d;
        next[sz] = head[x];
        head[x] = sz++;
      }
    
      void roll() { REP(i, sz) state[i] <<= offset; }
    } H[2], *H0, *H1;
    
    char A[N + 1][M + 1];
    
    void push(int i, int j, int dn, int rt) {
      b[j] = dn;
      b[j + 1] = rt;
      if (A[i][j] != '.') {
        bool bad = A[i][j] == 'o';
        REP(jj, j + 1) if (b[jj]) bad ^= 1;
        if (bad) return;
      }
      H1->push(encode());
    }
    
    int solve() {
      cin >> n >> m;
      int ti, tj;
      REP(i, n) {
        scanf("%s", A[i]);
        REP(j, m) if (A[i][j] == 'o') ti = i, tj = j;
        A[i][m] = '.';
      }
      REP(j, m + 1) A[n][j] = '.';
      ++n, ++m, ++ti, ++tj;
      H0 = H, H1 = H + 1;
      H1->clear();
      d = 0;
      H1->push(0);
      int z = INF;
      REP(i, n) {
        REP(j, m) {
          swap(H0, H1);
          H1->clear();
          REP(ii, H0->sz) {
            decode(H0->state[ii]);
            d = H0->key[ii] + 1;
            int lt = b[j], up = b[j + 1];
            bool dn = i != n - 1, rt = j != m - 1;
            if (lt && up) {
              if (lt == up) {
                int cnt = 0;
                REP(i, m + 1) if (b[i])++ cnt;
                if (cnt == 2 && i == ti && j == tj) {
                  checkMin(z, d);
                }
              } else {
                REP(i, m + 1) if (b[i] == lt) b[i] = up;
                push(i, j, 0, 0);
              }
            } else if (lt || up) {
              int t = lt | up;
              if (dn) {
                push(i, j, t, 0);
              }
              if (rt) {
                push(i, j, 0, t);
              }
            } else {
              --d;
              push(i, j, 0, 0);
              ++d;
              if (dn && rt) {
                push(i, j, m, m);
              }
            }
          }
        }
        H1->roll();
      }
      if (z == INF) z = -1;
      return z;
    }
    
    int main() {
      int T;
      cin >> T;
      for (int Case = 1; Case <= T; ++Case) {
        printf("Case #%d: %d\n", Case, solve());
      }
    }
    ```

### Bài tập

<span id="bài-tập_4"></span>

??? note "Bài tập [「SCOI 2011」Sàn nhà](https://www.luogu.com.cn/problem/P3272)"
    Tóm tắt đề bài: trên bàn cờ $r\times c$ có một số vị trí đặt chướng ngại. Hỏi có bao nhiêu cách dùng gạch hình chữ L lát kín tất cả các ô không có chướng ngại.

??? note "Bài tập [「HDU 4796」Winter's Coming](https://acm.hdu.edu.cn/showproblem.php?pid=4796)"
    Tóm tắt đề bài: tô đen, trắng, xám các điểm lưới chưa tô trong bàn cờ $N\times M$, yêu cầu toàn bộ vùng đen và toàn bộ vùng trắng đều liên thông, đồng thời vùng đen và vùng trắng lần lượt liên thông với biên trên và biên dưới của bàn cờ, và vùng đen với vùng trắng không được kề nhau. Mỗi ô có một chi phí tương ứng; tìm một phương án tô màu sao cho chi phí vùng xám nhỏ nhất.
    
    ![Ví dụ tô màu trong bài Winter's Coming](./images/4796.jpg)

??? note "Bài tập [「ZOJ 2125」Rocket Mania](https://pintia.cn/problem-sets/91827364500/exam/problems/type/7?page=11&problemSetProblemId=91827365624)"
    Tóm tắt đề bài: trên bản đồ $9\times6$, mỗi ô chứa một loại ống (`-`, `T`, `L`, `+` hoặc không có). Có thể xoay ống 0°, 90°, 180°, 270°. Hỏi tối đa có bao nhiêu hàng có biên phải nối được với biên trái của hàng X thông qua ống.

??? note "Bài tập [「ZOJ 2126」Rocket Mania Plus](https://pintia.cn/problem-sets/91827364500/exam/problems/type/7?page=11&problemSetProblemId=91827365625)"
    Tóm tắt đề bài: trên bản đồ $9\times6$, mỗi ô chứa một loại ống (`-`, `T`, `L`, `+` hoặc không có). Có thể xoay ống 0°, 90°, 180°, 270°. Hỏi tối đa có bao nhiêu hàng có biên phải nối được với biên trái thông qua ống.

??? note "Bài tập [「World Finals 2009/2010 Harbin」Channel](https://qoj.ac/problem/13134)"
    Tóm tắt đề bài: trên một bản đồ ô vuông, dùng `.` biểu thị đất trống và `#` biểu thị đá. Tìm một đường đi dài nhất thỏa mãn:
    
    1.  Điểm đầu ở góc trên trái, điểm cuối ở góc dưới phải.
    2.  Không được đi qua đá.
    3.  Bản thân đường đi không được tạo chu trình theo nghĩa tám hướng. (Tức là kể cả ở góc cũng không được chạm nhau)

??? note "Bài tập [「HDU 3958」Tower Defence](https://acm.hdu.edu.cn/showproblem.php?pid=3958)"
    Tóm tắt đề bài: có thể chuyển thành bài toán tìm đường đi dài nhất không tự chạm từ $\mathit{S}$ đến $\mathit{T}$; được phép chạm ở góc.

??? note "Bài tập [「UVa 10531」Maze Statistics](https://onlinejudge.org/index.php?option=com_onlinejudge&Itemid=8&category=24&page=show_problem&problem=1472)"
    Tóm tắt đề bài: có một đồ thị $N\times M$, mỗi ô độc lập có xác suất $\mathit{p}$ trở thành chướng ngại vật. Cần đi từ góc trên trái đến góc dưới phải của mê cung. Tính xác suất để mỗi ô trở thành chướng ngại vật trong một **mê cung có lời giải (tức điểm đầu và điểm cuối liên thông bốn hướng)**. ($N \le 5$, $M \le 6$)

??? note "Bài tập [「Aizu 2452」Pipeline Plans](https://judge.u-aizu.ac.jp/onlinejudge/description.jsp?id=2452)"
    Tóm tắt đề bài: có tổng cộng 12 loại mẫu gạch, mỗi loại có số lượng cho trước. Cần lát chúng lên một sàn hình chữ nhật xem như đồ thị lưới $R\times C$, mỗi ô đặt một viên gạch, sao cho tâm của ô góc trên trái liên thông với tâm của ô góc dưới phải thông qua các đường trên mẫu gạch. $(2 \le R \times C \le 15)$
    
    ![Các mẫu gạch trong bài Pipeline Plans](./images/plug2.png)

??? note "Bài tập [「SDOI 2014」Bảng mạch](https://www.luogu.com.cn/problem/P3314)"
    Tóm tắt đề bài: một bảng mạch $N\times M$ có một số vị trí là chướng ngại mà dây điện không thể đi qua. Cho $K$ cặp ô, yêu cầu mỗi cặp ô đều được nối bằng dây điện, và các dây điện không giao nhau (cho phép một đường dây đi vào ô hiện tại từ biên trên rồi rời khỏi ô qua biên trái, đồng thời một đường dây khác đi vào từ biên dưới rồi ra qua biên phải). Xem dây điện là cạnh vô hướng; tìm tổng chiều dài dây điện ngắn nhất thỏa mãn yêu cầu và số phương án.

??? note "Bài tập [「SPOJ CAKE3」Delicious Cake](https://www.spoj.com/problems/CAKE3)"
    Tóm tắt đề bài: một chiếc bánh có thể xem như lưới $N\times M$; nay cắt bánh dọc theo các đường lưới thành nhiều phần. Hỏi có bao nhiêu cách cắt khác nhau. Hai cách cắt được xem là giống nhau khi và chỉ khi từng miếng bánh sau khi cắt đều có cùng hình dạng và nằm ở cùng vị trí. ($\min(N,M) \le 5, \max(N,M) \le 130$)

## Ghi chú chương

<span id="ghi-chú-chương"></span>

Các bài toán DP đầu nối thường khó mã hóa và thảo luận phức tạp, nên thuộc nhóm lĩnh vực tương đối [ít phổ biến](https://github.com/OI-wiki/libs/blob/master/topic/7-%E7%8E%8B%E5%A4%A9%E6%87%BF-%E8%AE%BA%E5%81%8F%E9%A2%98%E7%9A%84%E5%8D%B1%E5%AE%B3.ppt) trong OI/ACM. Tài liệu kinh điển nhất về hướng này là luận văn đội tuyển năm 2008 của [Chen Danqi](https://www.cs.princeton.edu/~danqic/) - [quy hoạch động dựa trên nén trạng thái liên thông](https://github.com/AngelKitty/review_the_national_post-graduate_entrance_examination/tree/master/books_and_notes/professional_courses/data_structures_and_algorithms/sources/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F%E8%AE%BA%E6%96%87/%E5%9B%BD%E5%AE%B6%E9%9B%86%E8%AE%AD%E9%98%9F2008%E8%AE%BA%E6%96%87%E9%9B%86/%E9%99%88%E4%B8%B9%E7%90%A6%E3%80%8A%E5%9F%BA%E4%BA%8E%E8%BF%9E%E9%80%9A%E6%80%A7%E7%8A%B6%E6%80%81%E5%8E%8B%E7%BC%A9%E7%9A%84%E5%8A%A8%E6%80%81%E8%A7%84%E5%88%92%E9%97%AE%E9%A2%98%E3%80%8B). Ngoài ra, năm 2011 notonlysuccess của HDU từng viết hai bài chuyên đề từ dễ đến khó trên blog, cũng là tài liệu rất quý, nhưng hiện nay phải tra lại qua Web Archive.

-   [notonlysuccess, chuyên đề DP đầu nối](https://web.archive.org/web/20110815044829/http://www.notonlysuccess.com/?p=625)
-   [notonlysuccess, bản đầy đủ về DP đầu nối](https://web.archive.org/web/20111007185146/http://www.notonlysuccess.com/?p=931)

### Lát domino

<span id="lát-domino"></span>

[「HDU 1400」Mondriaan’s Dream](https://acm.hdu.edu.cn/showproblem.php?pid=1400) cũng xuất hiện trong [Training Guide for Algorithmic Contests](../contest/resources.md#sách), với vai trò bài ví dụ của mục "quy hoạch động trên đường biên". [Lát domino](https://en.wikipedia.org/wiki/Domino_tiling) là một nhóm bài toán toán học rất kinh điển; chỉ cần thay đổi nhẹ phạm vi dữ liệu là có thể thu được các bài toán con ở nhiều mức độ khó khác nhau, đòi hỏi các thuật toán khác nhau.

Khi giới hạn $m=2$, lát domino tương đương với dãy Fibonacci. [Concrete Mathematics](https://www.csie.ntu.edu.tw/~r97002/temp/Concrete%20Mathematics%202e.pdf) dùng bài toán này để dẫn nhập dãy Fibonacci, đồng thời dùng nhiều phương pháp để thu được nghiệm giải tích của nó.

Khi $m\le 10,n\le 10^9$, có thể tiền xử lý công thức chuyển thành dạng ma trận và dùng [nhân ma trận để tăng tốc](http://www.matrix67.com/blog/archives/276).

![Ma trận chuyển cho bài toán lát domino V2](./images/domino_v2_transform_matrix.svg)

Khi $n,m\le 100$, có thể dùng [thuật toán FKT](https://en.wikipedia.org/wiki/FKT_algorithm) để tính số ghép cặp hoàn hảo của đồ thị phẳng tương ứng.

-   [「51nod 1031」Lát domino](https://www.51nod.com/Html/Challenge/Problem.html#problemId=1031)
-   [「51nod 1033」Lát domino V2](https://www.51nod.com/Html/Challenge/Problem.html#problemId=1033)|[「Vijos 1194」Domino](https://vijos.org/p/1194)
-   [「51nod 1034」Lát domino V3](https://www.51nod.com/Html/Challenge/Problem.html#problemId=1034)|[「Ural 1594」Kho báu Aztec](https://acm.timus.ru/problem.aspx?space=1&num=1594)
-   [Wolfram MathWorld, đa thức Chebyshev loại hai](https://mathworld.wolfram.com/ChebyshevPolynomialoftheSecondKind.html)

### Một đường đi

<span id="một-đường-đi_1"></span>

"Một đường đi" là một trường hợp đặc biệt của bài toán [đường đi Hamilton](https://en.wikipedia.org/wiki/Hamiltonian_path) trên [đồ thị lưới](https://mathworld.wolfram.com/GridGraph.html). Bài toán quyết định của đường đi Hamilton là một thành viên quan trọng trong họ [NP-đầy đủ](https://en.wikipedia.org/wiki/NP-completeness).
