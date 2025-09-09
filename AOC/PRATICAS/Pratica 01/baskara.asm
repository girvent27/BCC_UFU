.data                   # Declaração de variáveis e constantes
valorA:     .asciiz "Informe o valor de A: "
valorB:     .asciiz "Informe o valor de B: "
valorC:     .asciiz "Informe o valor de C: "
deltaNegativo: .asciiz "Erro: Raízes imaginárias (delta < 0)\n"
raiz1:      .asciiz "Raiz 1: "
raiz2:      .asciiz "Raiz 2: "
valor_zero: .float 0.0
valor_4:    .float 4.0
valor_2:    .float 2.0

.text                   # Declaração do código em assembly
.globl main

main:
    # valor de a
    li $v0, 4
    la $a0, valorA
    syscall

    li $v0, 6
    syscall
    mov.s $f0, $f12      # a = $f0

    # valor de b
    li $v0, 4
    la $a0, valorB
    syscall

    li $v0, 6
    syscall
    mov.s $f1, $f12      # b = $f1

    # valor de c
    li $v0, 4
    la $a0, valorC
    syscall

    li $v0, 6
    syscall
    mov.s $f2, $f12      # c = $f2

    # delta = b² - 4ac
    mul.s $f3, $f1, $f1      # b² = $f3
    mul.s $f4, $f0, $f2      # a * c = $f4
    l.s   $f5, valor_4
    mul.s $f4, $f5, $f4      # 4ac = $f4
    sub.s $f6, $f3, $f4      # delta = $f6

    # if (delta < 0.0)
    l.s $f7, valor_zero
    c.lt.s $f6, $f7
    bc1t delta_menor

    # sqrt(delta)
    sqrt.s $f8, $f6

    # raiz1 = (-b + sqrt(delta)) / (2a)
    neg.s $f9, $f1
    add.s $f10, $f9, $f8
    l.s $f11, valor_2
    mul.s $f12, $f11, $f0
    div.s $f13, $f10, $f12   # raiz1 = $f13

    # raiz2 = (-b - sqrt(delta)) / (2a)
    sub.s $f10, $f9, $f8
    div.s $f14, $f10, $f12   # raiz2 = $f14

    # imprimir raiz1
    li $v0, 4
    la $a0, raiz1
    syscall

    li $v0, 2
    mov.s $f12, $f13
    syscall

    # imprimir raiz2
    li $v0, 4
    la $a0, raiz2
    syscall

    li $v0, 2
    mov.s $f12, $f14
    syscall

    j fim

delta_menor:
    li $v0, 4
    la $a0, deltaNegativo
    syscall

fim:
    li $v0, 10
    syscall
