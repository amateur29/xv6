#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main()
{
  printf(1, "Burst time of current process = %d\n", get_burst_time());
  exit();
}
