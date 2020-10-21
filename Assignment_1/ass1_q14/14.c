/*13. Write a program to build multifile program using fork & exec as follows
   * There are multiple source files holding some functions
   * Create multiple child processes to compile each source file (execl/execlp)
   * On successful completion, launch another child process for linking
   * On successful linking, launch another child process for executing */
   

#include<unistd.h>
#include <string.h>
#include<stdio.h>
#include<stdlib.h>
#include <sys/wait.h>
#include <string.h>



int main()
{
	int ret,returni;
	int child_1=fork();
	int child_2;
	int child_3;
	int child_4;
	int child_5;
	char *Ps;
	char *Pss;
	Pss="./s.out";
	Ps="s.out"; 
	if(child_1<0||child_2<0||child_3<0)
	{
	perror("fork");
	exit(1);
	}
	if(child_1==0)
	{ 
	execl("/bin/gcc","gcc","-c","test.c",NULL);
    	}
    	else
    	{
    	waitpid(child_1, &returni, 0);
    	child_2=fork();
    	}
	if(child_2==0)
    	execl("/bin/gcc","gcc","-c","sum.c",NULL);
    	else
    	{waitpid(child_2, &returni, 0);
    	child_3=fork();}
	if(child_3==0)
  	execl("/bin/gcc","gcc","sum.o","test.o","-o",s,NULL);
    	else
    	{
    	waitpid(child_3, &returni, 0);
    	child_4=fork();
	} 
	if(child_4==0)
	execl("./s.out", "./s.out", NULL); 
	else
	{
	  
	} 	 
	exit(0);
}

