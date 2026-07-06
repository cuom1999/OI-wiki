author: cutekibry, woruo27, Backl1ght, c-forrest

**Lý thuyết trò chơi** (game theory) là một nhánh của kinh tế học, chủ yếu nghiên cứu hành vi của các cá thể có tính cạnh tranh hoặc đối kháng dưới những quy tắc nhất định. Lý thuyết trò chơi quan tâm đến hành vi dự kiến và hành vi thực tế của các cá thể trong trò chơi, đồng thời nghiên cứu chiến lược tối ưu của họ.

Nói một cách bình dân, lý thuyết trò chơi chủ yếu nghiên cứu câu hỏi: trong một trò chơi, nhiều người chơi tham gia sẽ lựa chọn chiến lược như thế nào.

<span id="khái-niệm-cơ-bản"></span>
## Khái niệm cơ bản

Mục này giới thiệu ngắn gọn một số khái niệm thường gặp trong lý thuyết trò chơi.

<span id="trò-chơi-hợp-tác-không-hợp-tác"></span>
### Trò chơi hợp tác / không hợp tác

**Trò chơi hợp tác** (cooperative game) là trò chơi trong đó các bên tham gia có thể lập liên minh và hợp tác với nhau. Trong loại trò chơi này, hành vi không hợp tác của cá thể thường bị một cơ chế bên ngoài nào đó trừng phạt. Ngược lại, trong **trò chơi không hợp tác** (noncooperative game), cơ chế như vậy không tồn tại; vì thế, các bên tham gia hoặc không thể lập liên minh, hoặc chỉ có thể duy trì hợp tác dựa trên một cơ chế đe dọa đáng tin cậy.

So với trò chơi hợp tác, nghiên cứu về trò chơi không hợp tác có hệ thống hơn và phát triển chín muồi hơn. Tất cả trò chơi được thảo luận trong bài này đều là trò chơi không hợp tác.

<span id="trò-chơi-đối-xứng-không-đối-xứng"></span>
### Trò chơi đối xứng / không đối xứng

Trong **trò chơi đối xứng** (symmetric game), các bên tham gia khác nhau nhận cùng một lợi ích khi thực hiện cùng một hành vi; nói cách khác, lợi ích chỉ phụ thuộc vào bản thân hành vi, không phụ thuộc vào danh tính của người thực hiện. Trò chơi không thỏa điều kiện này được gọi là **trò chơi không đối xứng** (asymmetric game).

<span id="trò-chơi-tổng-bằng-không-không-tổng-bằng-không"></span>
### Trò chơi tổng bằng không / không tổng bằng không

Trang chính: [Trò chơi tổng bằng không](./zero-sum-game.md)

**Trò chơi tổng bằng không** (zero-sum game) là trò chơi mà dù các bên hành động thế nào, tổng lợi ích của tất cả người tham gia luôn bằng không. Trò chơi tổng bằng không thường được thảo luận với hai người tham gia; khi đó, lợi ích của một bên tất yếu là tổn thất của bên kia. Ngược lại, **trò chơi không tổng bằng không** (non-zero-sum game) cho phép nhiều bên cùng thắng hoặc cùng thua, bao gồm **trò chơi tổng dương** (positive-sum game), **trò chơi tổng âm** (negative-sum game), v.v.

<span id="trò-chơi-đồng-thời-tuần-tự"></span>
### Trò chơi đồng thời / tuần tự

Trong **trò chơi đồng thời** (simultaneous game), tất cả người tham gia đưa ra quyết định cùng lúc mà không biết lựa chọn của người khác. Ví dụ, oẳn tù tì là một trò chơi đồng thời điển hình. Loại trò chơi này thường được biểu diễn bằng ma trận lợi ích và thường không liên quan đến khái niệm thời gian.

Đối lập với nó là **trò chơi tuần tự** (sequential game), tức người tham gia lần lượt hành động. Người hành động sau ít nhất phải quan sát được một phần hành vi của người hành động trước; nếu không, thứ tự trước sau sẽ không có ý nghĩa. Trò chơi tuần tự thường được mô tả bằng cây trò chơi.

<span id="trò-chơi-thông-tin-hoàn-hảo-không-hoàn-hảo"></span>
### Trò chơi thông tin hoàn hảo / không hoàn hảo

**Thông tin hoàn hảo** (perfect information) nghĩa là khi đưa ra quyết định ở bất kỳ thời điểm nào, người tham gia biết đầy đủ mọi sự kiện đã xảy ra trước đó, bao gồm cả trạng thái ban đầu của trò chơi. Ví dụ, cờ tướng, cờ vây, v.v. là các trò chơi thông tin hoàn hảo; còn mạt chược và poker là trò chơi thông tin không hoàn hảo, vì người chơi không biết bài trên tay người khác. Thông tin hoàn hảo thường được dùng để mô tả trò chơi tuần tự; vì trong trò chơi đồng thời người chơi không thể biết hành động sắp chọn của nhau, trò chơi đồng thời thường không được xem là trò chơi thông tin hoàn hảo.

<span id="trò-chơi-thông-tin-đầy-đủ-không-đầy-đủ"></span>
### Trò chơi thông tin đầy đủ / không đầy đủ

**Thông tin đầy đủ** (complete information) nghĩa là tất cả người tham gia hiểu đầy đủ cấu trúc của trò chơi, bao gồm các quyết định có thể chọn của mỗi bên và lợi ích cuối cùng, đồng thời những thông tin này là tri thức chung (common knowledge). Ngược lại là trò chơi thông tin không đầy đủ, trong đó một số yếu tố của trò chơi, chẳng hạn quyết định có thể chọn của đối thủ hoặc hàm lợi ích, là chưa biết đối với người tham gia.

Cần lưu ý rằng "thông tin đầy đủ" và "thông tin hoàn hảo" là hai khái niệm độc lập, không bao hàm nhau. Ví dụ, mạt chược là một trò chơi thông tin đầy đủ nhưng không hoàn hảo: luật chơi và lợi ích đều công khai, nhưng thông tin về bài không minh bạch. Ngược lại, một số trò chơi có mục tiêu ẩn nhưng mọi hành vi đều công khai trong suốt quá trình lại thuộc loại thông tin hoàn hảo nhưng không đầy đủ.

<span id="lý-thuyết-trò-chơi-tổ-hợp"></span>
## Lý thuyết trò chơi tổ hợp

Trong lập trình thi đấu, loại trò chơi thường gặp nhất là **trò chơi tổ hợp** (combinatorial game). Thuật ngữ này thường chỉ những trò chơi khó giải do số trạng thái rất lớn. Vì trò chơi tổ hợp tổng quát khá phức tạp, lý thuyết trò chơi tổ hợp chủ yếu quan tâm đến loại trò chơi sau: hai người thay phiên hành động, thông tin hoàn hảo, không có yếu tố ngẫu nhiên. Cờ tướng, cờ vây, v.v. đều là các trò chơi tổ hợp điển hình.

<span id="trò-chơi-tổ-hợp-công-bằng"></span>
### Trò chơi tổ hợp công bằng

Trang chính: [Trò chơi tổ hợp công bằng](./impartial-game.md)

**Trò chơi công bằng** (impartial game) là trò chơi tổ hợp thỏa các điều kiện sau:

-   Ở mọi trạng thái xác định, các hành động mà mọi người tham gia có thể chọn là hoàn toàn giống nhau, chỉ phụ thuộc vào trạng thái hiện tại và không phụ thuộc vào danh tính;
-   Cùng một trạng thái trong trò chơi không thể được đạt tới nhiều lần; trò chơi kết thúc khi người tham gia không thể hành động, và trò chơi luôn kết thúc sau hữu hạn bước với kết quả không hòa.

Trò chơi công bằng luôn là trò chơi đối xứng.

<span id="trò-chơi-tổ-hợp-không-công-bằng"></span>
### Trò chơi tổ hợp không công bằng

Trang chính: [Trò chơi tổ hợp không công bằng](./partizan-game.md)

Khái niệm đối lập với trò chơi công bằng là **trò chơi không công bằng** (partizan game), tức hành động mà người tham gia có thể thực hiện ở một trạng thái nào đó phụ thuộc vào danh tính của họ. Phần lớn trò chơi cờ, như cờ vua, cờ tướng, cờ vây, gomoku, v.v., đều là trò chơi không công bằng, vì người tham gia chỉ có thể điều khiển quân của mình.

<span id="trò-chơi-chuẩn-misère"></span>
### Trò chơi chuẩn / misère

Trong trò chơi tổ hợp, người thắng thông thường là người tham gia thực hiện hành động cuối cùng trước khi trò chơi kết thúc. Đây được gọi là **trò chơi chuẩn** (normal game). Đối lập với nó là **trò chơi misère** (misère game), tức người tham gia thực hiện hành động cuối cùng trước khi trò chơi kết thúc là người thua.

Trò chơi tổ hợp công bằng và không công bằng đều có thể là trò chơi chuẩn hoặc trò chơi misère.

<span id="tài-liệu-tham-khảo"></span>
## Tài liệu tham khảo

-   [Game theory - Wikipedia](https://en.wikipedia.org/wiki/Game_theory)
-   [Combinatorial game theory - Wikipedia](https://en.wikipedia.org/wiki/Combinatorial_game_theory)
-   [Impartial game - Wikipedia](https://en.wikipedia.org/wiki/Impartial_game)
-   [Misère - Wikipedia](https://en.wikipedia.org/wiki/Mis%C3%A8re)
