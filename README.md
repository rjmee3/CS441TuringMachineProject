## Compiling
cd build
cmake ..
make

## Usage
./SUNY_VM [-a | --animate] [frame delay] <.bin file> <.tape file>

-a | --animate:
Animates process in place in terminal, uses the 'frame delay' argument as the number of microseconds in between frames.


## If Interrupted...
This program uses the ANSI escape code to set the cursor invisible while animating. If interrupted while running, the 
cursor will remain invisible in your terminal. To restore your cursor, use either "echo -e "\e[?25h"" or "tput cnorm". 
Or allow the program to run to completion.