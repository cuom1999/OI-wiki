import re
from pathlib import Path

HTML_TRANSLATIONS = {
    "Switch to dark mode": "Chuyển sang chế độ tối",
    "Switch to light mode": "Chuyển sang chế độ sáng",
    'aria-label="Tabs"': 'aria-label="Thẻ"',
    'title="Permanent link"': 'title="Liên kết cố định"',
    'title="edit.link.title"': 'title="Chỉnh sửa"',
    "本页面最近更新：": "Trang này được cập nhật gần nhất: ",
    "更新历史": "lịch sử cập nhật",
    "</span>，<a": "</span>, <a",
    "发现错误？想一起完善？ ": "Phát hiện lỗi? Muốn cùng cải thiện? ",
    "在 GitHub 上编辑此页！": "Chỉnh sửa trang này trên GitHub!",
    "本页面贡献者：": "Người đóng góp trang này: ",
    "本页面的全部内容在 ": "Toàn bộ nội dung của trang này được cung cấp theo ",
    " 协议之条款下提供，附加条款亦可能应用": "; các điều khoản bổ sung cũng có thể áp dụng",
    "回到顶部": "Về đầu trang",
    "最近更新：": "Cập nhật gần nhất: ",
    "Cập nhật gần nhất: , ": "Cập nhật gần nhất: ",
    "黑ICP备19005132号-2": "Giấy phép ICP Hắc Long Giang 19005132-2",
    "少年，恭喜你囍提彩蛋，我们在做一些 OI 相关的有趣的事情，如果您对此感兴趣，欢迎访问 https://join-us.oi-wiki.org": "Chúc mừng bạn đã tìm thấy easter egg. Chúng tôi đang làm một số việc thú vị liên quan đến OI; nếu quan tâm, hãy truy cập https://join-us.oi-wiki.org",
    '"data-lang":"en-US"': '"data-lang":"vi"',
}

def _nav_math():
    raw_re = r"\\\((.+?)\\\)"
    target = r'<span class="arithmatex">\(\1\)</span>'
    r = re.compile(raw_re)
    def nav_math(s):
        return r.sub(target, s).replace(" <span", "&nbsp;<span").replace("</span> ", "</span>&nbsp;")
    return nav_math

def on_env(env, config, files, **kwargs):
    env.filters["nav_math"] = _nav_math()
    return env

def on_post_page(output, page, config, **kwargs):
    for source, target in HTML_TRANSLATIONS.items():
        output = output.replace(source, target)
    return output

def on_post_build(config, **kwargs):
    site_dir = Path(config["site_dir"])
    for html_file in site_dir.rglob("*.html"):
        output = html_file.read_text(encoding="utf-8")
        for source, target in HTML_TRANSLATIONS.items():
            output = output.replace(source, target)
        html_file.write_text(output, encoding="utf-8")
