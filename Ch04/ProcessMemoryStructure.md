# Chapter 4 - Process Memory Structure


## Probing Static Memory Layout

Once we have an executable we can probe its static memory. It does not have any dynamic memory yet since it is not currently running.

We can use the command *size* to view the segments of an executable. The folder example4-1 contains the files used in this example.

    $ gcc main.c
    $ size ./a.out
    text    data     bss     dec     hex filename
    1235     544       8    1787     6fb ./a.out

We see that the text section which is machine-level instructions. There is the data section for initialized data. And there is the bss section which displays the number of bytes required for storing uninitialized or initialized to zero variables.

## BSS Segment

The BSS stands for Block Started by Symbol. This segment is used for uninitialized global variables or global variables set to zero.

The code for this example is in exmaple4-2. This example adds 2 uninitialized globals and a global set to zero.

    $ size ./a.out
    text    data     bss     dec     hex filename
    1235     544      16    1795     703 ./a.out

We see that after we add those globals the bss section increases. No other segments increased.

## Data Segment

This segment stores initialized global variables. This examples is in example4-3. After adding a double and a char with initial values to the global scope we can see that the data size increased by 9 bytes (8 bytes in a double 1 byte in a char).

    # size ./a.out
    text    data     bss     dec     hex filename
    1235     553      20    1808     710 ./a.out

## Static

These global variables all have static properties. Making automatic variables static also causes the data and bss sections to increase. Makes total sense.

## objdump

We can also view the static segments of an executable using objdump.

    int x = 33; // 0x00000021
    int y = 0x12345678;
    char z[] = "ABCDE";

    int main(int argc, char** argv){
        return 0;
    }

We can view the data segment of the corresponding executable and see the following.


    $ objdump -s -j .data ./a.out
    a.out:     file format elf64-x86-64

    Contents of section .data:
     4000 00000000 00000000 08400000 00000000  .........@......
     4010 21000000 78563412 41424344 4500      !...xV4.ABCDE.  

This makes me a little confused about what are sections vs segments. Is .data a section inside the data segment since it has a period prefix? That was a common theme of sections in the readelf outputs on sections. Oh well moving on. The -s flag tells objdump to show all of the section this is the same as the --full-contents option. The -j .data specifies which section to show by name. The format for the -j switch is "-j name" or "--section=name". Under "Contents of section .data" we see two rows. The first column of each row is the address of the data. The next 4 columns are data. The last column is the ASCII format of the previous 4 columns. We can see that the 4 data columns are displayed in hex. The int with the value 33 is the second column of the second row 21000000. The data is also little endian so our variable specified in hex to be 0x12345678 is stored in the third column second row as 78563412. The next column over has the hex representation of the ASCII values "ABCDE".

## Text Segment

The linker writes the resulting machine-level instructions into the executable. We can view the text segment of a executable by using the -S flag on the objdump command. The -S switch stands for source code and it implies the switch -d which shows disassembly.

In the objdump output we can see several sections which contain machine-level instructions: .text, .init, and .plt. These allow a program to become loaded and running. These sections fall within the text segment. Our code only provided the main function. However, several functions ended up in the executable. These functions typically come from the glibc library.

## Dynamic Memory Layout

We a program is run it gets handled by a program called the loader which creates a new process and creates its dynamic memory layout. Note that the dynamic memory layout encapsulates the static layout as the static layout is still there when the process is running.

We expect to see 5 segments of a process. The static is made up of text, data, and bss. The dynamic adds the stack and the heap segments.

We will make a program which will run endlessly so that we will have time to inspect its dynamic memory. See example4-6. To inspect a running process we now have to learn about /proc and the procfs filesystem. Since nearly everything is a file in UNIX, processes or at least the data regarding to processes is keep in the /proc folder.

To analyze our running process we will run it in the background and search for its PID in the /proc folder. If the processes PID is 444 we can find info on that process at /proc/444. The memory mappings of the process would be in /proc/444/maps.

    $ cat /proc/444/maps

    55ae427be000-55ae427bf000 r--p 00000000 08:02 6866571                    /home/kin/tutorials/extremeC/Ch4/example4-6/a.out
    55ae427bf000-55ae427c0000 r-xp 00001000 08:02 6866571                    /home/kin/tutorials/extremeC/Ch4/example4-6/a.out
    55ae427c0000-55ae427c1000 r--p 00002000 08:02 6866571                    /home/kin/tutorials/extremeC/Ch4/example4-6/a.out
    55ae427c1000-55ae427c2000 r--p 00002000 08:02 6866571                    /home/kin/tutorials/extremeC/Ch4/example4-6/a.out
    55ae427c2000-55ae427c3000 rw-p 00003000 08:02 6866571                    /home/kin/tutorials/extremeC/Ch4/example4-6/a.out
    7f29b8200000-7f29b8228000 r--p 00000000 08:02 3283101                    /usr/lib/x86_64-linux-gnu/libc.so.6
    7f29b8228000-7f29b83bd000 r-xp 00028000 08:02 3283101                    /usr/lib/x86_64-linux-gnu/libc.so.6
    7f29b83bd000-7f29b8415000 r--p 001bd000 08:02 3283101                    /usr/lib/x86_64-linux-gnu/libc.so.6
    7f29b8415000-7f29b8419000 r--p 00214000 08:02 3283101                    /usr/lib/x86_64-linux-gnu/libc.so.6
    7f29b8419000-7f29b841b000 rw-p 00218000 08:02 3283101                    /usr/lib/x86_64-linux-gnu/libc.so.6
    7f29b841b000-7f29b8428000 rw-p 00000000 00:00 0 
    7f29b8545000-7f29b8548000 rw-p 00000000 00:00 0 
    7f29b8560000-7f29b8562000 rw-p 00000000 00:00 0 
    7f29b8562000-7f29b8564000 r--p 00000000 08:02 3282764                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
    7f29b8564000-7f29b858e000 r-xp 00002000 08:02 3282764                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
    7f29b858e000-7f29b8599000 r--p 0002c000 08:02 3282764                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
    7f29b859a000-7f29b859c000 r--p 00037000 08:02 3282764                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
    7f29b859c000-7f29b859e000 rw-p 00039000 08:02 3282764                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
    7ffcc6f03000-7ffcc6f24000 rw-p 00000000 00:00 0                          [stack]
    7ffcc6fea000-7ffcc6fee000 r--p 00000000 00:00 0                          [vvar]
    7ffcc6fee000-7ffcc6ff0000 r-xp 00000000 00:00 0                          [vdso]
    ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]

Fourth row from the bottom we see labelled as the stack. The addresses being the leftmost column. We can see what memory addresses are mapped to which files on the right side. The top five rows are mapped to the executable of the process. The 5 below that are mapped to the shared object file called libc.so.6. Then it seems like 3 rows of space then 5 rows of addresses mapped to the shared object file corresponding to the loader. After that comes the stack and some other memory what seems to correspond to system services?

The columns are from left to right: 
    Address range 
    Permissions - straight forward rwx, but with p for private or s for shared.
    Offset - If a region maps to a file this is the offset from the beginning of the file.
    Device - m:n - need to learn more about.
    The inode - Each file has its own - need to learn more about.
    Pathname or description - If mapped to a file this shows which file or the description of the memory.

## Stack Segment

Most of the time the contents of a process are private so they cannot be seen unless using a debugger and debugging symbols were set during compiling. The stack segment is the default source of memory for a program. Automatic memory management. Stores stack frames and variables.

## Heap Segment

The heap segment can only be used by a specific API provided by the standard C library. This API is malloc, calloc, realloc, and free. Once you use these functions to allocate heap memory we can run the program and see its memory allocation in the procfs.

    $ cat /proc/444/maps

    564f99433000-564f99434000 r--p 00000000 08:02 6866597                    /home/kin/tutorials/extremeC/Ch4/example4-7/a.out
    564f99434000-564f99435000 r-xp 00001000 08:02 6866597                    /home/kin/tutorials/extremeC/Ch4/example4-7/a.out
    564f99435000-564f99436000 r--p 00002000 08:02 6866597                    /home/kin/tutorials/extremeC/Ch4/example4-7/a.out
    564f99436000-564f99437000 r--p 00002000 08:02 6866597                    /home/kin/tutorials/extremeC/Ch4/example4-7/a.out
    564f99437000-564f99438000 rw-p 00003000 08:02 6866597                    /home/kin/tutorials/extremeC/Ch4/example4-7/a.out
    564f9956d000-564f9958e000 rw-p 00000000 00:00 0                          [heap]
    7f69a1400000-7f69a1428000 r--p 00000000 08:02 3283101                    /usr/lib/x86_64-linux-gnu/libc.so.6
    7f69a1428000-7f69a15bd000 r-xp 00028000 08:02 3283101                    /usr/lib/x86_64-linux-gnu/libc.so.6
    7f69a15bd000-7f69a1615000 r--p 001bd000 08:02 3283101                    /usr/lib/x86_64-linux-gnu/libc.so.6
    7f69a1615000-7f69a1619000 r--p 00214000 08:02 3283101                    /usr/lib/x86_64-linux-gnu/libc.so.6
    7f69a1619000-7f69a161b000 rw-p 00218000 08:02 3283101                    /usr/lib/x86_64-linux-gnu/libc.so.6
    7f69a161b000-7f69a1628000 rw-p 00000000 00:00 0 
    7f69a1816000-7f69a1819000 rw-p 00000000 00:00 0 
    7f69a1831000-7f69a1833000 rw-p 00000000 00:00 0 
    7f69a1833000-7f69a1835000 r--p 00000000 08:02 3282764                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
    7f69a1835000-7f69a185f000 r-xp 00002000 08:02 3282764                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
    7f69a185f000-7f69a186a000 r--p 0002c000 08:02 3282764                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
    7f69a186b000-7f69a186d000 r--p 00037000 08:02 3282764                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
    7f69a186d000-7f69a186f000 rw-p 00039000 08:02 3282764                    /usr/lib/x86_64-linux-gnu/ld-linux-x86-64.so.2
    7fff6c0fb000-7fff6c11c000 rw-p 00000000 00:00 0                          [stack]
    7fff6c1d8000-7fff6c1dc000 r--p 00000000 00:00 0                          [vvar]
    7fff6c1dc000-7fff6c1de000 r-xp 00000000 00:00 0                          [vdso]
    ffffffffff600000-ffffffffff601000 --xp 00000000 00:00 0                  [vsyscall]

We now see a new section called heap.