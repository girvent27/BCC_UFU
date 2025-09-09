# Autorres: Ana Luiza, Matheus, Jean, Pedro e Eric
# Data: 02-08-2025
# Descrição: Programa para codificar e decoficar palavras

.data
n: .word 6
zero: .float 0.0
um: .float 1.0

.text
.globl main
main: 
	lw $t0, n
	li $t1, 1 #iniciar $t1 com o valor um para usar como contador
	l.s $f0, zero #iniciar $f0 com o valor zero para armazenar a soma da harmônica
	l.s $f2, um #iniciar $f2 com o valor um para calcular 1/i
	
	loop: mtc1 $t1, $f4
	      cvt.s.w $f4, $f4 #converter $f4 para float
	      div.s $f6, $f2, $f4 #calcula 1/i
	      add.s $f0, $f0, $f6 # soma o valor de 1/i no total
	      addi $t1, $t1, 1 #incrementa o contador
	      ble $t1, $t0, loop #se $t1 for menor que o valor de n, continua o loop
	
	mov.s $f12, $f0
	li $v0, 2 #chamada para imprimir o resultado
	syscall 
	li $v0, 10 #encerra o programa
	syscall 
