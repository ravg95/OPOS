#Target - name of executable
TARGET := kernel.bin

#Check for operating system and determine compiler
include check_compiler.mk

#Directories
SRCDIRS := kernel lib keyboard shell 
ASMSOURCES := $(foreach DIR, $(SRCDIRS), $(wildcard $(DIR)/*.asm))
CSOURCES := $(foreach DIR, $(SRCDIRS), $(wildcard $(DIR)/*.c))
COBJECTS := $(CSOURCES:%.c=%.c.o)
ASMOBJECTS := $(ASMSOURCES:%.asm=%.a.o)

#Default target
.PHONY : all
all : $(TARGET)

#Linking
$(TARGET) :  $(ASMOBJECTS) $(COBJECTS)
	$(LD) $(LDFLAGS) -o $@ $^
	
#Compiling ASM Sources
%.a.o : %.asm
	$(AA) $(AFLAGS) -o $@ $<

#Compiling C Sources
%.c.o : %.c
	$(CC) $(CFLAGS) $(CINCLUDES) -o $@ -c $<

iso: kernel.iso

kernel.iso: kernel.bin
	mkdir iso
	mkdir iso/boot
	mkdir iso/boot/grub
	cp $< iso/boot/$<
	echo 'set timeout=0' > iso/boot/grub/grub.cfg
	echo 'set default=0' >> iso/boot/grub/grub.cfg
	echo 'menuentry "posOS" {' >> iso/boot/grub/grub.cfg
	echo '	multiboot /boot/kernel.bin' >> iso/boot/grub/grub.cfg
	echo '	boot' >> iso/boot/grub/grub.cfg
	echo '}' >> iso/boot/grub/grub.cfg
	grub-mkrescue --output=$@ iso
	rm -rf iso

run: kernel.iso
	(killall VirtualBox && sleep 2) || true
	VirtualBox --startvm "OPOS" &

	
#Generate ctags file
ctags : 
	$(CT) -R .

#Generate and strip debuging symbols
debug-syms:
	$(OC) --only-keep-debug kernel.bin kernel.sym
	$(OC) --strip-debug kernel.bin

#Remove executables and object files
clean : 
	$(RM) kernel.bin
	$(RM) kernel.sym
	$(RM) kernel.iso
	$(foreach DIR, $(SRCDIRS), $(RM) $(DIR)/*.o)
