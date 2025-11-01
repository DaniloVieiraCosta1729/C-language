; calcula o tamanho de uma string.
section .note.GNU-stack noalloc noexec nowrite

section .text
    global stringLength

; rdi -> address to the start of the string
; rax -> return: number of characters before the '\0'
stringLength:
    xor rax, rax

    lea r8, [rdi]
    mov r9b, byte [r8]
    test r9b, r9b
    jz .theEnd

    .next:
    inc rax
    lea r8, [rdi + rax]
    mov r9b, byte [r8]
    test r9b, r9b
    jnz .next

    .theEnd:
    ret