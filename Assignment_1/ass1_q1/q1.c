#include<unistd.h>
#include<fcntl.h>
#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int main()
{
    int len=128;
	char buffer[len];
	int fd,fd1;
    ssize_t ret_in, ret_out;    /* Number of bytes returned by read() and write() */
	fd=open("intro.txt",O_RDONLY);
    
	if(fd<0)
	{
		perror("open");
		exit(1);
	}
	
    fd1=open("intro1.txt",O_WRONLY|O_CREAT, 0666);
    if(fd1<0)
	{
		perror("open");
		exit(1);
	}
  
    /* Copy process */
    while((ret_in = read (fd, &buffer, len)) > 0)
          {
            ret_out = write (fd1, &buffer, (ssize_t) ret_in);
            if(ret_out != ret_in)
               {
                /* Write error */
                perror("write");
                return 4;
               }
           }
	close(fd);
    close(fd1);
	return 0;	//exit(0);
}
