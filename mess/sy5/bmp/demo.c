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
	
	//��ֻ���ķ�ʽ����1.bmp
	fd_bmp=open("1.bmp",O_RDONLY);
	
	if(fd_bmp < 0)
	{
		printf("open 1.bmp fail\n");
		
		return -1;
	}

	//��λ��RGB���ݵ���ʼλ��(ƫ���ļ�ͷ��54���ֽ�)
	lseek(fd_bmp,54,SEEK_SET);	
	
	//��ȡ���е�RGB����
	read(fd_bmp,bmp_buf,800*480*3);
	
	//����ʹ�ø�ͼƬ���͹ر�
	close(fd_bmp);
	
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
	for(i=0,j=0; i<800*480*4; i+=4,j+=3)
	{
		color_buf[i] 	= bmp_buf[j];		//b
		color_buf[i+1] 	= bmp_buf[j+1];		//g	
		color_buf[i+2] 	= bmp_buf[j+2];		//r
		color_buf[i+3] 	= 0;		//a	
		
	}
	
	for(i=479; i>=0; i--)
		write(fd_lcd,&color_buf[800*i*4],800*4);
	
	//�ر�lcd�豸
	close(fd_lcd);
	
	//��ȷ�ķ���
	return 0;
}