Trang này giới thiệu ngắn gọn về sắp xếp vun đống.

## Định nghĩa

Sắp xếp vun đống (tiếng Anh: Heapsort) là một thuật toán sắp xếp được thiết kế dựa trên cấu trúc dữ liệu [đống nhị phân](../ds/binary-heap.md). Cấu trúc dữ liệu phù hợp để cài đặt sắp xếp vun đống là mảng.

## Quy trình

Bản chất của sắp xếp vun đống là sắp xếp chọn được xây dựng trên đống.

### Sắp xếp

Trước hết xây dựng một đống lớn (max-heap), sau đó lấy phần tử ở đỉnh đống làm giá trị lớn nhất, hoán đổi nó với phần tử cuối mảng, rồi duy trì tính chất của phần đống còn lại;

Tiếp theo lấy phần tử ở đỉnh đống làm giá trị lớn thứ hai, hoán đổi nó với phần tử áp chót của mảng, rồi duy trì tính chất của phần đống còn lại;

Tiếp tục quá trình này, sau thao tác thứ $n-1$, toàn bộ mảng sẽ được sắp xếp.

### Xây dựng đống nhị phân trên mảng

Bắt đầu từ nút gốc, lần lượt đặt các nút của từng tầng vào mảng.

Khi đó, với nút có chỉ số `i` trong mảng, nút cha, nút con trái và nút con phải tương ứng là:

```cpp
iParent(i) = (i - 1) / 2;
iLeftChild(i) = 2 * i + 1;
iRightChild(i) = 2 * i + 2;
```

## Tính chất

### Tính ổn định

Tương tự sắp xếp chọn, do có thao tác hoán đổi vị trí, đây là một thuật toán sắp xếp không ổn định.

### Độ phức tạp thời gian

Độ phức tạp thời gian tốt nhất, trung bình và xấu nhất của sắp xếp vun đống đều là $O(n\log n)$.

### Độ phức tạp bộ nhớ

Vì có thể xây dựng đống ngay trên mảng đầu vào, đây là một thuật toán tại chỗ.

## Cài đặt

=== "C++"
    ```cpp
    void sift_down(int arr[], int start, int end) {
      // Tính chỉ số của nút cha và nút con
      int parent = start;
      int child = parent * 2 + 1;
      while (child <= end) {  // Chỉ so sánh khi chỉ số nút con còn nằm trong phạm vi
        // So sánh hai nút con trước, chọn nút lớn hơn
        if (child + 1 <= end && arr[child] < arr[child + 1]) child++;
        // Nếu nút cha lớn hơn hoặc bằng nút con, việc điều chỉnh đã hoàn tất
        if (arr[parent] >= arr[child])
          return;
        else {  // Ngược lại, hoán đổi cha con rồi tiếp tục so sánh với tầng dưới
          swap(arr[parent], arr[child]);
          parent = child;
          child = parent * 2 + 1;
        }
      }
    }
    
    void heap_sort(int arr[], int len) {
      // Bắt đầu sift down từ cha của nút cuối cùng để hoàn thành heapify
      for (int i = (len - 1 - 1) / 2; i >= 0; i--) sift_down(arr, i, len - 1);
      // Hoán đổi phần tử đầu với vị trí ngay trước phần đã sắp xếp, rồi điều chỉnh lại phần còn lại
      for (int i = len - 1; i > 0; i--) {
        swap(arr[0], arr[i]);
        sift_down(arr, 0, i - 1);
      }
    }
    ```

=== "Python"
    ```python
    def sift_down(arr, start, end):
        # Tính chỉ số của nút cha và nút con
        parent = int(start)
        child = int(parent * 2 + 1)
        while child <= end:  # Chỉ so sánh khi chỉ số nút con còn nằm trong phạm vi
            # So sánh hai nút con trước, chọn nút lớn hơn
            if child + 1 <= end and arr[child] < arr[child + 1]:
                child += 1
            # Nếu nút cha lớn hơn hoặc bằng nút con, việc điều chỉnh đã hoàn tất
            if arr[parent] >= arr[child]:
                return
            else:  # Ngược lại, hoán đổi cha con rồi tiếp tục so sánh với tầng dưới
                arr[parent], arr[child] = arr[child], arr[parent]
                parent = child
                child = int(parent * 2 + 1)
    
    
    def heap_sort(arr, len):
        # Bắt đầu sift down từ cha của nút cuối cùng để hoàn thành heapify
        i = (len - 1 - 1) / 2
        while i >= 0:
            sift_down(arr, i, len - 1)
            i -= 1
        # Hoán đổi phần tử đầu với vị trí ngay trước phần đã sắp xếp, rồi điều chỉnh lại phần còn lại
        i = len - 1
        while i > 0:
            arr[0], arr[i] = arr[i], arr[0]
            sift_down(arr, 0, i - 1)
            i -= 1
    ```

## Liên kết ngoài

-   [Heapsort - Wikipedia](https://en.wikipedia.org/wiki/Heapsort)
