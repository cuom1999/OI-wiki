author: Ir1d, HeRaNO, NachtgeistW, i-Yirannn, bear-good, ranwen, CoelacanthusHex, billchenchina, Tiger3018, Xeonacid

## Lemon

???+ warning "Cảnh báo"
    Trên macOS, Lemon có thể đo bộ nhớ không chính xác, vì macOS thiếu một số công cụ giám sát của Linux và Lemon-Linux cũng chưa được tối ưu riêng cho macOS.

**Lemon** là một công cụ chấm mã nguồn mở do zhipeng-jia viết. Mã nguồn được lưu trữ tại [zhipeng-jia/project-lemon](https://github.com/zhipeng-jia/project-lemon).

### Phiên bản có thể chạy trực tiếp

-   Ir1d cung cấp một bản đã biên dịch cho Linux; mã nguồn được lưu trữ tại [FreestyleOJ/Project\_lemon](https://github.com/FreestyleOJ/Project_lemon/tree/Built).
-   (Đã ngừng bảo trì) Menci cung cấp một phiên bản mới hơn; mã nguồn được lưu trữ tại [Menci/Lemon](https://github.com/Menci/Lemon/).
-   (Đã ngừng bảo trì) Dust1404 duy trì một phiên bản hỗ trợ thư mục con, kiểm thử từng bài và một số tính năng khác; mã nguồn được lưu trữ tại [Dust1404/Project\_LemonPlus](https://github.com/Dust1404/Project_LemonPlus).
-   iotang và Coelacanthus duy trì một phiên bản hỗ trợ thư mục con, kiểm thử từng bài và một số tính năng khác; mã nguồn được lưu trữ tại [Project-LemonLime/Project\_LemonLime](https://github.com/Project-LemonLime/Project_LemonLime).

### Tự biên dịch

Ubuntu:

```bash
sudo apt update
sudo apt install qt5-default build-essential git -y
git clone --depth=1 https://github.com/Menci/Lemon.git
cd lemon
# Có thể sửa số sau -j để điều chỉnh số luồng make job
./make -j2
sudo install -Dm755 -t /usr/bin/ Lemon
```

Nếu muốn biên dịch LemonLime, hãy tham khảo [sổ tay biên dịch](https://github.com/Project-LemonLime/Project_LemonLime/blob/master/BUILD.md) của LemonLime.

### Định dạng dữ liệu

Trước hết, mở Lemon và chọn "Tạo bài mới", rồi mở thư mục của bài vừa tạo.

Đề và dữ liệu nên có định dạng như sau:

```text
├── data
│   ├── gendata.py
│   ├── product
│   │   ├── product100.in
│   │   ├── product100.out
│   │   ├── product10.in
│   │   ├── product10.out
│   │   ├── product11.in
...
```

Sau khi thêm xong tất cả bài, quay lại Lemon và chọn "Tự động thêm bài". Lúc này, các bài và test sẽ xuất hiện trong Lemon.
