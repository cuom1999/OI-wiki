???+ note "Ghi chú"
    Trang này tập trung giới thiệu hệ thống quản lý phiên bản Git. Nội dung liên
    quan đến GitHub xem tại [Tài liệu GitHub](https://docs.github.com/en) và [Cách
    tham gia - OI Wiki](../intro/htc.md).

Git hiện là một trong những hệ thống quản lý phiên bản được sử dụng rộng rãi
nhất. **OI Wiki** cũng dùng Git làm hệ thống quản lý phiên bản.

## Cài đặt

Xem [Git - tải xuống](https://git-scm.com/downloads).

## Cấu hình

Dựa trên phạm vi áp dụng của tệp cấu hình, Git chia tệp cấu hình thành nhiều cấp.
Hai cấp thường dùng hơn là[^note1]:

1.  Tệp cấu hình toàn cục áp dụng cho người dùng hiện tại; khi người dùng này
    thao tác với mọi kho trên hệ thống, Git đều tra cứu tệp cấu hình này.
2.  Tệp cấu hình áp dụng cho kho hiện tại.

Khi nhiều tệp cấu hình cùng thiết lập một tùy chọn, thiết lập cục bộ sẽ tự động
ghi đè thiết lập toàn cục. Vì vậy, nếu cần áp dụng một thiết lập riêng cho một
kho nào đó, hãy sửa thiết lập riêng trong kho đó; thiết lập toàn cục sẽ không bị
ảnh hưởng.

Muốn sửa tệp cấu hình cần dùng lệnh `git config`.

### Thiết lập thông tin người dùng

Sau khi cài Git, việc đầu tiên là thiết lập tên người dùng và email. Các thông
tin này sẽ được dùng trong mỗi lần commit.

```console
$ git config --global user.name "OI Wiki"
$ git config --global user.email oi-wiki@example.com
```

???+ note "Ghi chú"
    Tên người dùng và email trong ví dụ này chỉ dùng để minh họa. Khi cấu hình
    theo nội dung trang này, cần đổi thành thông tin của chính mình.

Tùy chọn `--global` nghĩa là sửa cấu hình toàn cục, tức thiết lập này có hiệu lực
với mọi kho của người dùng hiện tại. Nếu không thêm tùy chọn `--global`, Git sẽ
mặc định sửa tệp cấu hình của kho hiện tại.

Nếu muốn sửa thiết lập riêng của một kho, chạy lệnh không có `--global` trong kho đó.

### Cấu hình trình soạn thảo

```console
$ git config --global core.editor emacs
```

Chạy lệnh trên có thể đổi trình soạn thảo thành [Emacs](./editor/emacs.md).

Trên Windows, trình soạn thảo mặc định của Git có thể được chọn khi cài Git. Nếu
sau đó muốn sửa, nhập lệnh như trên trong Git Bash, thay tên trình soạn thảo bằng
đường dẫn tuyệt đối của trình soạn thảo rồi chạy lệnh.

### Hiển thị cấu hình

Có thể dùng `git config -l` để liệt kê tất cả tham số cấu hình hiện đã đặt. Dùng
`git config --global -l` để liệt kê toàn bộ cấu hình toàn cục.

## Thao tác cơ bản với kho

### Tạo kho Git mới

Để tạo một kho Git mới, nhập lệnh sau trong thư mục muốn tạo kho:

```console
$ git init
```

Git sẽ tạo một thư mục `.git` mới trong thư mục hiện tại; vậy là kho đã được tạo xong.

Nếu muốn clone một kho về máy tính của mình (ví dụ sao chép mã nguồn **OI Wiki**
về cục bộ để chỉnh sửa), dùng lệnh `git clone`.

```console
$ git clone https://github.com/OI-wiki/OI-wiki
```

???+ note "Liên kết của kho từ xa"
    Liên kết kho trong ví dụ này là liên kết HTTP(S), tức dùng phương thức
    HTTP(S) để kết nối đến kho từ xa.

    Thực tế còn nhiều cách khác để kết nối đến kho từ xa. Trong đó, dùng ssh để
    kết nối kho từ xa gọn và an toàn hơn; phần "Quản lý kho từ xa" sẽ
    giới thiệu ngắn gọn cách dùng ssh để kết nối kho từ xa.

Như vậy, nội dung của kho được clone sẽ được lưu vào một thư mục mới cùng tên với
kho dưới thư mục hiện tại. Trong ví dụ này, dưới thư mục hiện tại sẽ xuất hiện
một thư mục mới tên `OI-wiki`.

### Theo dõi tệp

Sau khi sửa một số tệp trong kho, các thay đổi này cần được đưa vào quản lý phiên bản.

Dùng lệnh `git status` để xem trạng thái tệp trong kho hiện tại.

Ví dụ, sau khi thêm một tệp `README.md` trong một kho rỗng, chạy `git status` sẽ
có kết quả như sau:

<!-- scripts.linter.preprocess.fix_details off -->

```console
$ git status
On branch master

No commits yet

Untracked files:
  (use "git add <file>..." to include in what will be committed)

        README.md

nothing added to commit but untracked files present (use "git add" to track)
```

<!-- scripts.linter.preprocess.fix_details on -->

Trong kết quả trên, `Untracked files` chỉ các tệp trước đó chưa được Git theo dõi. Nếu một tệp chưa được theo dõi, các thay đổi đối với tệp đó sẽ không được Git ghi lại.

Chạy lệnh `git add <tệp>` để đưa tệp chỉ định vào vùng staging. Với tệp mới, thao tác này cũng bắt đầu để Git theo dõi tệp đó.

<!-- scripts.linter.preprocess.fix_details off -->

```console
$ git add README.md # Đưa tệp này vào vùng staging
$ git status
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)

        new file:   README.md
```

<!-- scripts.linter.preprocess.fix_details on -->

Lúc này `README.md` đã được Git theo dõi và đặt vào vùng staging. Tiếp theo, chạy lệnh `git commit` để commit thay đổi này.

Nhưng trước khi làm việc đó, sửa nhẹ `README.md`.

<!-- scripts.linter.preprocess.fix_details off -->

```console
$ vim README.md # Sửa tùy ý một chút
$ git status
On branch master

No commits yet

Changes to be committed:
  (use "git rm --cached <file>..." to unstage)

        new file:   README.md

Changes not staged for commit:
  (use "git add <file>..." to update what will be committed)
  (use "git restore -- <file>..." to discard changes in working directory)

        modified:   README.md
```

<!-- scripts.linter.preprocess.fix_details on -->

Lúc này `README.md` đồng thời có thay đổi đã nằm trong vùng staging và thay đổi
chưa nằm trong vùng staging. Việc "đã stage hay chưa" áp dụng cho từng thay đổi,
không phải cho cả tệp. Vì vậy, thay đổi trước đó của `README.md` đã được đưa vào
vùng staging, còn thay đổi sau thì chưa. Nếu lúc này chạy `git commit`, chỉ các
thay đổi đã nằm trong vùng staging được commit, còn thay đổi chưa stage sẽ không
được commit.

Git đã đưa ra gợi ý: chạy `git add README.md` để đưa các thay đổi chưa stage vào
vùng staging.

???+ note "Đưa tất cả thay đổi vào vùng staging cùng lúc"
    Lệnh `git add` sẽ đưa các thay đổi của tệp chỉ định vào vùng staging.

    Trong đa số trường hợp, cần đưa tất cả thay đổi vào vùng staging cùng lúc.
    Khi đó có thể dùng lệnh `git add -A`. Lệnh này sẽ đưa mọi thay đổi (bao gồm
    tệp chưa được theo dõi, không bao gồm tệp bị bỏ qua) vào vùng staging.

    Nếu chỉ cập nhật các tệp đã được theo dõi, không đưa tệp chưa được theo
    dõi vào vùng staging, có thể dùng `git add -u`.

???+ note "Bỏ qua tệp"
    Đôi khi không muốn để Git theo dõi một số tệp (như tệp thực thi, v.v.). Khi
    đó có thể tạo tệp `.gitignore` ở thư mục gốc của kho và ghi các tệp muốn bỏ
    qua vào đó. Git sẽ không theo dõi các tệp này.

    Ví dụ, `*.exe` sẽ tự động bỏ qua mọi tệp có phần mở rộng `.exe` trong kho.

Bây giờ đưa các thay đổi chưa stage vào vùng staging, rồi commit tất cả thay đổi cùng lúc.

```console
$ git add README.md
$ git commit # Sau đó trình soạn thảo sẽ bật lên; cần viết thông điệp commit
[master (root-commit) f992763] initial commit
 1 file changed, 2 insertions(+)
 create mode 100644 README.md
```

Bây giờ lưu ý thông tin của commit này.

`master` nghĩa là hiện đang ở nhánh `master` (vấn đề về nhánh sẽ được giới thiệu
chi tiết bên dưới), `f992763` là một vài ký tự đầu của mã băm SHA-1 của commit
này, phía sau là thông tin của commit.

Điểm cần đặc biệt lưu ý là mã băm SHA-1 trong dòng này: mỗi mã băm tương ứng với
một ảnh chụp (snapshot) của kho tại một thời điểm nào đó. Nhờ đặc tính này, có
thể truy cập ảnh chụp của kho ở một thời điểm trong lịch sử và sửa đổi trên ảnh
chụp đó.

Hai dòng tiếp theo mô tả chi tiết các thay đổi tệp liên quan đến lần cập nhật này.

Ngoài ra, trong quá trình commit có thể dùng một vài tham số để rút gọn thao tác:

-   `-a`: trước khi commit, đưa mọi thay đổi của các tệp đã được theo dõi vào
    vùng staging. Lưu ý rằng các tệp chưa được theo dõi (tệp mới tạo) sẽ không tự
    động được thêm vào vùng staging; cần dùng lệnh `git add` để thêm thủ công.
-   `-m`: phía sau tham số này là thông điệp commit, nghĩa là commit lần thay đổi
    này với thông điệp đó. Ví dụ `git commit -m "fix: typo"` sẽ tạo một commit có
    tiêu đề `fix: typo`.

### Xem lịch sử commit

Dùng lệnh `git log` để xem lịch sử commit của kho.

Lịch sử commit ghi lại mã băm SHA-1, tác giả commit, thời gian commit và thông điệp commit của mỗi lần commit.

```console
$ git log
commit ae9dd3768a405b348bc6170c7acb8b6cb5fe333e (HEAD -> master)
Author: OI Wiki <oi-wiki@example.com>
Date:   Sun Sep 13 00:30:18 2020 +0800

    feat: update README.md

commit f99276362a3c260d439364c505a7a06859f34bf9
Author: OI Wiki <oi-wiki@example.com>
Date:   Sun Sep 13 00:06:07 2020 +0800

    initial commit
```

## Quản lý nhánh

Vì sao quản lý phiên bản cần quản lý nhánh? Câu trả lời chủ yếu có hai điểm:

1.  Sửa trực tiếp nhánh chính không chỉ làm lịch sử rối hơn mà cũng có thể gây ra một số hậu quả nguy hiểm.
2.  Thông qua nhánh, có thể tập trung vào công việc hiện tại. Nếu cần hoàn thành hai công việc khác nhau, hãy mở hai nhánh; công việc giữa hai nhánh không ảnh hưởng lẫn nhau.

Trong Git, nói đơn giản, nhánh là con trỏ trỏ đến một ảnh chụp nào đó. Mỗi lần commit, Git đều tạo một ảnh chụp cho lần commit này và di chuyển con trỏ của nhánh hiện tại đến ảnh chụp đó.

Ngoài ra còn có con trỏ HEAD, nó trỏ đến nhánh hiện tại.

Nói đơn giản, quá trình chuyển nhánh là đổi con trỏ HEAD từ nhánh hiện tại sang một nhánh khác. Trong quá trình này, Git sẽ tự động cập nhật tệp, để sau khi chuyển nhánh, trạng thái kho khớp với ảnh chụp mà nhánh đích trỏ tới.

### Tạo nhánh

Dùng lệnh `git branch` để tạo nhánh, lệnh `git switch` để chuyển nhánh, và lệnh `git switch -c` để tạo nhánh rồi chuyển sang nhánh mới này.

```console
$ git switch -c dev # Tạo một nhánh mới tên dev và chuyển nhánh hiện tại sang dev
Switched to branch 'dev'
$ git branch # Xem danh sách nhánh
  master
* dev
```

Dấu sao trước `dev` cho biết nhánh hiện tại của kho là `dev`; các thay đổi tiếp theo đối với kho này sẽ được ghi trên nhánh này.

Thử tạo một tệp mới `aplusb.cpp`.

```console
$ vim aplusb.cpp
$ git add aplusb.cpp
$ git commit -m "feat: add A+B Problem code"
[dev 5da093b] feat: add A+B Problem code
 1 file changed, 7 insertions(+)
 create mode 100644 aplusb.cpp
```

Bây giờ chuyển về nhánh `master`. Lúc này trong thư mục không còn `aplusb.cpp`; mọi thứ trở về trạng thái khi vừa tạo nhánh `dev`. Khi đó có thể tiếp tục hoàn thành công việc khác trên nhánh `master`.

```console
$ git switch master
Switched to branch 'master'
$ vim README.md # Sửa nhẹ README
$ git commit -a -m "feat: update README.md"
[master 5ca15f0] feat: update README.md
 1 file changed, 1 insertion(+), 1 deletion(-)
```

Hình dưới đây giải thích quá trình thao tác vừa rồi.

![](./images/git1.svg)

Nhánh `master` được tô đỏ, cho biết sau các thao tác này, nó là nhánh hiện tại (tức vị trí HEAD trỏ tới).

-   Ban đầu `master` trỏ đến ảnh chụp `ae9dd37`.
-   Tiếp đó tạo một nhánh dev mới tại vị trí của `master`; ban đầu nhánh này trỏ cùng vị trí với master.
-   Trên nhánh `dev`, thực hiện một số thay đổi (tạo `aplusb.cpp`) rồi commit một lần. Sau commit này, nhánh `dev` trỏ đến ảnh chụp `5da093b`.
-   Sau khi chuyển về nhánh `master`, vì nhánh `master` vẫn trỏ đến `ae9dd37` và chưa tạo `aplusb.cpp`, nên trong kho không có tệp này.
-   Tiếp theo, sửa trên nhánh `master` (cập nhật `README.md`) rồi commit một lần; nhánh `master` trỏ đến ảnh chụp `5ca15f0`.

### Gộp nhánh

Khi công việc trên một nhánh đã hoàn thành, có thể gộp các công việc đó vào một nhánh khác.

Tiếp tục ví dụ trên: công việc của nhánh `dev` đã hoàn thành. Dùng lệnh `git merge` để gộp nhánh này vào nhánh hiện tại (`master`):

```console
$ git merge dev
Merge made by the 'recursive' strategy.
 aplusb.cpp | 7 +++++++
 1 file changed, 7 insertions(+)
 create mode 100644 aplusb.cpp
```

![](./images/git2.svg)

Lần gộp này cụ thể được thực hiện như thế nào?

Trước khi gộp, `master` trỏ đến `5ca15f0`, còn `dev` trỏ đến `5da093b`; hai trạng thái này không nằm trên cùng một chuỗi.

Git sẽ tìm tổ tiên chung gần nhất của hai trạng thái này (trong hình trên là `ae9dd37`) và thực hiện một lần gộp dựa trên ba ảnh chụp. Kết quả gộp của ba ảnh chụp trở thành một ảnh chụp mới, rồi nhánh hiện tại được trỏ đến ảnh chụp này.

Bản thân quá trình gộp cũng là một commit. Tuy nhiên, khác với commit thông thường, commit gộp (merge commit) có nhiều hơn một commit tiền nhiệm; nó là kết quả sau khi gộp nhiều trạng thái commit.

Sau khi gộp xong, nhánh `dev` đã hoàn thành nhiệm vụ. Lúc này có thể dùng lệnh sau để xóa nhánh `dev`:

```console
$ git branch -d dev # Với nhánh chưa gộp, có thể dùng tham số -D để ép xóa
```

Tuy nhiên, quá trình gộp không phải lúc nào cũng thuận lợi. Trong một số trường hợp, quá trình gộp có thể xuất hiện xung đột; vấn đề này sẽ được nói tiếp theo.

### Giải quyết xung đột khi gộp

Nếu ở hai nhánh, cùng một phần của cùng một tệp bị sửa theo hai cách khác nhau, Git sẽ không thể tự động gộp hai nhánh này, tức xảy ra xung đột khi gộp (merge conflict).

Tiếp tục ví dụ trên. Giả sử trên cơ sở nhánh `master` sau khi gộp, mở một nhánh mới `readme-refactor` để viết lại README. Nhưng do một số sơ suất, README đồng thời bị sửa trên cả nhánh `readme-refactor` và `master`.

Ban đầu README như sau:

```markdown
# Đây là một kho thử nghiệm.

Kho này chứa một số mã C++.
```

README trên nhánh `readme-refactor` như sau:

```markdown
# Thư viện mã

Kho này chứa một số mã C++.
```

README trên nhánh `master` như sau:

```markdown
# Đây là một thư viện mã.

Kho này chứa một số mã C++.
```

Lúc này chạy lệnh `git merge readme-refactor`, Git báo xuất hiện xung đột khi gộp.

Chạy lệnh `git status` để xem những tệp nào gây xung đột.

<!-- scripts.linter.preprocess.fix_details off -->

```console
$ git status
On branch master
You have unmerged paths.
  (fix conflicts and run "git commit")

Unmerged paths:
  (use "git add <file>..." to mark resolution)

    both modified:      README.md

no changes added to commit (use "git add" and/or "git commit -a")
```

<!-- scripts.linter.preprocess.fix_details on -->

Giải quyết xung đột thế nào? Với mỗi tệp xảy ra xung đột khi gộp, Git sẽ thêm các dấu đánh dấu xung đột vào tệp đó. Ví dụ trong tệp `README.md` của ví dụ này, khi mở ra sẽ thấy như sau:

    <<<<<<< HEAD
    # Đây là một thư viện mã.
    =======
    # Thư viện mã
    >>>>>>> readme-refactor

    Kho này chứa một số mã C++.

`=======` là đường phân cách chia nội dung của hai nhánh; phần giữa dấu `<<<<<<< HEAD` và `=======` là nội dung của con trỏ HEAD (nhánh `master`), còn phần giữa `=======` và dấu `>>>>>>> readme-refactor` là nội dung của nhánh `readme-refactor`.

Xử lý xung đột bằng cách chỉnh sửa văn bản, xóa các dấu xung đột này, lưu tệp, đưa các tệp đó vào vùng staging rồi commit.

```console
$ git add README.md # Đưa tệp đã giải quyết xung đột vào vùng staging
$ git commit
[master fe92c6b] Merge branch readme-refactor into master
```

### Các cách gộp khác

Mặc định, Git dùng cách gộp thường (Merge) để gộp hai nhánh. Khi dùng cách này để gộp nhánh B vào nhánh A, toàn bộ commit của nhánh B sẽ được đưa vào lịch sử commit của nhánh A.

Ngoài ra, Git còn cung cấp hai cách gộp nhánh khác: Squash và Rebase.

#### Squash

Khi dùng cách gộp nén (Squash) để gộp nhánh B vào nhánh A, tất cả thay đổi trên nhánh B sẽ được gộp thành một commit rồi commit vào nhánh A.

Thêm tham số `--squash` vào `git merge` để dùng cách Squash khi gộp nhánh.

```console
$ git merge <branch> --squash
```

Lưu ý rằng sau khi chạy lệnh trên, Git chỉ đưa toàn bộ thay đổi của nhánh B vào vùng staging của nhánh A; tiếp theo vẫn cần chạy một lần `git commit` để hoàn thành việc gộp.

Dùng cách gộp nén (Squash) có thể rút gọn lịch sử commit, nhưng sẽ mất thông tin chi tiết của từng commit (người commit từng lần, thay đổi của từng commit, v.v.), chỉ giữ lại thông tin sau khi gộp thành một tổng thể (người commit của từng commit sẽ được liệt kê trong thông điệp commit dưới dạng "Co-authored-by"). Tuy nhiên, nếu dùng "Squash and Merge" trên GitHub, thông tin ban đầu vẫn có thể xem trong Pull Request.

#### Rebase

Khi dùng cách đổi nền (Rebase) để gộp nhánh B vào nhánh A, từng commit trên nhánh B sẽ được thêm riêng vào nhánh A, thay vì tạo một commit gộp (merge commit) để gộp nội dung hai nhánh như cách Merge[^note2].

Trước hết, chuyển sang nhánh B, sau đó rebase nhánh B lên nhánh A:

```console
$ git checkout B
$ git rebase A
```

Bây giờ chuyển về nhánh A, rồi chạy thêm một lần lệnh `git merge` để hoàn thành việc gộp nội dung nhánh B vào nhánh A.

```console
$ git checkout A
$ git merge B
```

Dùng cách đổi nền (Rebase) để hoàn thành việc gộp có thể làm lịch sử commit tuyến tính hơn. Trong bối cảnh phù hợp, dùng Rebase đúng cách có thể đạt hiệu quả tốt hơn Merge. Nhưng cách này sẽ thay đổi lịch sử commit; khi rebase và khi thực hiện các thao tác gộp liên quan sau rebase, khả năng xuất hiện xung đột đều tăng lên. Nếu thao tác không đúng, lịch sử commit có thể còn rối hơn. Vì vậy, nếu chưa hiểu đầy đủ thao tác Rebase, không nên dùng.

## Quản lý kho từ xa

Sau khi hoàn thành thay đổi ở cục bộ, có thể cần đẩy các thay đổi này lên các nền tảng lưu trữ kho Git như GitHub. Các kho được lưu trữ trên những nền tảng này thuộc phạm trù kho từ xa: có thể lấy thông tin từ những kho đó, cũng có thể đẩy thay đổi của mình lên kho từ xa. Việc cộng tác với người khác thường không thể tách khỏi kho từ xa, vì vậy học cách quản lý kho từ xa là cần thiết.

### Xem kho từ xa

Dùng lệnh `git remote` để xem danh sách kho từ xa của kho hiện tại.

Nếu kho hiện tại được clone về, thường sẽ có một kho từ xa tên origin; liên kết của nó chính là liên kết dùng khi clone.

```console
$ git remote
origin
```

Nếu muốn xem thông tin chi tiết của một kho từ xa, có thể làm như sau:

```console
$ git remote show origin
* remote origin
  Fetch URL: git@github.com:OI-wiki/OI-wiki.git
  Push  URL: git@github.com:OI-wiki/OI-wiki.git
  HEAD branch: master
  Remote branches:
    git             tracked
    master          tracked
  ...
```

### Cấu hình kho từ xa

Chạy lệnh `git remote add <name> <url>` để thêm một kho từ xa có tên `name` và liên kết `url`.

Chạy `git remote rename <oldname> <newname>` để đổi tên kho từ xa tên `oldname` thành `newname`.

Chạy `git remote rm <name>` để xóa kho từ xa tên `name`.

Chạy `git remote get-url <name>` để xem liên kết của kho từ xa tên `name`.

Chạy `git remote set-url <name> <newurl>` để đổi liên kết của kho từ xa tên `name` thành `newurl`.

### Lấy thay đổi từ kho từ xa

Trong kho từ xa, người khác có thể đẩy một số thay đổi. Chạy lệnh `git fetch` để lấy các thay đổi đó về cục bộ.

```console
$ git fetch <remote-name> # Lấy thay đổi của <remote-name>
```

Lưu ý rằng lệnh `git fetch` chỉ lấy thay đổi của kho từ xa, chứ không gộp các thay đổi này vào kho cục bộ. Nếu cần gộp các thay đổi này, có thể dùng lệnh `git pull`. Mặc định, `git pull` tương đương với `git fetch` rồi `git merge FETCH_HEAD`.

```console
$ git pull <remote-name> <branch> # Lấy thay đổi của <remote-name>, rồi gộp các thay đổi này vào HEAD
```

### Đẩy thay đổi lên kho từ xa

Sau khi hoàn thành một số thay đổi, dùng lệnh `git push` để đẩy các thay đổi này lên kho từ xa.

```console
$ git push <remote> <from>:<to> # Đẩy thay đổi của nhánh cục bộ <from> lên nhánh <to> của <remote>
```

Tùy yêu cầu của kho từ xa, có thể phải nhập tên người dùng và mật khẩu của tài khoản kho từ xa.

Lưu ý rằng để thay đổi cục bộ được đẩy thành công, phải thỏa mãn hai điều kiện:
có quyền ghi vào kho (nhánh) này, và nhánh cục bộ mới hơn nhánh tương ứng trên
kho từ xa (có thể hiểu là không có ai push trong khoảng thời gian sửa). Khi nhánh
từ xa có thay đổi mới mà nhánh hiện tại chưa có, có thể chạy lệnh `git pull` để
gộp rồi commit.

Nếu cần buộc đẩy thay đổi của nhánh cục bộ lên kho từ xa, có thể thêm tham số
`-f`. Khi đó **lịch sử commit của kho từ xa sẽ bị lịch sử commit cục bộ ghi đè**,
vì vậy cần dùng lệnh này thận trọng. Lựa chọn tốt hơn là dùng tham số
`--force-with-lease`, tham số này chỉ ghi đè khi kho từ xa chưa cập nhật. Lưu ý
rằng "cập nhật" trong ngữ cảnh này được tính so với lần fetch gần nhất; nếu dùng
chức năng Auto Fetch do VS Code cung cấp, có thể không nhận ra đã có cập nhật,
khiến `--force-with-lease` nguy hiểm chẳng khác gì `-f`.

### Theo dõi nhánh từ xa

Bằng cách thiết lập một nhánh cục bộ theo dõi nhánh từ xa, có thể xem khác biệt
giữa nhánh cục bộ và nhánh từ xa dễ hơn, đồng thời rút gọn thao tác
khi tương tác với nhánh từ xa.

Trước khi bắt đầu theo dõi, cần chạy `git fetch <remote-name>` để lấy thông tin kho từ xa về cục bộ.

Tiếp theo chạy `git switch <remote-branch>`; Git sẽ tự động tạo một nhánh mới tên
`<remote-branch>` ở cục bộ và thiết lập nhánh này tự động theo dõi nhánh từ xa
tương ứng.

???+ note "Ghi chú"
    Lưu ý: chỉ khi cục bộ chưa tồn tại nhánh này và đúng một nhánh từ xa có tên
    khớp với nhánh đó, Git mới tự động tạo nhánh này và thiết lập nó theo dõi
    nhánh từ xa tương ứng.

Lúc này chạy lệnh `git status`, Git sẽ thông báo khác biệt giữa nhánh hiện tại và nhánh từ xa.

Vì đã thiết lập nhánh từ xa mà nhánh cục bộ theo dõi, lệnh đẩy lên nhánh từ xa
cũng được rút gọn. Chạy lệnh `git push`, các thay đổi thực hiện trên
nhánh cục bộ sẽ được đẩy lên nhánh từ xa mà nó theo dõi.

Đối với nhánh cục bộ đã tồn tại, có thể thiết lập nhánh theo dõi từ xa tương ứng
bằng cách chạy `git branch -u <remote-name>/<remote-branch>` dưới nhánh hiện tại.
Lệnh này sẽ thiết lập nhánh cục bộ hiện tại theo dõi nhánh từ xa
`<remote-name>/<remote-branch>`.

### Kết nối bằng ssh

So với HTTP(S), dùng ssh để kết nối kho từ xa gọn và an toàn hơn.

Trước khi dùng ssh để kết nối kho từ xa, cần thêm khóa ssh ở cục bộ. Sau đó cần
tải **khóa công khai** của khóa ssh đã thêm ở cục bộ lên tài khoản kho từ xa.

Vì bài này chủ yếu hướng dẫn người đóng góp **OI Wiki** dùng Git, phần này dẫn lại [hướng dẫn trong Tài liệu GitHub](https://docs.github.com/en/authentication/connecting-to-github-with-ssh) để người đọc tham khảo.

Sau khi hoàn thành các bước trên, có thể kết nối đến kho từ xa bằng ssh. Dưới đây là một lệnh clone kho **OI Wiki** thông qua ssh:

```console
$ git clone git@github.com:OI-wiki/OI-wiki.git
```

Quá trình đẩy thay đổi lên kho từ xa tương tự khi dùng HTTP(S). Nhưng khi dùng ssh, có thể bỏ qua bước xác thực tên tài khoản và mật khẩu của kho từ xa.

## Công cụ GUI cho Git

Với người chưa quen dòng lệnh, Git thuần dòng lệnh có thể hơi khó bắt đầu; dùng công cụ GUI có thể giảm một phần độ khó khi học Git. Ngoài ra, so với dòng lệnh, công cụ GUI có trải nghiệm tốt hơn ở một mức độ nhất định khi xem diff và log.

Bản thân Git có GUI đi kèm, và trên thị trường cũng có nhiều công cụ Git GUI xuất sắc, ví dụ TortoiseGit dành cho người dùng Windows[^note3], Sourcetree hỗ trợ Windows và Mac[^note4], v.v.

Phần này giới thiệu ngắn gọn cách dùng TortoiseGit. Sau khi tải và cài TortoiseGit, trong thư mục kho cục bộ, nhấp chuột phải sẽ hiện các chức năng Git trong menu chuột phải.

![Menu chuột phải của TortoiseGit trong thư mục kho cục bộ](images/git11.png)

Phần này không trình bày chi tiết cách sử dụng nữa; có thể tham khảo tài liệu sử dụng trên trang chính thức hoặc học qua công cụ tìm kiếm, ví dụ [sổ tay TortoiseGit](https://tortoisegit.org/docs/tortoisegit/index.html).

Nhiều công cụ GUI có hỗ trợ nhiều ngôn ngữ giao diện, ví dụ Git Desktop và TortoiseGit. Tuy nhiên vẫn có một số bản dịch đọc hơi gượng, nên khuyến nghị dùng bản tiếng Anh nếu cần đối chiếu thuật ngữ chính xác.

## Liên kết ngoài

-   [Tài liệu tham khảo Git](https://git-scm.com/docs)
-   [Sách Pro Git](https://git-scm.com/book/en/v2)
-   [Học phân nhánh Git](https://learngitbranching.js.org/)

## Tài liệu tham khảo và chú thích

[^note1]: Git còn có một tệp cấu hình chung dành cho mọi người dùng trên hệ thống và mọi kho trên hệ thống. Tệp cấu hình này có phạm vi bao phủ rộng nhất, cấp cao hơn tệp cấu hình người dùng. Vì cấu hình này ít dùng trong thực tế, phần này không trình bày thêm.

[^note2]: [Sách Pro Git](https://git-scm.com/book/en/v2/Git-Branching-Rebasing) cung cấp hình minh họa quá trình Rebase; nhờ hình ảnh, người đọc có thể hiểu cơ chế Rebase tốt hơn.

[^note3]: [TortoiseGit](https://tortoisegit.org/)

[^note4]: [Sourcetree](https://www.sourcetreeapp.com/)
