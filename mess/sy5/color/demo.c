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
	
	//�Կɶ���д�ķ�ʽ����LCD�豸
	fd_lcd=open("/dev/fb0",O_RDWR);
	
	if(fd_lcd < 0)
	{
		printf("open lcd fail\n");
		
		return -1;
	}
	
	
	//��λ����ʾ����ʼλ��(ƫ���ļ�ͷ��0���ֽ�)
	lseek(fd_lcd,0,SEEK_SET);
	
	//��LCD�豸д��Ҫ��ʾ������
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
	
	//�ر�lcd�豸
	close(fd_lcd);
	
	//��ȷ�ķ���
	return 0;
}