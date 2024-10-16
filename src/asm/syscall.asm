section .data
    command db "clear", 0
    args db 0

section .text
    global _syscall_entry  ; Novo nome

_syscall_entry:
    ; Chamada para execução do comando "clear"
    mov rax, 59              ; Número da syscall para execve
    lea rdi, [command]       ; Endereço do comando
    lea rsi, [args]          ; Argumentos (NULL)
    xor rdx, rdx             ; Variáveis de ambiente (NULL)
    syscall                  ; Chamada do sistema

    ; Syscall para alocação de memória (mmap)
    mov rax, 9               ; Número da syscall para mmap
    xor rdi, rdi             ; Endereço inicial (NULL)
    mov rsi, 4096            ; Tamanho do bloco (4KB)
    mov rdx, 3               ; Proteções: leitura e escrita (PROT_READ | PROT_WRITE)
    mov r10, 34              ; Flags: MAP_ANONYMOUS | MAP_PRIVATE
    xor r8, r8               ; Fd (não importa para MAP_ANONYMOUS)
    xor r9, r9               ; Offset (0)
    syscall                  ; Chamada do sistema

    ; Finalização do programa
    mov rax, 60              ; Número da syscall para exit
    xor rdi, rdi             ; Código de saída (0 para sucesso)
    syscall                  ; Chamada do sistema
