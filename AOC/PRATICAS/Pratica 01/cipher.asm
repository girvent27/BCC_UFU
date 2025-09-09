# Autorres: Ana Luiza, Matheus, Jean, Pedro e Eric
# Data: 08-08-2025
# Descrição: Programa para codificar e decoficar palavras

.data
msg1:    .asciiz "Informe uma palavra: "
msg2:    .asciiz "Informe o deslocamento (entre 1 e 25): "
msg3:     .asciiz "Palavra codificada: "
msg4:    .asciiz "Palavra decodificada: "
str1:    .space 100 #tamanho da palavra
codificada: .space 100  #salvar a palavra codificada
decodificada: .space 100 #salvar a palavra decodificada
espaco: .asciiz "\n"

.text 
.globl main
main:
     li $t5, 'A'
     li $t6, 'Z'
     li $t7, 'a'
     li $t8, 'z'
     
      li $v0, 4
      la $a0, msg1 #imprime a string msg1
      syscall
      
      li $v0, 8 
      la $a0, str1  #a0 recebe str1
      li $a1, 100   #tamanho da string
      syscall
      move $t0, $a0 #t0 recebe o endereço da palavra lida
	
      li $v0, 4
      la $a0, msg2 #imprime a string msg2
      syscall
      li $v0, 5
      syscall
      move $t4, $v0 #$t4 recebe o deslocamento
      
      la $t1, codificada #$t1 recebe o endereco da palavra codificada
      move $t2, $zero #$t2 recebe zero

      
        loop: lb $t3, 0($t0) #lê o caracter atual
              beq $t3, $zero, codificacao #encerra o programa se encontrar \0
              
              li $t9, 10 # ASCII de '\n'
              beq $t3, $t9, pula # se for newline, pula
              
              #valores entre A e Z   
              bge $t3, $t5, maiuscula_final #se t3 for maior ou igual a A, chama confere_final
              j minuscula #se não, chama minuscula           
              
              maiuscula_final : ble $t3, $t6, maiuscula #se t3 for menor ou igual a Z, chama maiscula
                              j inicio_minuscula #se não, chama minuscula
              
              inicio_minuscula: bge $t3, $t7, minuscula_final #se t3 for maior ou igual a 'a', chama minuscula_final
                                j copia
                                
              minuscula_final: ble $t3, $t8, minuscula #se t3 for menor ou igual a 'z', chama minuscula
                               j copia
              #deslocamento
              maiuscula: sub $t3, $t3, $t5 #transforma as letras em numero a partir de 0
                        add $t3, $t3, $t4 #adiciona o deslocamento
                        rem $t3, $t3, 26 #pega o resto por 26 para descobrir o valor
                        add $t3, $t3, $t5 #retorna para o valor ascii
                        j copia
                        
              minuscula: sub $t3, $t3, $t7 #transforma as letras em numero a partir de 0
                        add $t3, $t3, $t4 #adiciona o deslocamento
                        rem $t3, $t3, 26 #pega o resto por 26 para descobrir o valor
                        add $t3, $t3, $t7 #retorna para o valor ascii
                        j copia
                        
              copia: sb $t3, 0($t1)#salva o valor na nova string
                     addi $t0, $t0, 1 #avança na string original
                     addi $t1, $t1, 1 #avança na nova string
                     j loop
                     
              pula:addi $t0, $t0, 1
                   j loop
                     
              codificacao: sb $zero, 0($t1) 
              
                           li $v0, 4  
                           la $a0, msg3 #imprime a msg3
                           syscall
                   
                           li $v0, 4 
                           la $a0, codificada #imprime a palavra codificada
                           syscall
                           
                           li $v0, 4 
                           la $a0,espaco #adiciona espaco entre as frases
                           syscall
                           
                           la $t0, codificada
                           la $t1, decodificada
                           
                           j loop2
                           
              loop2: lb $t3, 0($t0) #lê o caracter atual
                     beq $t3, $zero, decodificacao #encerra o programa se encontrar \0
              
                     li $t9, 10 # ASCII de '\n'
                     beq $t3, $t9, pula2 # se for newline, pula
              
                     #valores entre A e Z   
                     bge $t3, $t5, maiuscula_final2 #se t3 for maior ou igual a A, chama confere_final
                     j minuscula2 #se não, chama minuscula           
              
                     maiuscula_final2 : ble $t3, $t6, maiuscula2 #se t3 for menor ou igual a Z, chama maiscula
                                        j inicio_minuscula2 #se não, chama minuscula
              
                     inicio_minuscula2: bge $t3, $t7, minuscula_final2 #se t3 for maior ou igual a 'a', chama minuscula_final
                                        j copia2
                                
                     minuscula_final2: ble $t3, $t8, minuscula2 #se t3 for menor ou igual a 'z', chama minuscula
                                       j copia2
                             
                     #deslocamento
                     maiuscula2: sub $t3, $t3, $t5 #transforma as letras em numero a partir de 0
                                 sub $t3, $t3, $t4 #subtrai o deslocamento
                                 addi $t3, $t3, 26 #garante o valor positivo no calculo
                                 rem $t3, $t3, 26 #pega o resto por 26 para descobrir o valor
                                 add $t3, $t3, $t5 #retorna para o valor ascii
                                 j copia2
                        
                    minuscula2: sub $t3, $t3, $t7 #transforma as letras em numero a partir de 0
                                sub $t3, $t3, $t4 #adiciona o deslocamento
                                addi $t3, $t3, 26 #garante o valor positivo no calculo
                                rem $t3, $t3, 26 #pega o resto por 26 para descobrir o valor
                                add $t3, $t3, $t7 #retorna para o valor ascii
                                j copia2
                        
                    copia2: sb $t3, 0($t1)#salva o valor na nova string
                            addi $t0, $t0, 1 #avança na string original
                            addi $t1, $t1, 1 #avança na nova string
                            j loop2
                     
                    pula2:addi $t0, $t0, 1
                          j loop2
                      
                   decodificacao: sb $zero, 0($t1) 
              
                                   li $v0, 4  
                                   la $a0, msg4 #imprime a msg3
                                   syscall
                   
                                   li $v0, 4 
                                   la $a0, decodificada #imprime a palavra codificada

                                   syscall
                                 
                                  li $v0, 10 #encerra o programa
                                  syscall
                  