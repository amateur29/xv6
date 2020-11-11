#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main(int argc, char *argv[])
{
  if (argc < 2)
    {
        printf(1, "test-case <burst-time>\n");
        exit();
    }

  int burst_time = atoi(argv[1]);
  set_burst_time(burst_time);
  cps();
  printf(1, "Burst time of current process = %d\n", get_burst_time());
  exit();
}
