######################################
#可执行程序 可用于编译动态库的可执行程序 Makefile
#cpp代码要和main同目录下
#头文件放在inc下
######################################
#source file
#源文件，自动找所有.c和.cpp文件，并将目标定义为同名.o文件
SOURCE  := $(wildcard *.c) $(wildcard *.cpp)
OBJS    := $(patsubst %.c,%.o,$(patsubst %.cpp,%.o,$(SOURCE)))
  
#target you can change test to what you want
#目标文件名，输入任意你想要的执行文件名
TARGET  := test
  
#compile and lib parameter
#编译参数
CC      := g++ #要注意这里gcc和g++的区别，一般c++就用g++
#-o和文件后面
LIBS    := -L./lib  #这里添加库路径 -L./lib
LDFLAGS :=    #这里添加库名-lmath
#-o前面
DEFINES :=  
INCLUDE := -I./inc  -I.  #这里添加头文件路径-I./inc
CFLAGS  := -g -Wall -O3 $(DEFINES) $(INCLUDE)
CXXFLAGS:= $(CFLAGS) -DHAVE_CONFIG_H
 
  
#i think you should do anything here
#下面的基本上不需要做任何改动了
.PHONY : everything objs clean veryclean rebuild
  
everything : $(TARGET)
  
all : $(TARGET)
  
objs : $(OBJS)
  
rebuild: veryclean everything
                
clean :
	rm -fr *.so
	rm -fr *.o
veryclean : clean
	rm -fr $(TARGET)
  
$(TARGET) : $(OBJS)
	$(CC) $(CXXFLAGS) -o $@ $(OBJS) $(LDFLAGS) $(LIBS)
