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
#define PIC_SUM 7
#define GEC6818_LED_ON		_IOW('L',  1, unsigned long)
#define GEC6818_LED_OFF		_IOW('L',  2, unsigned long)


	

int pic_num=0;
int paly_flag=0;
int led_fd=-1;
static char color_buf[800*480*4]={0};
static char bmp_buf[800*480*3]={0};
int play_pic(int p_num);
int pic_next();
int pic_back();
int K4,K3,K2,K6;
int led7_flag,led8_flag,led9_flag,led10_flag;



static int getResultFromSystemCall(const char *pCmd,char *pResult,int size);
int get_sta()
{
	int fd_ts;

	unsigned int x,y;

	struct input_event buf;
	fd_ts=open("/dev/input/event0",O_RDWR);

	if(fd_ts < 0)
	{
		printf("open ts error\r\n");
		
		return -1;
		
	}
	while(1)
	{
		
		//printf(system("cat /sys/class/gpio/gpio28/value"));

		//读取触摸屏设备的数据
		read(fd_ts, &buf, sizeof buf);
		
		//如果是绝对坐标值的事件类型
		if(buf.type == EV_ABS|| buf.type==EV_KEY)
		{
			if(buf.code == ABS_X)
			{
				x = buf.value* 800/1024;
				printf("x=%d\n",buf.value);
				
			}
			
			if(buf.code == ABS_Y)
			{
				y = buf.value* 480/600;
				printf("y=%d\n",buf.value);
				
			} 
			

		}
		
		//判断当前点击操作是否已经释放【重点添加和修改】
		if(buf.type == EV_KEY && buf.code == BTN_TOUCH )
		{
			//松开
			if(buf.value == 0)
			{
				if(x < 200)
				{
					printf("left,release!\n");
					
				}
				
				if(x < 600 && x>200)
				{
					printf("min,release!\n");
				}      

				if(x > 600)
				{
					printf("right,release!\n");
				}              
				
			}
			//按下
			else
			{
				if(x < 200)
				{
					printf("left,down!\n");
					pic_back();
				}
				if(x < 600 && x>200)
				{
					if(paly_flag==0)
					{
						paly_flag=1;
					}
					else
					{paly_flag=0;}
					printf("min,down!\n");
				}  
				if(x > 600)
				{
					printf("right,down!\n");
					pic_next();
				}                  
				
			}
		}
	}
	return 0;
}

int pic_next()
{
	pic_num+=1;
	if(pic_num>PIC_SUM)
	{
		pic_num=0;
	}
	//printf(pic_num);
	play_pic(pic_num);
	play_pic(pic_num);
	return 0;
}

