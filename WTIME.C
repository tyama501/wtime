#include <time.h>
#include <stdio.h>
#include <stdlib.h>

char _asm_1(char *);

/* DOS */
#define c_INT_21() _asm_1("\n\tINT\t33\n")
#define c_AH_08() _asm_1("\n\tMOV\tAH,8\n")
#define c_AH_0B() _asm_1("\n\tMOV\tAH,11\n")

/* PC-98 BIOS */
#define c_INT_18() _asm_1("\n\tINT\t24\n")
#define c_AH_11() _asm_1("\n\tMOV\tAH,17\n")
#define c_AH_12() _asm_1("\n\tMOV\tAH,18\n")

int main(int argc, char *argv[])
{
  time_t cur_time = 0;
  time_t prev_time = 0;
  char c_key;

  long wait_time;
  long delta_time;

  if (argc != 2) {
    printf("Please specify time. WTIME.EXE time[s]\n");
    exit(1);
  }
  else {
    wait_time = atoi(argv[1]);
  }

  c_AH_12(); /* cursor off */
  c_INT_18();

  while (wait_time > 0) {
    printf("%5d\r", wait_time);
    cur_time = clock();

    delta_time = cur_time - prev_time;

    if (delta_time > 0) {

      if (prev_time != 0) {
        wait_time -= delta_time;
      }
      prev_time = cur_time;
    }

    c_AH_0B();
    if (c_INT_21()==0xFF) {
      c_AH_08();
      c_key = c_INT_21();
      if (c_key=='q' || c_key=='Q') {
        printf("Aborting.\n");
        c_AH_11();
        c_INT_18();
        exit(0);
      }
    }

  }

  c_AH_11(); /* cursor on */
  c_INT_18();

  return 0;
}
