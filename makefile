.PHONY:all
all:client server

client:client.c shm.c
	gcc -o $@ $^
server:server.c shm.c
	gcc -o $@ $^

.PHONY:clean
clean:
	rm -f client server 
