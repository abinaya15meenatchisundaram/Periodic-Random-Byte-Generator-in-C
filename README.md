# 🔄 Periodic Random Byte Generator in C

This C program simulates a time-based random byte generation process. It mimics sensor data collection by generating a random number of bytes every second and printing them in hexadecimal format when a specific condition is met.

---

## 🧠 What the Program Does

- Every **1 second**, a random number (`0–5`) is generated.
- That number is used to generate that many random bytes (`0–255`), which are stored in an array.
- Every **10 seconds**, the program checks:
  - If there are **at least 50 bytes**, it prints the **latest 50** bytes in hex format, removes them from the array, and exits.
  - Otherwise, it continues collecting data.

---

## 📄 Full Source Code

```c
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <unistd.h>

#define MAX_SIZE 1000

unsigned char data[MAX_SIZE];
int count = 0;

void addData() {
    int n = rand() % 6;
    for (int i = 0; i < n && count < MAX_SIZE; i++) {
        data[count++] = rand() % 256;
    }
}

void printLast50() {
    printf("Last 50 bytes in hex:\n");
    for (int i = count - 50; i < count; i++) {
        printf("%02X ", data[i]);
    }
    printf("\n");
    count -= 50;
}

int main() {
    srand(time(0));
    for (int sec = 1; sec <= 1000; sec++) {
        addData();
        sleep(1);
        if (sec % 10 == 0 && count >= 50) {
            printLast50();
            printf("End program.\n");
            break;
        }
    }
    return 0;
}
