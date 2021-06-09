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

long int x_buf=0,y_buf=0;
long int star_x=0,star_y=0,end_x=0;
long int pic_x=0,pic_y=0,pic_x2=0,pic_y2=0;
int pic_num=0;
int paly_flag=0;
int led_fd=-1;
int lipu=0;
static char color_buf1[64000*480*4]={0};
static char color_buf[64000*480*4]={0};
static char bmp_buf[800*480*3]={0};
int play_pic(int p_num);
int pic_next();
int pic_back();
int K4,K3,K2,K6;
int K4i=0;
int led7_flag,led8_flag,led9_flag,led10_flag;

static int getResultFromSystemCall(const char *pCmd,char *pResult,int size);
void pic_slip();
int load_all_pic();
void pic_slip_butten(int sli);
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
				//x_buf=x-star_x;
				//pic_slip();
				//printf("x_buf=%d\n",x_buf);
				
			}
			if(buf.code == ABS_Y)
			{
				y = buf.value* 480/600;
			}
			if(buf.type == EV_KEY && buf.code == BTN_TOUCH )
			{
			//松开
			if(buf.value == 0)
			{
				end_x=x;
				//printf("end_x=%d\n",end_x);
				lipu=0;
				pic_x=pic_x+x_buf;
				pic_y=pic_y+y_buf;
				if(pic_x<0)
				{pic_x=0;}
				if(pic_y<0)
				{pic_y=0;}
				printf("release!\n");
				if(x < 200)
				{
					//x_buf=pic_x+x_buf;
					
					//printf("left,release!\n");
					
				}
				
				if(x < 600 && x>200)
				{
					//printf("min,release!\n");
				}      

				if(x > 600)
				{
					//printf("right,release!\n");
				}              
				
			}
			//按下
			else
			{	
				
				star_x=x;
				star_y=y;
				//x_buf=0;
				//pic_slip();
				printf("x=%d\n",x);
				printf("y=%d\n",y);
				printf("down!\n");
				if((x<100 && y<50)||(x>570 && y<50))
				{
					//printf("left,down!\n");
					pic_back();
				}
				if((250<x&&x<400&&y<50)||(250<x&&x<400&&y>330))
				{
					if(paly_flag==0)
					{
						paly_flag=1;
					}
					else
					{
						paly_flag=0;
					}
					//printf("min,down!\n");
				}  
				if((x<100 && y>330)||(x>570 && y>330))
				{
					//printf("right,down!\n");
					pic_next();
				}                  
				
			}
		}


			if(buf.code == ABS_X)
			{
				x = buf.value* 800/1024;
				x_buf=x-star_x;
				//printf("x=%d\n",x);
				//printf("star_x=%d\n",star_x);
				//if(lipu<2)
				//{
				//	lipu++;
					//goto alip;
				//}
				//pic_slip();
				//alip:
				//printf("x_buf=%d\n",x_buf);
				
			}
			
			if(buf.code == ABS_Y)
			{
				y = buf.value* 480/600;
				//printf("y=%d\n",y);
				y_buf=y-star_y;
				if(lipu<2)
				{
					lipu++;
					goto alip;
				}
				pic_slip();
				alip:
				printf("\n");
				
			} 
			

		}
		
		//判断当前点击操作是否已经释放【重点添加和修改】
		
	}
	return 0;
}
void pic_slip()
{
	int fd_lcd=-1,i=0;
    pic_y2=pic_y+y_buf;
	if(pic_y2<0)
		{pic_y=1600+pic_y;}
	if(pic_y2>=1600)
		{pic_y=pic_y-1600;}
	//printf("pic_y2=%d\r\n",pic_y2);
	//printf("pic_y=%d ",pic_y);
	//printf("y_buf=%d\r\n",y_buf);
    fd_lcd=open("/dev/fb0",O_RDWR);
    lseek(fd_lcd,0,SEEK_SET);
    
	for(i=479; i>=0; i--)
        {write(fd_lcd,&color_buf1[800*(i+pic_y2*3)*4],800*4);}
	for(i=479; i>=0; i--)
        {write(fd_lcd,&color_buf1[800*(i+pic_y2*3)*4],800*4);}
    close(fd_lcd);
}


int pic_next()
{
	int sli=0,sli1=0;
	sli1=pic_y2;
	for(sli=pic_y2;sli<=((sli1/160)+1)*160;sli++)
	{
		pic_y=sli;
		y_buf=0;
		pic_slip();
		if(pic_y<0)
			{pic_y=1600+pic_y;}
		if(pic_y>=1600)
			{pic_y=pic_y-1600;}
		pic_y2=pic_y;
		//printf("pic_y2=%d\r\n",pic_y2);
	}
	return 0;
}

int pic_back()
{
	int slii=0,slii1=0;
	slii1=pic_y2;
	for(slii=pic_y2;slii>=((slii1/150)-1)*160;slii--)
	{
		pic_y=slii;
		y_buf=0;
		if(pic_y<0)
			{pic_y=1600+pic_y;}
		if(pic_y>=1600)
			{pic_y=pic_y-1600;}
		pic_slip();
		pic_y2=pic_y;
		//printf("pic_y2=%d\r\n",pic_y2);
	}
	return 0;
}

int load_all_pic()
{
	int fd_bmp;
	int i=0,j=0;
	//char *s[8]={"0.bmp","1.bmp","2.bmp","3.bmp","4.bmp","5.bmp","6.bmp","7.bmp"};
    
        fd_bmp=open("0.bmp",O_RDONLY);
        lseek(fd_bmp,54,SEEK_SET);	
        read(fd_bmp,bmp_buf,800*480*3);
        close(fd_bmp);
		printf("load_0.bmp\r\n");
        for(i=0+0*800*480*4,j=0; i<1*800*480*4; i+=4,j+=3)
        {
            color_buf1[i] 	= bmp_buf[j];		//b
            color_buf1[i+1] 	= bmp_buf[j+1];		//g	
            color_buf1[i+2] 	= bmp_buf[j+2];		//r
            color_buf1[i+3] 	= 0;		//a	
            
        }

        fd_bmp=open("1.bmp",O_RDONLY);
        lseek(fd_bmp,54,SEEK_SET);	
        read(fd_bmp,bmp_buf,800*480*3);
        close(fd_bmp);
		printf("load_1.bmp\r\n");
        for(i=0+1*800*480*4,j=0; i<2*800*480*4; i+=4,j+=3)
        {
            color_buf1[i] 	= bmp_buf[j];		//b
            color_buf1[i+1] 	= bmp_buf[j+1];		//g	
            color_buf1[i+2] 	= bmp_buf[j+2];		//r
            color_buf1[i+3] 	= 0;		//a	
            
        }

        fd_bmp=open("2.bmp",O_RDONLY);
        lseek(fd_bmp,54,SEEK_SET);	
        read(fd_bmp,bmp_buf,800*480*3);
        close(fd_bmp);
		printf("load_2.bmp\r\n");
        for(i=0+2*800*480*4,j=0; i<3*800*480*4; i+=4,j+=3)
        {
            color_buf1[i] 	= bmp_buf[j];		//b
            color_buf1[i+1] 	= bmp_buf[j+1];		//g	
            color_buf1[i+2] 	= bmp_buf[j+2];		//r
            color_buf1[i+3] 	= 0;		//a	
            
        }

        fd_bmp=open("3.bmp",O_RDONLY);
        lseek(fd_bmp,54,SEEK_SET);	
        read(fd_bmp,bmp_buf,800*480*3);
        close(fd_bmp);
		printf("load_3.bmp\r\n");
        for(i=0+3*800*480*4,j=0; i<4*800*480*4; i+=4,j+=3)
        {
            color_buf1[i] 	= bmp_buf[j];		//b
            color_buf1[i+1] 	= bmp_buf[j+1];		//g	
            color_buf1[i+2] 	= bmp_buf[j+2];		//r
            color_buf1[i+3] 	= 0;		//a	
            
        }

        fd_bmp=open("4.bmp",O_RDONLY);
        lseek(fd_bmp,54,SEEK_SET);	
        read(fd_bmp,bmp_buf,800*480*3);
        close(fd_bmp);
		printf("load_4.bmp\r\n");
        for(i=0+4*800*480*4,j=0; i<5*800*480*4; i+=4,j+=3)
        {
            color_buf1[i] 	= bmp_buf[j];		//b
            color_buf1[i+1] 	= bmp_buf[j+1];		//g	
            color_buf1[i+2] 	= bmp_buf[j+2];		//r
            color_buf1[i+3] 	= 0;		//a	
            
        }

        fd_bmp=open("5.bmp",O_RDONLY);
        lseek(fd_bmp,54,SEEK_SET);	
        read(fd_bmp,bmp_buf,800*480*3);
        close(fd_bmp);
		printf("load_5.bmp\r\n");
        for(i=0+5*800*480*4,j=0; i<6*800*480*4; i+=4,j+=3)
        {
            color_buf1[i] 	= bmp_buf[j];		//b
            color_buf1[i+1] 	= bmp_buf[j+1];		//g	
            color_buf1[i+2] 	= bmp_buf[j+2];		//r
            color_buf1[i+3] 	= 0;		//a	
            
        }

        fd_bmp=open("6.bmp",O_RDONLY);
        lseek(fd_bmp,54,SEEK_SET);	
        read(fd_bmp,bmp_buf,800*480*3);
        close(fd_bmp);
		printf("load_6.bmp\r\n");
        for(i=0+6*800*480*4,j=0; i<7*800*480*4; i+=4,j+=3)
        {
            color_buf1[i] 	= bmp_buf[j];		//b
            color_buf1[i+1] 	= bmp_buf[j+1];		//g	
            color_buf1[i+2] 	= bmp_buf[j+2];		//r
            color_buf1[i+3] 	= 0;		//a	
            
        }

        fd_bmp=open("7.bmp",O_RDONLY);
        lseek(fd_bmp,54,SEEK_SET);	
        read(fd_bmp,bmp_buf,800*480*3);
        close(fd_bmp);
		printf("load_7.bmp\r\n");
        for(i=0+7*800*480*4,j=0; i<8*800*480*4; i+=4,j+=3)
        {
            color_buf1[i] 	= bmp_buf[j];		//b
            color_buf1[i+1] 	= bmp_buf[j+1];		//g	
            color_buf1[i+2] 	= bmp_buf[j+2];		//r
            color_buf1[i+3] 	= 0;		//a	
            
        }

		 fd_bmp=open("8.bmp",O_RDONLY);
        lseek(fd_bmp,54,SEEK_SET);	
        read(fd_bmp,bmp_buf,800*480*3);
        close(fd_bmp);
		printf("load_8.bmp\r\n");
        for(i=0+8*800*480*4,j=0; i<9*800*480*4; i+=4,j+=3)
        {
            color_buf1[i] 	= bmp_buf[j];		//b
            color_buf1[i+1] 	= bmp_buf[j+1];		//g	
            color_buf1[i+2] 	= bmp_buf[j+2];		//r
            color_buf1[i+3] 	= 0;		//a	
            
        }

		 fd_bmp=open("9.bmp",O_RDONLY);
        lseek(fd_bmp,54,SEEK_SET);	
        read(fd_bmp,bmp_buf,800*480*3);
        close(fd_bmp);
		printf("load_9.bmp\r\n");
        for(i=0+9*800*480*4,j=0; i<10*800*480*4; i+=4,j+=3)
        {
            color_buf1[i] 	= bmp_buf[j];		//b
            color_buf1[i+1] 	= bmp_buf[j+1];		//g	
            color_buf1[i+2] 	= bmp_buf[j+2];		//r
            color_buf1[i+3] 	= 0;		//a	
            
        }

		 fd_bmp=open("0.bmp",O_RDONLY);
        lseek(fd_bmp,54,SEEK_SET);	
        read(fd_bmp,bmp_buf,800*480*3);
        close(fd_bmp);
		//printf("load_9.bmp\r\n");
        for(i=0+10*800*480*4,j=0; i<11*800*480*4; i+=4,j+=3)
        {
            color_buf1[i] 	= bmp_buf[j];		//b
            color_buf1[i+1] 	= bmp_buf[j+1];		//g	
            color_buf1[i+2] 	= bmp_buf[j+2];		//r
            color_buf1[i+3] 	= 0;		//a	
            
        }

     
} 



int play_pic(int p_num)
{
	int fd_lcd;
	int fd_bmp;
	int i=0,j=0;
	p_num+='0';
	switch (p_num)	
	{
		case '0':
			fd_bmp=open("0.bmp",O_RDONLY);
		
			if(fd_bmp < 0)
			{
				printf("open 0.bmp fail\n");
				return -1;
			}
			break;
		case '1':
			fd_bmp=open("1.bmp",O_RDONLY);
		
			if(fd_bmp < 0)
			{
				printf("open 1.bmp fail\n");
				return -1;
			}
			break;
		case '2':
			fd_bmp=open("2.bmp",O_RDONLY);
		
			if(fd_bmp < 0)
			{
				printf("open 2.bmp fail\n");
				return -1;
			}
			break;
		case '3':
			fd_bmp=open("3.bmp",O_RDONLY);
		
			if(fd_bmp < 0)
			{
				printf("open 3.bmp fail\n");
				return -1;
			}
			break;
		case '4':
			fd_bmp=open("4.bmp",O_RDONLY);
		
			if(fd_bmp < 0)
			{
				printf("open 4.bmp fail\n");
				return -1;
			}
			break;
		case '5':
			fd_bmp=open("5.bmp",O_RDONLY);
		
			if(fd_bmp < 0)
			{
				printf("open 5.bmp fail\n");
				return -1;
			}
			break;
		case '6':
			fd_bmp=open("6.bmp",O_RDONLY);
		
			if(fd_bmp < 0)
			{
				printf("open 6.bmp fail\n");
				return -1;
			}
			break;
		case '7':
			fd_bmp=open("7.bmp",O_RDONLY);
		
			if(fd_bmp < 0)
			{
				printf("open 5.bmp fail\n");
				return -1;
			}
			break;
		

	lseek(fd_bmp,54,SEEK_SET);	
	
	read(fd_bmp,bmp_buf,800*480*3);
	
	close(fd_bmp);
	
	fd_lcd=open("/dev/fb0",O_RDWR);
	
	if(fd_lcd < 0)
	{
		printf("open lcd fail\n");
		
		return -1;
	}
	
	
	lseek(fd_lcd,0,SEEK_SET);
	
	for(i=0,j=0; i<800*480*4; i+=4,j+=3)
	{
		color_buf[i] 	= bmp_buf[j];		//b
		color_buf[i+1] 	= bmp_buf[j+1];		//g	
		color_buf[i+2] 	= bmp_buf[j+2];		//r
		color_buf[i+3] 	= 0;		//a	
		
	}
	
	for(i=479; i>=0; i--)
		write(fd_lcd,&color_buf[800*i*4],800*4);
	
	close(fd_lcd);

	}

	
	lseek(fd_bmp,54,SEEK_SET);	
	
	read(fd_bmp,bmp_buf,800*480*3);
	close(fd_bmp);
	

	fd_lcd=open("/dev/fb0",O_RDWR);
	
	if(fd_lcd < 0)
	{
		printf("open lcd fail\n");
		
		return -1;
	}
	
	

	lseek(fd_lcd,0,SEEK_SET);
	

	for(i=0,j=0; i<800*480*4; i+=4,j+=3)
	{
		color_buf[i] 	= bmp_buf[j];		//b
		color_buf[i+1] 	= bmp_buf[j+1];		//g	
		color_buf[i+2] 	= bmp_buf[j+2];		//r
		color_buf[i+3] 	= 0;		//a	
		
	}
	
	for(i=479; i>=0; i--)
		write(fd_lcd,&color_buf[800*i*4],800*4);
	

	close(fd_lcd);
	

	return 0;
}

void *pic_auto_play(void *arg)
{
	while(1)
	{

		if(paly_flag==1)
		{
			pic_next();
			sleep(1);
			
			usleep(100);
		}
	}
}

void *get_butten()
{
	// struct pollfd fdset;
    // unsigned char buf[128];
	// int fd=open("/sys/class/gpio/gpio63/value",O_RDWR);
	// while (1) {
    //     memset(&fdset,0x00,sizeof(struct pollfd));
    //     fdset.fd = fd; //fd 即为open /sys/class/gpio/gpioN/value返回的句柄
    //     fdset.events = POLLPRI;
    //     poll(&fdset,1,3000);
    //     if (fdset.events & POLLPRI) {
    //         read(fdset.fd,buf,sizeof(buf));
    //         lseek(fdset.fd,0,SEEK_SET);
    //         printf("K4");
    //     }
	// }
		int K4_fd,K3_fd,K2_fd,K6_fd;
		int K[7];
		
	while(1)
	{
		system("cat /sys/class/gpio/gpio63/value > K4.txt");
		usleep(1000);
		system("cat /sys/class/gpio/gpio62/value > K3.txt");
		usleep(1000);
		system("cat /sys/class/gpio/gpio28/value > K2.txt");
		usleep(1000);
		system("cat /sys/class/gpio/gpio41/value > K6.txt");
		usleep(1000);
		K4_fd=open("K4.txt",O_RDONLY);
		K3_fd=open("K3.txt",O_RDONLY);
		K2_fd=open("K2.txt",O_RDONLY);
		K6_fd=open("K6.txt",O_RDONLY);
		read(K4_fd,&K[4],1);
		read(K3_fd,&K[3],1);
		read(K2_fd,&K[2],1);
		read(K6_fd,&K[6],1);
		//printf("K4=%c\r\n",K[4]);
		close(K4_fd);
		close(K3_fd);
		close(K2_fd);
		close(K6_fd);
		K4=K[4]-'0';
		K3=K[3]-'0';
		K2=K[2]-'0';
		K6=K[6]-'0';
		
		//system("echo star:K6=");
		//system("cat K6.txt");
		//system("echo end");

		// if(K4==1)
		// {
		// 	usleep(1000);
		// 	if(K4==1)
		// 	{	
		// 		pic_back();
		// 		printf("K4");
		// 	}	
		// }
		// if(K3==0)
		// {
		// 	usleep(1000);
		// 	if(K4==0)
		// 	{
		// 		//pic_next();
		// 		printf("K3");
		// 	}
		// }
		// if(K2==0)
		// {
			
		// 	printf("K2");
		// }
		// if(K6==0)
		// {
		// 	printf("K6");
		// }
		 usleep(10000);
	}
}

void *butten_turn()
{
	led7_flag=led8_flag=led9_flag=led10_flag=0;
	
	while(1)
	{
		for(K4i;K4i<1;K4i++)
		{sleep(1);printf("laozihaizai");}
		if(K4==0)
			{
				pic_back();
				//printf("K4_daodi=%c\r\n",K4);
			}
		if(K3==0)
			{
				pic_next();
			}
		if(K2==0)
			{
				paly_flag=1;
			}
		if(K6==0)
			{
				paly_flag=0;
			}
	}		
}
static int getResultFromSystemCall(const char *pCmd,char *pResult,int size)
{
 int fd[2];
 if(pipe(fd)){
   printf("pipe error ! \n");
   return -1; 
 }
 int bak_fd = dup(STDOUT_FILENO);
 int new_fd = dup2(fd[1],STDOUT_FILENO);

  system(pCmd);
  read(fd[0],pResult,size-1);
  pResult[strlen(pResult)-1] = 0;

 dup2(bak_fd,new_fd);
 return 0;
}

int main(int argc, char **argv)
{  
	pthread_t tid_photo;
	pthread_t tid_get_butten;
	pthread_t tid_butten_turn;
	//pthread_t tid_pic_slip;
    
	load_all_pic();

	system("echo 63 > /sys/class/gpio/export");//k4
	system("echo 62 > /sys/class/gpio/export");//k3
	system("echo 28 > /sys/class/gpio/export");//K2
	system("echo 41 > /sys/class/gpio/export");//k6
	//system("rmmod led_drv > /dev/null");//led.ko
	//system("insmod led.ko > /dev/null");//led.ko
	
	//led_fd = open("/dev/gec6818_leds",O_RDWR);
	pthread_create(&tid_photo,NULL,pic_auto_play,NULL);
	pthread_create(&tid_get_butten,NULL,get_butten,NULL);
	pthread_create(&tid_butten_turn,NULL,butten_turn,NULL);
	//pthread_create(&tid_pic_slip,NULL,pic_slip,NULL);
	
		//pic_next();
		//sleep(2);
		get_sta();
	//pic_y=0;
	//y_buf=0;
	//pic_slip();
	K4=1;
	while(1);
	//返回0是正确，没有错误，也就是的正确的返回
	return 0;  
}