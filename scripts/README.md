# scripts

Thư mục này chứa các script dùng để kiểm thử, xây dựng và sắp xếp mã nguồn.

-   `pre-build`: các script chạy trước khi build
    - `install-theme.sh, install-theme-vendor.sh`: cài đặt theme mkdocs và các
      thư viện bên thứ ba mà theme sử dụng
    - `pre-build.sh`: script chạy khi CI build site production, bao gồm cài đặt
      theme và điều chỉnh cấu hình
-   `post-build`: các script chạy sau khi build
    - `commits-info`: render thông tin liên quan đến Git commits trên từng
      trang, chẳng hạn thời gian cập nhật và danh sách người đóng góp
    - `math`: render công thức toán học trên từng trang (**lưu ý:** trong bản
      build preview, công thức được render ở frontend)
    - `redirect`: tạo các trang chuyển hướng
-   `post-deploy`: các script chạy sau khi triển khai production cho site chính
    - `baidu-push.sh, convert-sitemap.py`: chuyển đổi sitemap và đẩy lên Baidu
      Search
-   `netlify`: các script dùng cho bản build preview trên Netlify (xem
    `/netlify.toml`)
    - `build.sh`: toàn bộ quy trình build trên Netlify, với bước cài đặt phụ
      thuộc thủ công
    - `install-python.sh`: cài đặt phiên bản Python được chỉ định trên Netlify

Các script dưới đây không liên quan trực tiếp đến build:

- `test.py`: kiểm tra các đoạn mã ví dụ trong tài liệu có biên dịch bình thường
  hay không
- `check-characters.py`: quét các tệp Markdown và TeX đã sửa để tìm ký tự không
  hiển thị bất thường và các bộ thủ hoặc nét có thể thay bằng ký tự CJK tương
  ứng
- `celebration.py`: tự động tạo issue mừng số lượng star
- `linter_patch.py`: hỗ trợ bot sửa kết quả định dạng tài liệu bị lỗi
-   `linter`: một phần của `linter_patch.py`; xem `linter/README.md` để biết
    chi tiết
-   `utils`: một số công cụ
    - `find_jk.py`: tìm các Hán tự nằm ngoài codepoint tiếng Trung trong tệp nguồn
