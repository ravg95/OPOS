# OPOS


To configure your enviroment, please use the following script:

https://github.com/Cheapskate01/Cross-Compiler-Build-Script
Download, run with i386-elf as the target, add the resulting folders to your PATH. 

I think it's best to test our OS on virtualbox so you must additionally install:

`$ apt install virtualbox xorriso`

I have prepared a makefile with various options.
first use:

`$ make iso` 

to generate iso file.

Then open it in virtualbox, set it up as Other/unknown system and !!!!This is Important!!!
Call it "posOS"
Then:
- give it 64MB of RAM
- create a virtual hard drive of type: VDI and size: 128MB.

If you do it, you will be able to run the system directly from the console just by typing:

`$ make run`

MAKARON = SPAGHETTI CODE
