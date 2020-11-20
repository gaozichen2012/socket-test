SERVER_TARGETS = mcu_server
CLIENT_TARGETS = mcu_client

SERVER_SRC_FILES = udpserver.c
CLIENT_SRC_FILES = udpclient.c

# CLIENT_COMPILER = gcc
CLIENT_COMPILER = arm-oe-linux-gnueabi-gcc  -march=armv7-a -mfloat-abi=softfp -mfpu=neon  -O2 -fexpensive-optimizations -frename-registers -fomit-frame-pointer -include quectel-features-config.h
SERVER_COMPILER = gcc

.PHPNY: all
all: $(SERVER_TARGETS) $(CLIENT_TARGETS)

# 嵌入式下的client需要再交叉编译工具下编译；ubuntu系统中用gcc
$(SERVER_TARGETS): 
	$(SERVER_COMPILER) $(SERVER_SRC_FILES) -o $@

$(CLIENT_TARGETS): 
	$(CLIENT_COMPILER) $(CLIENT_SRC_FILES) -o $@

clean:
	rm -rf $(SERVER_TARGETS) $(CLIENT_TARGETS) *.o
