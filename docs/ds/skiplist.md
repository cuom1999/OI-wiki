Skip list là một cấu trúc dữ liệu tìm kiếm do William Pugh phát minh, hỗ trợ tìm kiếm, chèn và xóa dữ liệu nhanh.

Độ phức tạp không gian kỳ vọng của skip list là $O(n)$; độ phức tạp thời gian kỳ vọng của các thao tác truy vấn, chèn và xóa trong skip list đều là $O(\log n)$.

## Ý tưởng cơ bản

Đúng như tên gọi, skip list là một cấu trúc dữ liệu tương tự danh sách liên kết. Chính xác hơn, skip list là một cải tiến của danh sách liên kết có thứ tự.

Để thuận tiện cho việc thảo luận, mọi danh sách liên kết có thứ tự bên dưới mặc định được sắp xếp theo thứ tự **tăng dần**.

Thao tác tìm kiếm trên một danh sách liên kết có thứ tự bắt đầu từ đầu danh sách và so sánh từng phần tử, cho đến khi giá trị của nút hiện tại lớn hơn hoặc bằng giá trị của nút mục tiêu. Rõ ràng, độ phức tạp của thao tác này là $O(n)$.

Trên cơ sở danh sách liên kết có thứ tự, skip list đưa vào khái niệm **phân tầng**. Trước hết, mỗi tầng của skip list đều là một danh sách liên kết có thứ tự; đặc biệt, tầng thấp nhất là danh sách liên kết có thứ tự ban đầu. Mỗi nút nằm ở tầng thứ $i$ sẽ xuất hiện ở tầng thứ $i+1$ với xác suất $p$, trong đó $p$ là một hằng số.

Gọi tầng kỳ vọng chứa $\frac{1}{p}$ phần tử trong skip list có $n$ nút là tầng thứ $L(n)$, dễ thấy $L(n) = \log_{\frac{1}{p}}n$.

Khi tìm kiếm trong skip list, ta bắt đầu từ tầng thứ $L(n)$, so sánh lần lượt theo chiều ngang cho đến khi nút kế tiếp của nút hiện tại lớn hơn hoặc bằng nút mục tiêu, rồi đi xuống tầng dưới. Lặp lại quá trình này cho đến khi đến tầng thứ nhất và không thể tiếp tục thao tác. Lúc này, nếu nút kế tiếp là nút mục tiêu thì tìm kiếm thành công; ngược lại, phần tử không tồn tại. Nhờ vậy, quá trình tìm kiếm sẽ bỏ qua một số phép so sánh không cần thiết, nên truy vấn trên skip list nhanh hơn so với truy vấn trên danh sách liên kết có thứ tự. Có thể chứng minh rằng độ phức tạp trung bình của truy vấn trên skip list là $O(\log n)$.

## Chứng minh độ phức tạp

### Độ phức tạp không gian

Đối với một nút, xác suất để tầng cao nhất của nút đó là $i$ bằng $p^{i-1}(1 - p)$. Vì vậy, số tầng kỳ vọng của skip list là $\sum_{i\ge 1} ip^{i - 1}(1-p) = \frac{1}{1 - p}$; do $p$ là hằng số, **độ phức tạp không gian kỳ vọng** của skip list là $O(n)$.

Trong trường hợp xấu nhất, danh sách liên kết có thứ tự ở mỗi tầng đều bằng danh sách liên kết có thứ tự ban đầu, tức **độ phức tạp không gian tệ nhất** của skip list là $O(n \log n)$.

### Độ phức tạp thời gian

Phân tích đường đi tìm kiếm từ sau ra trước, quá trình này có thể chia thành hai phần: leo từ tầng thấp nhất lên tầng thứ $L(n)$ và các thao tác sau đó. Khi phân tích, giả sử thông tin cụ thể của một nút là chưa biết trước khi nút đó được truy cập.

Giả sử hiện tại ta đang ở một nút $x$ thuộc tầng thứ $i$. Ta không biết số tầng tối đa của $x$ cũng như số tầng tối đa của nút bên trái $x$, chỉ biết số tầng tối đa của $x$ ít nhất là $i$. Nếu số tầng tối đa của $x$ lớn hơn $i$, bước tiếp theo nên đi lên; trường hợp này có xác suất $p$. Nếu số tầng tối đa của $x$ bằng $i$, bước tiếp theo nên đi sang trái; trường hợp này có xác suất $1-p$.

Đặt $C(i)$ là chi phí kỳ vọng để leo lên $i$ tầng trong một skip list có độ dài vô hạn, khi đó có:

$$
\begin{aligned}
C(0) & = 0 \\
C(i) & = (1-p)(1+C(i)) + p(1+C(i-1))
\end{aligned}
$$

Giải ra được $C(i)=\frac{i}{p}$.

Từ đó suy ra: trong một skip list có độ dài $n$, số bước kỳ vọng để leo từ tầng thấp nhất lên tầng thứ $L(n)$ có cận trên là $\frac{L(n) - 1}{p}$.

Bây giờ chỉ cần phân tích sau khi leo đến tầng thứ $L(n)$ thì còn phải đi thêm bao nhiêu bước. Dễ thấy sau khi đến tầng thứ $L(n)$, số bước đi sang trái không vượt quá tổng số nút ở tầng thứ $L(n)$ và các tầng cao hơn; kỳ vọng của tổng này là $\frac{1}{p}$. Vì vậy, số bước kỳ vọng đi sang trái sau khi đến tầng thứ $L(n)$ có cận trên là $\frac{1}{p}$. Tương tự, số bước kỳ vọng đi lên sau khi đến tầng thứ $L(n)$ cũng có cận trên là $\frac{1}{p}$.

Do đó, số bước tìm kiếm kỳ vọng của truy vấn trên skip list là $\frac{L(n) - 1}{p} + \frac{2}{p}$. Lại do $L(n)=\log_{\frac{1}{p}}n$, nên **độ phức tạp thời gian kỳ vọng** của truy vấn trên skip list là $O(\log n)$.

Trong trường hợp xấu nhất, danh sách liên kết có thứ tự ở mỗi tầng đều bằng danh sách liên kết có thứ tự ban đầu, quá trình tìm kiếm tương đương với truy vấn trên danh sách liên kết có thứ tự ở tầng cao nhất, tức **độ phức tạp thời gian tệ nhất** của thao tác truy vấn trên skip list là $O(n)$.

Thao tác chèn và thao tác xóa đều là quá trình thực hiện một lượt truy vấn, ghi lại các nút cần sửa đổi trên đường đi, rồi cuối cùng hoàn tất việc sửa đổi. Dễ thấy ở mỗi tầng nhiều nhất chỉ cần sửa đổi một nút; lại do số tầng kỳ vọng của skip list là $\log_{\frac{1}{p}}n$, nên **độ phức tạp thời gian kỳ vọng** của thao tác chèn và xóa cũng là $O(\log n)$.

## Cài đặt cụ thể

### Lấy số tầng tối đa của nút

Mô phỏng việc tăng thêm một tầng với xác suất $p$, cuối cùng lấy giá trị nhỏ hơn giữa kết quả và giới hạn trên.

```cpp
int randomLevel() {
  int lv = 1;
  // MAXL = 32, S = 0xFFFF, PS = S * P, P = 1 / 4
  while ((rand() & S) < PS) ++lv;
  return min(MAXL, lv);
}
```

### Truy vấn

Truy vấn xem trong skip list có tồn tại nút có khóa là `key` hay không. Khi cài đặt cụ thể, có thể đặt hai nút lính canh để giảm số trường hợp biên cần xét.

```cpp
V& find(const K& key) {
  SkipListNode<K, V>* p = head;

  // Tìm nút cuối cùng ở tầng này có khóa nhỏ hơn key, rồi đi xuống
  for (int i = level; i >= 0; --i) {
    while (p->forward[i]->key < key) {
      p = p->forward[i];
    }
  }
  // Hiện tại p vẫn nhỏ hơn key, nên cần đi tiếp một bước
  p = p->forward[0];

  // Tìm thấy nút
  if (p->key == key) return p->value;

  // Nút không tồn tại, trả về INVALID
  return tail->value;
}
```

### Chèn

Chèn nút `(key, value)`. Quá trình chèn nút là trước tiên thực hiện một lượt truy vấn, trong lúc đó ghi lại nút mới cần được chèn sau những nút nào, rồi cuối cùng thực hiện việc chèn. Ở mỗi tầng, nút cuối cùng có khóa nhỏ hơn `key` chính là nút cần sửa đổi.

```cpp
void insert(const K &key, const V &value) {
  // Ghi lại các nút cần sửa đổi
  SkipListNode<K, V> *update[MAXL + 1];

  SkipListNode<K, V> *p = head;
  for (int i = level; i >= 0; --i) {
    while (p->forward[i]->key < key) {
      p = p->forward[i];
    }
    // Nút cần sửa đổi ở tầng i là p
    update[i] = p;
  }
  p = p->forward[0];

  // Nếu đã tồn tại thì cập nhật
  if (p->key == key) {
    p->value = value;
    return;
  }

  // Lấy số tầng tối đa của nút mới
  int lv = randomLevel();
  if (lv > level) {
    lv = ++level;
    update[lv] = head;
  }

  // Tạo nút mới
  SkipListNode<K, V> *newNode = new SkipListNode<K, V>(key, value, lv);
  // Chèn nút mới vào các tầng từ 0 đến lv
  for (int i = lv; i >= 0; --i) {
    p = update[i];
    newNode->forward[i] = p->forward[i];
    p->forward[i] = newNode;
  }

  ++length;
}
```

### Xóa

Xóa nút có khóa là `key`. Quá trình xóa nút là trước tiên thực hiện một lượt truy vấn, trong lúc đó ghi lại nút cần xóa nằm sau những nút nào, rồi cuối cùng thực hiện việc xóa. Ở mỗi tầng, nút cuối cùng có khóa nhỏ hơn `key` chính là nút cần sửa đổi.

```cpp
bool erase(const K &key) {
  // Ghi lại các nút cần sửa đổi
  SkipListNode<K, V> *update[MAXL + 1];

  SkipListNode<K, V> *p = head;
  for (int i = level; i >= 0; --i) {
    while (p->forward[i]->key < key) {
      p = p->forward[i];
    }
    // Nút cần sửa đổi ở tầng i là p
    update[i] = p;
  }
  p = p->forward[0];

  // Nút không tồn tại
  if (p->key != key) return false;

  // Xóa từ tầng thấp nhất trở lên
  for (int i = 0; i <= level; ++i) {
    // Nếu tầng này không có p thì việc xóa đã hoàn tất
    if (update[i]->forward[i] != p) {
      break;
    }
    // Ngắt liên kết của p
    update[i]->forward[i] = p->forward[i];
  }

  // Thu hồi bộ nhớ
  delete p;

  // Xóa nút có thể làm giảm số tầng tối đa
  while (level > 0 && head->forward[level] == tail) --level;

  // Độ dài của skip list
  --length;
  return true;
}
```

### Mã hoàn chỉnh

Đoạn mã sau là một `map` được cài đặt bằng skip list. Mã chưa được kiểm thử nghiêm túc, chỉ dùng để tham khảo.

??? note "Mã tham khảo"
    ```cpp
    #include <cassert>
    #include <climits>
    #include <ctime>
    #include <iostream>
    #include <map>
    using namespace std;
    
    template <typename K, typename V>
    struct SkipListNode {
      int level;
      K key;
      V value;
      SkipListNode **forward;
    
      SkipListNode() {}
    
      SkipListNode(K k, V v, int l, SkipListNode *nxt = NULL) {
        key = k;
        value = v;
        level = l;
        forward = new SkipListNode *[l + 1];
        for (int i = 0; i <= l; ++i) forward[i] = nxt;
      }
    
      ~SkipListNode() {
        if (forward != NULL) delete[] forward;
      }
    };
    
    template <typename K, typename V>
    struct SkipList {
      static constexpr int MAXL = 32;
      static constexpr int P = 4;
      static constexpr int S = 0xFFFF;
      static constexpr int PS = S / P;
      static constexpr int INVALID = INT_MAX;
    
      SkipListNode<K, V> *head, *tail;
      int length;
      int level;
    
      SkipList() {
        srand(time(nullptr));
    
        level = length = 0;
        tail = new SkipListNode<K, V>(INVALID, 0, 0);
        head = new SkipListNode<K, V>(INVALID, 0, MAXL, tail);
      }
    
      ~SkipList() {
        delete head;
        delete tail;
      }
    
      int randomLevel() {
        int lv = 1;
        while ((rand() & S) < PS) ++lv;
        return MAXL > lv ? lv : MAXL;
      }
    
      void insert(const K &key, const V &value) {
        SkipListNode<K, V> *update[MAXL + 1];
    
        SkipListNode<K, V> *p = head;
        for (int i = level; i >= 0; --i) {
          while (p->forward[i]->key < key) {
            p = p->forward[i];
          }
          update[i] = p;
        }
        p = p->forward[0];
    
        if (p->key == key) {
          p->value = value;
          return;
        }
    
        int lv = randomLevel();
        if (lv > level) {
          lv = ++level;
          update[lv] = head;
        }
    
        SkipListNode<K, V> *newNode = new SkipListNode<K, V>(key, value, lv);
        for (int i = lv; i >= 0; --i) {
          p = update[i];
          newNode->forward[i] = p->forward[i];
          p->forward[i] = newNode;
        }
    
        ++length;
      }
    
      bool erase(const K &key) {
        SkipListNode<K, V> *update[MAXL + 1];
        SkipListNode<K, V> *p = head;
    
        for (int i = level; i >= 0; --i) {
          while (p->forward[i]->key < key) {
            p = p->forward[i];
          }
          update[i] = p;
        }
        p = p->forward[0];
    
        if (p->key != key) return false;
    
        for (int i = 0; i <= level; ++i) {
          if (update[i]->forward[i] != p) {
            break;
          }
          update[i]->forward[i] = p->forward[i];
        }
    
        delete p;
    
        while (level > 0 && head->forward[level] == tail) --level;
        --length;
        return true;
      }
    
      V &operator[](const K &key) {
        V v = find(key);
        if (v == tail->value) insert(key, 0);
        return find(key);
      }
    
      V &find(const K &key) {
        SkipListNode<K, V> *p = head;
        for (int i = level; i >= 0; --i) {
          while (p->forward[i]->key < key) {
            p = p->forward[i];
          }
        }
        p = p->forward[0];
        if (p->key == key) return p->value;
        return tail->value;
      }
    
      bool count(const K &key) { return find(key) != tail->value; }
    };
    
    int main() {
      SkipList<int, int> L;
      map<int, int> M;
    
      clock_t s = clock();
    
      for (int i = 0; i < 1e5; ++i) {
        int key = rand(), value = rand();
        L[key] = value;
        M[key] = value;
      }
    
      for (int i = 0; i < 1e5; ++i) {
        int key = rand();
        if (i & 1) {
          L.erase(key);
          M.erase(key);
        } else {
          int r1 = L.count(key) ? L[key] : 0;
          int r2 = M.count(key) ? M[key] : 0;
          assert(r1 == r2);
        }
      }
    
      clock_t e = clock();
      cout << "Time elapsed: " << (double)(e - s) / CLOCKS_PER_SEC << endl;
      // about 0.2s
    
      return 0;
    }
    ```

## Tối ưu truy cập ngẫu nhiên cho skip list

Truy cập nút thứ $k$ trong skip list tương đương với truy cập nút thứ $k$ trong danh sách liên kết có thứ tự ban đầu. Rõ ràng độ phức tạp thời gian của thao tác này là $O(n)$, chưa đủ tốt.

Tối ưu truy cập ngẫu nhiên cho skip list là duy trì thêm độ dài của mỗi con trỏ tiến. Giả sử $A$ và $B$ đều là các nút trong skip list, trong đó $A$ là nút thứ $a$ của skip list, $B$ là nút thứ $b$ của skip list $(a < b)$, và ở một tầng nào đó của skip list, con trỏ tiến của $A$ trỏ đến $B$. Khi đó độ dài của con trỏ tiến này là $b - a$.

Bây giờ, để truy cập nút thứ $k$ trong skip list, ta có thể bắt đầu từ tầng trên cùng, duyệt danh sách liên kết của tầng đó theo chiều ngang cho đến khi vị trí của nút hiện tại cộng với độ dài con trỏ tiến của nút hiện tại tại tầng đó lớn hơn hoặc bằng $k$, rồi đi xuống tầng dưới. Lặp lại quá trình này cho đến khi đến tầng thứ nhất và không thể tiếp tục thao tác. Lúc này, nút hiện tại chính là nút thứ $k$ trong skip list.

Như vậy, ta có thể truy cập nhanh phần tử thứ $k$ của skip list. Có thể chứng minh rằng độ phức tạp thời gian của thao tác này là $O(\log n)$.

## Tài liệu tham khảo

1.  [Skip Lists: A Probabilistic Alternative to Balanced Trees](https://15721.courses.cs.cmu.edu/spring2018/papers/08-oltpindexes1/pugh-skiplists-cacm1990.pdf)
2.  [Skip List](https://en.wikipedia.org/wiki/Skip_list)
3.  [A Skip List Cookbook](http://cglab.ca/~morin/teaching/5408/refs/p90b.pdf)
