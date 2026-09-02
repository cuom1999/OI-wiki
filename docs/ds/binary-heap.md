author: HeRaNO, Xeonacid, AzurIce

<span id="cấu-trúc"></span>

## Cấu trúc

Đống nhị phân (binary heap) có cấu trúc là một cây nhị phân hoàn chỉnh. Mỗi
đỉnh lưu một phần tử, hay nói cách khác là một trọng số.

Tính chất đống: trọng số của cha không nhỏ hơn trọng số của con (đống lớn).
Tương tự, cũng có thể định nghĩa đống nhỏ. Trang này lấy đống lớn làm ví dụ.

Theo tính chất đống, gốc cây lưu giá trị lớn nhất, vì vậy thao tác `getMax` có
thể được xử lý trực tiếp.

<span id="quy-trình"></span>

## Quy trình

<span id="thao-tác-chèn"></span>

### Thao tác chèn

Thao tác chèn là đưa một phần tử vào đống nhị phân, đồng thời bảo đảm sau khi
chèn nó vẫn là một cây nhị phân hoàn chỉnh.

Cách đơn giản nhất là chèn vào ngay sau lá ngoài cùng bên phải ở tầng dưới cùng.

Nếu tầng dưới cùng đã đầy, tạo thêm một tầng mới.

Sau khi chèn, tính chất đống có thể không còn được thỏa mãn.

**Điều chỉnh lên**: nếu trọng số của đỉnh này lớn hơn trọng số của cha nó, hoán
đổi hai đỉnh. Lặp lại quá trình này cho đến khi điều kiện không còn đúng hoặc đã
lên tới gốc.

Có thể chứng minh rằng sau khi chèn rồi điều chỉnh lên, không có đỉnh nào khác
vi phạm tính chất đống.

Độ phức tạp thời gian của điều chỉnh lên là $O(\log n)$.

![Thao tác chèn của đống nhị phân](./images/binary_heap_insert.svg)

<span id="thao-tác-xóa"></span>

### Thao tác xóa

Thao tác xóa trong phần này là xóa phần tử lớn nhất trong đống, tức xóa đỉnh gốc.

Nhưng nếu xóa trực tiếp, cây sẽ tách thành hai đống và trở nên khó xử lý.

Vì vậy, có thể nghĩ tới quá trình ngược với thao tác chèn: tìm cách chuyển đỉnh
gốc tới đỉnh cuối cùng rồi xóa trực tiếp.

Tuy nhiên cách đó khó thực hiện trong thực tế.
Phương pháp thường dùng là hoán đổi trực tiếp đỉnh gốc với đỉnh cuối cùng.

Sau đó xóa đỉnh gốc cũ đang nằm ở vị trí đỉnh cuối cùng, nhưng đỉnh gốc
mới có thể không thỏa mãn tính chất đống.

**Điều chỉnh xuống**: trong các con của đỉnh hiện tại, tìm con có trọng số lớn
nhất và hoán đổi với đỉnh đó. Lặp lại quá trình này cho đến tầng dưới cùng.

Có thể chứng minh rằng sau khi xóa rồi điều chỉnh xuống, không có đỉnh nào khác
vi phạm tính chất đống.

Độ phức tạp thời gian là $O(\log n)$.

<span id="tăng-trọng-số-của-một-đỉnh"></span>

### Tăng trọng số của một đỉnh

Sau khi sửa trực tiếp trọng số, chỉ cần điều chỉnh lên một lần. Độ phức tạp thời
gian là $O(\log n)$.

<span id="cài-đặt"></span>

## Cài đặt

Các thao tác ở trên chủ yếu dựa vào hai thao tác cốt lõi: điều chỉnh lên và
điều chỉnh xuống.

Xét cách dùng một dãy $h$ để biểu diễn đống.
Hai con của $h_i$ lần lượt là $h_{2i}$ và $h_{2i+1}$;
$1$ là đỉnh gốc:

![Cấu trúc đống của h](./images/binary-heap-array.svg)

Mã tham khảo:

```cpp
void up(int x) {
  while (x > 1 && h[x] > h[x / 2]) {
    std::swap(h[x], h[x / 2]);
    x /= 2;
  }
}

void down(int x) {
  while (x * 2 <= n) {
    t = x * 2;
    if (t + 1 <= n && h[t + 1] > h[t]) t++;
    if (h[t] <= h[x]) break;
    std::swap(h[x], h[t]);
    x = t;
  }
}
```

<span id="xây-heap"></span>

### Xây đống

Xét bài toán sau: bắt đầu từ một đống rỗng, chèn $n$ phần tử vào đống và không
quan tâm thứ tự chèn.

Nếu chèn trực tiếp từng phần tử một thì cần $O(n \log n)$ thời gian. Có cách nào tốt hơn không?

<span id="cách-1-dùng-điều-chỉnh-lên"></span>

#### Cách 1: dùng điều chỉnh lên

Bắt đầu từ gốc và thực hiện theo thứ tự BFS.

```cpp
void build_heap_1() {
  for (i = 1; i <= n; i++) up(i);
}
```

Cách này về bản chất vẫn là chèn từng phần tử một, chỉ khác ở chỗ các phần tử đã
được đặt sẵn trong mảng nên hằng số có thể nhỏ hơn. Trong trường hợp xấu nhất,
độ phức tạp thỏa mãn truy hồi $T(n)=T(n-1)+\Theta(\log n)$; cộng dồn cho ta
$T(n)=\Theta(n\log n)$.

<span id="cách-2-dùng-điều-chỉnh-xuống"></span>

#### Cách 2: dùng điều chỉnh xuống

Lúc này đổi góc nhìn: bắt đầu từ các nút gần lá và lần lượt điều chỉnh xuống.

```cpp
void build_heap_2() {
  for (i = n; i >= 1; i--) down(i);
}
```

Một cách hiểu khác là mỗi lần "gộp" hai đống đã được điều chỉnh xong; điều này
cho thấy tính đúng đắn của thuật toán.

Các nút lá không cần điều chỉnh, vì vậy có thể bắt đầu từ vị trí xấp xỉ $n/2$
trong dãy để giảm hằng số. Theo cách hiểu mỗi bước gộp hai đống đã được điều
chỉnh, độ phức tạp thỏa mãn
$T(n)=2T\left(\dfrac n2\right)+O(\log n)$. Theo định lý chính,
$T(n)=\Theta(n)$.

Sở dĩ có thể xây đống trong $\Theta(n)$ là vì tính chất đống khá yếu, đống nhị phân
không phải là duy nhất.

Nếu yêu cầu mạnh như trong bài toán sắp xếp, chưa chắc có thể đạt được cách xây
dựng tuyến tính như vậy.

<span id="ứng-dụng"></span>

## Ứng dụng

<span id="heap-đối-đỉnh"></span>

### Đống đối đỉnh

??? note "[SPOJ RMID2 - Lại tính trung vị động](https://www.spoj.com/problems/RMID2/)"
    Duy trì một dãy và hỗ trợ hai thao tác:
    
    1.  Chèn một phần tử vào dãy
    2.  In ra và xóa trung vị hiện tại của dãy (nếu độ dài dãy là số chẵn, in trung vị nhỏ hơn)

Bài toán này có thể được trừu tượng hóa thêm thành: duy trì động phần tử lớn thứ
$k$ trên một dãy, trong đó giá trị $k$ có thể thay đổi.

Với loại bài toán này, có thể dùng kỹ thuật **đống đối đỉnh** để giải quyết,
tránh sự rườm rà khi phải viết cây đoạn theo trọng số hoặc cây tìm kiếm nhị phân.

Đống đối đỉnh gồm một đống lớn và một đống nhỏ. Đống nhỏ duy trì các giá trị
lớn, tức $k$ giá trị lớn nhất (bao gồm phần tử lớn thứ $k$). Đống lớn duy trì
các giá trị nhỏ, tức các số còn lại nhỏ hơn phần tử lớn thứ $k$.

Cấu trúc dữ liệu tạo bởi hai đống này hỗ trợ các thao tác sau:

-   Duy trì: khi kích thước của đống nhỏ chưa đạt $k$, liên tục lấy phần tử ở
    đỉnh đống lớn ra và chèn vào đống nhỏ cho đến khi kích thước đống nhỏ bằng
    $k$. Khi kích thước của đống nhỏ vượt quá $k$, liên tục lấy phần tử ở đỉnh
    đống nhỏ ra và chèn vào đống lớn cho đến khi kích thước đống nhỏ bằng $k$;
-   Chèn phần tử: nếu phần tử cần chèn lớn hơn hoặc bằng phần tử ở đỉnh đống nhỏ,
    chèn nó vào đống nhỏ; ngược lại, chèn nó vào đống lớn.
    Sau đó duy trì đống đối đỉnh;
-   Truy vấn phần tử lớn thứ $k$: phần tử ở đỉnh đống nhỏ chính là đáp án;
-   Xóa phần tử lớn thứ $k$: xóa phần tử ở đỉnh đống nhỏ, sau đó duy trì đống
    đối đỉnh;
-   Giá trị $k$ tăng/giảm $1$: duy trì trực tiếp đống đối đỉnh theo giá trị $k$ mới.

Độ phức tạp thời gian để truy vấn phần tử lớn thứ $k$ là $O(1)$. Sau khi chèn,
xóa hoặc điều chỉnh giá trị $k$, kích thước của đống nhỏ lệch tối đa $1$ so với
giá trị $k$ mong muốn. Vì vậy mỗi lần duy trì chỉ cần điều chỉnh nhiều nhất một
phần tử giữa đống lớn và đống nhỏ, nên độ phức tạp thời gian của các thao tác
này đều là $O(\log n)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/ds/code/binary-heap/binary-heap_1.cpp"
    ```

<span id="bài-tập"></span>

### Bài tập

-   [SPOJ RMID - Trung vị động](https://www.spoj.com/problems/RMID)
-   [Luogu P1801 - Hộp đen](https://www.luogu.com.cn/problem/P1801)
