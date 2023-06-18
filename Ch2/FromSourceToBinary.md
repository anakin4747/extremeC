# Chapter 2 - From Source To Binary

Headers are used to declare elements like functions, variables, and structures. While the definitions should always be in source files (*.c). This is a fundamental rule all C programs should follow. The only exceptions are when an element's declaration and definition cannot be separated like in a union.

A definition to know -  Forward declaration is the prototype of a function.

2 Main Compilation Rules
- We only compile .c files (which makes sense since the headers get added in by preprocessing)
- We compile each file separately

## Step 1 - Preprocessing

Replacing macros, inserting includes, or any other #s. It also removes comments. Again, the output of the Preprocessor can be seen by passing the -E flag to gcc.

The input is the program .c files and the output is a translation unit.

## Step 2 - Compilation

The input to compilation is a translation unit and the output is assembly language.

Assembly is technically still human readable.

You can have gcc stop and output the assembly to a .s file by passing the -S flag.

## Step 3 - Assembly

Input is the assembly code generated from the compilation stage. The output is machine code which is no longer human readable but is machine readable. This output is an object file. Tools like *as* are used for this function. The object files are not executable yet as they are only the implementation of the single .c file that was initially used to create it. We can use *as* in the following manor to only perform the step of assembly.

    $ as ch_2_1.s -o ch_2_1.o
This manual step is not common practice as we can just call the compiler to use *as* internally.

It is more common to run gcc with the -c flag to perform these 3 steps all together. This will make a .o file with the same prefix as the .c file.

    $ gcc -c ch_2_1.c

## Step 4 - Linker

The next step in the toolchain is the linker which combines objects files together into a final executable. The linker can be called from the UNIX command *ld* but just as *as* it is a tool used by gcc so we typically will not have to call it directly. It is more common to use gcc to link object files as it will pass the correct options.

## Preprocessor

The preprocessor simply does simple tasks like text replacement and conditional statements. It doesn't even check for valid syntax. To see translation units you can use the -E flag with gcc or you can use a command called cpp. Which stands for C Pre Processor opposed to C++.

## Compiler

The compiler does not have commands like *as* or *ld* embedded within it. It just uses the commands that are native to the system. This is because only the host would have assemblers and linkers that are optimized to run on their system.

The compilers task is to generate correct assembly instructions that will be interpreted on the target device.

To do this the compiler is split into two sections (compiler frontend and compiler backend). The compiler frontend is tasked with generating a C-independent Abstract Syntax Tree (AST). This step is architecture independent. The backend converts the AST into architecture specific assembly language.

To see the AST you can run the following command.

    $ gcc -Xclang -ast-dump -fsyntax-only ast.c         

ast.c is the example code that is being used.

## Assembler

If you have the same hardware but different OS on 2 different systems the output from the assembler would be different, even though the machine-level instruction set will be the same. In Linux the Executable and Linking Format (ELF) is used for object files.

## Linker

The linker pulls together object files to make final executables or shared object files.

The build process of a C project can have one of 3 products (or artifacts):
- An executable sometimes with the suffix .out on UNIX based systems or .exe on Windows
- A static library which can end with a .a to indicate that it is an archive or .lib in Windows
- A shared library (or shared object file) which ends with a .so in UNIX, a .dll in Windows, and a .dylib in MacOS 

Static library files are not produced by the linker. They are made by an archiving command called *ar* on UNIX based systems.
Static libraries can be linked together with other object files to produce a final executable.

Shared object files are produced by the linker. These are more dynamic libraries which get loaded into a running process at runtime. This is because it can be shared between processes so if a process is already using a .so library and a new process starts that depends on it, the .so file does not need to be loading again it can just be shared.

Instructions are grouped into symbols in .o object files. To view these symbols see the sample code *example2-3.c* which defines two simple functions. Preprocess, compile, and assemble it with the gcc -c flag to generate the object file.

    $ gcc -c example2-3.c
Now you have an object file called example2-3.o. To view the symbols pass the new object file to the nm command.

    $ nm example2-3.o
    0000000000000000 T _average
    0000000000000020 T _sum

As you can see the symbols match the functions we defined in our original .c file. Well my Mac adds underscores in front of them but it seems that on Linux it wouldn't. You can see the symbol table of this object using the readelf utility.

    $ readelf -s example2-3.o