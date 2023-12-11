ifneq ($(KERNELRELEASE),)

	obj-m   := hello.o

	hello-y := hello1.o hello2.o

	ccflags-y += -I$(obj)/inc



else

KDIR ?= /lib/modules/`uname -r`/build



default:

	$(MAKE) -C $(KDIR) M=$$PWD

        

endif
