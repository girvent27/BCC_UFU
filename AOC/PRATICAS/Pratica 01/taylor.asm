.data
prompt:     .asciiz "Digite o valor de x em graus de 0 a 360: "
res_seno:    .asciiz "\nSeno aproximado = "
res_cos:    .asciiz "\nCosseno aproximado = "
precisao:   .double 0.00001    
um:         .double 1.0
menos_um:   .double -1.0
pi:	    .double 3.1415926535

.text
.globl main

main:
    li $v0, 4		# Interacao no terminal
    la $a0, prompt
    syscall

    li $v0, 7		# Vai ler double e guardar em f0
    syscall
    mov.d $f2, $f0	# Mover para f2
    l.d $f26, pi	# a partir daqui eu converto x rad em graus
    mul.d $f2, $f2, $f26
    li $t4, 180
    mtc1 $t4, $f26
    cvt.d.w $f26, $f26
    div.d $f2, $f2, $f26
    
    
    #----------------------------------
    # Calculo de SEN(x)
    #----------------------------------
    mov.d $f4, $f2     # termo = x
    mov.d $f6, $f4     # soma = termo
    l.d $f8, um        # n = 1
    l.d $f28, um       # f28 usado como um mesmo, nao mudar
    l.d $f10, menos_um  # f22 = -um
    l.d $f24, precisao

sen_loop:
    # Calcula proximo termo:
    # termo *= -x^2 / ((2n)*(2n+1))

    mul.d $f12, $f2, $f2          # f8 = x^2
    neg.d $f12, $f12              # f8 = -x^2
    # Precisamos de (2n)*(2n+1):
    # f8 == n
    add.d $f14, $f8, $f8       # f14 = 2n
    add.d $f16, $f14, $f28     # f16 = 2n+1
    mul.d $f18, $f14, $f16     # f18 = (2n)*(2n+1)
    div.d $f20, $f12, $f18        # f20 = (-x^2)/((2n)*(2n+1))
    mul.d $f4, $f4, $f20          # termo *= esse fator
    add.d $f6, $f6, $f4           # soma += termo

    # Verificar |termo| >= precisao
    abs.d $f22, $f4
    c.lt.d $f22, $f24
    bc1t sen_fim                 # se termo < precisao ? fim
    add.d $f8, $f8, $f28	 # n++
    j sen_loop

sen_fim:
    # Imprimir resultado do seno
    li $v0, 4
    la $a0, res_seno
    syscall

    li $v0, 3
    mov.d $f12, $f6
    syscall

    #---------------------------------
    # Calculo de COS(x)
    #---------------------------------
    l.d $f4, um       # termo = 1
    mov.d $f6, $f4    # soma = termo
    li $t0, 1         # n = 1

cos_loop:
    # termo *= -x^2 / ((2n-1)*(2n)) 

    mul.d $f8, $f2, $f2
    neg.d $f8, $f8

    mtc1 $t0, $f10		#isso aqui evita usar muitos registradores igual eu fiz no seno
    cvt.d.w $f10, $f10		#resumidamente transformo int em float e dps em double	
				#fica seno e cosseno implementados em formas diferentes para fins didaticos
    add.d $f12, $f10, $f10       # f12 = 2n
    li $t1, 1
    mtc1 $t1, $f14
    cvt.d.w $f14, $f14
    sub.d $f14, $f12, $f14       # f14 = 2n - 1

    mul.d $f12, $f12, $f14       # f12 = (2n)*(2n-1)

    div.d $f8, $f8, $f12
    mul.d $f4, $f4, $f8

    add.d $f6, $f6, $f4

    abs.d $f16, $f4
    l.d $f18, precisao
    c.lt.d $f16, $f18
    bc1t cos_fim

    addi $t0, $t0, 1
    j cos_loop

cos_fim:
    # Imprimir resultado do cosseno
    li $v0, 4
    la $a0, res_cos
    syscall

    li $v0, 3
    mov.d $f12, $f6
    syscall

    # Encerrar programa
    li $v0, 10
    syscall
