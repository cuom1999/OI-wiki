disqus:
pagetime:
title: OI Wiki tiếng Việt

# Chào mừng đến với **OI Wiki tiếng Việt**! [![GitHub watchers](https://img.shields.io/github/watchers/cuom1999/OI-wiki.svg?style=social&label=Theo%20dõi)](https://github.com/cuom1999/OI-wiki) [![GitHub stars](https://img.shields.io/github/stars/cuom1999/OI-wiki.svg?style=social&label=Sao)](https://github.com/cuom1999/OI-wiki)

[![Chữ nghệ thuật OI Wiki](images/wordArt.webp)](https://github.com/cuom1999/OI-wiki)

**OI** (Olympiad in Informatics, Olympic Tin học) là một mảng thi đấu tin học
dành cho học sinh phổ thông. Ở Trung Quốc, OI bắt đầu từ năm 1984 và là một
trong năm kỳ thi học sinh giỏi cấp trung học quan trọng.

**ICPC** (International Collegiate Programming Contest) do ICPC Foundation tổ
chức và là một trong những cuộc thi lập trình đại học có ảnh hưởng nhất. Vì
trước đây ACM từng tài trợ cuộc thi này, nhiều người vẫn quen gọi là ACM.

**OI Wiki** hướng tới việc trở thành một kho tri thức **lập trình thi đấu
(competitive programming)** miễn phí, mở và được cập nhật liên tục. Tại đây,
bạn có thể tìm thấy kiến thức thú vị và hữu ích về thi đấu lập trình: nền tảng
cơ bản, dạng bài thường gặp, hướng giải, công cụ và kinh nghiệm học tập.

Bản tiếng Việt này dịch dần từ dự án gốc, giữ nguyên cấu trúc nguồn để dễ theo
dõi thay đổi của bản gốc. Một số trang vẫn còn dấu vết hoặc bối cảnh từ bản gốc
trong thời gian chuyển đổi.

Dự án gốc lấy cảm hứng từ [CTF Wiki](https://ctf-wiki.org/) và tham khảo nhiều
tài liệu trong quá trình biên soạn.

## Bảng màu Material

### Màu chính

> Mặc định là `white`

Nhấn vào một ô màu để đổi màu chính của giao diện.

<div id="color-button">
<button data-md-color-primary="red">Đỏ</button>
<button data-md-color-primary="pink">Hồng</button>
<button data-md-color-primary="purple">Tím</button>
<button data-md-color-primary="deep-purple">Tím đậm</button>
<button data-md-color-primary="indigo">Chàm</button>
<button data-md-color-primary="blue">Xanh lam</button>
<button data-md-color-primary="light-blue">Xanh lam nhạt</button>
<button data-md-color-primary="cyan">Lục lam</button>
<button data-md-color-primary="teal">Xanh mòng két</button>
<button data-md-color-primary="green">Xanh lá</button>
<button data-md-color-primary="light-green">Xanh lá nhạt</button>
<button data-md-color-primary="lime">Vàng chanh</button>
<button data-md-color-primary="yellow">Vàng</button>
<button data-md-color-primary="amber">Hổ phách</button>
<button data-md-color-primary="orange">Cam</button>
<button data-md-color-primary="deep-orange">Cam đậm</button>
<button data-md-color-primary="brown">Nâu</button>
<button data-md-color-primary="grey">Xám</button>
<button data-md-color-primary="blue-grey">Xám xanh</button>
<button data-md-color-primary="white">Trắng</button>
</div>

<script>
  var buttons = document.querySelectorAll("button[data-md-color-primary]");
  Array.prototype.forEach.call(buttons, function(button) {
    button.addEventListener("click", function() {
      document.body.dataset.mdColorPrimary = this.dataset.mdColorPrimary;
      localStorage.setItem("data-md-color-primary",this.dataset.mdColorPrimary);
    })
  })
</script>

### Màu nhấn

> Mặc định là `red`

Nhấn vào một ô màu để đổi màu nhấn của giao diện.

<div id="color-button">
<button data-md-color-accent="red">Đỏ</button>
<button data-md-color-accent="pink">Hồng</button>
<button data-md-color-accent="purple">Tím</button>
<button data-md-color-accent="deep-purple">Tím đậm</button>
<button data-md-color-accent="indigo">Chàm</button>
<button data-md-color-accent="blue">Xanh lam</button>
<button data-md-color-accent="light-blue">Xanh lam nhạt</button>
<button data-md-color-accent="cyan">Lục lam</button>
<button data-md-color-accent="teal">Xanh mòng két</button>
<button data-md-color-accent="green">Xanh lá</button>
<button data-md-color-accent="light-green">Xanh lá nhạt</button>
<button data-md-color-accent="lime">Vàng chanh</button>
<button data-md-color-accent="yellow">Vàng</button>
<button data-md-color-accent="amber">Hổ phách</button>
<button data-md-color-accent="orange">Cam</button>
<button data-md-color-accent="deep-orange">Cam đậm</button>
</div>

<script>
  var buttons = document.querySelectorAll("button[data-md-color-accent]");
  Array.prototype.forEach.call(buttons, function(button) {
    button.addEventListener("click", function() {
      document.body.dataset.mdColorAccent = this.dataset.mdColorAccent;
      localStorage.setItem("data-md-color-accent",this.dataset.mdColorAccent);
    })
  })

  // #758
  document.getElementsByClassName('md-nav__title')[1].click()
</script>

<div align="center">
<a href="https://www.hulu.com/" target="_blank"><img height="40px" src="images/hulu-black.png"></a>
<a href="https://www.netlify.com/" target="_blank" style="margin-left: 60px;"><img height="40px" src="images/netlify.png"></a>
</div>
