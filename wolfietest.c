#include "types.h"
#include "stat.h"
#include "user.h"


int main(int argc, char** argv)
{
	//define user buffer
	char *buf; 
	buf=(char*)malloc(atoi(argv[1]) * sizeof(char)); 
	
	//use system call to wolfie that returns number of bytes copied if buffer
	//is not too small, else it returns -1
	int r=wolfie(buf,atoi(argv[1]));
	
	//check if buffer is not too small
	if(r!=-1)
	printf(1,"%s",buf);
	else
	printf(1,"%d \n buffer size is too small\n",r);
	exit();
}
