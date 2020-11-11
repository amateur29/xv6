#include "types.h"
#include "stat.h"
#include "user.h"
#include "fcntl.h"

int main()
{
  int pid=3;
  struct processInfo *p = malloc (sizeof (struct processInfo));

  int res = getProcInfo(pid, p);
  if(res==-1)
   printf(1, "Process not found.\n");
  else{
   printf(1, "Process Parent PID: %d\n", p->ppid);
   printf(1, "Process size: %d\n", p->psize);
   printf(1, "Number of Context Switches: %d\n", p->numberContextSwitches);
  }
  exit();
}
