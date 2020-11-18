SERVER_TARGETS = mcu_server
CLIENT_TARGETS = mcu_client

SERVER_SRC_FILES = udpserver.c
CLIENT_SRC_FILES = udpclient.c

.PHPNY: all
all: $(SERVER_TARGETS) $(CLIENT_TARGETS)

$(SERVER_TARGETS): 
	gcc $(SERVER_SRC_FILES) -o $@

$(CLIENT_TARGETS): 
	gcc $(CLIENT_SRC_FILES) -o $@

clean:
	rm -rf $(SERVER_TARGETS) $(CLIENT_TARGETS) *.o
