import java.util.Scanner;

public class Main {
    public static void main(String[] args) {
        Scanner input = new Scanner(System.in);
        int u = input.nextInt();
        int d = input.nextInt();
        int n = input.nextInt();
        int time = 0, dist = 0;
        while (true) {  // Dùng vòng lặp vô hạn để liệt kê.
            dist += u;
            time++;
            if (dist >= n) {
                break;  // Thoát vòng lặp vô hạn khi thỏa điều kiện.
            }
            dist -= d;
        }
        System.out.println(time);   // In kết quả thu được.
        input.close();
    }
}
