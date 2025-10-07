section .note.GNU-stack noalloc noexec nowrite
section .text

    global soma

soma: 
    mov rax, rdi
    add rax, rsi
    ret