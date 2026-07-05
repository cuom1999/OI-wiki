author: Ir1d, TianyiQ

## Mở đầu

Phương pháp tăng dần ngẫu nhiên là một thuật toán quan trọng trong hình học tính toán. Nó không đòi hỏi nhiều kiến thức lý thuyết, có độ phức tạp thời gian thấp và phạm vi ứng dụng rộng.

Ý tưởng của phương pháp tăng dần tương tự nguyên lý quy nạp toán học thứ nhất: bản chất là biến một bài toán thành bài toán con có quy mô nhỏ hơn đúng một mức. Sau khi giải bài toán con, ta thêm đối tượng hiện tại vào. Viết dưới dạng truy hồi:

$$
T(n)=T(n-1)+g(n)
$$

Phương pháp tăng dần có hình thức gọn gàng và có thể áp dụng cho nhiều bài toán hình học.

Phương pháp tăng dần thường được kết hợp với ngẫu nhiên hóa để tránh xuất hiện trường hợp xấu nhất.

## Bài toán đường tròn bao nhỏ nhất

### Mô tả bài toán

Trên một mặt phẳng có $n$ điểm, hãy tìm đường tròn có bán kính nhỏ nhất sao cho bao phủ được tất cả các điểm.

### Quy trình

Giả sử đường tròn $O$ là đường tròn bao nhỏ nhất của $i-1$ điểm đầu. Khi thêm điểm thứ $i$, nếu điểm này nằm trong đường tròn hoặc trên biên thì không cần làm gì. Ngược lại, đường tròn bao nhỏ nhất mới chắc chắn đi qua điểm thứ $i$.

Sau đó lấy điểm thứ $i$ làm cơ sở, bán kính bằng $0$, rồi lặp lại quá trình trên để lần lượt thêm điểm thứ $j$. Nếu điểm thứ $j$ nằm ngoài đường tròn, thì đường tròn bao nhỏ nhất chắc chắn đi qua điểm thứ $j$.

Lặp lại các bước trên. Vì nhiều nhất cần ba điểm để xác định đường tròn bao nhỏ nhất này, nên quá trình được lặp ba tầng.

Sau khi duyệt hết mọi điểm, đường tròn thu được chính là đường tròn bao nhỏ nhất bao phủ tất cả các điểm.

### Tính chất

**Độ phức tạp thời gian**  $O(n)$, chứng minh xem trong phần tài liệu tham khảo.

**Độ phức tạp không gian**  $O(n)$

### Cài đặt

??? note "Mã cài đặt"
    ```cpp
    #include <cmath>
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <iostream>
    
    using namespace std;
    
    int n;
    double r;
    
    struct point {
      double x, y;
    } p[100005], o;
    
    double sqr(double x) { return x * x; }
    
    double dis(point a, point b) { return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y)); }
    
    bool cmp(double a, double b) { return fabs(a - b) < 1e-8; }
    
    point geto(point a, point b, point c) {
      double a1, a2, b1, b2, c1, c2;
      point ans;
      a1 = 2 * (b.x - a.x), b1 = 2 * (b.y - a.y),
      c1 = sqr(b.x) - sqr(a.x) + sqr(b.y) - sqr(a.y);
      a2 = 2 * (c.x - a.x), b2 = 2 * (c.y - a.y),
      c2 = sqr(c.x) - sqr(a.x) + sqr(c.y) - sqr(a.y);
      if (cmp(a1, 0)) {
        ans.y = c1 / b1;
        ans.x = (c2 - ans.y * b2) / a2;
      } else if (cmp(b1, 0)) {
        ans.x = c1 / a1;
        ans.y = (c2 - ans.x * a2) / b2;
      } else {
        ans.x = (c2 * b1 - c1 * b2) / (a2 * b1 - a1 * b2);
        ans.y = (c2 * a1 - c1 * a2) / (b2 * a1 - b1 * a2);
      }
      return ans;
    }
    
    int main() {
      scanf("%d", &n);
      for (int i = 1; i <= n; i++) scanf("%lf%lf", &p[i].x, &p[i].y);
      for (int i = 1; i <= n; i++) swap(p[rand() % n + 1], p[rand() % n + 1]);
      o = p[1];
      for (int i = 1; i <= n; i++) {
        if (dis(o, p[i]) < r || cmp(dis(o, p[i]), r)) continue;
        o.x = (p[i].x + p[1].x) / 2;
        o.y = (p[i].y + p[1].y) / 2;
        r = dis(p[i], p[1]) / 2;
        for (int j = 2; j < i; j++) {
          if (dis(o, p[j]) < r || cmp(dis(o, p[j]), r)) continue;
          o.x = (p[i].x + p[j].x) / 2;
          o.y = (p[i].y + p[j].y) / 2;
          r = dis(p[i], p[j]) / 2;
          for (int k = 1; k < j; k++) {
            if (dis(o, p[k]) < r || cmp(dis(o, p[k]), r)) continue;
            o = geto(p[i], p[j], p[k]);
            r = dis(o, p[i]);
          }
        }
      }
      printf("%.10lf\n%.10lf %.10lf", r, o.x, o.y);
      return 0;
    }
    ```

## Bài tập

[Minimum Enclosing Circle](https://www.luogu.com.cn/problem/P1742)

[HNOI2012 Archery](https://www.luogu.com.cn/problem/P3222)

[CodeForces 442E](https://codeforces.com/problemset/problem/442/E)

## Tài liệu tham khảo và đọc thêm

[Phương pháp tăng dần ngẫu nhiên - Xie Yilun](https://github.com/hzwer/shareOI/blob/master/%E8%AE%A1%E7%AE%97%E5%87%A0%E4%BD%95/%E9%9A%8F%E6%9C%BA%E5%A2%9E%E9%87%8F%E7%AE%97%E6%B3%95_%E8%A7%A3%E8%BD%B6%E4%BC%A6.pdf)

<https://www.cnblogs.com/aininot260/p/9635757.html>

<https://www.cise.ufl.edu/~sitharam/COURSES/CG/kreveldnbhd.pdf>

<https://blog.csdn.net/u014609452/article/details/62039612>
