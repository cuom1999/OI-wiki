Trình tương tác (interactor) dùng để giao tiếp với chương trình của thí sinh trong bài tương tác. Phần giới thiệu về bài tương tác nằm ở [Các dạng bài - Bài tương tác](../../contest/problems.md#bài-tương-tác).

???+ note "Ghi chú"
    Testlib chỉ hỗ trợ bài tương tác theo kiểu Codeforces, tức hai chương trình tương tác với nhau. Testlib không hỗ trợ kiểu NOI, trong đó thí sinh viết hàm để tương tác với các hàm khác.

Hãy đọc [Thông dụng](./general.md) trước khi đọc tiếp.

Testlib cung cấp cho trình tương tác một luồng đặc biệt `std::fstream tout`. Đây là luồng nhật ký; bạn có thể ghi vào nó trong interactor và đọc lại bằng `ouf` trong checker.

Trong interactor, ta đọc dữ liệu test của đề từ `inf`, ghi đầu vào chuẩn cho chương trình thí sinh (và chương trình chuẩn) vào `stdout` (trực tuyến), đọc đầu ra của thí sinh từ `ouf` (trực tuyến), và đọc đầu ra chuẩn từ `ans` (trực tuyến).

Nếu interactor trả về trạng thái `_ok`, checker (nếu có) sẽ tiếp quản và kiểm tra tính hợp lệ của đáp án.

## Cách dùng

Windows:

```bat
interactor.exe <Input_File> <Output_File> [<Answer_File> [<Result_File> [-appes]]],
```

Linux:

```bash
./interactor.out <Input_File> <Output_File> [<Answer_File> [<Result_File> [-appes]]],
```

## Ví dụ đơn giản

???+ note "Đề bài"
    Trình tương tác chọn ngẫu nhiên một số nguyên trong khoảng $[1,10^9]$. Bạn cần viết một chương trình để đoán số đó; bạn được hỏi tối đa $50$ lần, mỗi lần hỏi một số nguyên trong khoảng $[1,10^9]$.
    
    Trình tương tác sẽ trả về:
    
    `1`: số được hỏi bằng đáp án, chương trình của bạn nên dừng hỏi.
    
    `0`: số được hỏi nhỏ hơn đáp án.
    
    `2`: số được hỏi lớn hơn đáp án.

Lưu ý rằng trong bài này ta không cần `ans`, vì không cần so sánh với đầu ra chuẩn; trong các bài khác, việc này có thể cần thiết.

```cpp
int main(int argc, char** argv) {
  registerInteraction(argc, argv);
  int n = inf.readInt();  // Số được chọn
  cout.flush();           // Xả bộ đệm
  int left = 50;
  bool found = false;
  while (left > 0 && !found) {
    left--;
    int a = ouf.readInt(1, 1000000000);  // Câu hỏi
    if (a < n)
      cout << 0 << endl;
    else if (a > n)
      cout << 2 << endl;
    else
      cout << 1 << endl, found = true;
    cout.flush();
  }
  if (!found) quitf(_wa, "couldn't guess the number with 50 questions");
  ouf.readEof();
  quitf(_ok, "guessed the number with %d questions!", 50 - left);
}
```

**Bài viết này chủ yếu được dịch từ [Interactors with testlib.h - Codeforces](https://codeforces.com/blog/entry/18455). Kho GitHub của `testlib.h` là [MikeMirzayanov/testlib](https://github.com/MikeMirzayanov/testlib).**
