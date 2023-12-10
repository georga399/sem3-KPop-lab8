global passwordCoder

section .text

%macro initS_block 3
  ;%1 - key string pointer
  ;%2 - key string size
  ;%3 - S_block pointer
  mov rcx, 256
  mov rsi, 0
  mov rbx, %3
  mov rax, 0
%%while_fill:
  mov [rbx+rsi], al
  inc si
  inc al
  cmp si, cx
  loopne %%while_fill
  
  mov rdi, 0 ;j
  mov rsi, 0 ;i
  mov cx,256

%%while_swap:
  mov rax, rdi ; add j
  
  mov rbx, %3
  mov dl, [rbx+rsi] 
  add al, dl ;add S[i]

  push ax

  xor rdx, rdx
  mov ax, si
  mov bx, %2
  div bx
  
  mov rax, rdx
  mov rbx,%1
  mov dl,[rbx+rax]

  pop ax

   
  add al,dl
  
  mov di, ax

  ;swap S[rsi] and S[rdi]
  mov rbx, %3
  mov al, [rbx+rsi]
  mov dl, [rbx+rdi]
  mov [rbx+rdi], al
  mov [rbx+rsi], dl

  inc si
  cmp si, cx
  loopne %%while_swap


%endmacro


%macro PRGA 2
  ;%1 - S_block pointer
  ;%2 - cipher pointer
  ;rcx, rdi - string size
  ;rsi - string pointer
  mov rsi,0 ; i
  mov rdi,0  ;j
  mov rdx,0
  mov rax,0
%%PRGA_loop:

  push rax
  push rcx

  mov rax,rsi ;i =(i+1)mod256
  inc al
  mov rsi,rax

  mov rbx, %1
  mov rdx, rdi
  add dl,[rbx+rsi] ;j = (j+S[i])mod256
  mov rdi, rdx

  
  mov al,[rbx+rsi] ;Swap S[i] and S[j]
  mov dl,[rbx+rdi]
  mov [rbx+rdi],al
  mov [rbx+rsi],dl

  add al,dl
  mov dl,[rbx+rax] ;t = (S[i] + S[j])mod256

  pop rcx
  pop rax

  mov rbx, %2
  mov [rbx+rax],dl ; cipher[rax] = S[t]

  inc rax
  loop %%PRGA_loop

%endmacro

%macro xorCipher 1
  ;%1 - cipher
  ;rdi - size of string
  ;rsi - pointer of string
  mov rcx, rdi
  mov rdi,0
%%xorLoop:
  mov rbx,%1
  mov dl,[rbx+rdi]

  mov rbx,rsi
  xor dl,[rbx+rdi]
  mov rbx, %1
  mov [rbx+rdi],dl

  inc rdi
  ; cmp rcx,rdi
  loop %%xorLoop


%endmacro

passwordCoder:
  ;rdi - size of string
  ;rsi - pointer of string
  push rdi
  push rsi
  initS_block key, keyLength, S_block
  pop rsi
  pop rdi
  push rdi
  push rsi

  mov rcx, rdi 
  PRGA S_block, cipher

  pop rsi
  pop rdi

  xorCipher cipher

  mov rax, cipher
  ret

section .data
  cipher: db 2000 dup(0)
  cipherLength: equ $ - cipher
  S_block: db 256 dup(0)

section .rodata
  key: db "egor123"
  keyLength: equ $ - key
