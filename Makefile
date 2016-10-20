
CFLAGS  = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -std=c99
CXXFLAGS = -m32 -fno-use-cxa-atexit -nostdlib -fno-builtin -fno-rtti -fno-exceptions -fno-leading-underscore -O2
ASMFLAGS = --32
LDFLAGS = -melf_i386

objects = ostream.o main.o loader.o gdt.o

%.o : %.cpp
	g++ $(CXXFLAGS) -c -o $@ $<
%.o : %.c
	gcc $(CFLAGS) -c  -o $@ $<

%.o : %.s
	as $(ASMFLAGS) -o $@ $<
	
kernel.bin: linker.ld $(objects)
	ld $(LDFLAGS) -T $< -o $@ $(objects)
	
	
iso: kernel.bin
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
	grub-mkrescue --output=kernel.iso iso
	rm -rf iso

clean:
	rm -rf $(objects) kernel.bin kernel.iso
	
run: iso
	(killall VirtualBox && sleep 2) || true
	VirtualBox --startvm "posOS" &

	
