## Định lý Pick

Định lý Pick: với một đa giác đơn có mọi đỉnh đều là điểm nguyên, định lý Pick mô tả quan hệ giữa diện tích ${\displaystyle A}$, số điểm lưới nằm bên trong ${\displaystyle i}$ và số điểm lưới nằm trên biên ${\displaystyle b}$ của nó: ${\displaystyle A=i+{\frac {b}{2}}-1}$.

Chứng minh cụ thể: [Pick's theorem](https://en.wikipedia.org/wiki/Pick%27s_theorem)

Định lý này có các mở rộng sau:

-   Lấy diện tích của hình tạo bởi các điểm lưới làm một đơn vị. Với lưới hình bình hành, định lý Pick vẫn đúng. Khi áp dụng cho lưới tam giác bất kỳ, dạng của định lý Pick là ${\displaystyle A=2 \times i+b-2}$.
-   Với đa giác không đơn ${\displaystyle P}$, định lý Pick có dạng ${\displaystyle A=i+{\frac {b}{2}}-\chi (P)}$, trong đó ${\displaystyle \chi (P)}$ là **đặc trưng Euler** của ${\displaystyle P}$.
-   Mở rộng lên số chiều cao hơn: đa thức Ehrhart.
-   Định lý Pick tương đương với **công thức Euler** (${\displaystyle V-E+F=2}$).

## Một bài ví dụ ([POJ 1265](http://poj.org/problem?id=1265))

### Tóm tắt đề bài

Trong hệ tọa độ vuông góc, một robot xuất phát từ một điểm bất kỳ và thực hiện $\textit{n}$ lần di chuyển; mỗi lần đi sang phải $\textit{dx}$ và đi lên $\textit{dy}$. Cuối cùng đường đi tạo thành một đa giác đơn khép kín trên mặt phẳng. Cần tính số điểm trên biên, số điểm bên trong đa giác và diện tích đa giác.

### Lời giải

Bài này thực chất dùng ba kiến thức sau:

-   Với một đoạn thẳng có hai đầu mút là điểm nguyên, nếu $\textit{dx}$ và $\textit{dy}$ của cạnh đều khác $0$, số điểm lưới mà đoạn đi qua là $\gcd(\textit{dx}, \textit{dy}) + 1$. Khi tính cho cả hình, điểm cộng thêm đã được cạnh trước đó tính rồi, nên không cần cộng nữa. Vì vậy số điểm mà một cạnh đóng góp là $\gcd(\textit{dx},\textit{dy})$, trong đó $\textit{dx},\textit{dy}$ lần lượt là độ lệch theo phương ngang và phương dọc của đoạn thẳng. Nếu $\textit{dx}$ hoặc $\textit{dy}$ bằng $0$, số điểm đóng góp là $\textit{dy}$ **hoặc** $\textit{dx}$.
-   Định lý Pick: diện tích của đa giác đơn trên mặt phẳng có các đỉnh là điểm nguyên = số điểm trên biên/2 + số điểm bên trong - 1.
-   Diện tích của một đa giác bất kỳ bằng một nửa tổng tích có hướng của các vector tạo bởi từng cặp điểm kề nhau theo thứ tự với gốc tọa độ (điều này cũng có thể suy ra bằng tích phân có hướng theo chiều kim đồng hồ).

??? note "Mã tham khảo"
    ```cpp
    --8<-- "docs/geometry/code/pick/pick_1.cpp"
    ```
