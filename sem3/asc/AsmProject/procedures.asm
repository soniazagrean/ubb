; procedures module

; importam variabilele din main
extrn octet_array:byte, actual_len:word, word_c:word, file_buffer:word
extrn max_bit_pos:byte, buffer:byte, msg_space:byte

; facem functiile vizibile pentru main
public parse_input_file, calc_word_c, sort_desc, find_max_bits, rotation
public display_array, display_array_full, print_hex_byte

code segment
assume cs:code

; parse_input
parse_input_file proc       ; cum intelegem aici <=> void parse_input()
    lea si, file_buffer     ; load effective address, ia adresa in sine si o pune in registru
    lea di, octet_array
    xor cx, cx
next_octet:
    xor ax, ax            ; reset ax pt noul octet
    xor bx, bx            ; in bx construim valoarea

skip_spaces:            ; curata sirul introdus de utilizator, ignora spatiile pana cand gaseste o cifra valida sau sfarsitul liniei
    mov al,[si]         ; ia valoarea de la adresa si
    cmp al, 0           ; verificam daca e 'enter'
    je done_parsing
    cmp al, ' '           ; sarim peste spatii
    jne get_first_nibble
    inc si
    jmp skip_spaces

get_first_nibble:
    call hex_to_nibble    ; convertim primul caracter ascii in valoare numerica
    mov bl, al            ; salvam prima cifra
    inc si 

    mov al, [si]          ; inspectam caracterul curent pentru a decide tipul de input
    cmp al, ' '
    je store_byte         ; valoarea ramane in partea low
    cmp al, 0           ; verificam daca am ajuns la sfarsitul sirului
    je store_byte         ; daca da, salvam cifra curenta ca fiind ultimul octet

    shl bl, 4             ; prima cifra ramane in partea high
    call hex_to_nibble    ; convertim al doilea caracter ascii in valoare numerica
    or  bl, al            ; combinam cele doua cifre intr-un singur octet
    inc si                ; trecem la urmatorul caracter din buffer

store_byte:
    mov [di], bl          ; salvam in array octetul rezultat
    inc di                ; incrementam indexul in array
    inc cx                ; incrementam numarul de elemente citite
    cmp cx, 16            ; verificam limita maxima de 16 elemente
    je done_parsing
    jmp next_octet        ; continuam procesarea pentru restul sirului

done_parsing:
    mov actual_len, cx    ; salvam numarul total de octeti procesati
    ret
parse_input_file endp

hex_to_nibble proc        ; o functie care returneaza valoarea de la un anumit cod ascii 
                          ; '0' - '9' = 30h - 39h, 'A' - 'F' = 41h - 46h
    cmp al, '0'           ; verificare limita inferioara cifre
    jb b_err
    cmp al, '9'           ; verificare daca este cifra 0-9
    jbe dig
    and al, 0dfh          ; transformam in litera mare daca este cazul
    sub al, 7             ; ajustare pentru literele a-f
dig: sub al, '0'          ; conversie finala din ascii in valoare
    ret
b_err: xor al, al         ; in caz de eroare returnam zero
    ret
hex_to_nibble endp

; calc_word_c  = bitmask
calc_word_c proc
    ; xor intre primii 4 biti octet 0 si ultimii 4 biti ultimul octet
    mov al, octet_array[0]
    shr al, 4             ; primii 4 biti
    mov si, actual_len
    dec si
    mov bl, octet_array[si]
    and bl, 0fh           ; ultimii 4 biti
    xor al, bl
    and al, 0fh
    mov bl, al            ; stocam in bl (bits 0-3 ai lui C)

    ; or intre bitii 2-5 ai fiecarui octet
    xor al, al
    lea si, octet_array
    mov cx, actual_len
or_l:
    mov dl, [si]
    shr dl, 2             ; shiftare dreapta cu 2 pozitii
    and dl, 0fh
    or al, dl
    inc si
    loop or_l
    shl al, 4             ; mutam pe pozitia bits 4-7
    or bl, al

    ; pas 3: suma modulo 256 [cite: 60, 73]
    xor al, al
    lea si, octet_array
    mov cx, actual_len
sum_l: add al, [si]       ; adunare repetata pentru suma modulo 256
    inc si
    loop sum_l
    
    mov ah, al            ; suma pe bits 8-15 
    mov al, bl            ; rezultatele pas 1 si 2 pe bits 0-7
    mov word_c, ax
    ret
calc_word_c endp

; sort_desc
sort_desc proc
    mov cx, actual_len
    dec cx                ; setam numarul de pasi pentru bubble sort
    jz s_done
outer:
    push cx
    lea si, octet_array
inner:
    mov al, [si]
    cmp al, [si+1]        ; comparam elementele vecine
    jae no_swap           ; daca ordinea e corecta, nu facem nimic
    xchg al, [si+1]       ; interschimbare valori, sortare descrescatoare
    mov [si], al
no_swap: inc si
    loop inner
    pop cx
    loop outer
s_done: ret
sort_desc endp

; find_max_bits
find_max_bits proc
    xor dx, dx            ; dh va fi pozitia curenta, dl va fi numarul maxim de biti
    mov max_bit_pos, 0ffh ; valoare default daca nu a fost gasit
    mov cx, actual_len
    lea si, octet_array
f_loop:
    push cx
    mov al, [si]
    xor bl, bl            ; contor pentru bitii de 1 ai octetului curent
    mov cx, 8
b_cnt: shr al, 1          ; extragem bitul cel mai putin semnificativ in carry
    adc bl, 0             ; adunam carry la contor
    loop b_cnt
    cmp bl, 3             ; verificam conditia: mai mult de 3 biti de 1
    jbe f_next
    cmp bl, dl            ; comparam cu maximul gasit anterior
    jbe f_next
    mov dl, bl            ; actualizam maximul
    mov max_bit_pos, dh   ; retinem pozitia curenta
f_next: inc si
    inc dh                ; avansam la urmatoarea pozitie
    pop cx
    loop f_loop
    ret
find_max_bits endp

; rotation
rotation proc
    lea si, octet_array
    mov cx, actual_len
rot_l:
    push cx
    mov al, [si]
    mov bl, al
    shr bl, 6             ; izolam bitii 7 si 6
    mov bh, bl
    shr bh, 1             ; bh = bit 7
    and bl, 01h           ; bl = bit 6
    add bl, bh            ; bl = n (suma bitilor)
    mov cl, bl
    rol al, cl
    mov [si], al
    inc si
    pop cx
    loop rot_l
    ret
rotation endp

; utilitare i/o 
display_array proc
    lea si, octet_array
    mov cx, actual_len
da_l: mov al, [si]
    call print_hex_byte   ; afisam octetul curent
    mov ah, 09h
    lea dx, msg_space     ; afisam spatiu intre elemente
    int 21h
    inc si
    loop da_l
    ret
display_array endp

display_array_full proc
    lea si, octet_array
    mov cx, actual_len
daf_l: push cx
    mov al, [si]
    call print_hex_byte   ; afisare format hex
    mov dl, '('
    mov ah, 02h
    int 21h
    mov al, [si]
    call print_bin_byte   ; afisare format binar
    mov dl, ')'
    int 21h
    mov ah, 09h
    lea dx, msg_space
    int 21h
    inc si
    pop cx
    loop daf_l
    ret
display_array_full endp

print_hex_byte proc
    push ax
    mov bl, al
    shr al, 4             ; extragem prima cifra hex
    call print_nibble
    mov al, bl
    and al, 0fh           ; extragem a doua cifra hex
    call print_nibble
    pop ax
    ret
print_hex_byte endp

print_nibble proc
    cmp al, 9
    jbe is_d
    add al, 7             ; ajustare pentru caracterele a-f
is_d: add al, '0'         ; transformare in caracter ascii
    mov dl, al
    mov ah, 02h           ; apel dos pentru afisare caracter
    int 21h
    ret
print_nibble endp

print_bin_byte proc
    push cx
    mov cx, 8
    mov bl, al
pb_l: rol bl, 1           ; aducem bitul cel mai semnificativ in carry
    mov dl, '0'
    adc dl, 0             ; adaugam carry la caracterul '0'
    mov ah, 02h
    int 21h               ; afisam '0' sau '1'
    loop pb_l
    pop cx
    ret
print_bin_byte endp

code ends
end