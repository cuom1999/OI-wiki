author: hyp1231, 383494

## Mở đầu

Phép nghịch đảo phù hợp với những bài toán có nhiều quan hệ tiếp xúc giữa các đường tròn hoặc đường thẳng. Tận dụng các tính chất của phép nghịch đảo để giải bài toán trong không gian nghịch đảo có thể đơn giản hóa phép tính đáng kể.

## Định nghĩa

Cho tâm nghịch đảo $O$ và bán kính nghịch đảo $R$. Nếu hai điểm $P$ và $P'$ trên mặt phẳng thỏa mãn:

-   Điểm $P'$ nằm trên tia $\overrightarrow{OP}$
-   $|OP| \cdot |OP'| = R^2$

thì gọi $P$ và $P'$ là hai điểm nghịch đảo của nhau.

## Giải thích

Hình dưới đây minh họa phép nghịch đảo của một điểm $P$ trên mặt phẳng:

![Nghịch đảo 1](./images/inverse1.png)

## Tính chất

1.  Điểm ở ngoài đường tròn $O$ có điểm nghịch đảo nằm trong đường tròn $O$, và ngược lại; điểm nằm trên đường tròn $O$ có điểm nghịch đảo là chính nó.

2.  Một đường tròn $A$ không đi qua điểm $O$ có ảnh nghịch đảo cũng là một đường tròn không đi qua điểm $O$.

    ![Nghịch đảo 2](./images/inverse2.png)

    -   Gọi bán kính của đường tròn $A$ là $r_1$, bán kính của đường tròn ảnh nghịch đảo $B$ là $r_2$, có:

        $$
        r_2 = \frac{1}{2}\left(\frac{1}{|OA| - r_1} - \frac{1}{|OA| + r_1}\right) R^2
        $$

    ???+ note "Chứng minh"
        ![Nghịch đảo 3](./images/inverse3.png)
        
        Theo định nghĩa của phép nghịch đảo:
        
        $$
        \begin{aligned}
        |OC|\cdot|OC'| &= (|OA|+r_1)\cdot(|OB|-r_2) = R^2 \\
        |OD|\cdot|OD'| &= (|OA|-r_1)\cdot(|OB|+r_2) = R^2
        \end{aligned}
        $$
        
        Khử $|OB|$ rồi giải phương trình là được.

    -   Gọi tọa độ của điểm $O$ là $(x_0, y_0)$, tọa độ của điểm $A$ là $(x_1, y_1)$, tọa độ của điểm $B$ là $(x_2, y_2)$, có:

        $$
        \begin{aligned}
        x_2 &= x_0 + \frac{|OB|}{|OA|} (x_1 - x_0) \\
        y_2 &= y_0 + \frac{|OB|}{|OA|} (y_1 - y_0)
        \end{aligned}
        $$

        Trong đó $|OB|$ có thể được tính trong quá trình tính $r_2$ ở trên.

3.  Một đường tròn $A$ đi qua điểm $O$ có ảnh nghịch đảo là một đường thẳng không đi qua điểm $O$. Lý do là một điểm trên đường tròn $A$ tiến gần vô hạn tới $O$ sẽ có điểm nghịch đảo cách $O$ vô hạn.

    ![Nghịch đảo 4](./images/inverse4.png)

4.  Nếu hai hình tiếp xúc nhau và điểm tiếp xúc không phải là điểm $O$, thì các ảnh nghịch đảo của chúng cũng tiếp xúc nhau.

## Ví dụ

### [ICPC 2013 Hangzhou Regional - Problem of Apollonius](https://acm.hdu.edu.cn/showproblem.php?pid=4773)

#### Tóm tắt đề bài

Tìm tất cả các đường tròn đi qua một điểm nằm ngoài hai đường tròn đã cho và tiếp xúc với cả hai đường tròn đó.

#### Cách giải

Trước hết nếu xét cách giải bằng hình học giải tích, bài toán có vẻ rất khó giải.

Xét phép nghịch đảo với tâm là điểm mà đường tròn cần tìm phải đi qua, bán kính nghịch đảo tùy ý. Ảnh nghịch đảo của đường tròn cần tìm là một đường thẳng, theo tính chất $3$, và nó tiếp xúc với ảnh nghịch đảo của hai đường tròn đã cho, theo tính chất $2$ và tính chất $4$.

Do đó sau phép nghịch đảo, bài toán trở thành: tìm tất cả các tiếp tuyến chung của hai đường tròn.

Sau khi tìm được các tiếp tuyến chung, lấy ảnh nghịch đảo trở lại mặt phẳng ban đầu là được.

??? note "Mã ví dụ"
    ```cpp
    #include <algorithm>
    #include <cmath>
    #include <cstdio>
    #include <cstring>
    #include <iostream>
    #include <vector>
    using namespace std;
    
    constexpr double EPS = 1e-8;   // Hệ số sai số
    const double PI = acos(-1.0);  // pi
    constexpr int N = 4;
    
    // Định nghĩa điểm
    struct Point {
      double x, y;
    
      Point(double x = 0, double y = 0) : x(x), y(y) {}
    
      bool operator<(Point A) const { return x == A.x ? y < A.y : x < A.x; }
    };
    
    // Định nghĩa vectơ
    using Vector = Point;
    
    // Cộng vectơ
    Vector operator+(Vector A, Vector B) { return Vector(A.x + B.x, A.y + B.y); }
    
    // Trừ vectơ
    Vector operator-(Vector A, Vector B) { return Vector(A.x - B.x, A.y - B.y); }
    
    // Nhân vectơ với số
    Vector operator*(Vector A, double p) { return Vector(A.x * p, A.y * p); }
    
    // Chia vectơ cho số
    Vector operator/(Vector A, double p) { return Vector(A.x / p, A.y / p); }
    
    // Quan hệ với 0
    int dcmp(double x) {
      if (fabs(x) < EPS) return 0;
      return x < 0 ? -1 : 1;
    }
    
    // Tích vô hướng của vectơ
    double Dot(Vector A, Vector B) { return A.x * B.x + A.y * B.y; }
    
    // Độ dài vectơ
    double Length(Vector A) { return sqrt(Dot(A, A)); }
    
    // Tích có hướng của vectơ
    double Cross(Vector A, Vector B) { return A.x * B.y - A.y * B.x; }
    
    // Hình chiếu của điểm lên đường thẳng
    Point GetLineProjection(Point P, Point A, Point B) {
      Vector v = B - A;
      return A + v * (Dot(v, P - A) / Dot(v, v));
    }
    
    // Đường tròn
    struct Circle {
      Point c;
      double r;
    
      Circle() : c(Point(0, 0)), r(0) {}
    
      Circle(Point c, double r = 0) : c(c), r(r) {}
    
      // Nhập góc cực và trả về tọa độ điểm
      Point point(double a) { return Point(c.x + cos(a) * r, c.y + sin(a) * r); }
    };
    
    // Tiếp tuyến chung của hai đường tròn. Trả về số tiếp tuyến, -1 nghĩa là vô số tiếp tuyến
    // a[i] và b[i] lần lượt là tiếp điểm của tiếp tuyến thứ i trên đường tròn A và B
    int getTangents(Circle A, Circle B, Point* a, Point* b) {
      int cnt = 0;
      if (A.r < B.r) {
        swap(A, B);
        swap(a, b);
      }
      double d2 =
          (A.c.x - B.c.x) * (A.c.x - B.c.x) + (A.c.y - B.c.y) * (A.c.y - B.c.y);
      double rdiff = A.r - B.r;
      double rsum = A.r + B.r;
      if (dcmp(d2 - rdiff * rdiff) < 0) return 0;  // Chứa trong
    
      double base = atan2(B.c.y - A.c.y, B.c.x - A.c.x);
      if (dcmp(d2) == 0 && dcmp(A.r - B.r) == 0) return -1;  // Vô số tiếp tuyến
      if (dcmp(d2 - rdiff * rdiff) == 0) {  // Tiếp xúc trong, một tiếp tuyến
        a[cnt] = A.point(base);
        b[cnt] = B.point(base);
        ++cnt;
        return 1;
      }
      // Có tiếp tuyến chung ngoài
      double ang = acos(rdiff / sqrt(d2));
      a[cnt] = A.point(base + ang);
      b[cnt] = B.point(base + ang);
      ++cnt;
      a[cnt] = A.point(base - ang);
      b[cnt] = B.point(base - ang);
      ++cnt;
      if (dcmp(d2 - rsum * rsum) == 0) {  // Một tiếp tuyến chung trong
        a[cnt] = A.point(base);
        b[cnt] = B.point(PI + base);
        ++cnt;
      } else if (dcmp(d2 - rsum * rsum) > 0) {  // Hai tiếp tuyến chung trong
        double ang = acos(rsum / sqrt(d2));
        a[cnt] = A.point(base + ang);
        b[cnt] = B.point(PI + base + ang);
        ++cnt;
        a[cnt] = A.point(base - ang);
        b[cnt] = B.point(PI + base - ang);
        ++cnt;
      }
      return cnt;
    }
    
    // Điểm O nằm ngoài đường tròn A, tìm đường tròn nghịch đảo B của A, R là bán kính nghịch đảo
    Circle Inversion_C2C(Point O, double R, Circle A) {
      double OA = Length(A.c - O);
      double RB = 0.5 * ((1 / (OA - A.r)) - (1 / (OA + A.r))) * R * R;
      double OB = OA * RB / A.r;
      double Bx = O.x + (A.c.x - O.x) * OB / OA;
      double By = O.y + (A.c.y - O.y) * OB / OA;
      return Circle(Point(Bx, By), RB);
    }
    
    // Nghịch đảo đường thẳng thành đường tròn B đi qua O, R là bán kính nghịch đảo
    Circle Inversion_L2C(Point O, double R, Point A, Vector v) {
      Point P = GetLineProjection(O, A, A + v);
      double d = Length(O - P);
      double RB = R * R / (2 * d);
      Vector VB = (P - O) / d * RB;
      return Circle(O + VB, RB);
    }
    
    // Trả về true nếu hai điểm A và B ở cùng phía của đường thẳng
    bool theSameSideOfLine(Point A, Point B, Point S, Vector v) {
      return dcmp(Cross(A - S, v)) * dcmp(Cross(B - S, v)) > 0;
    }
    
    int main() {
      int T;
      scanf("%d", &T);
      while (T--) {
        Circle A, B;
        Point P;
        scanf("%lf%lf%lf", &A.c.x, &A.c.y, &A.r);
        scanf("%lf%lf%lf", &B.c.x, &B.c.y, &B.r);
        scanf("%lf%lf", &P.x, &P.y);
        Circle NA = Inversion_C2C(P, 10, A);
        Circle NB = Inversion_C2C(P, 10, B);
        Point LA[N], LB[N];
        Circle ansC[N];
        int q = getTangents(NA, NB, LA, LB), ans = 0;
        for (int i = 0; i < q; ++i)
          if (theSameSideOfLine(NA.c, NB.c, LA[i], LB[i] - LA[i])) {
            if (!theSameSideOfLine(P, NA.c, LA[i], LB[i] - LA[i])) continue;
            ansC[ans++] = Inversion_L2C(P, 10, LA[i], LB[i] - LA[i]);
          }
        printf("%d\n", ans);
        for (int i = 0; i < ans; ++i) {
          printf("%.8f %.8f %.8f\n", ansC[i].c.x, ansC[i].c.y, ansC[i].r);
        }
      }
    
      return 0;
    }
    ```

## Bài tập

[ICPC 2017 Nanning Regional Online - Finding the Radius for an Inserted Circle](https://vjudge.net/problem/%E8%AE%A1%E8%92%9C%E5%AE%A2-A1283)

[CCPC 2017 Online - The Designer](https://acm.hdu.edu.cn/showproblem.php?pid=6158)

## Tài liệu tham khảo và đọc thêm

-   [Inversive geometry - Wikipedia](https://en.wikipedia.org/wiki/Inversive_geometry)

-   [Phép nghịch đảo của đường tròn - blog ACdreamers](https://blog.csdn.net/acdreamers/article/details/16966369)
