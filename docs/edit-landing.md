disqus:

## Trước khi chỉnh sửa

Trước hết, xin cảm ơn mọi đóng góp cho **OI Wiki**.

Tuy nhiên, trước khi bắt đầu, cần đọc và nắm rõ nội dung trong [Cách tham gia](./intro/htc.md) và [Sổ tay định dạng](./intro/format.md), để tránh các lỗi không cần thiết khi chỉnh sửa.

Sau khi đọc xong, nhấp nút bên dưới rồi bắt đầu chỉnh sửa.

???+ note "Vui lòng lưu ý"
    -   Nhớ thêm GitHub ID vào sau trường `author` ở đầu tệp theo đúng định dạng.
    -   Theo Issue [#3061](https://github.com/OI-wiki/OI-wiki/issues/3061), thay đổi hiện sẽ được gộp bằng một trong hai cách rebase hoặc squash tùy theo chất lượng thông điệp commit. Khi dùng squash, người đóng góp có thể là tác giả của commit đó thay vì người commit; vui lòng lưu ý điều này.

<a id="btn-startedit" style="padding: 0.75em 1.25em; display: inline-block; line-height: 1; text-decoration: none; white-space: nowrap; cursor: pointer; border: 1px solid #6190e8; border-radius: 5px; background-color: #6190e8; color: #fff; outline: none; font-size: 0.75em;">Bắt đầu chỉnh sửa</a>

<script>
    function getQueryVariable(name, dft)
    {
        var reg = new RegExp('(^|&)' + name + '=([^&]*)(&|$)', 'i');
        var r = window.location.search.substr(1).match(reg);
        if (r != null)
        {
            return unescape(r[2]);
        }
        return dft;
    }
    document.getElementById("btn-startedit").href = "https://github.com/OI-wiki/OI-wiki/edit/master/docs" + getQueryVariable("ref", "");
</script>
