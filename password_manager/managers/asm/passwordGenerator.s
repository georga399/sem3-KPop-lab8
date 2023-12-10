global passwordGenerator

section .text

%macro randomMax 1
  
  ;rax - return generated random value
  xor rax, rax
  rdtsc ;edx:eax
  mul esi
  add eax, edx
  mov rbx, %1
  mov rdx,0
  div rbx
  mov rax, rdx

%endmacro 

passwordGenerator:
  ; rdi - sizeof password
  mov rsi, 0
  cmp rdi,1
  jb endPasswordGen
passwordGenLoop:
  push rsi
  randomMax passwordSymbsLength
  pop rsi
  mov rbx, passwordSymbs
  mov dl, [rbx+rax]
  mov rbx, password
  mov [rbx+rsi],dl
  inc rsi
  cmp rsi, rdi
  loopne passwordGenLoop

endPasswordGen:
  mov rax, password
  ret

section .rodata
  passwordSymbs: db "_abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ1234567890"
  passwordSymbsLength: equ $-passwordSymbs

section .data
  password: db 500 dup(0)
  
  