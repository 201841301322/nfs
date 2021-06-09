
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

	


