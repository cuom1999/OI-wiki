author: GoodCoder666, Ir1d, Marcythm, ouuan, hsfzLZH1, Xeonacid, greyqz, Chrogeek, ftxj, sshwy, LuoshuiTianyi, hyp1231, sun2snow

## Mở đầu

Phân rã cây thành chuỗi được dùng để chia cây thành nhiều chuỗi, qua đó duy trì thông tin trên các đường đi của cây.

Cụ thể, phân rã toàn bộ cây thành một số chuỗi để biến nó thành một cấu trúc tuyến tính, rồi dùng các cấu trúc dữ liệu khác để duy trì thông tin.

**Phân rã cây thành chuỗi** còn gọi là phân rã chuỗi trên cây, có nhiều dạng, chẳng hạn **phân rã chuỗi nặng** (heavy-light decomposition, HLD), **phân rã chuỗi dài** và phép phân rã dùng trong cây Link-Cut, đôi khi gọi là "phân rã chuỗi thực". Trong phần lớn trường hợp, nếu không nói rõ thêm, "phân rã cây thành chuỗi" thường chỉ "phân rã chuỗi nặng".

Phân rã chuỗi nặng có thể chia một đường đi bất kỳ trên cây thành không quá $O(\log n)$ chuỗi liên tiếp. Các đỉnh trên mỗi chuỗi có độ sâu đôi một khác nhau, tức là một chuỗi đi từ dưới lên, và LCA của mọi đỉnh trên chuỗi là một đầu mút của chuỗi.

Phân rã chuỗi nặng còn bảo đảm các đỉnh trên mỗi chuỗi được tách ra có thứ tự DFS liên tiếp, nên có thể thuận tiện dùng các cấu trúc dữ liệu duy trì dãy, như cây đoạn, để duy trì thông tin đường đi trên cây. Ví dụ:

1.  Sửa giá trị của tất cả các đỉnh **trên đường đi giữa hai đỉnh của cây**.
2.  Truy vấn **tổng/cực trị/thông tin khác** của trọng số các đỉnh **trên đường đi giữa hai đỉnh của cây**, miễn là thông tin đó có thể được duy trì trên dãy và dễ gộp bằng cấu trúc dữ liệu.

Ngoài việc phối hợp với cấu trúc dữ liệu để duy trì thông tin đường đi trên cây, HLD còn có thể dùng để tìm LCA trong $O(\log n)$ với hằng số nhỏ. Trong một số bài toán, cũng có thể khai thác các tính chất của nó một cách linh hoạt.

## Phân rã chuỗi nặng

Một số định nghĩa:

Định nghĩa **con nặng** là đỉnh con có cây con lớn nhất trong các con của một đỉnh. Nếu có nhiều con có cây con lớn nhất, chọn một đỉnh bất kỳ. Nếu không có con thì không có con nặng.

Định nghĩa **con nhẹ** là tất cả các đỉnh con còn lại.

Cạnh từ đỉnh này tới con nặng của nó được gọi là **cạnh nặng**.

Cạnh tới các con nhẹ khác được gọi là **cạnh nhẹ**.

Một số cạnh nặng nối đầu cuối với nhau tạo thành **chuỗi nặng**.

Nếu cũng xem một đỉnh lẻ là một chuỗi nặng, thì toàn bộ cây được phân rã thành nhiều chuỗi nặng.

Như hình sau:

![Ví dụ phân rã cây thành các chuỗi nặng](./images/hld.png)

## Cài đặt

Cài đặt HLD gồm hai lần DFS. Mã giả như sau:

Lần DFS thứ nhất ghi lại cha của mỗi đỉnh ($\textit{father}$), độ sâu ($\textit{depth}$), kích thước cây con ($\textit{size}$) và con nặng ($\textit{hson}$).

$$
\begin{array}{l}
\text{TREE-BUILD }(u,\textit{dep}) \\
\begin{array}{ll}
1 & u.\textit{hson}\gets 0 \\
2 & u.\textit{hson}.\textit{size}\gets 0 \\
3 & u.\textit{depth}\gets \textit{dep} \\
4 & u.\textit{size}\gets 1 \\
5 & \textbf{với mỗi }\text{con }v\text{ của }u \\
6 & \qquad u.\textit{size}\gets u.\textit{size} + \text{TREE-BUILD }(v,\textit{dep}+1) \\
7 & \qquad v.\textit{father}\gets u \\
8 & \qquad \textbf{nếu }v.\textit{size}> u.\textit{hson}.\textit{size} \\
9 & \qquad \qquad u.\textit{hson}\gets v \\
10 & \textbf{trả về } u.\textit{size}
\end{array}
\end{array}
$$

Lần DFS thứ hai ghi lại đỉnh đầu chuỗi chứa đỉnh hiện tại ($\textit{top}$, nên khởi tạo là chính đỉnh đó), thứ tự DFS khi ưu tiên đi cạnh nặng ($\textit{dfn}$) và số hiệu đỉnh tương ứng với thứ tự DFS ($\textit{rank}$).

$$
\begin{array}{l}
\text{TREE-DECOMPOSITION }(u,\textit{top}) \\
\begin{array}{ll}
1 & u.\textit{top}\gets \textit{top} \\
2 & \textit{tot}\gets \textit{tot}+1\\
3 & u.\textit{dfn}\gets \textit{tot} \\
4 & \textit{rank}(\textit{tot})\gets u \\
5 & \textbf{nếu }u.\textit{hson}\text{ khác }0 \\
6 & \qquad \text{TREE-DECOMPOSITION }(u.\textit{hson},\textit{top}) \\
7 & \qquad \textbf{với mỗi }\text{con }v\text{ của }u \\
8 & \qquad \qquad \textbf{nếu }v\text{ khác }u.\textit{hson} \\
9 & \qquad \qquad \qquad \text{TREE-DECOMPOSITION }(v,v) 
\end{array}
\end{array}
$$

Sau đây là phần cài đặt.

Trước hết là một số định nghĩa:

-   $\operatorname{fa}(x)$ biểu thị cha của đỉnh $x$ trên cây.
-   $\operatorname{dep}(x)$ biểu thị độ sâu của đỉnh $x$ trên cây.
-   $\operatorname{siz}(x)$ biểu thị số đỉnh trong cây con của đỉnh $x$.
-   $\operatorname{son}(x)$ biểu thị **con nặng** của đỉnh $x$.
-   $\operatorname{top}(x)$ biểu thị đỉnh đầu, tức đỉnh có độ sâu nhỏ nhất, của **chuỗi nặng** chứa đỉnh $x$.
-   $\operatorname{dfn}(x)$ biểu thị **thứ tự DFS** của đỉnh $x$, đồng thời cũng là chỉ số của nó trong cây đoạn.
-   $\operatorname{rnk}(x)$ biểu thị số hiệu đỉnh tương ứng với một thứ tự DFS, có $\operatorname{rnk}(\operatorname{dfn}(x))=x$.

Chạy hai lần DFS để tiền xử lý các giá trị này. Lần DFS thứ nhất tính $\operatorname{fa}(x)$, $\operatorname{dep}(x)$, $\operatorname{siz}(x)$, $\operatorname{son}(x)$; lần DFS thứ hai tính $\operatorname{top}(x)$, $\operatorname{dfn}(x)$, $\operatorname{rnk}(x)$.

```cpp
void dfs1(int u, int f) {
  fa[u] = f, dep[u] = dep[f] + 1, siz[u] = 1;
  for (auto v : G[u]) {
    if (v == f) continue;
    dfs1(v, u);
    siz[u] += siz[v];
    if (siz[v] > siz[son[u]]) son[u] = v;
  }
}

void dfs2(int u, int ftop) {
  top[u] = ftop, dfn[u] = ++idx, rnk[idx] = u;
  if (son[u]) dfs2(son[u], ftop);
  for (auto v : G[u])
    if (v != son[u] && v != fa[u]) dfs2(v, v);
}
```

## Tính chất của phân rã chuỗi nặng

**Mỗi đỉnh trên cây thuộc đúng một chuỗi nặng**.

Đỉnh đầu của một chuỗi nặng không thể là con nặng, vì nó hoặc là gốc, hoặc là con nhẹ của cha nó.

Tất cả các chuỗi nặng **phân rã hoàn toàn** toàn bộ cây.

Khi phân rã, cần **duyệt ưu tiên cạnh nặng**. Khi đó trên thứ tự DFS cuối cùng của cây, các thứ tự DFS trong cùng một chuỗi nặng là liên tiếp. Dãy sau khi sắp xếp theo DFN chính là các chuỗi sau phân rã.

Thứ tự DFS trong một cây con là liên tiếp.

Khi đi xuống qua một **cạnh nhẹ**, kích thước cây con đang xét giảm ít nhất một nửa.

Do đó, với một đường đi bất kỳ trên cây, có thể tách nó thành hai đoạn đi xuống từ [LCA](./lca.md) về hai phía. Mỗi phía nhiều nhất đi qua $O(\log n)$ cạnh nhẹ, vì vậy mỗi đường đi trên cây có thể được tách thành không quá $O(\log n)$ chuỗi nặng.

??? info "Cách tạo dữ liệu để ép HLD"
    Trong trường hợp thông thường, hằng số của $O(\log n)$ trong HLD không đủ lớn nên rất khó ép thời gian. Nếu muốn ép, chỉ có thể xây cây nhị phân có độ sâu thấp.
    
    Vì vậy có thể cân nhắc một phương án trung hòa.
    
    Xây một cây nhị phân có $\sqrt{n}$ đỉnh. Với mỗi cạnh từ một đỉnh tới con của nó, thay cạnh đó bằng một chuỗi độ dài $\sqrt{n}$.
    
    Như vậy, với các truy vấn ngẫu nhiên, có thể ép số lần chuyển giữa chuỗi nhẹ và chuỗi nặng trung bình xuống khoảng $\frac{\log n}{2}$, đồng thời độ sâu là $O(\sqrt{n} \log n)$.
    
    Thêm một số lá ngẫu nhiên có vẻ giúp ép HLD, nhưng do hằng số của HLD nhỏ nên khả năng ép được vẫn thấp.

## Ứng dụng thường gặp

### Duy trì trên đường đi

Dùng HLD để tính tổng trọng số trên đường đi giữa hai đỉnh của cây, mã giả như sau:

$$
\begin{array}{l}
\text{TREE-PATH-SUM }(u,v) \\
\begin{array}{ll}
1 & \textit{tot}\gets 0 \\
2 & \textbf{trong khi }u.\textit{top}\text{ khác }v.\textit{top} \\
3 & \qquad \textbf{nếu }u.\textit{top}.\textit{depth}< v.\textit{top}.\textit{depth} \\
4 & \qquad \qquad \text{SWAP}(u, v) \\
5 & \qquad \textit{tot}\gets \textit{tot} + \text{tổng các giá trị giữa }u\text{ và }u.\textit{top} \\
6 & \qquad u\gets u.\textit{top}.\textit{father} \\
7 & \textit{tot}\gets \textit{tot} + \text{tổng các giá trị giữa }u\text{ và }v \\
8 & \textbf{trả về } \textit{tot}
\end{array}
\end{array}
$$

Thứ tự DFS trên một chuỗi là liên tiếp, nên có thể dùng cây đoạn hoặc cây chỉ số nhị phân để duy trì.

Mỗi lần chọn chuỗi có độ sâu lớn hơn để nhảy lên, cho tới khi hai đỉnh nằm trên cùng một chuỗi.

Cấu trúc nhảy chuỗi tương tự cũng áp dụng được cho việc duy trì và thống kê các thông tin khác trên đường đi.

### Duy trì trên cây con

Đôi khi bài toán yêu cầu duy trì thông tin trên cây con, ví dụ tăng trọng số của mọi đỉnh trong cây con gốc $x$ thêm $v$.

Khi duyệt DFS, các đỉnh trong một cây con có thứ tự DFS liên tiếp.

Mỗi đỉnh ghi lại `bottom`, biểu thị đỉnh ở cuối đoạn liên tiếp ứng với cây con của nó.

Như vậy, thông tin cây con được chuyển thành thông tin trên một đoạn liên tiếp.

### Tìm tổ tiên chung gần nhất

Liên tục nhảy lên theo chuỗi nặng. Khi hai đỉnh đã nằm trên cùng một chuỗi nặng, đỉnh có độ sâu nhỏ hơn chính là LCA.

Khi nhảy lên theo chuỗi nặng, cần nhảy đỉnh có đầu chuỗi hiện tại sâu hơn trước.

Mã tham khảo:

```cpp
int lca(int u, int v) {
  while (top[u] != top[v]) {
    if (dep[top[u]] > dep[top[v]])
      u = fa[top[u]];
    else
      v = fa[top[v]];
  }
  return dep[u] > dep[v] ? v : u;
}
```

### Đổi gốc

Xét một loại bài toán mới: ngoài các thao tác cơ bản mà HLD hỗ trợ, còn có thêm thao tác đổi gốc.

Vì thông tin mà HLD duy trì là tĩnh, nó không hỗ trợ sửa động cấu trúc phân rã. Đồng thời, không thể tiền xử lý lại sau mỗi lần đổi gốc vì độ phức tạp quá cao. Vì vậy cần tận dụng đầy đủ thông tin đã có để xử lý thao tác đổi gốc.

Với thao tác sửa và truy vấn đường đi, do đường đi đơn giữa hai đỉnh trên cây là duy nhất nên nó không thay đổi; cách xử lý giống như bình thường.

Với thao tác sửa và truy vấn cây con, ý tưởng thông thường là ánh xạ cây con sau khi đổi gốc về cây con trong cây ban đầu. Việc này cần xét theo vị trí tương đối giữa đỉnh gốc của cây con cần thao tác, gốc của toàn bộ cây sau khi đổi gốc và gốc của cây ban đầu. Chi tiết xem [bài ví dụ bên dưới](./hld.md#loj-139-hld).

## Bài ví dụ

Bài viết dùng các ví dụ để minh họa cách áp dụng phân rã chuỗi nặng. Trước hết là một bài mẫu.

???+ example "[ZJOI2008 - Thống kê trên cây](https://loj.ac/problem/10138)"
    Cho một cây tĩnh có $n$ đỉnh, mỗi đỉnh có trọng số. Thực hiện tổng cộng $q$ thao tác thuộc ba loại:
    
    1.  Sửa trọng số của một đỉnh.
    2.  Truy vấn trọng số lớn nhất trên đường đi từ $u$ tới $v$.
    3.  Truy vấn tổng trọng số trên đường đi từ $u$ tới $v$.
    
    Ràng buộc: $1\le n\le 30000$, $0\le q\le 200000$.

??? note "Lời giải"
    Theo đề bài và các tính chất đã nêu ở trên, cây đoạn cần duy trì ba thao tác:
    
    1.  Sửa một điểm.
    2.  Truy vấn giá trị lớn nhất trên một đoạn.
    3.  Truy vấn tổng trên một đoạn.
    
    Sửa một điểm có cách cài đặt đơn giản.
    
    Vì thứ tự DFS của cây con là liên tiếp, dù có HLD hay không, để sửa cây con của một đỉnh chỉ cần sửa đoạn thứ tự DFS liên tiếp đó.
    
    Vấn đề còn lại là cách sửa/truy vấn đường đi giữa hai đỉnh.
    
    Xét cách dùng **nhân đôi để tìm LCA**. Trước hết **nâng hai đỉnh lên cùng độ cao, rồi nâng cả hai đỉnh cùng lúc**. HLD cũng có thể dùng tư tưởng này.
    
    Trong quá trình nhảy lên, nếu đỉnh hiện tại nằm trên chuỗi nặng thì nhảy lên đầu chuỗi nặng; nếu đỉnh hiện tại không nằm trên chuỗi nặng thì nhảy lên một đỉnh. Lặp như vậy cho tới khi hai đỉnh trùng nhau. Trên đường đi, cập nhật hoặc truy vấn thông tin đoạn tương ứng.
    
    Với mỗi truy vấn, đi qua nhiều nhất $O(\log n)$ chuỗi nặng; trên mỗi chuỗi, độ phức tạp của cây đoạn là $O(\log n)$. Do đó tổng độ phức tạp thời gian là $O(n\log n+q\log^2 n)$. Trong đa số trường hợp, số chuỗi nặng khó đạt tới $O(\log n)$; dù có thể dùng cây nhị phân hoàn chỉnh để ép đạt, HLD thường vẫn có hằng số nhỏ.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/hld/hld_1.cpp"
    ```

Tiếp theo là một bài mẫu về phân rã chuỗi nặng có thao tác đổi gốc.

<a id="loj-139-hld"></a>

???+ example "[LOJ 139. Phân rã chuỗi trên cây](https://loj.ac/p/139)"
    Cho một cây có $n$ đỉnh, gốc ban đầu là đỉnh $1$. Cần hỗ trợ $m$ thao tác sau:
    
    -   Đổi gốc, đặt đỉnh $u$ làm gốc mới của cây.
    -   Sửa trọng số trên đường đi, tăng trọng số của tất cả các đỉnh trên đường đi giữa đỉnh $u$ và đỉnh $v$, bao gồm hai đỉnh này, thêm $w$.
    -   Sửa trọng số trên cây con, tăng trọng số của tất cả các đỉnh trong cây con gốc $u$ thêm $w$.
    -   Truy vấn đường đi, hỏi tổng trọng số của tất cả các đỉnh trên đường đi giữa đỉnh $u$ và đỉnh $v$, bao gồm hai đỉnh này.
    -   Truy vấn cây con, hỏi tổng trọng số của tất cả các đỉnh trong cây con gốc $u$.
    
    $1 \le n,m \le 10^5$.

??? note "Lời giải"
    Trước hết chạy DFS với $1$ làm gốc để tiền xử lý các thông tin cần thiết cho HLD. Để tiện trình bày, gọi cây có gốc $1$ là "cây ban đầu", còn cây sau một số thao tác đổi gốc là "cây hiện tại". Trong quá trình thao tác, cần duy trì $\textit{root}$ là gốc của cây hiện tại. Vì cây đoạn lưu thông tin theo thứ tự DFS của cây ban đầu, nên mỗi lần truy vấn và sửa cần chuyển thao tác trên cây hiện tại về cây ban đầu.
    
    Với thao tác đổi gốc, trực tiếp đặt $\textit{root}\gets u$. Với thao tác trên đường đi, vì đổi gốc không ảnh hưởng tới đường đi, nên xử lý tương ứng trên cây ban đầu.
    
    Trọng tâm là các thao tác trên cây con. Phân loại theo vị trí tương đối của $u$ và $\textit{root}$:
    
    -   $u = \textit{root}$: đây là trường hợp đặc biệt nhất, tương đương thao tác trên toàn bộ cây. Khi đó chỉ cần gắn đánh dấu vào gốc cây đoạn hoặc truy vấn đáp án tại đó.
    -   $u$ là tổ tiên của $\textit{root}$ trong cây ban đầu, tức $u$ nằm trên đường đi đơn từ $1$ tới $\textit{root}$.
    
        Đây là trường hợp quan trọng nhất. Định nghĩa $v$ là đỉnh có độ sâu nhỏ nhất trên đường đi đơn từ $u$ tới $\textit{root}$ trong cây ban đầu, nhưng khác $u$. Phần ngoài cây con của $v$ trong cây ban đầu chính là cây con của $u$ trong cây hiện tại.
    
        Xét cách tìm $v$ hiệu quả. Trước hết đặt $v\gets\textit{root}$, rồi nhảy lên theo các chuỗi nặng cho tới khi $\operatorname{dep}(\operatorname{top}(v))\le\operatorname{dep}(u)+1$.
    
        -   Nếu $\operatorname{dep}(\operatorname{top}(v))=\operatorname{dep}(u)+1$, đặt $v\gets\operatorname{top}(v)$. Khi đó $v$ là một con nhẹ của $u$.
        -   Nếu $\operatorname{dep}(\operatorname{top}(v))<\operatorname{dep}(u)+1$, tức $\operatorname{dep}(\operatorname{top}(v))\le \operatorname{dep}(u)$, điều này cho thấy $u,v$ nằm trên cùng một chuỗi nặng. Theo tính chất thứ tự DFS liên tiếp trên cùng một chuỗi nặng, đỉnh $v$ cần tìm thỏa $\operatorname{dfn}(v)=\operatorname{dfn}(u)+1$. Vì vậy có thể đặt $v\gets\operatorname{rnk}(\operatorname{dfn}(u)+1)$.
    
        Hai trường hợp này có thể gộp lại: sau khi nhảy xong, có thể trực tiếp đặt
    
        $$
        v\gets\operatorname{rnk}(\operatorname{dfn}(\operatorname{top}(v))+\operatorname{dep}(u)+1-\operatorname{dep}(\operatorname{top}(v))).
        $$
    
        Có thể kiểm chứng rằng $v$ tìm được bằng biểu thức này tương đương với $v$ tìm được bằng cách phân loại ở trên. Cài đặt tham khảo cũng dùng biểu thức này.
    
        Vì đoạn mà cây con của $v$ phủ là $[\operatorname{dfn}(v),\operatorname{dfn}(v)+\operatorname{siz}(v))$, nên chỉ cần thao tác trên $[1,\operatorname{dfn}(v))\cup[\operatorname{dfn}(v)+\operatorname{siz}(v),n]$.
    -   Các trường hợp khác. Thao tác đổi gốc không ảnh hưởng tới cây con của $u$, nên duy trì theo cách bình thường.
    
    Độ phức tạp của cách làm này giống cách không có đổi gốc, đều là $O(n\log^2 n)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/hld/hld_4.cpp"
    ```

Cuối cùng là một bài tương tác, cũng là một ứng dụng không truyền thống của HLD.

???+ example "[Nauuo and Binary Tree](https://loj.ac/problem/6669)"
    Có một cây nhị phân gốc $1$. Có thể hỏi khoảng cách giữa hai đỉnh bất kỳ; cần tìm cha của mỗi đỉnh.
    
    Số đỉnh không vượt quá $3000$, số lần hỏi không quá $30000$.

??? note "Lời giải"
    Trước hết có thể xác định độ sâu của mỗi đỉnh bằng $n-1$ lần hỏi.
    
    Sau đó xét việc xác định cha của các đỉnh theo thứ tự độ sâu tăng dần. Khi xác định cha của một đỉnh, tất cả tổ tiên của nó đều đã biết.
    
    Trước khi xác định cha của một đỉnh, thực hiện phân rã chuỗi nặng trên phần cây đã biết.
    
    Giả sử cần tìm vị trí của đỉnh $k$ trong cây con $u$. Có thể hỏi khoảng cách giữa $k$ và đuôi chuỗi nặng chứa $u$, từ đó xác định thêm vị trí của $k$. Xem hình sau:
    
    ![](./images/hld2.png)
    
    Trong đó đường nét đứt màu đỏ là một chuỗi nặng, $d$ là kết quả truy vấn, tức $\textit{dis}(k, \textit{bot}(u))$, và độ sâu của $v$ là $(\textit{dep}(k)+\textit{dep}(\textit{bot}(u))-d)/2$.
    
    Khi đó, nếu $v$ chỉ có một con thì cha của $k$ là $v$; nếu không, có thể đệ quy tìm cha của $k$ trong cây con của $w$.
    
    Độ phức tạp thời gian là $O(n^2)$, độ phức tạp số lần hỏi là $O(n\log n)$.
    
    Cụ thể, đặt $T(n)$ là số lần hỏi cần thiết trong trường hợp xấu nhất để tìm vị trí của một đỉnh mới trong một cây kích thước $n$, có:
    
    $$
    T(n)\le
    \begin{cases}
    0&n=1\\
    T\left(\left\lfloor\frac{n-1}2\right\rfloor\right)+1&n\ge2
    \end{cases}
    $$
    
    $2999+\sum_{i=1}^{2999}T(i)\le 29940$. Có thể dựng dữ liệu để đạt cận trên này, nhưng chỉ cần thêm một chút nhiễu ngẫu nhiên, chẳng hạn dùng thuật toán sắp xếp không ổn định khi sắp theo độ sâu, số lần hỏi rất khó vượt quá $21000$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/hld/hld_2.cpp"
    ```

## Phân rã chuỗi dài

Phân rã chuỗi dài về bản chất là một cách phân rã thành chuỗi khác.

Định nghĩa **con nặng** là đỉnh con có độ sâu cây con lớn nhất trong các con của một đỉnh. Nếu có nhiều con có cây con lớn nhất, chọn một đỉnh bất kỳ. Nếu không có con thì không có con nặng.

Định nghĩa **con nhẹ** là các đỉnh con còn lại.

Cạnh từ đỉnh này tới con nặng của nó được gọi là **cạnh nặng**.

Cạnh tới các con nhẹ khác được gọi là **cạnh nhẹ**.

Một số cạnh nặng nối đầu cuối với nhau tạo thành **chuỗi nặng**.

Nếu cũng xem một đỉnh lẻ là một chuỗi nặng, thì toàn bộ cây được phân rã thành nhiều chuỗi nặng.

Như hình sau, cách phân rã này vừa có thể xem là phân rã chuỗi nặng, vừa có thể xem là phân rã chuỗi dài:

![Ví dụ phân rã cây theo chuỗi dài](./images/hld.png)

Cách cài đặt phân rã chuỗi dài tương tự phân rã chuỗi nặng, nên không trình bày thêm.

### Ứng dụng thường gặp

Trước hết, nhận thấy trong phân rã chuỗi dài, số lần chuyển qua cạnh nhẹ trên đường đi từ một đỉnh tới gốc là cỡ $\sqrt{n}$.

??? info "Cách dựng dữ liệu để ép đầy số lần chuyển cạnh nhẹ/nặng"
    Có thể dựng một cây nhị phân T như sau:
    
    Giả sử tham số của cây nhị phân cần dựng là $D$.
    
    Nếu $D \neq 0$, dựng một cây nhị phân tham số $D-1$ ở con trái, và dựng một chuỗi độ dài $2D-1$ ở con phải.
    
    Nếu $D = 0$, có thể dựng trực tiếp một đỉnh lá đơn lẻ rồi kết thúc lời gọi.
    
    Cách dựng này làm cho đường đi từ đỉnh lá đơn lẻ tới gốc toàn là cạnh nhẹ, đồng thời cần số đỉnh cỡ $D^2$.
    
    Chọn $D=\sqrt{n}$.

#### Tối ưu DP bằng phân rã chuỗi dài

Thông thường, DP có thể được tối ưu bằng phân rã chuỗi dài sẽ có một chiều trạng thái là chiều độ sâu.

Có thể cân nhắc dùng phân rã chuỗi dài để tối ưu DP trên cây.

Cụ thể, trạng thái của mỗi đỉnh trực tiếp kế thừa trạng thái của con nặng của nó, đồng thời gộp trực tiếp các trạng thái DP của con nhẹ.

???+ example "[Codeforces 1009 F. Dominant Indices](http://codeforces.com/contest/1009/problem/F)"
    Cho một cây có gốc gồm $n$ đỉnh, lấy đỉnh $1$ làm gốc.
    
    Định nghĩa mảng độ sâu của đỉnh $x$ là một dãy vô hạn $[d_{x, 0}, d_{x, 1}, d_{x, 2}, \dots]$, trong đó $d_{x, i}$ biểu thị số đỉnh $y$ thỏa hai điều kiện sau:
    
    -   $x$ là tổ tiên của $y$.
    -   Đường đi đơn từ $x$ tới $y$ đi qua đúng $i$ cạnh.
    
    Chỉ số trội (dominant index) của mảng độ sâu của đỉnh $x$, gọi tắt là chỉ số trội của đỉnh $x$, được định nghĩa là một chỉ số $j$ thỏa:
    
    -   Với mọi $k < j$, đều có $d_{x, k} < d_{x, j}$.
    -   Với mọi $k > j$, đều có $d_{x, k} \le d_{x, j}$.
    
    Tính chỉ số trội của mỗi đỉnh trong cây.

??? note "Lời giải"
    Đặt $f_{i,j}$ biểu thị số đỉnh trong cây con của $i$ có khoảng cách tới $i$ là $j$.
    
    Chuyển trạng thái trực tiếp có độ phức tạp thời gian $O(n^2)$.
    
    Xét mỗi lần chuyển trạng thái: trực tiếp kế thừa mảng DP và đáp án của con nặng, rồi cập nhật trên cơ sở đó.
    
    Trước hết cần chèn một phần tử 1 vào đầu mảng DP của con nặng; phần tử này đại diện cho đỉnh hiện tại.
    
    Sau đó gộp trực tiếp mảng DP của tất cả con nhẹ vào mảng DP của đỉnh hiện tại.
    
    Độ dài mảng DP của một con nhẹ bằng độ dài chuỗi nặng chứa con nhẹ đó, còn tổng độ dài của tất cả chuỗi nặng là $n$.
    
    Nói cách khác, tổng độ phức tạp thời gian để gộp trực tiếp các con nhẹ là $O(n)$.

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/graph/code/hld/hld_3.cpp"
    ```

Trong trường hợp thông thường, bộ nhớ của mảng DP được cấp phát theo cả một chuỗi nặng, còn các đỉnh khác nhau trên chuỗi có các con trỏ đầu khác nhau.

Độ dài mảng DP có thể được tính theo đỉnh sâu nhất trong cây con.

Có nhiều kỹ thuật tối ưu DP bằng phân rã chuỗi dài, bao gồm nhưng không giới hạn ở việc đánh dấu lười. Phần này không trình bày thêm.

Tham khảo [blog của Zusu Yu](https://www.cnblogs.com/zhoushuyu/p/9468669.html).

#### Tìm tổ tiên cấp k bằng phân rã chuỗi dài

Tức là hỏi đỉnh thu được sau khi một đỉnh nhảy lên cha $k$ lần.

Trước hết giả sử đã tiền xử lý tổ tiên cấp $2^i$ của mỗi đỉnh.

Bây giờ giả sử đã tìm được tổ tiên cấp $2^i$ của đỉnh truy vấn sao cho $2^i \le k < 2^{i+1}$.

Xét việc lấy các đỉnh trên chuỗi nặng chứa nó và đưa vào bảng theo thứ tự độ sâu. Giả sử độ dài chuỗi nặng là $d$.

Đồng thời, khi tiền xử lý, tìm các tổ tiên cấp $1$ tới $d$ của đỉnh gốc mỗi chuỗi nặng và cũng đưa vào bảng.

Theo tính chất của phân rã chuỗi dài, $k-2^i \le 2^i \leq d$. Nói cách khác, có thể tìm tổ tiên cấp $k$ của đỉnh này trong bảng của chuỗi nặng đó trong $O(1)$.

Tiền xử lý cần tính tổ tiên cấp $2^i$ bằng nhân đôi, đồng thời cần tiền xử lý bảng ứng với mỗi chuỗi nặng.

Độ phức tạp tiền xử lý là $O(n\log n)$, độ phức tạp truy vấn là $O(1)$.

## Bài tập

-   [Luogu P3379 - Mẫu tổ tiên chung gần nhất (LCA)](https://www.luogu.com.cn/problem/P3379) (tìm LCA bằng HLD không cần cấu trúc dữ liệu, có thể dùng để luyện tập)
-   [JLOI2014 - Nhà mới của sóc](https://loj.ac/problem/2236) (cũng có thể dùng hiệu trên cây)
-   [HAOI2015 - Thao tác trên cây](https://loj.ac/problem/2125)
-   [Luogu P3384 - Mẫu phân rã chuỗi nặng/phân rã chuỗi trên cây](https://www.luogu.com.cn/problem/P3384)
-   [Luogu P1505 - Du lịch](https://www.luogu.com.cn/problem/P1505)
-   [NOI2015 - Trình quản lý gói phần mềm](https://uoj.ac/problem/128)
-   [SDOI2011 - Tô màu](https://www.luogu.com.cn/problem/P2486)
-   [SDOI2014 - Du lịch](https://hydro.ac/p/bzoj-P3531)
-   [Luogu P3979 - Vương quốc xa xôi](https://www.luogu.com.cn/problem/P3979)
-   [POI2014 - Hotel bản tăng cường](https://hydro.ac/p/bzoj-P4543) (tối ưu DP bằng phân rã chuỗi dài)
-   [Chiến lược](https://hydro.ac/p/bzoj-P3252) (tối ưu tham lam bằng phân rã chuỗi dài)
