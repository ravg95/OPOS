# OPOS


!!! To switch to opos, you must:
- edit project_path/.git/config  (replace posOS in url with OPOS)
- reconfigure VB
- if you have time and it is important for you, rename your directories

To configure your enviroment, please install the following packages:

`$ apt install g++ binutils libc6-dev-i386`

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

MAKARON!
