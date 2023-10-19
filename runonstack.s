.globl runonstack 
runonstack:
push %rbp
mov %rsp, %rbp
mov %rdx,%rsp # arg3 stack address
mov %rdi,%rax
mov %esi,%edi
callq  *%rax # call arg1(the test function)
mov %rbp,%rsp # restore the %rsp
pop %rbp
retq
