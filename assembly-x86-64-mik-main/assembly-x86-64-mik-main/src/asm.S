section .text
global asm_function
extern partition

asm_function:
    push    rbx
    push    rbp
    mov     rbp, rsp
    sub     rsp, 32            # Allocate 32 bytes for local variables

    # save parameters (Win64 calling convention)
    mov     [rbp-8], rcx       ; array pointer
    mov     [rbp-12], edx      ; left index
    mov     [rbp-16], r8d      ; right index

    # compare left and right indices
    cmp     edx, r8d
    jge     end_function

    # call partition function
    mov     rcx, [rbp-8]       ; 1st argument: array pointer
    mov     edx, [rbp-12]      ; 2nd argument: left index
    mov     r8d, [rbp-16]      ; 3rd argument: right index
    call    partition
    mov     [rbp-20], eax      ; save pivot

    # recursive call for left partition
    mov     rcx, [rbp-8]       ; 1st argument: array pointer
    mov     edx, [rbp-12]      ; 2nd argument: left index
    mov     r8d, [rbp-20]      ; 3rd argument: pivot
    dec     r8d                ; pivot - 1
    call    asm_function

    # recursive call for right partition
    mov     rcx, [rbp-8]       ; 1st argument: array pointer
    mov     edx, [rbp-20]      ; 2nd argument: pivot
    inc     edx                ; pivot + 1
    mov     r8d, [rbp-16]      ; 3rd argument: right index
    call    asm_function

end_function:
    mov     rsp, rbp
    pop     rbp
    pop     rbx
    ret