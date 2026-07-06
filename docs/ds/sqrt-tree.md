<span id="dẫn-nhập"></span>
## Dẫn nhập

Cho dãy độ dài $n$ là ${\left\langle a_i\right\rangle}_{i=1}^n$, cùng một phép toán kết hợp $\circ$ (ví dụ
$\gcd,\min,\max,+,\text{và},\text{hoặc},\operatorname{xor}$ đều có tính kết hợp). Với mỗi truy vấn đoạn $[l,r]$, cần
tính $a_l\circ a_{l+1}\circ\dotsb\circ a_{r}$.

Sqrt Tree có thể tiền xử lý trong thời gian $O(n\log\log n)$ và trả lời truy vấn trong thời gian $O(1)$.

<span id="giải-thích"></span>
## Giải thích

<span id="chia-dãy-thành-các-khối"></span>
### Chia dãy thành các khối

Trước hết, chia cả dãy thành $O(\sqrt{n})$ khối, mỗi khối có kích thước $O(\sqrt{n})$. Với mỗi khối, tính:

1.  $P_i$: giá trị các tiền tố trong khối.
2.  $S_i$: giá trị các hậu tố trong khối.
3.  Một mảng $\left\langle B_{i,j}\right\rangle$ biểu diễn đáp án đoạn từ khối thứ $i$ đến khối thứ $j$.

Lấy ví dụ, giả sử $\circ$ là phép cộng $+$ và dãy là $\{1,2,3,4,5,6,7,8,9\}$.

Đầu tiên, chia dãy thành ba khối: $\{1,2,3\},\{4,5,6\},\{7,8,9\}$.

Khi đó giá trị tiền tố và hậu tố trong từng khối lần lượt là

$$
\begin{aligned}
&P_1=\{1,3,6\},S_1=\{6,5,3\}\\
&P_2=\{4,9,15\},S_2=\{15,11,6\}\\
&P_3=\{7,15,24\},S_3=\{24,17,9\}\\
\end{aligned}
$$

Mảng $B$ là:

$$
B=\begin{bmatrix}
6 & 21 & 45\\
0 & 15 & 39\\
0 & 0 & 24\\
\end{bmatrix}
$$

(Với các trường hợp không hợp lệ $i>j$, giả sử đáp án là $0$.)

Các giá trị này có thể được tiền xử lý trong thời gian $O(n)$, và độ phức tạp bộ nhớ cũng là $O(n)$. Sau khi xử lý xong,
có thể dùng chúng để trả lời một số truy vấn đi qua nhiều khối trong thời gian $O(1)$. Tuy nhiên, các truy vấn mà toàn bộ
đoạn nằm trong cùng một khối vẫn chưa được xử lý, nên cần bổ sung thêm cấu trúc.

<span id="xây-dựng-cây"></span>
### Xây dựng cây

Một ý tưởng tự nhiên là dựng đệ quy cấu trúc trên trong từng khối để hỗ trợ truy vấn bên trong khối. Với khối kích thước
$1$, có thể trả lời truy vấn trong $O(1)$. Như vậy sẽ xây được một cây, trong đó mỗi nút biểu diễn một đoạn của dãy. Nút
lá có độ dài đoạn là $1$ hoặc $2$. Một nút kích thước $k$ có $O(\sqrt{k})$ nút con, nên chiều cao của cả cây là
$O(\log\log n)$. Tổng độ dài các đoạn trên mỗi tầng là $O(n)$, do đó độ phức tạp xây dựng cây là $O(n\log\log n)$.

??? note "Chứng minh chiều cao của cây"
    Theo định nghĩa, gọi $T(n)$ là chiều cao của cây con tại nút "quản lý" $n$ phần tử. Khi đó có hệ thức truy hồi:
    
    $$
    T(n)=T(\sqrt n)+1
    $$
    
    Đặt $n=2^m$, thu được
    
    $$
    T(2^m)=T(2^{\frac m2})+1
    $$
    
    Tiếp tục định nghĩa $S(m)=T(2^m)$. Thay vào hệ thức trên:
    
    $$
    S(m)=S(\dfrac m2)+1
    $$
    
    Theo định lý chính, $S(m)=O(\log m)$, vì vậy $T(n)=S(\log n)=O(\log\log n)$.

Bây giờ đã có thể trả lời truy vấn trong thời gian $O(\log\log n)$. Với truy vấn $[l,r]$, chỉ cần nhanh chóng tìm nút $u$
có độ dài đoạn nhỏ nhất sao cho $u$ chứa được $[l,r]$. Khi đó $[l,r]$ sẽ đi qua nhiều khối trong phân hoạch của
$u$, nên có thể tính đáp án trong $O(1)$. Độ phức tạp tổng thể của một truy vấn là $O(\log\log n)$, vì chiều cao cây là
$O(\log\log n)$. Tuy nhiên, quá trình này vẫn có thể tối ưu thêm.

<span id="tối-ưu-độ-phức-tạp-truy-vấn"></span>
### Tối ưu độ phức tạp truy vấn

Có thể nghĩ đến việc tìm kiếm nhị phân theo chiều cao, rồi kiểm tra tính hợp lệ trong $O(1)$. Khi đó độ phức tạp trở thành
$O(\log\log\log n)$. Nhưng vẫn có thể tăng tốc thêm.

Giả sử:

1.  Kích thước của mỗi khối đều là một lũy thừa của $2$.
2.  Trên cùng một tầng, các khối có cùng kích thước.

Để làm được điều này, cần thêm một số phần tử $0$ vào cuối dãy sao cho độ dài dãy trở thành một lũy thừa của $2$.
Dù một số khối có thể lớn gấp đôi so với ban đầu, kích thước đó vẫn là $O(\sqrt{k})$, nên độ phức tạp tiền xử lý phân khối
vẫn là $O(n)$.

Bây giờ có thể xác định một đoạn truy vấn có nằm hoàn toàn trong một khối hay không. Với đoạn $[l,r]$ (đánh số từ $0$),
viết hai đầu mút ở dạng nhị phân. Ví dụ, với $k=4, l=39, r=46$, biểu diễn nhị phân là

$$
l = 39_{10} = 100111_2,
r = 46_{10} = 101110_2
$$

Độ dài đoạn trên mỗi tầng là như nhau, và kích thước khối cũng như nhau (trong ví dụ trên, $2^k=2^4=16$). Các khối phủ
kín toàn bộ dãy, nên khối đầu tiên biểu diễn các phần tử $[0,15]$ (dạng nhị phân là $[000000_2,001111_2]$), khối thứ hai
biểu diễn đoạn phần tử $[16,31]$ (dạng nhị phân là $[010000_2,011111_2]$), và cứ tiếp tục như vậy. Vị trí của các phần tử
trong cùng một khối chỉ khác nhau ở $k$ bit cuối trong biểu diễn nhị phân (trong ví dụ trên $k=4$). Hai đầu mút $l,r$ của
ví dụ cũng chỉ khác nhau ở $k$ bit cuối, nên chúng nằm trong cùng một khối.

Vì vậy chỉ cần kiểm tra hai đầu mút của đoạn có chỉ khác nhau ở $k$ bit cuối hay không, tức là $l\oplus r\le 2^k-1$. Nhờ
đó có thể nhanh chóng tìm tầng chứa đoạn cần trả lời:

1.  Với mỗi $i\in [1,n]$, tìm bit $1$ cao nhất của $i$.
2.  Với một truy vấn $[l,r]$, tính bit cao nhất của $l\oplus r$, từ đó nhanh chóng xác định tầng chứa đoạn đáp án.

Như vậy có thể trả lời truy vấn trong thời gian $O(1)$.

<span id="quá-trình-cập-nhật-phần-tử"></span>
## Quá trình cập nhật phần tử

Có thể cập nhật phần tử trên Sqrt Tree; cả cập nhật điểm và cập nhật đoạn đều được hỗ trợ.

<span id="cập-nhật-điểm"></span>
### Cập nhật điểm

Xét một thao tác gán tại một điểm $a_x=\mathit{val}$. Mục tiêu là cập nhật các thông tin liên quan một cách hiệu quả.

<span id="cài-đặt-đơn-giản"></span>
#### Cài đặt đơn giản

Trước hết, xét Sqrt Tree thay đổi như thế nào sau một lần cập nhật điểm.

Xét một nút độ dài $l$ cùng các dãy tương ứng:
$\left\langle P_i\right\rangle,\left\langle S_i\right\rangle,\left\langle B_{i,j}\right\rangle$. Trong
$\left\langle P_i\right\rangle$ và $\left\langle S_i \right\rangle$, mỗi dãy chỉ có $O(\sqrt{l})$ phần tử thay đổi. Còn
trong $\left\langle B_{i,j}\right\rangle$, có $O(l)$ phần tử bị thay đổi. Do đó có $O(l)$ phần tử trên cây phải cập nhật.
Vì vậy độ phức tạp cập nhật điểm trên Sqrt Tree là $O(n+\sqrt{n}+\sqrt{\sqrt{n}}+\dotsb)=O(n)$.

<span id="dùng-sqrt-tree-thay-cho-mảng-b"></span>
#### Dùng cây Sqrt Tree thay cho mảng B

Lưu ý rằng điểm nghẽn của cập nhật điểm nằm ở việc cập nhật $\left\langle B_{i,j}\right\rangle$ của nút gốc. Vì vậy, thử
dùng một Sqrt Tree khác để thay cho $\left\langle B_{i,j}\right\rangle$ ở nút gốc, gọi là `index`. Vai trò của nó giống
mảng hai chiều ban đầu: duy trì đáp án cho các truy vấn trên cả đoạn. Các nút không phải gốc vẫn dùng
$\left\langle B_{i,j}\right\rangle$ để duy trì thông tin. Lưu ý: nếu nút gốc của một Sqrt Tree có cấu trúc `index`,
gọi Sqrt Tree đó là **có chỉ mục**; nếu nút gốc của một Sqrt Tree có cấu trúc $\left\langle B_{i,j}\right\rangle$, gọi nó
gọi Sqrt Tree đó là **không có chỉ mục**. Bản thân cây `index` là không có chỉ mục.

Do đó có thể cập nhật cây `index` như sau:

1.  Cập nhật $\left\langle P_i\right\rangle$ và $\left\langle S_i\right\rangle$ trong thời gian $O(\sqrt{n})$.
2.  Cập nhật `index`. Độ dài của nó là $O(n)$, nhưng chỉ cần cập nhật một phần tử trong đó (phần tử này đại diện cho khối
    bị thay đổi). Bước này tốn $O(\sqrt{n})$ thời gian nếu dùng thuật toán cài đặt đơn giản.
3.  Đi vào nút con phát sinh thay đổi và dùng thuật toán cài đặt đơn giản để cập nhật thông tin trong thời gian $O(\sqrt{n})$.

Lưu ý rằng độ phức tạp truy vấn vẫn là $O(1)$, vì cây `index` được dùng nhiều nhất một lần. Như vậy độ phức tạp cập nhật
điểm là $O(\sqrt{n})$.

<span id="cập-nhật-một-đoạn"></span>
### Cập nhật một đoạn

Sqrt Tree cũng hỗ trợ thao tác phủ đoạn $\operatorname{Update}(l,r,x)$, tức là biến mọi số trong đoạn $[l,r]$ thành $x$.
Có hai cách cài đặt: một cách cập nhật thông tin trong $O(\sqrt{n}\log\log n)$ và truy vấn trong $O(1)$; cách còn lại cập
nhật thông tin trong $O(\sqrt{n})$, nhưng thời gian truy vấn tăng lên $O(\log\log n)$.

Có thể gắn đánh dấu lười trên Sqrt Tree tương tự như trên cây đoạn. Tuy nhiên, Sqrt Tree có một điểm khác: việc đẩy đánh
dấu lười của một nút xuống có thể tốn tới $O(\sqrt{n})$. Vì vậy không đẩy đánh dấu khi truy vấn, mà kiểm tra xem nút cha
có đánh dấu hay không; nếu có thì đẩy đánh dấu đó xuống.

<span id="cài-đặt-thứ-nhất"></span>
#### Cài đặt thứ nhất

Trong cách cài đặt thứ nhất, chỉ gắn đánh dấu lười cho các nút ở tầng $1$ (độ dài đoạn của nút là $O(\sqrt{n})$). Khi đẩy
đánh dấu xuống, cập nhật trực tiếp toàn bộ cây con, với độ phức tạp $O(\sqrt{n}\log\log n)$. Quy trình thao tác như sau:

1.  Xét các nút trên tầng $1$; với những nút được đoạn cần sửa bao phủ hoàn toàn, gắn cho chúng một đánh dấu lười.

2.  Có hai khối chỉ bị bao phủ một phần. Trực tiếp **xây dựng lại** hai khối này trong thời gian
    $O(\sqrt{n}\log\log n)$. Nếu bản thân chúng mang đánh dấu lười từ lần sửa trước, đồng thời đẩy đánh dấu xuống trong
    lúc xây dựng lại.

3.  Cập nhật $\left\langle P_i\right\rangle$ và $\left\langle S_i\right\rangle$ của nút gốc, độ phức tạp $O(\sqrt{n})$.

4.  Xây dựng lại cây `index`, độ phức tạp $O(\sqrt{n}\log\log n)$.

Đến đây đã có thể cập nhật đoạn một cách hiệu quả. Cách dùng đánh dấu lười để trả lời truy vấn như sau:

1.  Nếu truy vấn nằm trong một khối có đánh dấu lười, có thể dùng đánh dấu lười để tính đáp án.

2.  Nếu truy vấn chứa nhiều khối, chỉ cần quan tâm đến đáp án của hai khối không trọn vẹn ở ngoài cùng bên trái và bên
    phải. Đáp án của các khối ở giữa có thể truy vấn trên cây `index` (vì cây `index` được xây dựng lại sau mỗi lần sửa),
    với độ phức tạp $O(1)$.

Do đó độ phức tạp truy vấn vẫn là $O(1)$.

<span id="cài-đặt-thứ-hai"></span>
#### Cài đặt thứ hai

Trong cách cài đặt này, mỗi nút đều có thể được gắn đánh dấu lười. Vì vậy khi xử lý một truy vấn, cần xét các đánh dấu
lười trên những nút tổ tiên, khiến độ phức tạp truy vấn trở thành $O(\log\log n)$. Đổi lại, cập nhật thông tin sẽ nhanh
hơn. Các bước như sau:

1.  Với các khối được đoạn cần sửa bao phủ hoàn toàn, thêm đánh dấu lười vào các khối đó, độ phức tạp $O(\sqrt{n})$.
2.  Với các khối bị đoạn cần sửa bao phủ một phần, cập nhật $\left\langle P_i\right\rangle$ và
    $\left\langle S_i\right\rangle$, độ phức tạp $O(\sqrt{n})$ (vì chỉ có hai khối bị sửa).
3.  Cập nhật cây `index`, độ phức tạp $O(\sqrt{n})$ (dùng cùng thuật toán cập nhật).
4.  Với các cây con không có chỉ mục, cập nhật $\left\langle B_{i,j}\right\rangle$ của chúng.
5.  Đệ quy cập nhật hai đoạn chưa được bao phủ hoàn toàn.

Độ phức tạp thời gian là $O(\sqrt{n}+\sqrt{\sqrt{n}}+\dotsb)=O(\sqrt{n})$.

<span id="cài-đặt"></span>
## Cài đặt

Cài đặt dưới đây xây cây trong thời gian $O(n\log\log n)$, trả lời truy vấn trong thời gian $O(1)$, và cập nhật điểm trong
thời gian $O(\sqrt{n})$.

```cpp
SqrtTreeItem op(const SqrtTreeItem &a, const SqrtTreeItem &b);

int log2Up(int n) {
  int res = 0;
  while ((1 << res) < n) {
    res++;
  }
  return res;
}

class SqrtTree {
 private:
  int n, lg, indexSz;
  vector<SqrtTreeItem> v;
  vector<int> clz, layers, onLayer;
  vector<vector<SqrtTreeItem>> pref, suf, between;

  void buildBlock(int layer, int l, int r) {
    pref[layer][l] = v[l];
    for (int i = l + 1; i < r; i++) {
      pref[layer][i] = op(pref[layer][i - 1], v[i]);
    }
    suf[layer][r - 1] = v[r - 1];
    for (int i = r - 2; i >= l; i--) {
      suf[layer][i] = op(v[i], suf[layer][i + 1]);
    }
  }

  void buildBetween(int layer, int lBound, int rBound, int betweenOffs) {
    int bSzLog = (layers[layer] + 1) >> 1;
    int bCntLog = layers[layer] >> 1;
    int bSz = 1 << bSzLog;
    int bCnt = (rBound - lBound + bSz - 1) >> bSzLog;
    for (int i = 0; i < bCnt; i++) {
      SqrtTreeItem ans;
      for (int j = i; j < bCnt; j++) {
        SqrtTreeItem add = suf[layer][lBound + (j << bSzLog)];
        ans = (i == j) ? add : op(ans, add);
        between[layer - 1][betweenOffs + lBound + (i << bCntLog) + j] = ans;
      }
    }
  }

  void buildBetweenZero() {
    int bSzLog = (lg + 1) >> 1;
    for (int i = 0; i < indexSz; i++) {
      v[n + i] = suf[0][i << bSzLog];
    }
    build(1, n, n + indexSz, (1 << lg) - n);
  }

  void updateBetweenZero(int bid) {
    int bSzLog = (lg + 1) >> 1;
    v[n + bid] = suf[0][bid << bSzLog];
    update(1, n, n + indexSz, (1 << lg) - n, n + bid);
  }

  void build(int layer, int lBound, int rBound, int betweenOffs) {
    if (layer >= (int)layers.size()) {
      return;
    }
    int bSz = 1 << ((layers[layer] + 1) >> 1);
    for (int l = lBound; l < rBound; l += bSz) {
      int r = min(l + bSz, rBound);
      buildBlock(layer, l, r);
      build(layer + 1, l, r, betweenOffs);
    }
    if (layer == 0) {
      buildBetweenZero();
    } else {
      buildBetween(layer, lBound, rBound, betweenOffs);
    }
  }

  void update(int layer, int lBound, int rBound, int betweenOffs, int x) {
    if (layer >= (int)layers.size()) {
      return;
    }
    int bSzLog = (layers[layer] + 1) >> 1;
    int bSz = 1 << bSzLog;
    int blockIdx = (x - lBound) >> bSzLog;
    int l = lBound + (blockIdx << bSzLog);
    int r = min(l + bSz, rBound);
    buildBlock(layer, l, r);
    if (layer == 0) {
      updateBetweenZero(blockIdx);
    } else {
      buildBetween(layer, lBound, rBound, betweenOffs);
    }
    update(layer + 1, l, r, betweenOffs, x);
  }

  SqrtTreeItem query(int l, int r, int betweenOffs, int base) {
    if (l == r) {
      return v[l];
    }
    if (l + 1 == r) {
      return op(v[l], v[r]);
    }
    int layer = onLayer[clz[(l - base) ^ (r - base)]];
    int bSzLog = (layers[layer] + 1) >> 1;
    int bCntLog = layers[layer] >> 1;
    int lBound = (((l - base) >> layers[layer]) << layers[layer]) + base;
    int lBlock = ((l - lBound) >> bSzLog) + 1;
    int rBlock = ((r - lBound) >> bSzLog) - 1;
    SqrtTreeItem ans = suf[layer][l];
    if (lBlock <= rBlock) {
      SqrtTreeItem add =
          (layer == 0) ? (query(n + lBlock, n + rBlock, (1 << lg) - n, n))
                       : (between[layer - 1][betweenOffs + lBound +
                                             (lBlock << bCntLog) + rBlock]);
      ans = op(ans, add);
    }
    ans = op(ans, pref[layer][r]);
    return ans;
  }

 public:
  SqrtTreeItem query(int l, int r) { return query(l, r, 0, 0); }

  void update(int x, const SqrtTreeItem &item) {
    v[x] = item;
    update(0, 0, n, 0, x);
  }

  SqrtTree(const vector<SqrtTreeItem> &a)
      : n((int)a.size()), lg(log2Up(n)), v(a), clz(1 << lg), onLayer(lg + 1) {
    clz[0] = 0;
    for (int i = 1; i < (int)clz.size(); i++) {
      clz[i] = clz[i >> 1] + 1;
    }
    int tlg = lg;
    while (tlg > 1) {
      onLayer[tlg] = (int)layers.size();
      layers.push_back(tlg);
      tlg = (tlg + 1) >> 1;
    }
    for (int i = lg - 1; i >= 0; i--) {
      onLayer[i] = max(onLayer[i], onLayer[i + 1]);
    }
    int betweenLayers = max(0, (int)layers.size() - 1);
    int bSzLog = (lg + 1) >> 1;
    int bSz = 1 << bSzLog;
    indexSz = (n + bSz - 1) >> bSzLog;
    v.resize(n + indexSz);
    pref.assign(layers.size(), vector<SqrtTreeItem>(n + indexSz));
    suf.assign(layers.size(), vector<SqrtTreeItem>(n + indexSz));
    between.assign(betweenLayers, vector<SqrtTreeItem>((1 << lg) + bSz));
    build(0, 0, n, 0);
  }
};
```

<span id="bài-tập"></span>
## Bài tập

[CodeChef - SEGPROD](https://www.codechef.com/NOV17/problems/SEGPROD)

**Trang này chủ yếu được dịch từ [Sqrt Tree - Algorithms for Competitive Programming](https://cp-algorithms.com/data_structures/sqrt-tree.html),
theo giấy phép CC-BY-SA 4.0.**
