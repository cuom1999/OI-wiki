import java.util.Arrays;
import java.util.Scanner;

class Edge {
    int u;
    int v;
    int w;

    Edge(int u, int v, int w) {
        this.u = u;
        this.v = v;
        this.w = w;
    }
}

public class Main {
    static int[] parent = new int[1010];  // Định nghĩa mảng cha.
    static int m, n, k;  // n là số đỉnh, m là số cạnh, k là số kẹo bông cần có.

    static Edge[] edges = new Edge[10010];
    static int l;

    static void addEdge(int u, int v, int w) {
        edges[++l] = new Edge(u, v, w);
    }

    // DSU chuẩn.
    static int findroot(int x) {
        if (parent[x] != x) {
            parent[x] = findroot(parent[x]);
        }
        return parent[x];
    }

    static void Merge(int x, int y) {
        x = findroot(x);
        y = findroot(y);
        parent[x] = y;
    }

    static boolean cmp(Edge A, Edge B) {
        return A.w < B.w;
    }

    // Thuật toán Kruskal.
    static void kruskal() {
        int tot = 0;  // Lưu số cạnh đã chọn.
        int ans = 0;  // Lưu tổng chi phí.

        for (int i = 1; i <= m; i++) {
            int xr = findroot(edges[i].u);
            int yr = findroot(edges[i].v);
            if (xr != yr) {   // Nếu hai gốc khác nhau.
                Merge(xr, yr); // Hợp nhất.
                tot++; // Tăng số cạnh.
                ans += edges[i].w; // Tăng chi phí.
                if (tot == n - k) {  // Kiểm tra số cạnh đã chọn có thỏa k kẹo bông không.
                    System.out.println(ans);
                    return;
                }
            }
        }
        System.out.println("No Answer");  // Không thể nối thành công.
    }

    public static void main(String[] args) {
        Scanner scanner = new Scanner(System.in);
        n = scanner.nextInt();
        m = scanner.nextInt();
        k = scanner.nextInt();

        if (n == k) { // Xử lý riêng trường hợp biên.
            System.out.println("0");
            return;
        }

        // Khởi tạo.
        for (int i = 1; i <= n; i++) {
            parent[i] = i;
        }
        for (int i = 1; i <= m; i++) {
            int u = scanner.nextInt();
            int v = scanner.nextInt();
            int w = scanner.nextInt();
            addEdge(u, v, w);  // Thêm cạnh.
        }
        Arrays.sort(edges, 1, m + 1, (a, b) -> Integer.compare(a.w, b.w));  // Trước hết sắp xếp theo trọng số cạnh.
        kruskal();
        scanner.close();
    }
}
