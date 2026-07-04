author: leoleoasd, yzxoi, Estrella-Explore

Trang này giới thiệu ngắn gọn về dạng bài xây dựng.

## Mở đầu

Bài xây dựng là một dạng bài thường gặp trong các cuộc thi.

Xét về hình thức, đáp án của bài thường có một quy luật nào đó, nhờ vậy khi
kích thước bài toán tăng nhanh, ta vẫn có cơ hội tìm được đáp án tương đối dễ.

Điều này đòi hỏi khi giải bài phải suy nghĩ xem việc tăng kích thước bài toán
ảnh hưởng đến đáp án như thế nào, và ảnh hưởng đó có thể tổng quát hóa hay
không. Chẳng hạn khi thiết kế quy hoạch động, ta phải xét việc chuyển từ một
trạng thái sang trạng thái kế tiếp gây ra tác động gì.

## Đặc điểm

Một đặc điểm rất rõ của bài xây dựng là độ tự do cao. Nói cách khác, một bài
có thể có nhiều cách xây dựng, nhưng thường tồn tại một cách tương đối đơn
giản thỏa mãn đề bài. Thoạt nhìn yêu cầu có vẻ được nới lỏng và bài trở nên dễ
hơn, nhưng nhiều khi chính độ tự do cao này làm bài không có hướng đi rõ ràng
và khiến ta khó bắt đầu.

Một đặc điểm khác là hình thức linh hoạt và biến hóa đa dạng. Không có một lời
giải tổng quát hay khuôn mẫu nào giải được mọi bài xây dựng; thậm chí rất khó
tìm ra điểm chung trong tư duy giải.

## Bài ví dụ

Dưới đây là một số bài ví dụ giúp người đọc cảm nhận tư tưởng của dạng bài xây
dựng và gợi mở hướng suy nghĩ. Bạn nên suy nghĩ kỹ trước khi xem lời giải.
Chúng tôi cũng hoan nghênh mọi người chia sẻ thêm những bài xây dựng thú vị.

### Bài ví dụ 1

???+ note "[Codeforces Round #384 (Div. 2) C. Vladik and fractions](http://codeforces.com/problemset/problem/743/C)"
    Hãy xây dựng một bộ $x,y,z$ sao cho với $n$ cho trước, ta có
    $\dfrac{1}{x}+\dfrac{1}{y}+\dfrac{1}{z}=\dfrac{2}{n}$.

??? note "Ý tưởng giải"
    Từ ví dụ thứ hai có thể nhìn ra cách xây dựng của bài này.

    Rõ ràng $n,n+1,n(n+1)$ là một bộ nghiệm hợp lệ. Trường hợp đặc biệt
    $n=1$ thì vô nghiệm, vì khi đó $n+1$ và $n(n+1)$ bằng nhau.

    Còn việc nghĩ ra cách xây dựng này có lẽ đến từ quan sát ví dụ cộng với
    một chút cảm giác số học. Bài này không khó với người có trực giác toán tốt.

### Bài ví dụ 2

???+ note "[Luogu P3599 Koishi Loves Construction](https://www.luogu.com.cn/problem/P3599)"
    Task 1: Hãy xét xem có thể xây dựng một hoán vị độ dài $n$ của
    $1\dots n$ sao cho $n$ tổng tiền tố của nó đôi một khác nhau modulo $n$
    hay không, và nếu có thì xây dựng.

    Task 2: Hãy xét xem có thể xây dựng một hoán vị độ dài $n$ của
    $1\dots n$ sao cho $n$ tích tiền tố của nó đôi một khác nhau modulo $n$
    hay không, và nếu có thì xây dựng.

??? note "Ý tưởng giải"
    Với task 1:

    Khi $n$ là số lẻ, không thể xây dựng nghiệm hợp lệ.

    Khi $n$ là số chẵn, có thể xây dựng một dãy dạng
    $n,1,n-2,3,\cdots$.

    Trước hết, ta thấy $n$ bắt buộc phải xuất hiện ở vị trí đầu tiên của dãy.
    Nếu không, hai tổng tiền tố trước và sau khi $n$ xuất hiện chắc chắn sẽ
    bằng nhau theo modulo.

    Sau đó xét cách xây dựng toàn bộ dãy:

    Hãy thử xây dựng dãy tổng tiền tố rồi suy ra dãy ban đầu. Ta nhận thấy
    hiệu giữa hai tổng tiền tố bất kỳ không được bằng nhau theo modulo, vì dãy
    sai phân của dãy tổng tiền tố tương ứng với hoán vị ban đầu.

    Vì vậy ta thử xây dựng dãy tổng tiền tố theo modulo dưới dạng

    $$
    0,1,-1,2,-2,\cdots
    $$

    Không khó để thấy dạng này thỏa mãn hoàn hảo mọi ràng buộc.

    Với task 2:

    Khi $n$ là hợp số khác $4$, không thể xây dựng nghiệm hợp lệ.

    Khi $n$ là số nguyên tố hoặc $4$, có thể xây dựng một dãy dạng
    $1,\dfrac{2}{1},\dfrac{3}{2},\cdots,\dfrac{n-1}{n-2},n$.

    Trước hết xét khi nào có nghiệm:

    Rõ ràng khi $n$ là hợp số thì vô nghiệm. Với một hợp số, tồn tại hai số
    nhỏ hơn nó là $p,q$ sao cho $p\times q \equiv 0 \pmod n$, ví dụ
    $(3\times6)\%9=0$. Khi cả $p$ và $q$ đều đã xuất hiện, mọi tích tiền tố
    phía sau sẽ luôn bằng $0$, nên hợp số là vô nghiệm. Riêng $4=2\times2$,
    không tồn tại $p,q$ thỏa điều kiện trên theo cách này, vì vậy vẫn có nghiệm
    hợp lệ.

    Tiếp theo xét cách xây dựng dãy:

    Tương tự task 1, ta thấy $1$ bắt buộc phải xuất hiện ở vị trí đầu tiên,
    nếu không hai tích tiền tố trước và sau khi $1$ xuất hiện sẽ bằng nhau.
    Còn $n$ bắt buộc phải xuất hiện ở vị trí cuối cùng, vì sau vị trí xuất hiện
    của $n$, mọi tích tiền tố theo modulo đều bằng $0$. Sau khi phân tích vài
    ví dụ trong đề, ta thấy mọi ví dụ đều có một nghiệm hợp lệ sao cho dãy tích
    tiền tố theo modulo là $1,2,3,\cdots,n$. Vì vậy có thể xây dựng dãy đã nêu
    ở trên để thỏa điều kiện này. Khi đó chỉ cần chứng minh $n$ số này đôi một
    khác nhau.

    Ta nhận thấy các số đó đều là nghịch đảo của $1\cdots n-2$ cộng thêm $1$,
    nên chúng đôi một khác nhau. Bài toán được giải.

### Bài ví dụ 3

???+ note "[AtCoder Grand Contest 032 B](https://atcoder.jp/contests/agc032/tasks/agc032_b)"
    Cho một số nguyên $N$, hãy xây dựng một đồ thị vô hướng có $N$ đỉnh. Đánh
    số các đỉnh là $1\ldots N$, và yêu cầu đồ thị thỏa mãn:

    -   Đây là một đồ thị đơn liên thông.
    -   Tồn tại một số nguyên $S$ sao cho với mọi đỉnh, tổng chỉ số của các
        đỉnh kề với nó bằng $S$.

    Dữ liệu bảo đảm có nghiệm.

??? note "Ý tưởng giải"
    Bằng cách phân tích các trường hợp $n=3,4,5$, ta có thể tìm ra một cách
    xây dựng.

    Hãy xây dựng một đồ thị $k$-phần đầy đủ, sao cho tổng chỉ số trong mỗi phần
    bằng nhau. Khi đó $S$ của mỗi đỉnh đều bằng
    $\dfrac{(k-1)\sum_{i=1}^{n}i}{k}$.

    Nếu $n$ chẵn, ta ghép các số đầu-cuối thành từng cặp:
    $\{1,n\},\{2,n-1\}\cdots$.

    Nếu $n$ lẻ, ta tách riêng $n$ thành một nhóm, rồi ghép cặp $n-1$ số còn
    lại: $\{n\},\{1,n-1\},\{2,n-2\}\cdots$.

    Đồ thị xây dựng theo cách này dễ chứng minh là liên thông khi $n\ge 3$,
    nên không trình bày thêm ở đây.

    Bài toán được giải.

### Bài ví dụ 4

???+ note "[BZOJ 4971「Lydsy1708 月赛」记忆中的背包](https://vjudge.net/problem/BZOJ-4971)"
    Sau một ngày làm việc vất vả, Tiểu Q chìm vào giấc ngủ. Trong đầu cậu hiện
    lên cảnh vừa vào đại học và học bài 01 knapsack. Khi đó, còn là tân sinh
    viên năm nhất, Tiểu Q đã giải một bài 01 knapsack đơn giản. Bài toán như
    sau:

    Cho $n$ đồ vật, thể tích của từng đồ vật lần lượt là $v_1,v_2,\ldots,v_n$.
    Hãy tính số cách chọn một số đồ vật, cũng có thể không chọn đồ vật nào, sao
    cho tổng thể tích đúng bằng $w$. Vì đáp án có thể rất lớn, chỉ cần in đáp
    án modulo $P$.

    Do thức khuya luyện bài lâu ngày, cậu chỉ nhìn thấy trong input mẫu có $w$
    và $P$, output mẫu là $k$, còn không nhìn rõ có bao nhiêu đồ vật và thể
    tích từng đồ vật là bao nhiêu. Đến khi tỉnh dậy, Tiểu Q vẫn không nhớ được
    $n$ và $v$. Hãy viết chương trình giúp Tiểu Q nhớ lại input mẫu năm xưa.

??? note "Ý tưởng giải"
    Đây là một trong những bài xây dựng có độ tự do cao nhất. Chính điều đó làm
    ta dễ rơi vào tình trạng không có manh mối và khó bắt đầu.

    Trước hết, không khó nhận ra modulo là giả. Vì ta được tự do xây dựng dữ
    liệu, ta luôn có thể khiến số cách không vượt quá modulo.

    Bằng một cách nghĩ khá lạ, ta có thể xây dựng $n$ đồ vật nhỏ có chi phí
    $1$ và một vài đồ vật lớn có chi phí lớn hơn $\dfrac{w}{2}$.

    Vì mỗi đồ vật lớn chỉ có thể chọn nhiều nhất một cái, nên một đồ vật lớn có
    chi phí $x$ đóng góp $\dbinom{n}{w-x}$ vào số cách.

    Gọi $f_{i,j}$ là số đồ vật lớn ít nhất cần dùng khi có $i$ đồ vật chi phí
    $1$ và số cách là $j$.

    Dùng DP để tiền xử lý $f$. Tính toán cho thấy chỉ cần tiền xử lý mọi giá
    trị với $i\le 20$ là đủ.

    Bài toán được giải.
