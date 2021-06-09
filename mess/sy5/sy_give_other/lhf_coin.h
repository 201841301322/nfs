int pic_back()
{
	pic_num-=1;
	if(pic_num<0)
	{
		pic_num=PIC_SUM;
	}
	play_pic(pic_num);
	play_pic(pic_num);
	return 0;
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
			sleep(2);
			
			usleep(100);
		}
	}
}


#define LHF \
    pthread_t tid_photo;\
	pthread_t tid_get_butten;\
	pthread_t tid_butten_turn;\
	system("echo 63 > /sys/class/gpio/export");\
	system("echo 62 > /sys/class/gpio/export");\
	system("echo 28 > /sys/class/gpio/export");\
	system("echo 41 > /sys/class/gpio/export");\
	system("rmmod led_drv > /dev/null");\
	system("insmod led.ko > /dev/null");\
	led_fd = open("/dev/gec6818_leds",O_RDWR);\
	pthread_create(&tid_photo,NULL,pic_auto_play,NULL);\
	pthread_create(&tid_get_butten,NULL,get_butten,NULL);\
	pthread_create(&tid_butten_turn,NULL,butten_turn,NULL);\
		pic_next();\
		sleep(2);\
		get_sta();


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
		if(K4==0)
			{
				pic_back();
				//printf("K4=%c\r\n",K4);
				if(led7_flag==0)
				{ioctl(led_fd,GEC6818_LED_ON,7);led7_flag=1;}
				else
				{ioctl(led_fd,GEC6818_LED_OFF,7);led7_flag=0;}
				while(!K4);	
			}
		if(K3==0)
			{
				pic_next();
				if(led8_flag==0)
				{ioctl(led_fd,GEC6818_LED_ON,8);led8_flag=1;}
				else
				{ioctl(led_fd,GEC6818_LED_OFF,8);led8_flag=0;}
				while(!K3);	
			}
		if(K2==0)
			{
				paly_flag=1;
				if(led9_flag==0)
				{ioctl(led_fd,GEC6818_LED_ON,9);led9_flag=1;}
				else
				{ioctl(led_fd,GEC6818_LED_OFF,9);led9_flag=0;}
				while(!K2);	
			}
		if(K6==0)
			{
				paly_flag=0;
				if(led10_flag==0)
				{ioctl(led_fd,GEC6818_LED_ON,10);led10_flag=1;}
				else
				{ioctl(led_fd,GEC6818_LED_OFF,10);led10_flag=0;}
				while(!K6);	
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
