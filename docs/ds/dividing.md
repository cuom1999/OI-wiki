author: Xarfa

## Giới thiệu

Cây phân hoạch là một cấu trúc dữ liệu dùng để xử lý truy vấn phần tử nhỏ thứ $k$ trong đoạn (tùy quy ước cũng có thể viết dưới dạng phần tử lớn thứ $K$). Hằng số và độ khó khi hiểu của nó đều thấp hơn cây phân đoạn bền vững khá nhiều. Đồng thời, cây phân hoạch gắn chặt với bài toán "phần tử nhỏ thứ $k$", nên đây là một cấu trúc dữ liệu dựa trên sắp xếp.

Kiến thức cần có: [cây phân đoạn bền vững](persistent-seg.md#%E4%B8%BB%E5%B8%AD%E6%A0%91)

## Quy trình

### Xây cây

Việc xây cây phân hoạch khá đơn giản, nhưng vẫn phức tạp hơn so với nhiều loại cây khác.

![](./images/dividing-1.svg)

Như hình trên, mỗi tầng đều có một mảng trông có vẻ không có thứ tự. Thực ra, mỗi số được đánh dấu màu đỏ đều là số **sẽ được đưa vào con trái**. Quy tắc phân chia là gì? Ta so sánh với **trung vị của tầng hiện tại**: nếu nhỏ hơn hoặc bằng trung vị thì đưa sang trái, ngược lại đưa sang phải. Tuy nhiên cần chú ý: quy tắc không phải lúc nào cũng cứng nhắc là **nhỏ hơn hoặc bằng thì sang trái, ngược lại sang phải**. Lý do là trung vị có thể xuất hiện nhiều lần, và cách chia còn liên quan đến tính chẵn lẻ của $N$. Đoạn mã dưới đây dùng một cách xử lý khéo léo cho trường hợp đó, bạn có thể tham khảo.

Ta không thể sắp xếp lại từng tầng ở mỗi lần xây dựng; chưa nói đến hằng số, ngay cả độ phức tạp lý thuyết cũng không đạt. Để tìm trung vị, chỉ cần sắp xếp một lần. Vì sao? Chẳng hạn, trung vị của đoạn $l,r$ chính là `num[mid]` sau khi mảng đã được sắp xếp.

Hai mảng then chốt:

tree\[log(N),N]: chính là cây, dùng để lưu toàn bộ giá trị; độ phức tạp không gian là $O(n\log n)$.
toleft\[log(N),n]: số lượng phần tử trong đoạn 1\~i của mỗi tầng được đưa vào con trái. Cần hiểu đây là một mảng tổng tiền tố.

???+ note "Cài đặt"
    ```pascal
    procedure Build(left,right,deep:longint); // left,right là hai đầu mút đoạn, deep là tầng hiện tại
    var
      i,mid,same,ls,rs,flag:longint; // flag dùng để cân bằng số lượng hai bên
    begin
      if left=right then exit; // đã tới tầng đáy
      mid:=(left+right) >> 1;
      same:=mid-left+1;
      for i:=left to right do
        if tree[deep,i]<num[mid] then
          dec(same);

      ls:=left; // con trỏ đầu tiên cho phần đưa vào con trái
      rs:=mid+1; // con trỏ đầu tiên cho phần đưa vào con phải
      for i:=left to right do
      begin
        flag:=0;
        if (tree[deep,i]<num[mid])or((tree[deep,i]=num[mid])and(same>0)) then // điều kiện để đưa sang trái
        begin
          flag:=1; tree[deep+1,ls]:=tree[deep,i]; inc(ls);
          if tree[deep,i]=num[mid] then // cân bằng số lượng hai bên
            dec(same);
        end
        else
        begin
          tree[deep+1,rs]:=tree[deep,i]; inc(rs);
        end;
        toleft[deep,i]:=toleft[deep,i-1]+flag;
      end;
      Build(left,mid,deep+1); // tiếp tục
      Build(mid+1,right,deep+1);
    end;
    ```

### Truy vấn

Trước hết nhắc lại một chút về cây phân đoạn bền vững. Khi dùng cây phân đoạn bền vững để tìm phần tử nhỏ thứ $K$ trong đoạn, ta lấy $K$ làm mốc: nếu đi sang trái thì giữ nguyên $K$, còn nếu đi sang phải thì phải trừ đi số lượng phần tử đã đi sang trái. Trong cây phân hoạch cũng tương tự.

Phần khó hiểu của truy vấn nằm ở thao tác **thu hẹp đoạn**. Trong hình dưới, đoạn cần truy vấn là từ $3$ đến $7$, nên ở tầng tiếp theo chỉ cần truy vấn từ $2$ đến $3$. Ở đây, ta định nghĩa $[\text{left},\text{right}]$ là đoạn sau khi thu hẹp (đoạn mục tiêu), còn $[l,r]$ vẫn là đoạn của nút hiện tại. Vì sao cần đánh dấu đoạn mục tiêu? Vì đó là **cơ sở để phán đoán đáp án nằm ở bên trái hay bên phải**.

![](./images/dividing-2.svg)

???+ note "Cài đặt"
    ```pascal
    function Query(left,right,k,l,r,deep:longint):longint;
    var
      mid,x,y,cnt,rx,ry:longint;
    begin
      if left=right then // viết là l=r cũng được, vì đoạn mục tiêu chắc chắn có đáp án
        exit(tree[deep,left]);
      mid:=(l+r) >> 1;
      x:=toleft[deep,left-1]-toleft[deep,l-1]; // số phần tử từ l đến left đi vào con trái
      y:=toleft[deep,right]-toleft[deep,l-1]; // số phần tử từ l đến right đi vào con trái
      ry:=right-l-y; rx:=left-l-x; // ry là số phần tử từ l đến right đi vào con phải, rx là số phần tử từ l đến left đi vào con phải
      cnt:=y-x; // số phần tử từ left đến right đi vào con trái
      if cnt>=k then // kiến thức cơ bản của cây phân đoạn bền vững
        Query:=Query(l+x,l+y-1,k,l,mid,deep+1) // l+x là biên trái sau khi thu hẹp, l+y-1 là biên phải sau khi thu hẹp. Với hình trên, tức là bỏ các nút 1 và 2.
      else
        Query:=Query(mid+rx+1,mid+ry+1,k-cnt,mid+1,r,deep+1); // cũng là thu hẹp đoạn, chỉ khác là chuyển sang bên phải. Chú ý cần trừ cnt khỏi k.
    end;
    ```

## Tính chất

Độ phức tạp thời gian: một lần truy vấn chỉ cần $O(\log n)$, nên $m$ truy vấn cần $O(m\log n)$.

Độ phức tạp không gian: chỉ cần lưu $O(n\log n)$ số.

Kết quả đo thử: cây phân đoạn bền vững: $1482 \text{ms}$, cây phân hoạch: $889 \text{ms}$. (Bản không đệ quy, hằng số khá nhỏ.)

## Ứng dụng của cây phân hoạch

Bài ví dụ: [Luogu P3157\[CQOI2011\] Cặp nghịch thế động](https://www.luogu.com.cn/problem/P3157)

> Tóm tắt đề bài: cho một hoán vị gồm $n$ phần tử ($n\leq 10^5$), có $m$ truy vấn ($m\leq 5\times 10^4$). Mỗi lần xóa một số trong hoán vị, hãy tính số cặp nghịch thế của hoán vị sau khi xóa số đó.

Bài này có thể được giải bằng CDQ trong thời gian $\Theta(n\log^2n)$ và không gian $\Theta(n)$, hơn nữa hằng số của CDQ cũng rất tốt.

Nếu bài này được đổi thành bắt buộc online, cách thường dùng là cây Fenwick + cây phân đoạn bền vững theo dạng cây lồng cây. Độ phức tạp thời gian là $\Theta(n\log^2n)$, độ phức tạp không gian là $\Theta(n\log^2n)$, hằng số hơi lớn nhưng vẫn có thể qua bài này.

Còn nếu dùng cây phân hoạch, ta có thể giải online bài này trong thời gian $\Theta(n\log^2n)$ và không gian $\Theta(n\log n)$; đồng thời hằng số cũng nhỏ hơn rất nhiều so với cách cây lồng cây. (Xấp xỉ với CDQ.)

???+ warning "Lưu ý"
    Để thuận tiện khi cài đặt, bài viết này chia mảng lớn thành hai mảng nhỏ theo vị trí giữa. Nói cách khác, cây phân hoạch trong phần dưới tương đương với quá trình của merge sort, chứ không phải quá trình của quicksort. Mảng lớn ở tầng trên cùng là mảng đã sắp xếp, còn tầng dưới cùng là mảng ban đầu.

Với mỗi nút trong cây phân hoạch, ta gọi nó là nút phải khi và chỉ khi ở tầng tiếp theo nó sẽ được phân vào con phải, tức là những số có vị trí tương đối về sau trong mảng ban đầu; nút trái được định nghĩa tương tự. Nếu trong quá trình xây cây ta sắp xếp tầng trên cùng, tương tự cách merge sort tính số cặp nghịch thế, có thể thấy số cặp nghịch thế của một mảng chính là tổng số nút phải đứng trước mỗi nút trái.

Tiếp theo xét thao tác xóa. Khi xóa một nút trái, số cặp nghịch thế của toàn bộ mảng sẽ giảm đi số nút phải đứng trước nó; khi xóa một nút phải, số cặp nghịch thế sẽ giảm đi số nút trái đứng sau nó. Vì vậy, ta có thể động duy trì "số nút phải đứng trước mỗi nút trái" và "số nút trái đứng sau mỗi nút phải". Việc này có thể được duy trì đơn giản bằng cây Fenwick.

Cần chú ý rằng khi dùng cây Fenwick để duy trì, ta chỉ được tính đóng góp trong cùng một khối của cây phân hoạch, không được nhảy ra ngoài khối. Với cây Fenwick, có một cách xử lý khá khéo léo cho việc này.

Xét rằng phạm vi chỉ số của mỗi khối trên cây phân hoạch chắc chắn có dạng $[c\times 2^k+1,(c+1)\times 2^k]$, liệt kê như sau (vì mã nguồn không xử lý tầng dưới cùng của cây phân hoạch, nên chỉ liệt kê đến tầng áp chót):

    [0001 0010] [0011 0100] [0101 0110] [0111 1000] [1001 1010] [1011 1100] [1101 1110] [1111 10000]  lev=1
    [0001 0010 0011 0100]   [0101 0110 0111 1000]   [1001 1010 1011 1100]   [1101 1110 1111 10000]    lev=2
    [0001 0010 0011 0100 0101 0110 0111 1000]       [1001 1010 1011 1100 1101 1110 1111 10000]        lev=3
    [0001 0010 0011 0100 0101 0110 0111 1000 1001 1010 1011 1100 1101 1110 1111 10000]                lev=4

Nhắc lại nguyên lý của cây Fenwick: khi nhảy lên, mỗi lần ta thực hiện `x += lowbit(x)`. Nếu khi nhảy lên ta bảo đảm không nhảy ra khỏi khối, thì có thể bảo đảm chỉ ảnh hưởng đến giá trị của các phần tử trong khối. Truy vấn theo hướng lên cũng tương tự.

Để vừa nhảy lên vừa bảo đảm không ra khỏi khối, chỉ cần bảo đảm tại thời điểm nhảy có $lowbit(x)<2^{lev}$.

Còn nhảy xuống là một cách xử lý hoàn toàn khác. Nếu dùng chỉ số 0-index, phạm vi chỉ số của mỗi khối có dạng $[c\times 2^k,(c+1)\times 2^k)$. Do đó, chỉ cần dịch phải giá trị của một chỉ số đi k bit là có thể biết nó thuộc khối nào. Khi nhảy xuống, ta chỉ cần liên tục kiểm tra xem có nhảy ra khỏi khối hay không.

Cần chú ý rằng cây Fenwick được cài đặt theo cách này sẽ truy cập tới chỉ số lớn nhất là lũy thừa của 2 gần $n$ nhất, vì vậy không thể chỉ cấp phát mảng đến chỉ số $n$.

Vì cần sửa đổi trên $\log n$ tầng, và độ phức tạp khi sửa đổi ở tầng thứ $k$ là $\Theta(k)$, độ phức tạp cuối cùng là $\Theta(n\log n+m\log^2n)$.

Mã nguồn:

```cpp
--8<-- "docs/ds/code/dividing/dividing_1.cpp"
```

## Ghi chú cuối

Bài viết tham khảo: [liên kết](https://blog.csdn.net/littlewhite520/article/details/70250722).
