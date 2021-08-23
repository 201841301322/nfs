#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <linux/input.h>    //支持输入事件
#include <stdlib.h>
#include <pthread.h>
#include <string.h>
#include <sys/poll.h>

static char color_buf[800*480*4]={0};

int fd_lcd=-1,i=0,j;

int play(char b,char g ,char r)
{
	fd_lcd=open("/dev/fb0",O_RDWR);
	if(fd_lcd < 0)
	{
		printf("open lcd fail\n");
		return -1;
	}
	
	
	lseek(fd_lcd,0,SEEK_SET);
	
	for(i=0,j=0; i<800*480*4; i+=4,j+=3)
	{
		
		color_buf[i] 	= b;		//b
		color_buf[i+1] 	= g;		//g	
		color_buf[i+2] 	= r;		//r
		color_buf[i+3] 	= 0;		//a	
		
		
	}
	
	for(i=479; i>=0; i--)
		write(fd_lcd,&color_buf[800*i*4],800*4);
	
	close(fd_lcd);
	return 0;
}


int main(int argc, char **argv)
{  
	int r,g,b;
	r=0;g=0;b=0;
	while(1)
	{
		r=rand()%254;
		g=rand()%254;
		b=rand()%254;
		play(r,g,b);
		
		usleep(500000);
	}
	play(b,g,r);
	usleep(100);

}
	

	
