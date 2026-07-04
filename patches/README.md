# Patches

Để bảo đảm tương thích với mkdocs, chúng tôi đã patch
`mdast-util-to-markdown`. Các thay đổi cụ thể như sau:

- Dùng hardbreak theo kiểu 2 dấu cách
- Tránh escape `&`
- Tránh xem dấu bằng là heading
