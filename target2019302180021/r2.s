movq	%rsp, %rax
ret
movq	%rax, %rdi
ret
popq	%rax
ret
movl	%eax, %ecx
ret
movl	%ecx, %edx
ret
movl	%edx, %esi
ret
lea	(%rdi, %rsi, 1), %rax
ret
movq	%rax, %rdi
ret
