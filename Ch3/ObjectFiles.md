# Chapter 3 - Object Files

Relocatable object files (\*.o) are temporary products in the C toolchain to either make executables or libraries. Hence, the *relocatable*.

## Application Binary Interface (ABI)

An ABI is an API but is compatible at the machine-level instructions. Object files must have the correct ABI to run on that hardware. 

## Object File Formats

The standard output from a compiler *a.out* stands for assembler output. This used to be a file format but is deprecated. It was replaced by Common Object File Format (COFF). Which then evolved into OS specific file formats like ELF for UNIX, Mach-O for Macs, and PE for Windows.

## Relocatable Object Files

Inside .o files there are several sections. There is a code section for instructions for functions. There is a data section for initialized variables. There is a symbol table for all the symbols in the translation unit. The instructions have no addresses so they can be *moved* when being linked together with other files to make other C build products.

You can view the internals of .o files by using the following command. The files funcs3-1.c and main3-1.c are used to be analyzed.

    $ readelf -hSl funcs3-1.o

This will display the sections of the relocatable object file. The section .text holds machine-level instructions for the translation unit. The .data section contains the initialized global variables. The .bss section holds the number of bytes required for uninitialized global variables. And the .symtab section is the symbol table.

We can look at the symbol table again with the following command.

    $ readelf -s funcs3-1.o

## Executable Object Files

As the name implies these are executable files which can be run. They contain similar stuff as relocatable object files but they are arranged differently. We will continue using the previous example.

First we will link the relocatable files like so:

    $ gcc funcs3-1.o main3-1.o
We can view the contents of executables the same way as relocatable with the following command.

    $ readelf -hSl a.out | less
I like piping it to less so that I can use vim keybindings.

The flag *-h* shows the file-header.

    ELF Header:
        Magic:   7f 45 4c 46 02 01 01 00 00 00 00 00 00 00 00 00 
        Class:                             ELF64
        Data:                              2's complement, little endian
        Version:                           1 (current)
        OS/ABI:                            UNIX - System V
        ABI Version:                       0
        Type:                              DYN (Position-Independent Executable file)
        Machine:                           Advanced Micro Devices X86-64
        Version:                           0x1
        Entry point address:               0x1040
        Start of program headers:          64 (bytes into file)
        Start of section headers:          14072 (bytes into file)
        Flags:                             0x0
        Size of this header:               64 (bytes)
        Size of program headers:           56 (bytes)
        Number of program headers:         13
        Size of section headers:           64 (bytes)
        Number of section headers:         29
        Section header string table index: 28

The flag *-S* shows the sections of the file.

    There are 29 section headers, starting at offset 0x36f8:

    Section Headers:
        [Nr] Name              Type             Address           Offset
            Size              EntSize          Flags  Link  Info  Align
        [ 0]                   NULL             0000000000000000  00000000
            0000000000000000  0000000000000000           0     0     0
        [ 1] .interp           PROGBITS         0000000000000318  00000318
            000000000000001c  0000000000000000   A       0     0     1
        [ 2] .note.gnu.pr[...] NOTE             0000000000000338  00000338
            0000000000000030  0000000000000000   A       0     0     8
        [ 3] .note.gnu.bu[...] NOTE             0000000000000368  00000368
            0000000000000024  0000000000000000   A       0     0     4
        [ 4] .note.ABI-tag     NOTE             000000000000038c  0000038c
            0000000000000020  0000000000000000   A       0     0     4
        [ 5] .gnu.hash         GNU_HASH         00000000000003b0  000003b0
            0000000000000024  0000000000000000   A       6     0     8
        [ 6] .dynsym           DYNSYM           00000000000003d8  000003d8
            0000000000000090  0000000000000018   A       7     1     8
        [ 7] .dynstr           STRTAB           0000000000000468  00000468
            0000000000000088  0000000000000000   A       0     0     1
        [ 8] .gnu.version      VERSYM           00000000000004f0  000004f0
            000000000000000c  0000000000000002   A       6     0     2
        [ 9] .gnu.version_r    VERNEED          0000000000000500  00000500
            0000000000000030  0000000000000000   A       7     1     8
        [10] .rela.dyn         RELA             0000000000000530  00000530
            00000000000000c0  0000000000000018   A       6     0     8
        [11] .init             PROGBITS         0000000000001000  00001000
            000000000000001b  0000000000000000  AX       0     0     4
        [12] .plt              PROGBITS         0000000000001020  00001020
            0000000000000010  0000000000000010  AX       0     0     16
        [13] .plt.got          PROGBITS         0000000000001030  00001030
            0000000000000010  0000000000000010  AX       0     0     16
        [14] .text             PROGBITS         0000000000001040  00001040
            0000000000000181  0000000000000000  AX       0     0     16
        [15] .fini             PROGBITS         00000000000011c4  000011c4
            000000000000000d  0000000000000000  AX       0     0     4
        [16] .rodata           PROGBITS         0000000000002000  00002000
            0000000000000004  0000000000000004  AM       0     0     4
        [17] .eh_frame_hdr     PROGBITS         0000000000002004  00002004
            000000000000003c  0000000000000000   A       0     0     4
        [18] .eh_frame         PROGBITS         0000000000002040  00002040
            00000000000000d4  0000000000000000   A       0     0     8
        [19] .init_array       INIT_ARRAY       0000000000003df0  00002df0
            0000000000000008  0000000000000008  WA       0     0     8
        [20] .fini_array       FINI_ARRAY       0000000000003df8  00002df8
            0000000000000008  0000000000000008  WA       0     0     8
        [21] .dynamic          DYNAMIC          0000000000003e00  00002e00
            00000000000001c0  0000000000000010  WA       7     0     8
        [22] .got              PROGBITS         0000000000003fc0  00002fc0
            0000000000000040  0000000000000008  WA       0     0     8
        [23] .data             PROGBITS         0000000000004000  00003000
            0000000000000018  0000000000000000  WA       0     0     8
        [24] .bss              NOBITS           0000000000004018  00003018
            0000000000000008  0000000000000000  WA       0     0     1
        [25] .comment          PROGBITS         0000000000000000  00003018
            000000000000002d  0000000000000001  MS       0     0     1
        [26] .symtab           SYMTAB           0000000000000000  00003048
            00000000000003c0  0000000000000018          27    19     8
        [27] .strtab           STRTAB           0000000000000000  00003408
            00000000000001e3  0000000000000000           0     0     1
        [28] .shstrtab         STRTAB           0000000000000000  000035eb
            000000000000010c  0000000000000000           0     0     1
    Key to Flags:
        W (write), A (alloc), X (execute), M (merge), S (strings), I (info),
        L (link order), O (extra OS processing required), G (group), T (TLS),
        C (compressed), x (unknown), o (OS specific), E (exclude),
        D (mbind), l (large), p (processor specific)

The *-l* flag shows the program header table which provides information about the segments.

    Elf file type is DYN (Position-Independent Executable file)
    Entry point 0x1040
    There are 13 program headers, starting at offset 64

    Program Headers:
        Type           Offset             VirtAddr           PhysAddr
                        FileSiz            MemSiz              Flags  Align
        PHDR           0x0000000000000040 0x0000000000000040 0x0000000000000040
                        0x00000000000002d8 0x00000000000002d8  R      0x8
        INTERP         0x0000000000000318 0x0000000000000318 0x0000000000000318
                        0x000000000000001c 0x000000000000001c  R      0x1
            [Requesting program interpreter: /lib64/ld-linux-x86-64.so.2]
        LOAD           0x0000000000000000 0x0000000000000000 0x0000000000000000
                        0x00000000000005f0 0x00000000000005f0  R      0x1000
        LOAD           0x0000000000001000 0x0000000000001000 0x0000000000001000
                        0x00000000000001d1 0x00000000000001d1  R E    0x1000
        LOAD           0x0000000000002000 0x0000000000002000 0x0000000000002000
                        0x0000000000000114 0x0000000000000114  R      0x1000
        LOAD           0x0000000000002df0 0x0000000000003df0 0x0000000000003df0
                        0x0000000000000228 0x0000000000000230  RW     0x1000
        DYNAMIC        0x0000000000002e00 0x0000000000003e00 0x0000000000003e00
                        0x00000000000001c0 0x00000000000001c0  RW     0x8
        NOTE           0x0000000000000338 0x0000000000000338 0x0000000000000338
                        0x0000000000000030 0x0000000000000030  R      0x8
        NOTE           0x0000000000000368 0x0000000000000368 0x0000000000000368
                        0x0000000000000044 0x0000000000000044  R      0x4
        GNU_PROPERTY   0x0000000000000338 0x0000000000000338 0x0000000000000338
                        0x0000000000000030 0x0000000000000030  R      0x8
        GNU_EH_FRAME   0x0000000000002004 0x0000000000002004 0x0000000000002004
                        0x000000000000003c 0x000000000000003c  R      0x4
        GNU_STACK      0x0000000000000000 0x0000000000000000 0x0000000000000000
                        0x0000000000000000 0x0000000000000000  RW     0x10
        GNU_RELRO      0x0000000000002df0 0x0000000000003df0 0x0000000000003df0
                        0x0000000000000210 0x0000000000000210  R      0x1

    Section to Segment mapping:
    Segment Sections...
        00     
        01     .interp 
        02     .interp .note.gnu.property .note.gnu.build-id .note.ABI-tag .gnu.hash .dynsym .dynstr .gnu.version .gnu.version_r .rela.dyn 
        03     .init .plt .plt.got .text .fini 
        04     .rodata .eh_frame_hdr .eh_frame 
        05     .init_array .fini_array .dynamic .got .data .bss 
        06     .dynamic 
        07     .note.gnu.property 
        08     .note.gnu.build-id .note.ABI-tag 
        09     .note.gnu.property 
        10     .eh_frame_hdr 
        11     
        12     .init_array .fini_array .dynamic .got

All of these flags together give a comprehensive overview of an object file.

More sections are present in executables than relocatable object files.

A new concept is also present, segments. Every ELF shared object file has a number of segments and sections.

All sections with machine-level instructions are grouped into the same segment.

Sections with similar function are grouped into segments for executables.

## Static Libraries

Static libraries are a possible product of the C toolchain. They are archived by the *ar* UNIX utility and end with a .a extension to show they are archived. When including them into the generation of an executable they are linked at the linking stage to the executable. They are not considered ELF files themselves. Just archived files.

To build an archive use the *ar* utility as follows.

    $ ar crs libexample.a obj1.o obj2.o obj3.o ...

This creates a library called libexample.a. The argument *c* tells *ar* to create a new archive. The *r* tells it to insert a member into the archive and to replace it if it already exists. The *s* tells it to write an object-file index into the archive.

The folder example3-2 contains an implementation of a static library.

It has three .c files and 1 header file containing all the declarations needed to use the .c files. To build the relocatable object files I ran the following command.

    $ for file in *.c; do gcc -c $file; done

Then you should have object files for each of your .c files. You can create a static library using the ar command.

    $ ar crs libgeometry.a trigon.o twoD.o threeD.o

We can peak in our newly created static library libgeometry.a using the following command.

    $ ar t libgeometry.a

We can move our library to a more globally accessible location like /opt/geometry. Now with our library, its declarations in the header file are our interface into our library. We include the header in programs that wish to use the library. They are the public interface of the library or more commonly the API of the library.

We have to link the static library to a relocatable object file with a main to create a final executable. To do this you need to tell gcc where to look for libraries and what libraries to link.

    $ gcc main.o -L/opt/geometry -lgeometry -lm -o ex3-3.out

To do this we use the -L and -l flags. The -L flag tells the linker where to find the libraries. The -l flag tells the linker what libraries to link. Note that it wants the root of your library, so to use ours we don't specify the lib or the .a just the geometry of the libgeometry.a. Same goes for the library libm.a specified by the -lm argument. Our library uses math.h so we need to include the libm.a library which provides the mathematical definitions of the trig functions.

Note that this executable will not depend on any other code now that it has been built. With static libraries all of the dependencies have been included into the executable. We could even delete the static library from this computer and the executable will not be affected.

The fact that it contains everything it needs means it is larger than if it used a shared library.

## Dynamic Libraries

Unlike static libraries, dynamic libraries get loaded in at runtime so they are not linked to the executable. This fact makes me think of the C toolchain like a 5 step chain with the final being the loader.

Executables and Shared object files both can have segments in their structure. With those segments being made up of zero or more sections. The main difference is that in executables the symbols have fixed addresses while the shared object file will have relative addresses for its symbols. This means its symbols are always addressed the same distance apart but the address can be any address at runtime. This concept is called *position independent*.

Another difference is that a shared object file will not have all the same segments that an executable would have. Such as segments related to starting execution.

We will remake the previous example to be a shared library instead. To start we need to specify the relocatable object files to be position independent. 

    $ gcc -c twoD.c -fPIC
    $ gcc -c threeD.c -fPIC
    $ gcc -c trigon.c -fPIC

The flag -fPIC tells gcc that these should be treated as position independent code. Since shared object files are still object files, they are created by the linker. To create a shared object file use the following command.

    $ gcc -shared twoD.o threeD.o trigon.o -o libgeometry.so

Now we have a shared object file libgeometry.so. We can move it to another folder to have a more standard way of accessing it for others on the system.

    $ mv libgeometry.so /opt/geometry

Note that you do not have to make the main.c file a PIC object file. Now we can link our program which won't link the PIC files until runtime.

    $ gcc main.o -L/opt/geometry -lgeometry -lm -o ex3-3.out

We tell the linker where to find libraries and what libraries to find. We should now be able to run it.

    $ ./ex3-3.out
    error while loading shared libraries: libgeometry.so: cannot open shared object file: No such file or directory

We get this error because the loader does not know where the shared library is. To let the loader know where the library is we have to specify it in a environment variable called **LD_LIBRARY_PATH**.

    $ LD_LIBRARY_PATH=/opt/geometry ./ex3-3.out

This is a cool trick where you don't have to use export to change LD_LIBRARY_PATH for the current session but by setting it inline before the command you change the environment variable for only the single command.

## Manual Loading of Shared Libraries

Shared object files can be loaded in manually in code. The folder example3-4 has the files for this.

We will need to make our .so file slightly differently.

    $ gcc -shared twoD.o threeD.o trigon.o -lm -o libgeometry.so

We do this to link the libm.so library to the libgeometry.so object.

To compile the executable we can run the following.

    $ gcc main.c -ldl
    $ ./a.out

We can see that we do not link the program with the library here because we do it manually in the program.