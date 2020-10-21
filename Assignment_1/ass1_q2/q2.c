#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
	int filed,nbytes;
	filed=open("intro.txt",O_RDONLY);
	if(filed<0)
	{
		perror("open");
		exit(1);
	}
	int len=128;
	char buf[len];
	nbytes=read(filed,buf,len);
	if(nbytes<0)
	{
		perror("read");
		exit(2);
	}
	write(1,buf,nbytes);
	close(filed);
	return 0;	//exit(0);
}
