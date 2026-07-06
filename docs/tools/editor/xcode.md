author: shenyouran, Xeonacid, StudyingFather, CoelacanthusHex

## Giới thiệu

Xcode là một môi trường phát triển tích hợp (IDE) chạy trên macOS, do Apple Inc. phát triển.

## Cài đặt

### Cách 1

Mở App Store có sẵn trên máy Mac (hoặc thử [liên kết nhanh](https://apps.apple.com/cn/app/xcode/id497799835?mt=12)) để tải Xcode. Nhấp `Get` (`Tải`), rồi nhập mật khẩu tài khoản Apple để bắt đầu tải xuống và cài đặt.

![](images/xcode-1.jpg)

### Cách 2

Truy cập [trang tải xuống dành cho nhà phát triển Apple](https://developer.apple.com/download/more/), đăng nhập bằng tài khoản Apple, rồi tìm gói cài đặt phiên bản ổn định mới nhất của Xcode (tức phiên bản mới nhất không phải Beta; trong hình là 11.6):

![](images/xcode-2.jpg)

Nhấp tên tệp màu xanh trong hộp thoại bật lên để tải xuống. Sau khi có tệp nén, dùng công cụ có sẵn của hệ thống để giải nén và nhận tệp `Xcode.app`. Di chuyển tệp này vào thư mục `Applications` để sử dụng.

## Cấu hình cơ bản

Khi mở Xcode lần đầu, có thể xuất hiện cửa sổ bật lên sau:

![](images/xcode-3.jpg)

Cửa sổ này là trình hướng dẫn cài đặt các thành phần của Xcode. Nhấp `Install` (`Cài đặt`) và nhập mật khẩu của người dùng hiện tại.

Sau khi cài đặt xong, phía bên trái giao diện sẽ hiển thị:

![](images/xcode-4.jpg)

Nhấp `Create a new Xcode project` (`Tạo một dự án Xcode mới`), sau đó chọn `Command Line Tool` (`Công cụ dòng lệnh`) trong mục `macOS` ở phía trên, rồi nhấp `Next` (`Tiếp theo`) ở góc dưới bên phải.

![](images/xcode-5.jpg)

Tiếp theo là bước đặt tên cho dự án, nhưng điều quan trọng nhất là chọn ngôn ngữ của dự án. Tùy nhu cầu, tại mục `Language` (`Ngôn ngữ`) ở phía dưới cùng, có thể chọn C hoặc C++:

![](images/xcode-6.jpg)

Thư mục của dự án có thể chọn theo nhu cầu. Sau khi tạo xong, Xcode sẽ tự động mở dự án này và tự tạo một tệp `main` (đuôi của C là `.c`, đuôi của C++ là `.cpp`).

Nhấp vào tệp này để mở vùng soạn thảo:

![](images/xcode-7.jpg)

Sau khi viết mã, có thể nhấn `⌘B` để biên dịch (`Build`), `⌘R` để chạy (`Run`). Sau khi chạy, kéo giao diện ra sẽ thấy ba phần:

![](images/xcode-8.jpg)

Thông thường chỉ cần dùng vùng soạn thảo và vùng chạy. Nếu chương trình có dữ liệu vào, nhập trong vùng chạy rồi sẽ nhận được kết quả đầu ra. Giao diện hiển thị như sau:

![](images/xcode-9.jpg)

Với cách này, có thể chạy các chương trình C/C++ tệp đơn.

## Sử dụng tệp tiêu đề tổng hợp

Trong quá trình viết mã, có thể cần dùng nhiều tệp tiêu đề. Một cách xử lý phổ biến là dùng tệp tiêu đề tổng hợp.

Khi thêm tệp tiêu đề tổng hợp ở dòng đầu tiên của mã nguồn, quá trình biên dịch lại báo: `'bits/stdc++.h' file not found`, nghĩa là không tìm thấy tệp tiêu đề này.

![](images/xcode-10.jpg)

Nguyên nhân là trên macOS, mặc định [libc++](https://libcxx.llvm.org/) được dùng làm phần triển khai thư viện chuẩn C++, còn tệp tiêu đề tổng hợp `bits/stdc++.h` là phần riêng của [GNU libstdc++](https://gcc.gnu.org/onlinedocs/libstdc++/).

Tuy vậy, vẫn có thể tự tạo một tệp tiêu đề tổng hợp để sử dụng.

### Bước 1

Mở Terminal.app, đi tới thư mục nơi Xcode lưu các tệp tiêu đề, tức là:

```bash
cd /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/include/c++/v1
```

Nếu phiên bản Xcode từ 12.5 trở lên, dùng:

```bash
cd /Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX.sdk/usr/include/c++/v1/
```

### Bước 2

Tạo thư mục `bits` rồi đi vào thư mục đó:

```bash
mkdir bits
cd bits
```

Dùng vim để tạo tệp `stdc++.h`:

```bash
vim stdc++.h
```

Giao diện như sau:

![](images/xcode-11.jpg)

Tiếp theo, cần chỉnh sửa tệp bằng vim. Nhấn phím `i` (`insert`, chèn) để vào chế độ chèn/chỉnh sửa (bên dưới xuất hiện `-- INSERT --`):

![](images/xcode-12.jpg)

Sao chép đoạn mã dưới đây và dán vào trình dòng lệnh:

??? note "Đoạn mã tệp tiêu đề tổng hợp"
    ```cpp
    // C++ includes used for precompiling -*- C++ -*-
    
    // Copyright (C) 2003-2020 Free Software Foundation, Inc.
    //
    // This file is part of the GNU ISO C++ Library.  This library is free
    // software; you can redistribute it and/or modify it under the
    // terms of the GNU General Public License as published by the
    // Free Software Foundation; either version 3, or (at your option)
    // any later version.
    
    // This library is distributed in the hope that it will be useful,
    // but WITHOUT ANY WARRANTY; without even the implied warranty of
    // MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    // GNU General Public License for more details.
    
    // Under Section 7 of GPL version 3, you are granted additional
    // permissions described in the GCC Runtime Library Exception, version
    // 3.1, as published by the Free Software Foundation.
    
    // You should have received a copy of the GNU General Public License and
    // a copy of the GCC Runtime Library Exception along with this program;
    // see the files COPYING3 and COPYING.RUNTIME respectively.  If not, see
    // <http://www.gnu.org/licenses/>.
    
    /** @file stdc++.h
     *  This is an implementation file for a precompiled header.
     */
    
    // 17.4.1.2 Headers
    
    // C
    #ifndef _GLIBCXX_NO_ASSERT
    #include <cassert>
    #endif
    #include <cctype>
    #include <cerrno>
    #include <cfloat>
    #include <ciso646>
    #include <climits>
    #include <clocale>
    #include <cmath>
    #include <csetjmp>
    #include <csignal>
    #include <cstdarg>
    #include <cstddef>
    #include <cstdio>
    #include <cstdlib>
    #include <cstring>
    #include <ctime>
    #include <cwchar>
    #include <cwctype>
    
    #if __cplusplus >= 201103L
    #include <ccomplex>
    #include <cfenv>
    #include <cinttypes>
    #include <cstdbool>
    #include <cstdint>
    #include <ctgmath>
    /* https://stackoverflow.com/a/25892335/15125422 */
    #if defined(__GLIBCXX__) || defined(__GLIBCPP__)
    #include <cstdalign>
    #include <cuchar>
    #endif
    #endif
    
    // C++
    #include <algorithm>
    #include <bitset>
    #include <complex>
    #include <deque>
    #include <exception>
    #include <fstream>
    #include <functional>
    #include <iomanip>
    #include <ios>
    #include <iosfwd>
    #include <iostream>
    #include <istream>
    #include <iterator>
    #include <limits>
    #include <list>
    #include <locale>
    #include <map>
    #include <memory>
    #include <new>
    #include <numeric>
    #include <ostream>
    #include <queue>
    #include <set>
    #include <sstream>
    #include <stack>
    #include <stdexcept>
    #include <streambuf>
    #include <string>
    #include <typeinfo>
    #include <utility>
    #include <valarray>
    #include <vector>
    
    #if __cplusplus >= 201103L
    #include <array>
    #include <atomic>
    #include <chrono>
    #include <codecvt>
    #include <condition_variable>
    #include <forward_list>
    #include <future>
    #include <initializer_list>
    #include <mutex>
    #include <random>
    #include <ratio>
    #include <regex>
    #include <scoped_allocator>
    #include <system_error>
    #include <thread>
    #include <tuple>
    #include <type_traits>
    #include <typeindex>
    #include <unordered_map>
    #include <unordered_set>
    #endif
    
    #if __cplusplus >= 201402L
    #include <shared_mutex>
    #endif
    
    #if __cplusplus >= 201703L
    #include <any>
    #include <charconv>
    // #include <execution>
    #include <filesystem>
    #include <memory_resource>
    #include <optional>
    #include <string_view>
    #include <variant>
    #endif
    
    #if __cplusplus > 201703L
    #include <bit>
    #include <compare>
    #include <concepts>
    #include <numbers>
    #include <ranges>
    #include <span>
    #include <stop_token>
    // #include <syncstream>
    #include <version>
    #endif
    ```

Tệp này lấy từ [libstdc++ phiên bản 10.2.0](https://github.com/gcc-mirror/gcc/blob/ee5c3db6c5b2c3332912fb4c9cfa2864569ebd9a/libstdc++-v3/include/precompiled/stdc++.h) và đã được chỉnh sửa nhẹ để tương thích với libc++.

Nhấn <kbd>Esc</kbd> ở góc trên bên trái bàn phím để thoát chế độ chỉnh sửa, sau đó nhập trực tiếp `:wq` rồi xuống dòng để lưu tệp.

### Bước 3

Đóng trình dòng lệnh và quay lại Xcode. Nhấn lại ⌘B/⌘R để biên dịch/chạy; lúc này quá trình biên dịch sẽ thành công:

![](images/xcode-13.jpg)

## Ưu và nhược điểm

Ưu điểm: do Apple phát triển, phù hợp với người dùng Mac, giao diện đầy đủ và hoàn thiện.

Nhược điểm: Xcode chủ yếu dùng để phát triển ứng dụng Apple, nên có nhiều chức năng dư thừa đối với lập trình thi đấu; gói cài đặt lớn và chỉ dùng được trên Mac.
