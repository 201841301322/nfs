cmd_libbb/perror_nomsg_and_die.o := arm-hisiv510-linux-gcc -Wp,-MD,libbb/.perror_nomsg_and_die.o.d   -std=gnu99 -Iinclude -Ilibbb  -include include/autoconf.h -D_GNU_SOURCE -DNDEBUG -D_LARGEFILE_SOURCE -D_LARGEFILE64_SOURCE -D_FILE_OFFSET_BITS=64 -D"BB_VER=KBUILD_STR(1.26.2)" -DBB_BT=AUTOCONF_TIMESTAMP  -Wall -Wshadow -Wwrite-strings -Wundef -Wstrict-prototypes -Wunused -Wunused-parameter -Wunused-function -Wunused-value -Wmissing-prototypes -Wmissing-declarations -Wno-format-security -Wdeclaration-after-statement -Wold-style-definition -fno-builtin-strlen -finline-limit=0 -fomit-frame-pointer -ffunction-sections -fdata-sections -fno-guess-branch-probability -funsigned-char -static-libgcc -falign-functions=1 -falign-jumps=1 -falign-labels=1 -falign-loops=1 -fno-unwind-tables -fno-asynchronous-unwind-tables -fno-builtin-printf -Os -mcpu=cortex-a7 -mfloat-abi=hard -mfpu=neon-vfpv4    -D"KBUILD_STR(s)=\#s" -D"KBUILD_BASENAME=KBUILD_STR(perror_nomsg_and_die)"  -D"KBUILD_MODNAME=KBUILD_STR(perror_nomsg_and_die)" -c -o libbb/perror_nomsg_and_die.o libbb/perror_nomsg_and_die.c

deps_libbb/perror_nomsg_and_die.o := \
  libbb/perror_nomsg_and_die.c \
  include/platform.h \
    $(wildcard include/config/werror.h) \
    $(wildcard include/config/big/endian.h) \
    $(wildcard include/config/little/endian.h) \
    $(wildcard include/config/nommu.h) \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/lib/gcc/arm-hisiv510-linux-uclibcgnueabi/6.2.1/include-fixed/limits.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/lib/gcc/arm-hisiv510-linux-uclibcgnueabi/6.2.1/include-fixed/syslimits.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/limits.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/features.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/uClibc_config.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/sys/cdefs.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/posix1_lim.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/local_lim.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/linux/limits.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/uClibc_local_lim.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/posix2_lim.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/xopen_lim.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/stdio_lim.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/byteswap.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/byteswap.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/byteswap-common.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/endian.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/endian.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/lib/gcc/arm-hisiv510-linux-uclibcgnueabi/6.2.1/include/stdint.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/stdint.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/wchar.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/wordsize.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/lib/gcc/arm-hisiv510-linux-uclibcgnueabi/6.2.1/include/stdbool.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/unistd.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/posix_opt.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/environments.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/types.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/lib/gcc/arm-hisiv510-linux-uclibcgnueabi/6.2.1/include/stddef.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/typesizes.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/pthreadtypes.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/confname.h \
  /opt/hisi-linux/x86-arm/arm-hisiv510-linux/target/usr/include/bits/getopt.h \

libbb/perror_nomsg_and_die.o: $(deps_libbb/perror_nomsg_and_die.o)

$(deps_libbb/perror_nomsg_and_die.o):
