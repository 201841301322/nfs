#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static char color_buf[800*480*4]={0};

int main(int argc, char **argv)
{
	int fd_lcd;
	int i=0;
	
	//以可读可写的方式，打开LCD设备
	fd_lcd=open("/dev/fb0",O_RDWR);
	
	if(fd_lcd < 0)
	{
		printf("open lcd fail\n");
		
		return -1;
	}
	
	
	//定位到显示的起始位置(偏移文件头部0个字节)
	lseek(fd_lcd,0,SEEK_SET);
	
	//向LCD设备写入要显示的数据
	for(i=0; i<800*480*4; i+=4)
	{
#if 0
		color_buf[i] = 255;		//b
		color_buf[i+1] = 0;		//g	
		color_buf[i+2] = 0;		//r
		color_buf[i+3] = 0;		//a	
#endif

#if 0
		color_buf[i] = 0;		//b
		color_buf[i+1] = 255;	//g	
		color_buf[i+2] = 0;		//r
		color_buf[i+3] = 0;		//a	
#endif


#if 1
		color_buf[i] = 0;		//b
		color_buf[i+1] = 0;	//g	
		color_buf[i+2] = 255;		//r
		color_buf[i+3] = 0;		//a	
#endif		
	}
	
	write(fd_lcd,color_buf,800*480*4);
	
	//关闭lcd设备
	close(fd_lcd);
	
	//正确的返回
	return 0;
}