 #include <stdio.h>
 int main() {
     int x = 1, y, z;
     y = ++x;
     z = y++;
     y = 2;
     printf("%%%d, %d, %d%%", x, y, z);
     return 0;
     }
