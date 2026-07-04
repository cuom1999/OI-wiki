disqus:
pagetime:
title: OI Wiki tiếng Việt

# Chào mừng đến với **OI Wiki tiếng Việt**! [![GitHub watchers](https://img.shields.io/github/watchers/OI-wiki/OI-wiki.svg?style=social&label=Watch)](https://github.com/OI-wiki/OI-wiki) [![GitHub stars](https://img.shields.io/github/stars/OI-wiki/OI-wiki.svg?style=social&label=Stars)](https://github.com/OI-wiki/OI-wiki)

[![Word Art](images/wordArt.webp)](https://github.com/OI-wiki/OI-wiki)

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
dõi thay đổi upstream. Một số trang vẫn còn tiếng Trung trong thời gian chuyển
đổi.

Dự án gốc lấy cảm hứng từ [CTF Wiki](https://ctf-wiki.org/) và tham khảo nhiều
tài liệu trong quá trình biên soạn.

## Bảng màu Material

### Màu chính

> Mặc định là `white`

Nhấn vào một ô màu để đổi màu chính của giao diện.

<div id="color-button">
<button data-md-color-primary="red">Red</button>
<button data-md-color-primary="pink">Pink</button>
<button data-md-color-primary="purple">Purple</button>
<button data-md-color-primary="deep-purple">Deep Purple</button>
<button data-md-color-primary="indigo">Indigo</button>
<button data-md-color-primary="blue">Blue</button>
<button data-md-color-primary="light-blue">Light Blue</button>
<button data-md-color-primary="cyan">Cyan</button>
<button data-md-color-primary="teal">Teal</button>
<button data-md-color-primary="green">Green</button>
<button data-md-color-primary="light-green">Light Green</button>
<button data-md-color-primary="lime">Lime</button>
<button data-md-color-primary="yellow">Yellow</button>
<button data-md-color-primary="amber">Amber</button>
<button data-md-color-primary="orange">Orange</button>
<button data-md-color-primary="deep-orange">Deep Orange</button>
<button data-md-color-primary="brown">Brown</button>
<button data-md-color-primary="grey">Grey</button>
<button data-md-color-primary="blue-grey">Blue Grey</button>
<button data-md-color-primary="white">White</button>
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
<button data-md-color-accent="red">Red</button>
<button data-md-color-accent="pink">Pink</button>
<button data-md-color-accent="purple">Purple</button>
<button data-md-color-accent="deep-purple">Deep Purple</button>
<button data-md-color-accent="indigo">Indigo</button>
<button data-md-color-accent="blue">Blue</button>
<button data-md-color-accent="light-blue">Light Blue</button>
<button data-md-color-accent="cyan">Cyan</button>
<button data-md-color-accent="teal">Teal</button>
<button data-md-color-accent="green">Green</button>
<button data-md-color-accent="light-green">Light Green</button>
<button data-md-color-accent="lime">Lime</button>
<button data-md-color-accent="yellow">Yellow</button>
<button data-md-color-accent="amber">Amber</button>
<button data-md-color-accent="orange">Orange</button>
<button data-md-color-accent="deep-orange">Deep Orange</button>
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
