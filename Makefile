obj-m += enable_ccr.o
	
all:
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) modules
	
clean:
	
	make -C /lib/modules/$(shell uname -r)/build M=$(PWD) clean
