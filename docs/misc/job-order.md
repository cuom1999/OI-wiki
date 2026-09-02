Có $n$ công việc, và cần tìm một thứ tự thực hiện chúng sao cho chi phí nhỏ nhất. Công việc thứ $i$ mất thời gian $t_i$, còn nếu công việc thứ $i$ phải chờ trong thời gian $t$ thì phát sinh chi phí $f_i(t)$.

Nói một cách hình thức, cho $n$ hàm $f_i$ và $n$ số $t_i$, cần tìm một hoán vị $p$ sao cho tối thiểu hóa

$$
F(p)=\sum_{i=1}^nf_{p_i}\left(\sum_{j=1}^{i-1}t_{p_j}\right)
$$

## Các hàm chi phí đặc biệt

### Hàm chi phí tuyến tính

Trước hết, xét trường hợp tất cả các hàm đều là hàm tuyến tính, tức là $f_i(x)=c_ix+d_i$, trong đó $c_i$ là số nguyên không âm. Các hằng số có thể được cộng trước, nên hàm được chuyển về dạng $f_i(x)=c_ix$.

Xét hai hoán vị $p$ và $p'$, trong đó $p'$ là hoán vị thu được bằng cách đổi chỗ phần tử ở vị trí thứ $i$ và vị trí thứ $i+1$ của $p$. Khi đó

$$
\begin{aligned}
F(p')-F(p)&=c_{p'_i}\sum_{j=1}^{i-1}t_{p'_j}+c_{p'_{i+1}}\sum_{j=1}^{i}t_{p'_j}
-\left(c_{p_i}\sum_{j=1}^{i-1}t_{p_j}+c_{p_{i+1}}\sum_{j=1}^{i}t_{p_j}\right)\\
&=c_{p_i}t_{p_{i+1}}-c_{p_{i+1}}t_{p_i}
\end{aligned}
$$

Vì vậy, chỉ cần sắp xếp theo chiến lược: nếu $c_{p_i}t_{p_{i+1}}-c_{p_{i+1}}t_{p_i}<0$ thì đổi chỗ hai phần tử. Viết lại dưới dạng $\dfrac{c_{p_i}}{t_{p_i}}<\dfrac{c_{p_{i+1}}}{t_{p_{i+1}}}$, có thể hiểu là sắp xếp hoán vị theo thứ tự giảm dần của $\dfrac{c_i}{t_i}$.

Khi xử lý bài toán này, ý tưởng là xét sự thay đổi sau một nhiễu nhỏ, rồi chọn nghiệm tối ưu theo cách tham lam.

### Hàm chi phí mũ

Xét hàm chi phí có dạng $f_i(x)=c_i\mathrm{e}^{ax}$, trong đó $c_i\ge 0,a>0$.

Tiếp tục dùng ý tưởng trên, xét biến thiên chi phí khi đổi chỗ hai phần tử ở vị trí $i$ và $i+1$. Thuật toán cuối cùng là sắp xếp hoán vị theo thứ tự tăng dần của $\dfrac{1-\mathrm{e}^{at_i}}{c_i}$.

### Cùng một hàm tăng

Xét trường hợp mọi $f_i(x)$ đều là cùng một hàm tăng. Khi đó chỉ cần sắp xếp hoán vị theo thứ tự tăng dần của $t_i$.

## Định lý Livshits-Kladov

Định lý Livshits-Kladov đúng khi và chỉ khi hàm chi phí thuộc một trong ba trường hợp sau:

-   Hàm tuyến tính: $f_i(t) = c_it + d_i$, trong đó $c_i\ge 0$;
-   Hàm mũ: $f_i(t) = c_i \mathrm{e}^{a t} + d_i$, trong đó $c_i,a>0$;
-   Cùng một hàm tăng: $f_i(t) = \phi(t)$, trong đó $\phi(t)$ là một hàm tăng.

Định lý được chứng minh dưới giả thiết hàm chi phí đủ trơn, tức là có đạo hàm bậc ba. Trong cả ba trường hợp này, nghiệm tối ưu của bài toán có thể được tìm bằng một phép sắp xếp đơn giản trong thời gian $O(n\log n)$.

**Trang này chủ yếu được dịch từ bài viết [Задача Джонсона с одним станком](http://e-maxx.ru/algo/johnson_problem_1) và bản dịch tiếng Anh [Scheduling jobs on one machine](https://cp-algorithms.com/schedules/schedule_one_machine.html). Bản tiếng Nga được cấp phép theo Public Domain + Leave a Link; bản tiếng Anh được cấp phép theo CC-BY-SA 4.0.**
