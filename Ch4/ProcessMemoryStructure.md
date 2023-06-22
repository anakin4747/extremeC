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