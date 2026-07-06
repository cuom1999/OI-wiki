<span id="tổng-quan"></span>
## Tổng quan

Từ chuẩn C++11, bốn bộ chứa kết hợp không thứ tự được cài đặt dựa trên
[bảng băm](../../ds/hash.md) đã chính thức được đưa vào thư viện chuẩn C++:
`unordered_set`, `unordered_multiset`, `unordered_map`, `unordered_multimap`.

??? note "Cách dùng khi trình biên dịch không hỗ trợ C++11"
    Trước C++11, các bộ chứa kết hợp không thứ tự thuộc phần mở rộng TR1 của
    C++. Vì vậy, nếu trình biên dịch không hỗ trợ C++11, khi sử dụng cần thêm
    tiền tố `tr1/` vào tên tệp tiêu đề, đồng thời dùng không gian tên
    `std::tr1`. Chẳng hạn `#include <unordered_map>` cần đổi thành
    `#include <tr1/unordered_map>`; `std::unordered_map` cần đổi thành
    `std::tr1::unordered_map` (nếu dùng `using namespace std;` thì là
    `tr1::unordered_map`).

Chúng có nhiều điểm chung với các bộ chứa kết hợp tương ứng về chức năng, hàm
thành viên, v.v. Khác biệt lớn nhất là các bộ chứa kết hợp thông thường thường
được cài đặt bằng cây đỏ-đen, nên các phần tử bên trong được sắp xếp theo một
thứ tự xác định; còn bộ chứa kết hợp không thứ tự lưu phần tử bằng bảng băm, nên
không bảo đảm thứ tự duyệt phần tử. Thứ tự duyệt cũng có thể thay đổi sau khi bộ
chứa rehash.

Nhờ cách lưu trữ bằng bảng băm, bộ chứa kết hợp không thứ tự có thể thực hiện
hầu hết thao tác (bao gồm tìm kiếm, chèn, xóa) trong thời gian hằng số **trong
trường hợp trung bình**, tốt hơn độ phức tạp logarit theo kích thước bộ chứa của
bộ chứa kết hợp có thứ tự.

??? warning "Cảnh báo"
    Trong trường hợp xấu nhất, độ phức tạp thời gian của các thao tác chèn, xóa,
    tìm kiếm trên bộ chứa kết hợp không thứ tự sẽ **tuyến tính theo kích thước
    bộ chứa**. Tình huống này thường xảy ra khi nhiều khóa rơi vào cùng bucket,
    tức có nhiều va chạm băm.
    
    Đồng thời, do các thao tác trên bộ chứa kết hợp không thứ tự thường có hằng
    số lớn, hiệu năng thực tế của chúng đôi khi không hơn bộ chứa kết hợp có thứ
    tự nhiều.
    
    Vì vậy cần thận trọng khi sử dụng bộ chứa kết hợp không thứ tự, tránh lạm
    dụng. Chẳng hạn, không nên vì ngại rời rạc hóa mà dùng
    `unordered_map<int, int>` như một mảng thông thường trên không gian khóa rất
    lớn.

Do bộ chứa kết hợp không thứ tự và bộ chứa kết hợp tương ứng có nhiều điểm chung
về mục đích và thao tác, phần này không giới thiệu lại từng thao tác của bộ chứa
kết hợp không thứ tự. Xem thêm
[bộ chứa kết hợp](./associative-container.md).

<span id="tạo-va-chạm-băm"></span>
## Tạo va chạm băm

Phần trên đã đề cập rằng trong trường hợp xấu nhất, độ phức tạp thời gian của
một số thao tác trên bộ chứa kết hợp không thứ tự sẽ tuyến tính theo kích thước
bộ chứa.

Khi hàm băm đã cố định, có thể xây dựng dữ liệu sao cho trong bộ chứa phát sinh
nhiều va chạm băm, khiến độ phức tạp đạt tới cận xấu nhất.

Trong một số cài đặt của thư viện chuẩn, bucket của mỗi phần tử được xác định
bằng cách lấy phần dư của giá trị băm theo một số nguyên tố. Các số nguyên tố
đó có thể nằm trong
[danh sách này](https://github.com/gcc-mirror/gcc/blob/releases/gcc-8.1.0/libstdc%2B%2B-v3/src/shared/hashtable-aux.cc)
(với một số phiên bản g++ 6 trở về trước, số nguyên tố này thường là $126271$;
với một số phiên bản g++ 7 trở về sau, số nguyên tố này thường là $107897$).

Vì vậy, với khóa số nguyên và hàm băm mặc định trên những cài đặt nói trên, có
thể chèn vào bộ chứa các bội của những số nguyên tố này để tạo ra nhiều va chạm
băm. Cách tấn công này phụ thuộc vào thư viện chuẩn và chính sách rehash cụ thể.

<span id="tùy-biến-hàm-băm"></span>
## Tùy biến hàm băm

Hàm băm tùy biến giúp giảm đáng kể nguy cơ va chạm băm do dữ liệu được thiết kế
có chủ đích tạo ra.

Để dùng hàm băm tùy biến, cần định nghĩa một `struct` và nạp chồng toán tử `()`
trong `struct` đó, như sau:

```cpp
struct my_hash {
  size_t operator()(int x) const { return x; }
};
```

Hàm băm phải nhất quán với phép so sánh bằng: nếu hai khóa được xem là bằng
nhau, chúng phải cho cùng giá trị băm.

Để giảm khả năng hàm băm bị phân tích nhanh chóng (ví dụ các bài nộp dùng bộ
chứa kết hợp không thứ tự trên Codeforces bị khai thác), có thể thêm một số yếu
tố ngẫu nhiên (như thời điểm chạy chương trình) vào hàm băm để tăng độ khó khi
phân tích.

Ví dụ, [bài blog này](https://codeforces.com/blog/entry/62393) đưa ra hàm băm
sau:

```cpp
struct my_hash {
  static uint64_t splitmix64(uint64_t x) {
    x += 0x9e3779b97f4a7c15;
    x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
    x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
    return x ^ (x >> 31);
  }

  size_t operator()(uint64_t x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x + FIXED_RANDOM);
  }

  // Hàm băm khi std::pair<int, int> là kiểu khóa
  size_t operator()(pair<uint64_t, uint64_t> x) const {
    static const uint64_t FIXED_RANDOM =
        chrono::steady_clock::now().time_since_epoch().count();
    return splitmix64(x.first + FIXED_RANDOM) ^
           (splitmix64(x.second + FIXED_RANDOM) >> 1);
  }
};
```

Sau khi viết xong hàm băm tùy biến, có thể truyền nó vào bộ chứa khi định nghĩa,
chẳng hạn `unordered_map<int, int, my_hash> my_map;` hoặc
`unordered_map<pair<int, int>, int, my_hash> my_pair_map;`.
