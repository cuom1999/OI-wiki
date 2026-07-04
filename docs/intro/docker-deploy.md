Trang này giới thiệu cách triển khai môi trường **OI Wiki** bằng Docker.

???+ warning "Warning"
    Các bước sau cần được thực hiện với quyền root hoặc bằng người dùng thuộc nhóm docker.

## Kéo image **OI Wiki**

```bash
# Chỉ cần chạy một trong các lệnh sau trên máy chủ
# Image Docker Hub (kho image chính thức)
docker pull 24oi/oi-wiki
# Image DaoCloud Hub (kho image trong nước)
docker pull daocloud.io/sirius/oi-wiki
# Image Tencent Hub (kho image trong nước)
docker pull ccr.ccs.tencentyun.com/oi-wiki/oi-wiki
```

## Tự build image

```bash
# Chạy các lệnh sau trên máy chủ
# Clone Git repository
git clone https://github.com/OI-wiki/OI-wiki.git
cd OI-wiki/
# Build image
docker build -t [name][:tag] . --build-arg [variable1]=[value1] [variable2]=[value2]...
```

-   (Bắt buộc) đặt `[name]` để đặt tên image; (tùy chọn) đặt `[tag]` để đặt nhãn image. Nếu đặt tag, tên image khi chạy sẽ gồm hai phần.
-   Có thể đặt biến môi trường thông qua tham số `--build-arg`.

Các biến môi trường có thể dùng:

-   Có thể đặt `WIKI_REPO` để dùng mirror site của kho Wiki (nếu không đặt thì tự động dùng GitHub)
-   Có thể đặt `PYPI_MIRROR` để dùng mirror site của kho PyPI (nếu không đặt thì tự động dùng PyPI chính thức)
    -   Ở Trung Quốc, nên dùng mirror TUNA `https://pypi.tuna.tsinghua.edu.cn/simple/`
-   Có thể đặt `LISTEN_IP` để đổi IP lắng nghe (nếu không đặt thì là `0.0.0.0`, tức lắng nghe truy cập từ mọi IP)
-   Có thể đặt `LISTEN_PORT` để đổi cổng lắng nghe (nếu không đặt thì là `8000`)

Ví dụ:

```bash
docker build -t OI_Wiki . --build-arg WIKI_REPO=https://hub.fastgit.xyz/OI-wiki/OI-wiki.git PYPI_MIRROR=https://pypi.tuna.tsinghua.edu.cn/simple/
# Xây dựng một image tên là OI_Wiki (tag mặc định), dùng dịch vụ FastGit để tăng tốc clone và dùng mirror TUNA.
```

## Chạy container

```bash
# Chạy lệnh sau trên máy chủ
docker run -d -it [image]
```

-   (Bắt buộc) đặt `[image]` để chỉ định image. Ví dụ, image kéo từ Docker Hub là `24oi/oi-wiki`; image kéo từ DaoCloud Hub là `daocloud.io/sirius/oi-wiki`.
-   (Bắt buộc) đặt `-p [port]:8000` để ánh xạ cổng container sang cổng trên máy chủ. Nếu không viết tùy chọn này thì mặc định không công khai cổng. Khi đặt, hãy thay `[port]` bằng cổng trên máy chủ. Sau khi đặt, có thể truy cập **OI Wiki** trên máy chủ qua `http://127.0.0.1:[port]`.
-   Đặt `--name [name]` để đặt tên container. Mặc định để trống. Khi đặt, hãy thay `[name]` bằng tên container tự chọn. Nếu muốn xem container id, hãy nhập `docker ps`.

## Sử dụng container

???+ note "Note"
    Ví dụ dựa trên triển khai bằng Ubuntu latest.

Vào container:

```bash
# Chạy lệnh sau trên máy chủ
docker exec -it [name] /bin/bash
```

Nếu bỏ `-d` trong lệnh chạy container ở trên, bạn có thể vào thẳng bash của container; sau khi thoát thì container sẽ dừng. Khi thêm `-d`, container chạy nền và cần dừng thủ công. Cách vào container ở trên dành cho container được chạy với `-d`.

Cách dùng đặc biệt:

```bash
# Chạy các lệnh sau trong container
# Cập nhật Git repository
wiki-upd

# Dùng theme tùy chỉnh của chúng tôi
wiki-theme

# Build mkdocs, trang tĩnh sẽ được tạo trong thư mục site
wiki-bld

# Build mkdocs và render MathJax, trang tĩnh sẽ được tạo trong thư mục site
wiki-bld-math

# Chạy một server; truy cập http://127.0.0.1:8000 trong container hoặc http://127.0.0.1:[port] trên máy chủ để xem kết quả
wiki-svr

# Sửa Markdown
wiki-o
```

Thoát container:

```bash
# Chạy các lệnh sau trong container
# Thoát
exit
```

## Dừng container

```bash
# Chạy lệnh sau trên máy chủ
docker stop [name]
```

## Khởi động container

```bash
# Chạy lệnh sau trên máy chủ
docker start [name]
```

## Khởi động lại container

```bash
# Chạy lệnh sau trên máy chủ
docker restart [name]
```

## Xóa container

```bash
# Chạy các lệnh sau trên máy chủ
# Hãy dừng container trước khi xóa
docker rm [name]
```

## Cập nhật image

Chỉ cần `pull` lại một lần nữa; thông thường image sẽ không được cập nhật.

## Xóa image

```bash
# Chạy các lệnh sau trên máy chủ
# Trước khi xóa, hãy xóa các container được tạo từ image oi-wiki
docker rmi [image]
```

## Câu hỏi

Nếu có câu hỏi, bạn có thể mở [issue](https://github.com/OI-wiki/OI-wiki/issues/new/choose)!
