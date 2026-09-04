# What is Libasm
Libasm is a basic library in 64-bit assembly, using Intel syntax. This current repository contains the library as well as tests for the library functions. The root of this repository can be seen as the "testing" directory, and the /lib directory as the actual libasm directory.

## Compile and test
1. Make sure the library is compiled before trying to compile and run the tests. Go to the /lib directory and run 'make' to compile the library:
```
cd lib && make
```

2. Go back to the root of the repo and run make to compile the test programme:
```
cd .. && make
```


3. Run the testing executabe (aptly named 'test') to run the tests:

```
./test
```

## Useful references
### Calling convention
- Calling conventions: https://en.wikibooks.org/wiki/X86_Disassembly/Calling_Conventions
- Syscall convention cheat sheet: https://x64.syscall.sh/

### NASM
- Official documentation: https://www.nasm.us/xdoc/3.02/nasmdoc.pdf
- NASM Tutorial: https://cs.lmu.edu/~ray/notes/nasmtutorial/

### Linux
- Linux syscall table: https://filippo.io/linux-syscall-table/
- Memory mapping in Linux: https://linux-kernel-labs.github.io/refs/heads/master/labs/memory_mapping.html
- Linux ABI description: https://docs.kernel.org/admin-guide/abi.html
- Comment explaining how errno gets set on linux: https://stackoverflow.com/questions/29047592/accessing-errno-h-in-assembly-language/29051118
- Procedure linkage table:https://refspecs.linuxfoundation.org/ELF/zSeries/lzsabi0_zSeries/x2251.html#PROCEDURELINKAGETABLE
	What does wrt ..plt do: "This technique is used to call external procedures/functions whose address isn't known in the time of linking, and is left to be resolved by the dynamic linker at run time."

### The stack in assembly
- Registers and calling convention, Harvard: https://cs61.seas.harvard.edu/site/2018/Asm1/
- Functions and stack frames: https://en.wikibooks.org/wiki/X86_Disassembly/Functions_and_Stack_Frames
- Calling functoins in assembly: https://www.cs.cornell.edu/courses/cs3410/2026sp/notes/asm-call.html

### Registers and memory layout
- Registers: https://www.cs.uaf.edu/2017/fall/cs301/lecture/09_11_registers.html
- Memory layout, Harvard: https://cs61.seas.harvard.edu/site/2018/Datarep3/
- XMM registers: https://www.cs.uaf.edu/2017/fall/cs301/lecture/10_02_float_asm.html


## Maybe useful refs
- System calls: https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/Syscall.html
- x86 Assembly Guide university of virgina: https://www.cs.virginia.edu/~evans/cs216/guides/x86.html
