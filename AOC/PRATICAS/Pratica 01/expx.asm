# Autorres: Ana Luiza, Matheus, Jean, Pedro e Eric
# Data: 02-08-2025
# Descricao: Programa que calcula e^x 

.data
parada:    .double 0.00001
um:        .double 1.0
mensagem1: .asciiz "para e^x digite x: "
mensagem2: .asciiz "Resultado eh: "


.text
.globl main
main: 
	li $v0, 4
    	la $a0, mensagem1
    	syscall
	li $v0, 7               # leitura de um float x (armazenado em $f0)
	syscall
	mov.d $f2, $f0		# mover x para f2 que sera usado
	l.d $f4, um		# f4 sera o somatorio = 1
	l.d $f6, um		# f6 sera o termo = 1
	l.d $f8, um		# f8 sera n = 1 (usado no fatorial)
	l.d $f10, parada	# f110 = 0,00001
	l.d $f16, um		# usado para somar
	
	
	loop:
	abs.d $f12, $f6		# f10 = |termo| (modulo do numero termo)
	c.lt.d $f12, $f10	# |termo| < 0.00001 ? flag em 1
	bc1t end_loop		# se a flag em 1 for true, pula pra end_loop
	
	div.d $f14, $f2, $f8     # f14 = x / n
    	mul.d $f6, $f6, $f14     # termo *= x/n
    	add.d $f4, $f4, $f6	 # somatorio = somatorio + termo
    	add.d $f8, $f8, $f16	 # n++
    	
    	j loop			 # pula para o inicio de loop
    	
    	end_loop:
    		# Imprimir resultado
    		li $v0, 4
    		la $a0, mensagem2
    		syscall

    		mov.d $f12, $f4          # mover o resultado do somatorio em f4 para f12, que sera imprimido
    		li $v0, 3
    		syscall

    		# Encerrar
    		li $v0, 10
    		syscall
    	
	
	
	
	
	
