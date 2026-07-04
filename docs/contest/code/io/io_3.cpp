#include <fcntl.h>
#include <sys/mman.h>
#include <sys/stat.h>
#include <unistd.h>

#include <cstdio>

char *pc;

void rd(int &x) {
  bool neg = false;
  x = 0;
  char ch = 0;
  while (ch < '0' || ch > '9') {
    if (ch == '-') neg = true;
    ch = *pc++;
  }
  if (neg) {
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + ('0' - ch);
      ch = *pc++;
    }
  } else {
    while (ch >= '0' && ch <= '9') {
      x = x * 10 + (ch - '0');
      ch = *pc++;
    }
  }
}

int main() {
  int fd = 0;  // Đọc từ stdin.
  // int fd = open("xxx.in", O_RDONLY); // Đọc từ file.
  struct stat state;
  fstat(fd, &state);  // Lấy kích thước file.
  pc = (char *)mmap(NULL, state.st_size, PROT_READ, MAP_PRIVATE, fd, 0);
  int n, x, sum = 0;
  rd(n);
  while (n--) {
    rd(x);
    sum += x;
  }
  printf("%d\n", sum);
}
