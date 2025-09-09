# Autorres: Ana Luiza, Matheus, Jean, Pedro e Eric
# Data: 02-08-2025
# Descrição: Programa para codificar e decoficar palavras

.data
n: .word 2000

.text
.globl main
main:
	li $t0, 0 #armazenará o resultado
	li $t1, 1 #será utilizado para o contador i
	lw $t2, n #t2= n
	
	loop: move $a0, $t2 #a0 receberá n
	      move $a1, $t1 #a1 receberá i
	      jal mdc #chama mdc de a0 e a1
	      
	      li $t3, 1
	      bne $v0, $t3, salto #se o resultado do mdc for diferente pula a adição de 1 ao resultado
	      addi $t0, $t0, 1 #soma 1 se o mdc for igual a 1
	      
	salto:addi $t1, $t1, 1 #incrementa o contador
	      ble $t1, $t2, loop #continua o loop se o contador é menor que n
	     
        move $a0, $t0
	li $v0, 1 #chamada para imprimir o resultado
	syscall 
	
	li $v0, 10 #encerra o programa
	syscall 
	
	mdc: beq $a1,$zero,final #se o resto da divisão é zero finaliza o calculo
	     div $a0, $a1 #divide o valor de a(n) por b(i) 
	     mfhi $t3 #recebe o resto da divisão (r)
	     move $a0, $a1 #atribui o valor do b no a
	     move $a1, $t3 #atribui o valor do r no b
	     j mdc #se o resto não é igual a zero calcula o mdc de b e r      
	     
	     final: move $v0, $a0
	     	    jr $ra #retorno
	
	
