#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <unistd.h>
#include <stdio.h>

static char color_buf[800*480*4]={0};
static char bmp_buf[800*480*3]={0};

int main(int argc, char **argv)
{
	int fd_lcd;
	int fd_bmp;
	int i=0,j=0;
	
	//以只读的方式，打开1.bmp
	fd_bmp=open("1.bmp",O_RDONLY);
	
	if(fd_bmp < 0)
	{
		printf("open 1.bmp fail\n");
		
		return -1;
	}

	//定位到RGB数据的起始位置(偏移文件头部54个字节)
	lseek(fd_bmp,54,SEEK_SET);	
	
	//读取所有的RGB数据
	read(fd_bmp,bmp_buf,800*480*3);
	
	//不再使用该图片，就关闭
	close(fd_bmp);
	
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
	for(i=0,j=0; i<800*480*4; i+=4,j+=3)
	{
		color_buf[i] 	= bmp_buf[j];		//b
		color_buf[i+1] 	= bmp_buf[j+1];		//g	
		color_buf[i+2] 	= bmp_buf[j+2];		//r
		color_buf[i+3] 	= 0;		//a	
		
	}
	
	for(i=479; i>=0; i--)
		write(fd_lcd,&color_buf[800*i*4],800*4);
	
	//关闭lcd设备
	close(fd_lcd);
	
	//正确的返回
	return 0;
}