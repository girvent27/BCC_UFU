.data
msgA:       .asciiz "Valor de A: "
msgB:       .asciiz "Valor de B: "
newline:    .asciiz "\n"
x_array:    .space 40        # espaço para floats
y_array:    .space 40        # espaço para floats

.text
.globl main

main:
    # n = 10
    li $t0, 10

    # seed = 12345 (fixa) - A seed é o valor inicial usado para gerar a sequência de números aleatórios.
    li $t1, 12345

    # ponteiros para arrays
    la $t2, x_array
    la $t3, y_array

    # contador i = 0
    li $t4, 0

gen_loop:
    beq $t4, $t0, gen_done

    # seed = seed * 1103515245 + 12345
    li $t5, 1103515245
    mult $t1, $t5
    mflo $t6
    addi $t6, $t6, 12345
    move $t1, $t6

    # Pega o valor da seed, desloca 16 bits para a direita (>> 16) e depois faz um AND com 0x7fff para manter apenas os 15 bits menos significativos do resultado. 
    # Pois sem isso o gerador não segue o padrão corret e os numeros poderiam sair repetidos
    srl $t7, $t6, 16
    andi $t7, $t7, 0x7fff

    # rand mod 20 -> resto em $t9
    li $t8, 20
    divu $t7, $t8
    mfhi $t9

    # converte inteiro para float e salva em x_array
    mtc1 $t9, $f0
    cvt.s.w $f0, $f0
    swc1 $f0, 0($t2)

    # gera y: repete o processo
    li $t5, 1103515245
    mult $t1, $t5
    mflo $t6
    addi $t6, $t6, 12345
    move $t1, $t6

    srl $t7, $t6, 16
    andi $t7, $t7, 0x7fff
    li $t8, 20
    divu $t7, $t8
    mfhi $t9

    mtc1 $t9, $f0
    cvt.s.w $f0, $f0
    swc1 $f0, 0($t3)

    # avança ponteiros
    addi $t2, $t2, 4
    addi $t3, $t3, 4

    addi $t4, $t4, 1
    j gen_loop

gen_done:
    # reseta ponteiros e contador
    la $t2, x_array
    la $t3, y_array
    li $t4, 0

    # inicializa somas Sx e Sy em $f10 e $f12 com 0.0
    mtc1 $zero, $f10
    mtc1 $zero, $f12

sum_loop:
    beq $t4, $t0, sum_done

    l.s $f2, 0($t2)
    l.s $f4, 0($t3)

    add.s $f10, $f10, $f2
    add.s $f12, $f12, $f4

    addi $t2, $t2, 4
    addi $t3, $t3, 4
    addi $t4, $t4, 1
    j sum_loop

sum_done:
    # imprimir Sx (como exemplo de "A")
    li $v0, 4
    la $a0, msgA
    syscall

    # guarda Sy antes de sobrescrever $f12 para imprimir Sx
    mov.s $f14, $f12    # salva Sy em $f14
    mov.s $f12, $f10    # coloca Sx em $f12 (argumento para syscall 2)
    li $v0, 2
    syscall

    # nova linha
    li $v0, 4
    la $a0, newline
    syscall

    # imprimir Sy (como exemplo de "B")
    li $v0, 4
    la $a0, msgB
    syscall

    mov.s $f12, $f14    # restaura Sy em $f12
    li $v0, 2
    syscall

    # nova linha
    li $v0, 4
    la $a0, newline
    syscall

    # fim
    li $v0, 10
    syscall
