Đồ thị dây cung là một lớp đồ thị đặc biệt. Nhiều bài toán NP-hard trên đồ thị tổng quát lại có thuật toán tuyến tính rất tốt trên đồ thị dây cung.

## Một số định nghĩa và tính chất

**Đồ thị con**: đồ thị có tập đỉnh và tập cạnh đều là tập con của tập đỉnh và tập cạnh của đồ thị ban đầu.

**Đồ thị con cảm sinh**: đồ thị có tập đỉnh là một tập con của tập đỉnh ban đầu, còn tập cạnh gồm mọi cạnh có **cả hai đầu mút đều thuộc tập đỉnh được chọn**.

**Clique**: đồ thị con đầy đủ.

**Clique cực đại**: clique không phải là đồ thị con của một clique khác.

**Clique lớn nhất**: clique có số đỉnh lớn nhất.

**Số clique**: số đỉnh của clique lớn nhất, ký hiệu là $\omega(G)$.

**Tô màu tối thiểu**: tô màu các đỉnh bằng ít màu nhất sao cho hai đầu mút của mọi cạnh có màu khác nhau.

**Sắc số**: số màu của phép tô màu tối thiểu, ký hiệu là $\chi(G)$.

**Tập độc lập lớn nhất**: tập đỉnh lớn nhất sao cho hai đỉnh bất kỳ trong tập đều không kề nhau. Kích thước của tập này được ký hiệu là $\alpha(G)$.

**Phủ clique tối thiểu**: phủ tất cả các đỉnh bằng ít clique nhất. Số clique được dùng ký hiệu là $\kappa(G)$.

**Dây cung**: cạnh nối hai đỉnh không kề nhau trên một chu trình.

**Đồ thị dây cung**: đồ thị mà mọi chu trình có độ dài lớn hơn $3$ đều có một dây cung được gọi là đồ thị dây cung.

**Bổ đề 1**: số clique $\omega(G)\le \chi(G)$ sắc số.

Chứng minh: xét riêng việc tô màu đồ thị con cảm sinh bởi một clique lớn nhất. Cần ít nhất $\omega(G)$ màu.

**Bổ đề 2**: kích thước tập độc lập lớn nhất $\alpha(G)\le \kappa(G)$ số phủ clique tối thiểu.

Chứng minh: trong mỗi clique chọn được nhiều nhất một đỉnh.

**Bổ đề 3**: mọi đồ thị con cảm sinh của đồ thị dây cung đều là đồ thị dây cung.

Chứng minh: nếu đồ thị dây cung có một đồ thị con cảm sinh không phải đồ thị dây cung, thì trong đồ thị con cảm sinh này tồn tại một chu trình không dây cung có độ dài lớn hơn $3$. Khi đó dù đồ thị ban đầu có thêm cạnh như thế nào, nó cũng không thể là đồ thị dây cung, mâu thuẫn.

**Bổ đề 4**: mọi đồ thị con cảm sinh của đồ thị dây cung không thể là một chu trình có số đỉnh lớn hơn $3$.

Chứng minh: một chu trình có số đỉnh lớn hơn $3$ không phải là đồ thị dây cung, áp dụng định lý trên là đủ.

## Nhận biết đồ thị dây cung

### Mô tả bài toán

Cho một đồ thị vô hướng, hãy xác định nó có phải là đồ thị dây cung hay không.

### Tập cắt đỉnh

Với hai đỉnh $u,v$ trên đồ thị $G$, định nghĩa **tập cắt đỉnh** giữa hai đỉnh này là một tập đỉnh sao cho sau khi xóa tập đó, hai đỉnh $u,v$ không còn liên thông với nhau. Nếu mọi tập con của một tập cắt đỉnh giữa $u,v$ đều không phải là tập cắt đỉnh, thì tập cắt đỉnh đó được gọi là **tập cắt đỉnh cực tiểu**.

**Bổ đề 5**: tập cắt đỉnh cực tiểu giữa $u,v$ trong đồ thị chia đồ thị ban đầu thành nhiều thành phần liên thông. Gọi thành phần liên thông chứa $u$ là $V_1$, thành phần liên thông chứa $v$ là $V_2$. Khi đó với mọi đỉnh $a$ thuộc tập cắt đỉnh cực tiểu, $N(a)$ chắc chắn chứa đỉnh thuộc cả $V_1$ và $V_2$.

Chứng minh: nếu $N(a)$ chỉ chứa đỉnh thuộc nhiều nhất một trong hai thành phần liên thông $V_1$ hoặc $V_2$, thì sau khi bỏ đỉnh $a$ khỏi tập cắt đỉnh, đồ thị vẫn không liên thông. Khi đó tập cắt đỉnh ban đầu không phải là tập cắt đỉnh cực tiểu.

**Bổ đề 6**: đồ thị con cảm sinh bởi tập cắt đỉnh cực tiểu giữa hai đỉnh bất kỳ trên đồ thị dây cung luôn là một clique.

Chứng minh: khi kích thước tập cắt đỉnh cực tiểu $\le 1$, đồ thị con cảm sinh chắc chắn là một clique.

Ngược lại, giả sử trong tập cắt đỉnh cực tiểu có hai đỉnh $x,y$. Theo **Bổ đề 5**, trong $N(x)$ có các đỉnh thuộc $V_1,V_2$, ký hiệu là $x_1,x_2$. Tương tự, ký hiệu các đỉnh tương ứng với $y$ là $y_1,y_2$. Lưu ý rằng có thể có $x_1=y_1,x_2=y_2$.

Vì $V_1,V_2$ đều là các thành phần liên thông, nên giữa hai cặp đỉnh $x_1,y_1$ và $x_2,y_2$ tồn tại các đường đi ngắn nhất. Gọi các đường đi ngắn nhất bên trong $V_1,V_2$ lần lượt là $x-x_1\sim y_1-y,x-x_2\sim y_2-y$. Khi đó trong đồ thị tồn tại một chu trình $x-x_1\sim y_1-y-y_2\sim x_2-x$, chu trình này chắc chắn có độ dài $\ge 4$. Theo định nghĩa đồ thị dây cung, trên chu trình đó chắc chắn tồn tại một dây cung.

Nếu dây cung này nối hai thành phần liên thông $V_1,V_2$, thì tập đỉnh đang xét không phải là tập cắt đỉnh. Nếu dây cung nối hai đỉnh trong cùng một thành phần liên thông, hoặc nối một đỉnh trong một thành phần liên thông với một đỉnh trên tập cắt, thì nó đều trái với tính chất đường đi ngắn nhất. Vì vậy dây cung này chỉ có thể nối hai đỉnh $x,y$.

Từ đó suy ra mọi cặp đỉnh trong mỗi tập cắt đỉnh cực tiểu của đồ thị dây cung đều kề nhau trực tiếp, nên tính chất được chứng minh.

### Đỉnh đơn hình

Gọi $N(x)$ là tập các đỉnh kề với đỉnh $x$. Nếu đồ thị con cảm sinh bởi tập đỉnh $\{x\}+N(x)$ là một clique, thì $x$ được gọi là đỉnh đơn hình.

**Bổ đề 7**: mọi đồ thị dây cung đều có ít nhất một đỉnh đơn hình; nếu đồ thị dây cung không phải đồ thị đầy đủ thì nó có ít nhất hai đỉnh đơn hình không kề nhau.

Chứng minh: dùng quy nạp toán học. Xét riêng từng thành phần liên thông.

Cơ sở quy nạp: khi đồ thị đẳng cấu với đồ thị đầy đủ, mọi đỉnh trên đồ thị đều là đỉnh đơn hình. Khi số đỉnh của đồ thị $\le 3$, bổ đề đúng.

Nếu đồ thị có số đỉnh $\ge 4$ và không phải đồ thị đầy đủ, chắc chắn tồn tại $u,v$ sao cho $(u,v)\notin E$. Gọi $I$ là tập cắt đỉnh cực tiểu giữa $u,v$ trong đồ thị. Gọi $A,B$ lần lượt là các thành phần liên thông chứa $u,v$ trong đồ thị con cảm sinh sau khi xóa $I$. Do tính đối xứng của bài toán, ta chỉ xét phía $A$. Đặt $L=A+I$. Nếu $L$ là đồ thị đầy đủ, thì $u$ là đỉnh đơn hình; nếu không, vì $L$ là đồ thị con cảm sinh của đồ thị ban đầu nên nó cũng là đồ thị dây cung, do đó có hai đỉnh đơn hình không kề nhau. Vì $I$ là một clique, mọi cặp đỉnh trong $I$ đều kề nhau, nên trong $A$ chắc chắn có một đỉnh đơn hình. Đỉnh đơn hình này mở rộng ra toàn đồ thị vẫn là đỉnh đơn hình.

Vì mỗi lần chứng minh đều chia toàn bộ đồ thị thành các thành phần liên thông nhỏ hơn, và các phần đó đều thỏa mãn tính chất, nên quy nạp đúng.

### Thứ tự khử hoàn hảo

Đặt $n=|V|$. Thứ tự khử hoàn hảo $v_1,v_2,\ldots ,v_n$ là một hoán vị của $1,2,\ldots ,n$, thỏa mãn $v_i$ là đỉnh đơn hình trong đồ thị con cảm sinh bởi $\{v_i,v_{i+1},\ldots ,v_n\}$.

**Bổ đề 8**: một đồ thị vô hướng là đồ thị dây cung khi và chỉ khi nó có một thứ tự khử hoàn hảo.

Chiều đủ: đồ thị dây cung có $1$ đỉnh có thứ tự khử hoàn hảo. Theo **Bổ đề 3** và **Bổ đề 7**, thứ tự khử hoàn hảo của một đồ thị dây cung có $n$ đỉnh có thể thu được bằng cách lấy thứ tự khử hoàn hảo của một đồ thị dây cung có $n-1$ đỉnh rồi thêm một đỉnh đơn hình.

Chiều cần: giả sử có một đồ thị vô hướng tồn tại chu trình có số đỉnh $>3$ và vẫn có thứ tự khử hoàn hảo. Gọi $v$ là đỉnh đầu tiên trên chu trình xuất hiện trong thứ tự khử hoàn hảo, và gọi $v_1,v_2$ là hai đỉnh kề với $v$ trên chu trình. Theo tính chất của thứ tự khử hoàn hảo, tức định nghĩa đỉnh đơn hình, $v_1,v_2$ phải kề nhau trực tiếp, mâu thuẫn.

### Thuật toán đơn giản

Mỗi lần tìm một **đỉnh đơn hình** $v$ rồi đưa nó vào thứ tự khử hoàn hảo.

Xóa đỉnh $v$ và các cạnh kề với nó khỏi đồ thị.

Lặp lại quá trình trên. Nếu mọi đỉnh đều bị xóa, thì đồ thị ban đầu là đồ thị dây cung và ta tìm được một thứ tự khử hoàn hảo; nếu trên đồ thị không tồn tại đỉnh đơn hình, thì đồ thị ban đầu không phải là đồ thị dây cung.

Độ phức tạp thời gian $O(n^4)$.

### Thuật toán MCS

**Maximum Cardinality Search** là một thuật toán có thể tìm thứ tự khử hoàn hảo của đồ thị vô hướng trong độ phức tạp thời gian $O(n+m)$.

Đánh số các đỉnh theo thứ tự ngược, tức gán nhãn cho đỉnh theo thứ tự từ $n$ đến $1$.

Gọi $label_x$ là số đỉnh đã được gán nhãn và kề với đỉnh thứ $x$. Mỗi lần chọn đỉnh chưa được gán nhãn có giá trị $label$ lớn nhất để gán nhãn.

Dùng danh sách liên kết để duy trì, với mỗi $i$, các đỉnh $x$ thỏa mãn $label_x=i$.

Vì mỗi cạnh đóng góp nhiều nhất $2$ vào $\sum_{i=1}^n label_i$, độ phức tạp thời gian là $O(n+m)$.

**Chứng minh tính đúng đắn**:

Gọi $\alpha(x)$ là vị trí của $x$ trong thứ tự này.
Ta cần chứng minh rằng với mọi đồ thị dây cung, thứ tự do thuật toán tìm được chắc chắn là một thứ tự khử hoàn hảo, tức mọi đỉnh đứng sau một đỉnh nào đó trong thứ tự và kề với đỉnh đó đều kề nhau từng đôi một.

**Bổ đề 9**: xét ba đỉnh $u,v,w$ thỏa mãn $\alpha(u)<\alpha(v)<\alpha(w)$. Nếu $uw$ kề nhau, còn $vw$ không kề nhau, thì $w$ chỉ đóng góp vào $label$ của $u$, không đóng góp vào $label$ của $v$. Để $v$ được đưa vào thứ tự trước $u$, cần có một đỉnh $x$ thỏa mãn $\alpha(v)<\alpha(x)$, $vx$ kề nhau và $ux$ không kề nhau, tức $x$ chỉ đóng góp cho $v$ mà không đóng góp cho $u$.

**Bổ đề 10**: trong bất kỳ đồ thị dây cung nào, không tồn tại một dãy $v_0,v_1,\dots,v_k(k\ge 2)$ thỏa mãn các tính chất sau:

1.  $v_iv_j$ kề nhau khi và chỉ khi $|i-j|=1$.
2.  $\alpha(v_0)>\alpha(v_i)(i\in[1,k])$.
3.  Tồn tại $i\in[1,k-1]$ sao cho $\alpha(v_i)<\alpha(v_{i+1})<\dots<\alpha(v_k)$ và $\alpha(v_i)<\alpha(v_{i-1})<\dots<\alpha(v_1)<\alpha(v_k)<\alpha(v_0)$.

Chứng minh:

Vì $\alpha(v_1)<\alpha(v_k)<\alpha(v_0)$, đồng thời $v_1v_0$ kề nhau và $v_kv_0$ không kề nhau, nên theo tính chất thứ nhất, tồn tại $x$ thỏa mãn $\alpha(v_k)<\alpha(x)$, $v_kx$ kề nhau và $v_1x$ không kề nhau.

Xét chỉ số nhỏ nhất $j\in(1,k]$ sao cho $v_jx$ kề nhau. Ta có thể suy ra $v_0x$ không kề nhau; nếu không, $v_0v_1\cdots v_jx$ sẽ tạo thành một chu trình không dây cung có độ dài $\ge 4$.

Nếu $x<v_0$, thì $v_0,v_1,\dots,v_j,x$ cũng là một dãy thỏa mãn các tính chất trên; nếu $v_0<x$, thì $x,v_j,\dots,v_1,v_0$ cũng là một dãy thỏa mãn các tính chất trên.

Trong suy luận trên, ta đã tăng $\min(v_0,v_k)$. Cứ tiếp tục như vậy thì chắc chắn sẽ dẫn tới mâu thuẫn.

**Định lý 1**: với mọi đồ thị dây cung, thứ tự do thuật toán Maximum Cardinality Search tìm được chắc chắn là một thứ tự khử hoàn hảo.

Chứng minh: xét ba đỉnh bất kỳ $u,v,w$ thỏa mãn $\alpha(u)<\alpha(v)<\alpha(w)$. Ta cần chứng minh rằng nếu $uv$ kề nhau và $uw$ kề nhau thì $vw$ chắc chắn kề nhau.

Dùng phản chứng, giả sử $vw$ không kề nhau. Khi đó $w,u,v$ là một dãy thỏa mãn các tính chất trong **Bổ đề 10**. Ta đã chứng minh dãy như vậy không tồn tại, nên mâu thuẫn. Do đó $vw$ kề nhau.

Mã tham khảo:

```cpp
while (cur) {
  p[cur] = h[nww];
  rnk[p[cur]] = cur;
  h[nww] = nxt[h[nww]];
  lst[h[nww]] = 0;
  lst[p[cur]] = nxt[p[cur]] = 0;
  tf[p[cur]] = true;
  for (vector<int>::iterator it = G[p[cur]].begin(); it != G[p[cur]].end();
       it++)
    if (!tf[*it]) {
      if (h[deg[*it]] == *it) h[deg[*it]] = nxt[*it];
      nxt[lst[*it]] = nxt[*it];
      lst[nxt[*it]] = lst[*it];
      lst[*it] = nxt[*it] = 0;
      deg[*it]++;
      nxt[*it] = h[deg[*it]];
      lst[h[deg[*it]]] = *it;
      h[deg[*it]] = *it;
    }
  cur--;
  if (h[nww + 1]) nww++;
  while (nww && !h[nww]) nww--;
}
```

Nếu đồ thị ban đầu là đồ thị dây cung, thứ tự vừa tìm được là thứ tự khử hoàn hảo. Nhưng vì đồ thị ban đầu có thể không phải là đồ thị dây cung, thứ tự tìm được lúc này không nhất thiết là thứ tự khử hoàn hảo, nên bài toán chuyển thành **kiểm tra thứ tự tìm được có phải là thứ tự khử hoàn hảo của đồ thị ban đầu hay không**.

### Kiểm tra một thứ tự có phải là thứ tự khử hoàn hảo hay không

#### Thuật toán đơn giản

Theo định nghĩa, lần lượt kiểm tra xem các đỉnh kề với $v_i$ trong $\{v_i,v_{i+1},\ldots ,v_n\}$ trên thứ tự khử hoàn hảo $v$ có tạo thành một clique hay không. Độ phức tạp thời gian $O(nm)$.

#### Thuật toán tối ưu

Theo định nghĩa thứ tự khử hoàn hảo, giả sử các đỉnh kề với $v_i$ trong ${v_i,v_{i+1},\ldots , v_n}$, sắp theo thứ tự tăng dần, là $\{v_{c_1},v_{c_2},\ldots ,v_{c_k} \}$. Khi đó chỉ cần kiểm tra $v_{c_1}$ có kề trực tiếp với các đỉnh còn lại hay không. Độ phức tạp thời gian $O(n+m)$.

```cpp
jud = true;
for (int i = 1; i <= n; i++) {
  cur = 0;
  for (vector<int>::iterator it = G[p[i]].begin(); it != G[p[i]].end(); it++)
    if (rnk[p[i]] < rnk[*it]) {
      s[++cur] = *it;
      if (rnk[s[cur]] < rnk[s[1]]) swap(s[1], s[cur]);
    }
  for (int j = 2; j <= cur; j++)
    if (!st[s[1]].count(s[j])) {
      jud = false;
      break;
    }
}
if (!jud)
  printf("Imperfect\n");
else
  printf("Perfect\n");
```

Đến đây, **bài toán nhận biết đồ thị dây cung** có thể được giải trong độ phức tạp thời gian $O(n+m)$.

## Clique cực đại của đồ thị dây cung

Gọi $N(x)$ là dãy các đỉnh kề trực tiếp với $x$ và đứng sau $x$ trong thứ tự khử hoàn hảo. Khi đó các clique cực đại của đồ thị dây cung chắc chắn có dạng $\{x\}+N(x)$.

Chứng minh: xét một clique cực đại $V$ của đồ thị dây cung. Gọi $x$ là đỉnh trong clique này xuất hiện đầu tiên trong thứ tự khử hoàn hảo. Khi đó chắc chắn có $V\subseteq \{x\}+N(x)$. Lại vì $V$ là clique cực đại, nên $V=\{x\}+N(x)$.

Đồ thị dây cung có nhiều nhất $n$ clique cực đại. Để tìm từng clique cực đại của đồ thị dây cung, có thể kiểm tra mỗi $\{x\}+N(x)$ có phải là clique cực đại hay không.

Đặt $A=\{x\}+N(x),B=\{y\}+N(y)$. Nếu $A\subsetneqq B$, thì $A$ không phải là clique cực đại. Khi đó rõ ràng trong thứ tự khử hoàn hảo, $y$ đứng trước $x$.

Gọi $nxt_x$ là đỉnh đứng sớm nhất trong thứ tự khử hoàn hảo trong $N(x)$, và gọi $y*$ là đỉnh đứng muộn nhất trong mọi $y$ thỏa mãn $A\subseteq B$. Khi đó chắc chắn có $nxt_{y*}=x$; nếu không, $y*$ không phải là đỉnh muộn nhất, vì đặt $y*=nxt_{y*}$ vẫn thỏa mãn điều kiện.

$A\subsetneqq B$ khi và chỉ khi $|A|+1\le |B|$.

Bài toán chuyển thành kiểm tra có tồn tại $y$ thỏa mãn $nxt_y=x$ và $|N(x)|+1\le |N(y)|$ hay không. Độ phức tạp thời gian $O(n+m)$.

```cpp
for (int i = 1; i <= n; i++) {
  cur = 0;
  for (vector<int>::iterator it = G[p[i]].begin(); it != G[p[i]].end(); it++)
    if (rnk[p[i]] < rnk[*it]) {
      s[++cur] = *it;
      if (rnk[s[cur]] < rnk[s[1]]) swap(s[1], s[cur]);
    }
  fst[p[i]] = s[1];
  N[p[i]] = cur;
}
for (int i = 1; i <= n; i++) {
  if (!vis[p[i]]) ans++;
  if (N[p[i]] >= N[fst[p[i]]] + 1) vis[fst[p[i]]] = true;
}
```

## Sắc số của đồ thị dây cung/số clique của đồ thị dây cung

Một cách xây dựng: theo thứ tự khử hoàn hảo từ sau ra trước, lần lượt tô màu mỗi đỉnh bằng màu nhỏ nhất có thể dùng. Độ phức tạp thời gian $O(m+n)$.

Chứng minh tính đúng đắn: giả sử phương pháp trên dùng $t$ màu, khi đó $t\ge \chi(G)$. Vì mỗi đỉnh trong một clique đều có màu khác nhau, nên $t=\omega(G)$. Theo **Bổ đề 1**, $t=\omega(G)\le \chi(G)$. Suy ra $t=\chi(G)=\omega(G)$.

Nếu không cần phương án tô màu mà chỉ cần tìm sắc số/số clique của đồ thị dây cung, có thể lấy giá trị lớn nhất của $|\{x\}+N(x)|$.

```cpp
for (int i = 1; i <= n; i++) ans = max(ans, deg[i] + 1);
```

## Tập độc lập lớn nhất/phủ clique tối thiểu của đồ thị dây cung

Tập độc lập lớn nhất: duyệt thứ tự khử hoàn hảo từ trước ra sau, chọn mọi đỉnh không có cạnh nối trực tiếp với các đỉnh đã chọn.

Phủ clique tối thiểu: giả sử tập độc lập lớn nhất là $\{v_1,v_2,\ldots ,v_t\}$, khi đó tập các clique $\{\{v_1+N(v_1)\},\{v_2+N(v_2)\},\ldots ,\{v_t+N(v_t)\} \}$ là phủ clique tối thiểu của đồ thị. Độ phức tạp thời gian của cả hai bài toán đều là $O(n+m)$.

Chứng minh tính đúng đắn: giả sử phương án trên có kích thước tập độc lập và số clique phủ đều là $t$. Theo định nghĩa, $t\le \alpha(G),t\ge \kappa(G)$. Theo **Bổ đề 2**, $\alpha(G)\le \kappa(G)$, nên $t=\alpha(G)=\kappa(G)$.

```cpp
for (int i = 1; i <= n; i++)
  if (!vis[p[i]]) {
    ans++;
    for (vector<int>::iterator it = G[p[i]].begin(); it != G[p[i]].end(); it++)
      vis[*it] = true;
  }
```

## Bài tập

[SPOJ FISHNET - Fishing Net](https://www.spoj.com/problems/FISHNET)

[P3196\[HNOI2008\] Vương quốc kỳ diệu](https://www.luogu.com.cn/problem/P3196)

[P3852\[TJOI2007\] Bạn nhỏ](https://www.luogu.com.cn/problem/P3852)

## Tài liệu tham khảo

[Tài liệu liên quan về đồ thị dây cung](https://yhx-12243.github.io/OI-transit/memos/15.html)

[Slide WC 2009](https://github.com/hzwer/shareOI/blob/master/%E5%9B%BE%E8%AE%BA/%E5%BC%A6%E5%9B%BE%E4%B8%8E%E5%8C%BA%E9%97%B4%E5%9B%BE_%E9%99%88%E4%B8%B9%E7%90%A6.pptx)

[Tổng kết về đồ thị dây cung - Zu Suyu](https://www.cnblogs.com/zhoushuyu/p/8716935.html)

[R. E. Tarjan and M. Yannakakis, Simple linear-time algorithms to test chordality of graphs,test acyclicity of hypergraphs,and selectively reduce acyclic hypergraphs, SIAM J. Comput., 13 (1984), pp. 566-579.](https://dl.acm.org/doi/abs/10.1137/0213035)
