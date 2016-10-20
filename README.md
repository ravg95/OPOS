# posOS

To configure your enviroment, please install the following packages:

`$ apt install g++ binutils libc6-dev-i386`

I think it's best to test our OS on virtualbox so you must additionally install:

`$ apt install virtualbox grub-legacy xorriso`

I have prepared a makefile with various options.
first use:
`$ make iso` 
to generate iso file.

Then open it in virtualbox, set it up as Other/unknown system and !!!!This is Important!!!
Call it "posOS"

If you do it, you will be able to run the system directly from the console just by typing:

`$ make run`

Na dzisiaj wystarczy...
