[![Word Art](docs/images/wordArt.webp)](https://oi-wiki.org/)

# Chào mừng đến với **OI Wiki tiếng Việt**!

[![GitHub Actions](https://img.shields.io/github/actions/workflow/status/OI-wiki/OI-wiki/build.yml?style=flat-square)](https://github.com/OI-wiki/OI-wiki/actions) [![Uptime Robot Status](https://img.shields.io/uptimerobot/status/m781254113-3e3bac467c64fc99eafd383e.svg?style=flat-square)](https://status.oi-wiki.org/) [![GitHub watchers](https://img.shields.io/github/watchers/OI-Wiki/OI-Wiki.svg?style=social&label=Watch)](https://github.com/OI-wiki/OI-wiki) [![GitHub stars](https://img.shields.io/github/stars/OI-Wiki/OI-Wiki.svg?style=social&label=Stars)](https://github.com/OI-wiki/OI-wiki)

---

## Nội dung

Đây là nhánh dịch tiếng Việt của **OI Wiki**, một kho tri thức mở về lập
trình thi đấu. Dự án gốc được cộng đồng OI Wiki xây dựng để tổng hợp kiến
thức về Olympic Tin học, ICPC/CCPC, thuật toán, cấu trúc dữ liệu, công cụ,
ngôn ngữ lập trình và kinh nghiệm làm bài.

Lập trình thi đấu đã phát triển trong nhiều năm, độ khó ngày càng cao và nội
dung ngày càng rộng. Tài liệu trên mạng thường rời rạc, nên người mới bắt đầu
dễ mất nhiều thời gian để tìm một lộ trình học có hệ thống.

**OI Wiki tiếng Việt** giữ cấu trúc nguồn của dự án gốc và dịch dần nội dung
sang tiếng Việt, ưu tiên sự chính xác của thuật ngữ, công thức, mã nguồn và
ý tưởng thuật toán. Các trang chưa dịch vẫn có thể còn tiếng Trung trong quá
trình chuyển đổi.

Trạng thái, quy ước thuật ngữ và phạm vi hiện tại được ghi trong
[`TRANSLATION.md`](TRANSLATION.md).

---

## Triển khai cục bộ

Dự án dùng [MkDocs](https://github.com/mkdocs/mkdocs). Cần Python 3 và
[uv](https://docs.astral.sh/uv/).

```bash
git clone https://github.com/cuom1999/OI-wiki.git --depth=1
cd OI-wiki

# Cài uv nếu máy chưa có.
pip install uv

# Cài dependency Python theo pyproject.toml/uv.lock.
uv sync

# Cài theme tùy biến của OI Wiki.
# Trên Windows, nên chạy bằng Git Bash.
./scripts/pre-build/install-theme.sh

# Chạy server cục bộ tại http://127.0.0.1:8000
uv run mkdocs serve -v

# Hoặc build trang tĩnh vào thư mục site/
uv run mkdocs build -v
```

Nếu cần render MathJax phía server giống dự án gốc, tham khảo workflow
[`build.yml`](https://github.com/OI-wiki/OI-wiki/blob/master/.github/workflows/build.yml)
và chuẩn bị Node.js.

---

## Đóng góp

Bản dịch này nhận đóng góp theo hướng giữ lịch sử và cấu trúc của upstream.
Khi dịch một trang:

- Giữ nguyên mã nguồn, công thức, ký hiệu và tên file.
- Dịch văn xuôi sang tiếng Việt tự nhiên, nhưng giữ tên thuật toán phổ biến
  bằng tiếng Anh khi đó là cách cộng đồng thường tra cứu.
- Chỉ thêm tên tiếng Anh trong ngoặc ở lần xuất hiện đầu tiên hoặc khi hữu ích
  cho việc tra cứu.
- Không dịch máy hàng loạt nếu chưa rà soát lại thuật ngữ và ví dụ.

Quy trình đóng góp chung của upstream nằm ở
[How to contribute](https://oi-wiki.org/intro/htc/). Với nhánh tiếng Việt,
hãy xem thêm [`TRANSLATION.md`](TRANSLATION.md).

---

## Giấy phép

Trừ khi có ghi chú riêng, nội dung ngoài phần mã nguồn của dự án gốc được cấp
phép theo
[Creative Commons BY-SA 4.0](https://creativecommons.org/licenses/by-sa/4.0/deed.vi)
và giấy phép bổ sung
[The Star And Thank Author License](https://github.com/zTrix/sata-license).

Khi sử dụng, bạn có thể chia sẻ và phái sinh nội dung, nhưng phải ghi công,
chia sẻ theo cùng giấy phép và không đặt thêm hạn chế. Dự án gốc cũng khuyến
khích người dùng star kho GitHub.

BibTeX cho dự án gốc:

```bibtex
@misc{oiwiki,
  author = {OI Wiki Team},
  title = {OI Wiki},
  year = {2016},
  publisher = {GitHub},
  journal = {GitHub Repository},
  howpublished = {\url{https://github.com/OI-wiki/OI-wiki}},
}
```

---

## Ghi nhận

Dự án gốc lấy cảm hứng từ [CTF Wiki](https://ctf-wiki.org/) và tham khảo nhiều
tài liệu trong quá trình biên soạn.

Xin cảm ơn [các cộng tác viên OI Wiki](https://github.com/OI-wiki/OI-wiki/graphs/contributors)
và [những người đã tài trợ OI Wiki](https://oi-wiki.org/intro/thanks/).

<a href="https://github.com/OI-wiki/OI-wiki/graphs/contributors"><img src="https://opencollective.com/oi-wiki/contributors.svg?width=890&button=false" /></a>
