author: xehoth

Trong hình học, tam giác phân là việc chia nhỏ một đối tượng phẳng thành các tam giác; mở rộng ra, trong không gian nhiều chiều, đó là việc chia nhỏ đối tượng hình học thành các đơn hình.
Với một tập điểm cho trước, có nhiều cách tam giác phân, chẳng hạn:

![Ba cách tam giác phân](./images/triangulation-0.svg)

Trong OI, tam giác phân chủ yếu chỉ tam giác phân hoàn hảo trong hình học hai chiều, tức tam giác phân Delaunay hai chiều, viết tắt là DT.

## Tam giác phân Delaunay

### Định nghĩa

Trong toán học và hình học tính toán, với một tập điểm rời rạc $P$ trên mặt phẳng, tam giác phân Delaunay DT($P$) thỏa mãn:

1.  Tính vòng tròn rỗng: DT($P$) là **duy nhất** nếu không có bốn điểm bất kỳ cùng nằm trên một đường tròn. Trong DT($P$), bên trong đường tròn ngoại tiếp của **mọi** tam giác không có điểm nào khác.
2.  Tối đa hóa góc nhỏ nhất: trong các tam giác phân có thể tạo ra từ tập điểm $P$, tam giác có góc nhỏ nhất lớn nhất là tam giác phân DT($P$). Theo nghĩa này, DT($P$) là tam giác phân **gần đều nhất**. Cụ thể, với đường chéo của một tứ giác lồi được tạo bởi hai tam giác kề nhau, sau khi đổi sang đường chéo còn lại, góc nhỏ nhất trong hai tam giác sẽ không tăng thêm.

![Một tam giác phân Delaunay có hiển thị các đường tròn ngoại tiếp](./images/triangulation-1.png)

### Tính chất

1.  Gần nhất: các tam giác được tạo bởi ba điểm gần nhau nhất, và các đoạn thẳng, tức các cạnh tam giác, không cắt nhau.
2.  Duy nhất: dù bắt đầu xây dựng từ vị trí nào trong miền, kết quả cuối cùng vẫn giống nhau, với điều kiện không có bốn điểm bất kỳ trong tập điểm cùng nằm trên một đường tròn.
3.  Tối ưu: nếu có thể đổi đường chéo của tứ giác lồi tạo bởi hai tam giác kề nhau, thì góc nhỏ nhất trong sáu góc trong của hai tam giác sẽ không thay đổi theo hướng tốt hơn.
4.  Đều nhất: nếu sắp xếp tăng dần góc nhỏ nhất của từng tam giác trong một tam giác phân, thì dãy thu được từ tam giác phân Delaunay là lớn nhất theo thứ tự từ điển.
5.  Tính cục bộ: thêm, xóa hoặc di chuyển một đỉnh chỉ ảnh hưởng đến các tam giác lân cận.
6.  Có vỏ lồi: biên ngoài cùng của tam giác phân tạo thành vỏ của một đa giác lồi.

## Thuật toán chia để trị xây dựng DT

Có nhiều thuật toán xây dựng DT. Trong các thuật toán xây dựng có độ phức tạp $O(n \log n)$, chia để trị là cách dễ hiểu và dễ cài đặt nhất.

Bước đầu tiên của cách chia để trị xây dựng DT là sắp xếp tập điểm đã cho theo tọa độ $x$ **tăng dần**. Hình dưới đây là một tập điểm đã sắp xếp có kích thước $10$.

![Tập điểm kích thước 10 đã được sắp xếp](./images/triangulation-2.svg)

Khi tập điểm đã có thứ tự, tiến hành chia liên tục thành hai phần, tức chia để trị, cho đến khi kích thước mỗi tập con không vượt quá $3$. Khi đó các tập con này có thể được tam giác phân ngay thành một tam giác hoặc một đoạn thẳng.

![Chia để trị thành các tập điểm gồm 2 hoặc 3 điểm](./images/triangulation-3.svg)

Sau đó, trong quá trình quay lui của chia để trị, các tập điểm con bên trái và bên phải đã được tam giác phân sẽ lần lượt được hợp nhất. Kết quả sau khi hợp nhất chứa cạnh LL, tức cạnh của tập điểm con bên trái, cạnh RR, tức cạnh của tập điểm con bên phải, và cạnh LR, tức cạnh mới nối hai tam giác phân trái phải. Trong hình, cạnh LL có màu xám, cạnh RR có màu đỏ, cạnh LR có màu xanh. Với tam giác phân sau khi hợp nhất, để duy trì tính chất DT, **có thể** cần xóa một số cạnh LL và cạnh RR, nhưng khi hợp nhất **không** thêm cạnh LL hay cạnh RR mới.

![Cạnh](./images/triangulation-4.svg)

Bước đầu tiên khi hợp nhất hai tam giác phân trái phải là chèn cạnh LR cơ sở. Cạnh LR cơ sở là cạnh LR ở **dưới cùng** và không cắt **bất kỳ** cạnh LL hay cạnh RR nào.

![Hợp nhất hai tam giác phân trái phải](./images/triangulation-5.svg)

Tiếp theo, cần xác định cạnh LR **ngay phía trên** cạnh LR cơ sở. Ví dụ, với tập điểm bên phải, các đỉnh có thể làm đầu mút tiếp theo của cạnh LR, tức đầu mút phải, là đầu mút còn lại của các cạnh RR nối với đầu mút phải của cạnh LR cơ sở, tương ứng các điểm số $6, 7, 9$; đầu mút trái là điểm số $2$.

![Cạnh LR tiếp theo](./images/triangulation-6.svg)

Với các đầu mút ứng viên, cần kiểm tra theo hai tiêu chí sau:

1.  Góc giữa cạnh RR tương ứng và cạnh LR cơ sở nhỏ hơn $180$ độ.
2.  Đường tròn đi qua hai đầu mút của cạnh LR cơ sở và điểm ứng viên đó không chứa bất kỳ **điểm ứng viên** nào khác.

![Kiểm tra điểm ứng viên](./images/triangulation-7.svg)

Như trong hình trên, đường tròn màu xanh lục ứng với điểm ứng viên số $6$ chứa điểm ứng viên số $9$, còn đường tròn màu tím ứng với điểm ứng viên số $7$ không chứa điểm ứng viên nào khác, vì vậy điểm số $7$ là đầu mút phải của cạnh LR tiếp theo.

Với tập điểm bên trái, quá trình xử lý là đối xứng.

![Kiểm tra điểm ứng viên bên trái](./images/triangulation-8.svg)

Khi cả hai tập điểm trái và phải đều không còn điểm ứng viên nào thỏa tiêu chí, quá trình hợp nhất hoàn tất. Khi một điểm ứng viên thỏa tiêu chí, cần thêm một cạnh LR; các cạnh LL và cạnh RR cắt cạnh LR cần thêm này sẽ bị xóa.

Khi cả hai tập điểm trái và phải đều có điểm ứng viên, cần kiểm tra đường tròn ứng với điểm bên trái có chứa điểm bên phải hay không; nếu có thì điểm bên trái không hợp lệ. Với điểm bên phải cũng kiểm tra tương tự. Thông thường chỉ có một điểm ứng viên thỏa tiêu chí, trừ khi bốn điểm cùng nằm trên một đường tròn.

![Cạnh LR tiếp theo](./images/triangulation-9.svg)

Sau khi cạnh LR này được thêm, lấy nó làm cạnh LR cơ sở rồi lặp lại các bước trên, tiếp tục thêm cạnh tiếp theo cho đến khi hợp nhất xong.

![Hợp nhất](./images/triangulation-10.svg)

## Mã nguồn

??? note "Cài đặt"
    ```cpp
    #include <algorithm>
    #include <cmath>
    #include <cstring>
    #include <list>
    #include <utility>
    #include <vector>
    
    constexpr double EPS = 1e-8;
    constexpr int MAXV = 10000;
    
    struct Point {
      double x, y;
      int id;
    
      Point(double a = 0, double b = 0, int c = -1) : x(a), y(b), id(c) {}
    
      bool operator<(const Point &a) const {
        return x < a.x || (fabs(x - a.x) < EPS && y < a.y);
      }
    
      bool operator==(const Point &a) const {
        return fabs(x - a.x) < EPS && fabs(y - a.y) < EPS;
      }
    
      double dist2(const Point &b) {
        return (x - b.x) * (x - b.x) + (y - b.y) * (y - b.y);
      }
    };
    
    struct Point3D {
      double x, y, z;
    
      Point3D(double a = 0, double b = 0, double c = 0) : x(a), y(b), z(c) {}
    
      Point3D(const Point &p) { x = p.x, y = p.y, z = p.x * p.x + p.y * p.y; }
    
      Point3D operator-(const Point3D &a) const {
        return Point3D(x - a.x, y - a.y, z - a.z);
      }
    
      double dot(const Point3D &a) { return x * a.x + y * a.y + z * a.z; }
    };
    
    struct Edge {
      int id;
      std::list<Edge>::iterator c;
    
      Edge(int id = 0) { this->id = id; }
    };
    
    int cmp(double v) { return fabs(v) > EPS ? (v > 0 ? 1 : -1) : 0; }
    
    double cross(const Point &o, const Point &a, const Point &b) {
      return (a.x - o.x) * (b.y - o.y) - (a.y - o.y) * (b.x - o.x);
    }
    
    Point3D cross(const Point3D &a, const Point3D &b) {
      return Point3D(a.y * b.z - a.z * b.y, -a.x * b.z + a.z * b.x,
                     a.x * b.y - a.y * b.x);
    }
    
    int inCircle(const Point &a, Point b, Point c, const Point &p) {
      if (cross(a, b, c) < 0) std::swap(b, c);
      Point3D a3(a), b3(b), c3(c), p3(p);
      b3 = b3 - a3, c3 = c3 - a3, p3 = p3 - a3;
      Point3D f = cross(b3, c3);
      return cmp(p3.dot(f));  // Kiểm tra cùng hướng, trong: < 0, trên: = 0, ngoài: > 0
    }
    
    int intersection(const Point &a, const Point &b, const Point &c,
                     const Point &d) {  // seg(a, b) và seg(c, d)
      return cmp(cross(a, c, b)) * cmp(cross(a, b, d)) > 0 &&
             cmp(cross(c, a, d)) * cmp(cross(c, d, b)) > 0;
    }
    
    class Delaunay {
     public:
      std::list<Edge> head[MAXV];  // đồ thị
      Point p[MAXV];
      int n, rename[MAXV];
    
      void init(int n, Point p[]) {
        memcpy(this->p, p, sizeof(Point) * n);
        std::sort(this->p, this->p + n);
        for (int i = 0; i < n; i++) rename[p[i].id] = i;
        this->n = n;
        divide(0, n - 1);
      }
    
      void addEdge(int u, int v) {
        head[u].push_front(Edge(v));
        head[v].push_front(Edge(u));
        head[u].begin()->c = head[v].begin();
        head[v].begin()->c = head[u].begin();
      }
    
      void divide(int l, int r) {
        if (r - l <= 2) {  // số điểm <= 3
          for (int i = l; i <= r; i++)
            for (int j = i + 1; j <= r; j++) addEdge(i, j);
          return;
        }
        int mid = (l + r) / 2;
        divide(l, mid);
        divide(mid + 1, r);
    
        std::list<Edge>::iterator it;
        int nowl = l, nowr = r;
    
        for (int update = 1; update;) {
          // Tìm tiếp tuyến chung dưới của hai bao lồi trái và phải.
          update = 0;
          Point ptL = p[nowl], ptR = p[nowr];
          for (it = head[nowl].begin(); it != head[nowl].end(); it++) {
            Point t = p[it->id];
            double v = cross(ptR, ptL, t);
            if (cmp(v) > 0 || (cmp(v) == 0 && ptR.dist2(t) < ptR.dist2(ptL))) {
              nowl = it->id, update = 1;
              break;
            }
          }
          if (update) continue;
          for (it = head[nowr].begin(); it != head[nowr].end(); it++) {
            Point t = p[it->id];
            double v = cross(ptL, ptR, t);
            if (cmp(v) < 0 || (cmp(v) == 0 && ptL.dist2(t) < ptL.dist2(ptR))) {
              nowr = it->id, update = 1;
              break;
            }
          }
        }
    
        addEdge(nowl, nowr);  // thêm tiếp tuyến
    
        for (int update = 1; true;) {
          update = 0;
          Point ptL = p[nowl], ptR = p[nowr];
          int ch = -1, side = 0;
          for (it = head[nowl].begin(); it != head[nowl].end(); it++) {
            if (cmp(cross(ptL, ptR, p[it->id])) > 0 &&
                (ch == -1 || inCircle(ptL, ptR, p[ch], p[it->id]) < 0)) {
              ch = it->id, side = -1;
            }
          }
          for (it = head[nowr].begin(); it != head[nowr].end(); it++) {
            if (cmp(cross(ptR, p[it->id], ptL)) > 0 &&
                (ch == -1 || inCircle(ptL, ptR, p[ch], p[it->id]) < 0)) {
              ch = it->id, side = 1;
            }
          }
          if (ch == -1) break;  // tiếp tuyến chung trên
          if (side == -1) {
            for (it = head[nowl].begin(); it != head[nowl].end();) {
              if (intersection(ptL, p[it->id], ptR, p[ch])) {
                head[it->id].erase(it->c);
                head[nowl].erase(it++);
              } else {
                it++;
              }
            }
            nowl = ch;
            addEdge(nowl, nowr);
          } else {
            for (it = head[nowr].begin(); it != head[nowr].end();) {
              if (intersection(ptR, p[it->id], ptL, p[ch])) {
                head[it->id].erase(it->c);
                head[nowr].erase(it++);
              } else {
                it++;
              }
            }
            nowr = ch;
            addEdge(nowl, nowr);
          }
        }
      }
    
      std::vector<std::pair<int, int>> getEdge() {
        std::vector<std::pair<int, int>> ret;
        ret.reserve(n);
        std::list<Edge>::iterator it;
        for (int i = 0; i < n; i++) {
          for (it = head[i].begin(); it != head[i].end(); it++) {
            if (it->id < i) continue;
            ret.push_back(std::make_pair(p[i].id, p[it->id].id));
          }
        }
        return ret;
      }
    };
    ```

## Biểu đồ Voronoi

Biểu đồ Voronoi gồm các đa giác liên tiếp được tạo bởi các đường trung trực của đoạn nối hai điểm lân cận. Với $n$ điểm sinh không trùng nhau trên mặt phẳng, nó chia mặt phẳng thành $n$ miền sao cho mọi điểm trong một miền gần điểm sinh của miền đó hơn so với các điểm sinh thuộc miền khác.

Biểu đồ Voronoi là đồ thị đối ngẫu của tam giác phân Delaunay. Có thể dùng thuật toán chia để trị xây dựng tam giác phân Delaunay để thu được lưới tam giác, rồi dùng thuật toán đường rẽ trái nhất để tìm đồ thị đối ngẫu của nó, từ đó xây dựng biểu đồ Voronoi trong độ phức tạp $O(n \log n)$.

## Bài tập

[SGU 383 Caravans](https://codeforces.com/problemsets/acmsguru/problem/99999/383) tam giác phân + nhân đôi

[ContestHunter. Endless Destruction](http://noi-test.zzstep.com/contest/Beta%20Round%20%EF%BC%832%20%28%E6%96%B0%E7%96%86%E7%9C%81%E9%98%9F%E4%BA%92%E6%B5%8BWeek1-Day2%29/%E6%97%A0%E5%B0%BD%E7%9A%84%E6%AF%81%E7%81%AD) dùng tam giác phân để tìm đồ thị đối ngẫu và xây dựng biểu đồ Voronoi

[Codeforces Gym 103485M. Constellation collection](https://codeforces.com/gym/103485/problem/M) xây đồ thị sau khi tam giác phân rồi chạy Floodfill

## Tài liệu tham khảo và đọc thêm

1.  [Wikipedia - Triangulation (geometry)](https://en.wikipedia.org/wiki/Triangulation_%28geometry%29)
2.  [Wikipedia - Delaunay triangulation](https://en.wikipedia.org/wiki/Delaunay_triangulation)
3.  Samuel Peterson - [Computing Constrained Delaunay Triangulations in 2-D (1997-98)](http://www.geom.uiuc.edu/~samuelp/del_project.html)
