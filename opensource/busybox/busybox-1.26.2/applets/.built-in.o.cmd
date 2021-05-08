cmd_applets/built-in.o :=  arm-hisiv510-linux-gcc -nostdlib -nostdlib -mcpu=cortex-a7 -mfloat-abi=hard -mfpu=neon-vfpv4 -r -o applets/built-in.o applets/applets.o
