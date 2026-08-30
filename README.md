# no

# don't read me

# I am a work in progress and only useful to Naomi

## Useful references
Syscall convention cheat sheet: https://x64.syscall.sh/
NASM Tutorial: https://cs.lmu.edu/~ray/notes/nasmtutorial/
Linux syscall table: https://filippo.io/linux-syscall-table/
NASM documentation: https://www.nasm.us/xdoc/3.02/nasmdoc.pdf

Registers and calling convention, Harvard: https://cs61.seas.harvard.edu/site/2018/Asm1/
Memory layout, Harvard: https://cs61.seas.harvard.edu/site/2018/Datarep3/

Calling coonventoins: https://en.wikibooks.org/wiki/X86_Disassembly/Calling_Conventions
Functions and stack frames: https://en.wikibooks.org/wiki/X86_Disassembly/Functions_and_Stack_Frames
Calling functoins in assembly: https://www.cs.cornell.edu/courses/cs3410/2026sp/notes/asm-call.html

Comment explaining how errno gets set on linux: https://stackoverflow.com/questions/29047592/accessing-errno-h-in-assembly-language/29051118
Memory mapping in Linux: https://linux-kernel-labs.github.io/refs/heads/master/labs/memory_mapping.html
Linux ABI descriptoin: https://docs.kernel.org/admin-guide/abi.html 

## Maybe useful refs
Registers https://www.cs.uaf.edu/2017/fall/cs301/lecture/09_11_registers.html
System calls: https://w3.cs.jmu.edu/kirkpams/OpenCSF/Books/csf/html/Syscall.html
xmm registers: https://www.cs.uaf.edu/2017/fall/cs301/lecture/10_02_float_asm.html
x86 Assembly Guide university of virgina: https://www.cs.virginia.edu/~evans/cs216/guides/x86.html


## Procedure linkage table
Reference to what it is: https://refspecs.linuxfoundation.org/ELF/zSeries/lzsabi0_zSeries/x2251.html#PROCEDURELINKAGETABLE
What does wrt ..plt do: "This technique is used to call external procedures/functions whose address isn't known in the time of linking, and is left to be resolved by the dynamic linker at run time."