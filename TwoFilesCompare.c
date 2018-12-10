/*  program written by surendranadh pasidi 

program for compare two file of 1MB  size 
 and assume that these two input file are in the 
current directory 

pasidi.surendra@gmail.com

*/ 



#include <stdio.h>
#include <sys/types.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdbool.h>
#include  <time.h>

void ReadOneByteFromTwoFiles(int,int);
bool compareTwobytes(char c1,char c2);
char errByte[16];


int main(int argc  ,char** argv)
{
  int fd1,fd2;
   
  
 time_t t1=time(0);
  printf("\n start time--> %s",ctime(&t1));
if (argc!=3)
{
printf(" improper input\n");
return 0;
}
if ( (fd1=open(argv[1],O_RDONLY))==-1)
{
printf(" unable to open the input file one-- (argv[1]) \n ");
return 0;
}
if((fd2=open(argv[2],O_RDONLY))==-1)
{
printf(" unable to open the input file two -- (argv[2]) \n");
return 0;
}

 ReadOneByteFromTwoFiles(fd1,fd2);


time_t t2=time(0);
  printf(" \n end time--> %s",ctime(&t2));

 printf(" \n diff time %e    \n",difftime(t2,t1));

}/* end of the program  */




 void ReadOneByteFromTwoFiles(int ffd, int sfd)
  {

   char c1;
   char  c2;
  int rReturn1=-5;
  int rReturn2=-5;
   off_t position;
int k;

    while ((rReturn1!=0) && (rReturn2!=0))
    {
        rReturn1=read(ffd,&c1,1);
       rReturn2=read(sfd,&c2,1);
    
    if (!(compareTwobytes(c1,c2)))
    {
      
     printf("\n files are not equal   \n");
     if((rReturn1==0) && (rReturn2!=0))  
      {
	
        printf(" upto end of file  argv[1], two files   are same but rest of the data reading from file two \n");
        position=lseek(sfd,(off_t)0,(SEEK_CUR));
	printf(" \nerror in current offset position %ld\n ",(long)position);
        read(sfd,errByte,16);
       printf(" \n16 bytes from mismatch position\n");
	for(k=0;errByte[k]!=0;k++)
        printf("%c",errByte[k]);
        printf("\n\n");
      }
     else if ((rReturn1!=0) && (rReturn2==0))
        {
 	 
	printf(" upto end of file  argv[2], two files   are same but rest of the data reading from file one \n");
   	position=lseek(ffd,(off_t)0,(SEEK_CUR));
	printf(" \n error in current offset position  %ld\n",(long)position);
        read(ffd,errByte,16);   
	printf(" \n16 bytes from mismatch position\n");
        for(k=0;errByte[k]!=0;k++)
        printf("%c",errByte[k]);
        printf("\n\n");      

         }
     else  if ((rReturn1!=0) && (rReturn2!=0))
      {
	
        printf("mismatch occured in the middle of the two files \n");
        position=lseek(ffd,(off_t)0,(SEEK_CUR));
	printf(" error in current offset position in the file %ld \n",(long)position);
        read(ffd,errByte,16);
        printf(" 16 bytes from mismatch position\n");
        for(k=0;errByte[k]!=0;k++)
        printf("%c",errByte[k]);
        printf("\n\n");
      }

       break;
    }
    
  }
   if((rReturn1==0) && (rReturn2==0))
     printf(" two file are equal\n");
     


}


bool compareTwobytes(char fc,char sc)
  {

   if(fc==sc)
   return true;
   else 
   return false;
  }
