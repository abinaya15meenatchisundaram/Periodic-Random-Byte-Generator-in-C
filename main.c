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
// Keep the older bytes (from index 0 to count-51)
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
