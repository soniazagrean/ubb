; main module
extrn parse_input_file:proc, calc_word_c:proc, sort_desc:proc
extrn find_max_bits:proc, rotation:proc
extrn display_array:proc, display_array_full:proc, print_hex_byte:proc

public msg_space, octet_array, actual_len, word_c, max_bit_pos, file_buffer

data segment
    ; msg_input db 13,10,'introduceti octetii in format hex (8-16 valori): $'
    msg_wordc db 13,10,'cuvantul c calculat: $'
    msg_sorted db 13,10,'sirul sortat (descrescator): $'
    msg_maxbit db 13,10,'pozitia octetului cu cele mai multe setari de 1 (>3): $'
    msg_rot db 13,10,'sirul dupa rotiri (hex si binar): $'
    msg_err_file db 13,10,'eroare: nu s-a putut deschide input.txt!$'
    msg_err_len db 13,10,'eroare: numarul de octeti nu este intre 8 si 16!$'
    msg_space db '  $'
    
    file_name db 'input.txt', 0
    file_handle dw 0
    file_buffer db 100 dup(0)
    
    octet_array db 16 dup(0)
    actual_len dw 0
    word_c dw 0
    max_bit_pos db 0ffh

    ; buffer db 50, 0, 50 dup(0)
data ends

_stack segment
    db 256 dup(?)
_stack ends

code segment
assume cs:code, ds:data, ss:_stack

start:
    mov ax, data
    mov ds, ax

    mov ah, 3dh         ; deschidere fisier
    mov al, 0           
    lea dx, file_name
    int 21h
    jnc open_ok         ; salt daca deschiderea a reusit
    jmp error_file      ; folosim jmp pentru a evita "out of range"

open_ok:
    mov file_handle, ax

    mov ah, 3fh         ; citire continut
    mov bx, file_handle
    mov cx, 100
    lea dx, file_buffer
    int 21h

    mov ah, 3eh         ; inchidere fisier
    mov bx, file_handle
    int 21h

    call parse_input_file       ; procesare date

    ; verificam daca avem intre 8 si 16 octeti
    cmp actual_len, 8
    jb error_len_jump
    cmp actual_len, 16
    ja error_len_jump
    jmp process_data

error_len_jump:
    jmp error_len

process_data:
    call calc_word_c
    call sort_desc
    call find_max_bits

    ; afisare cuvant c
    mov ah, 09h
    lea dx, msg_wordc
    int 21h
    ; functie pt afisare word_c
    mov ax, word_c
    mov al, ah
    call print_hex_byte
    mov al, byte ptr word_c
    call print_hex_byte

    ; afisare sortat
    mov ah, 09h
    lea dx, msg_sorted
    int 21h
    ; functie pt afisarea sirului sortat
    call display_array

    ; afisare max bit
    mov ah, 09h
    lea dx, msg_maxbit
    int 21h
    mov al, max_bit_pos
    cmp al, 0ffh
    je no_max   ; daca nu s-a gasit niciun octet nr de biti de 1 > 3
    add al, '0' ; convertim in ascii
    mov dl, al
    mov ah, 02h
    int 21h
    jmp do_rot
no_max:
    mov dl, '-' ; afisam daca nu exista rezultat
    mov ah, 02h
    int 21h

do_rot:
    call rotation
    mov ah, 09h
    lea dx, msg_rot
    int 21h
    ; functie pt afisarea sirului rotit
    call display_array_full 

    jmp final_exit

error_file:
    mov ah, 09h
    lea dx, msg_err_file
    int 21h
    jmp final_exit

error_len:
    mov ah, 09h
    lea dx, msg_err_len
    int 21h

final_exit:
    mov ah, 4ch
    int 21h
code ends
end start