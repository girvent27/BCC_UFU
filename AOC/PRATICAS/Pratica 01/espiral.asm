#P5: //DESENHO EM ASPIRAL//

# Arquivo: espiral.asm
# Descri��o: Preenche uma matriz com os caracteres de uma string em espiral (sentido hor�rio).

.data
	#�REA PARA DADOS NA MEM�RIA PRINCIPAL.

    # Nossa string e o tamanho da matriz.
    str: .asciiz "ADOREI PROGRAMAR EM MIPS ASSEMBLY"
    n:   .word 5
    
    # Matriz para armazenar os caracteres. 5x5 = 25 bytes.
    matriz: .space 25
    
    # Mensagens para impress�o.
    newline: .asciiz "\n"
    space:   .asciiz " "

.text
	#�REA PARA INSTRU�OES DO PROGRAMA.

.globl main
	
main:
    # Configura os argumentos para a sub-rotina desenharEspiral.
    la $a0, str     # $a0 = endere�o da string
    lw $a1, n       # $a1 = tamanho da matriz (n)
    la $a2, matriz  # $a2 = endere�o da matriz
    
    jal desenharEspiral
    
    # Chamamos a sub-rotina para imprimir a matriz.
    jal imprimir_matriz
    
    li $v0, 10
    syscall

# Sub-rotina: desenharEspiral
# Par�metros:
#   $a0 - Endere�o da string
#   $a1 - Tamanho da matriz (n)
#   $a2 - Endere�o da matriz

desenharEspiral:
    # Salva o endere�o de retorno e os registradores de trabalho.
    subi $sp, $sp, 20
    sw $ra, 0($sp)
    sw $s0, 4($sp) # s0 = n
    sw $s1, 8($sp) # s1 = k (�ndice da string)
    sw $s2, 12($sp) # s2 = top, s3 = bottom, s4 = left, s5 = right
    sw $s3, 16($sp)

    move $s0, $a1
    
    # Calcula o tamanho da string.
    move $a0, $a0 # Endere�o da string j� est� em $a0
    jal strlen
    move $s1, $v0  # $s1 = k = strlen(str)
    subi $s1, $s1, 1 # Come�a do final da string.
    
    # Inicializa as "paredes".
    li $s2, 0       # $s2 = top = 0
    subi $s3, $s0, 1 # $s3 = bottom = n - 1
    li $s4, 0       # $s4 = left = 0
    subi $s5, $s0, 1 # $s5 = right = n - 1
    
    # Ponto de entrada do loop principal.
    loop_principal:
        # Condi��o do loop: while (top <= bottom && left <= right)
        bgt $s2, $s3, fim_loop
        bgt $s4, $s5, fim_loop
        
        # Passo 1: Preencher a linha superior
        # for (int i = left; i <= right; i++)
        move $t0, $s4       # t0 = i = left
        loop_top:
            bgt $t0, $s5, fim_loop_top
            
            # Carrega o caractere da string.
            lb $t1, str($s1)
            # Calcula o endere�o da matriz: matriz[top][i] = matriz_base + top*n + i
            mul $t2, $s2, $s0
            add $t2, $t2, $t0
            add $t2, $t2, $a2
            sb $t1, 0($t2)
            
            subi $s1, $s1, 1 # k--
            addi $t0, $t0, 1 # i++
            j loop_top
        fim_loop_top:
        addi $s2, $s2, 1 # top++
        
        # Passo 2: Preencher a coluna da direita
        # for (int i = top; i <= bottom; i++)
        move $t0, $s2       # t0 = i = top
        loop_right:
            bgt $t0, $s3, fim_loop_right
            
            lb $t1, str($s1)
            # Endere�o: matriz[i][right] = matriz_base + i*n + right
            mul $t2, $t0, $s0
            add $t2, $t2, $s5
            add $t2, $t2, $a2
            sb $t1, 0($t2)
            
            subi $s1, $s1, 1 # k--
            addi $t0, $t0, 1 # i++
            j loop_right
        fim_loop_right:
        subi $s5, $s5, 1 # right--
        
        # Passo 3: Preencher a linha inferior
        # if (top <= bottom)
        bgt $s2, $s3, pular_bottom
        move $t0, $s5       # t0 = i = right
        loop_bottom:
            blt $t0, $s4, fim_loop_bottom
            
            lb $t1, str($s1)
            # Endere�o: matriz[bottom][i] = matriz_base + bottom*n + i
            mul $t2, $s3, $s0
            add $t2, $t2, $t0
            add $t2, $t2, $a2
            sb $t1, 0($t2)
            
            subi $s1, $s1, 1 # k--
            subi $t0, $t0, 1 # i--
            j loop_bottom
        fim_loop_bottom:
        subi $s3, $s3, 1 # bottom--
        
        pular_bottom:
        # Passo 4: Preencher a coluna da esquerda
        # if (left <= right)
        bgt $s4, $s5, pular_left
        move $t0, $s3       # t0 = i = bottom
        loop_left:
            blt $t0, $s2, fim_loop_left
            
            lb $t1, str($s1)
            # Endere�o: matriz[i][left] = matriz_base + i*n + left
            mul $t2, $t0, $s0
            add $t2, $t2, $s4
            add $t2, $t2, $a2
            sb $t1, 0($t2)
            
            subi $s1, $s1, 1 # k--
            subi $t0, $t0, 1 # i--
            j loop_left
        fim_loop_left:
        addi $s4, $s4, 1 # left++
        
        pular_left:
        j loop_principal
        
    fim_loop:
    # Restaura os registradores e retorna.
    lw $ra, 0($sp)
    lw $s0, 4($sp)
    lw $s1, 8($sp)
    lw $s2, 12($sp)
    lw $s3, 16($sp)
    addi $sp, $sp, 20
    jr $ra

# Sub-rotina auxiliar: strlen
# Par�metro:
#   $a0 - Endere�o da string
# Retorno:
#   $v0 - Tamanho da string

strlen:
    li $v0, 0
    li $t0, 0 # Contador
    
    loop_strlen:
        lb $t1, 0($a0)
        beqz $t1, fim_strlen # Se o byte for 0 (terminador), sai.
        addi $t0, $t0, 1
        addi $a0, $a0, 1
        j loop_strlen
    fim_strlen:
    move $v0, $t0
    jr $ra

# Sub-rotina auxiliar: imprimir_matriz
# Usa os mesmos par�metros globais de 'main' para a matriz.

imprimir_matriz:
    lw $s0, n       # s0 = n
    la $a2, matriz  # a2 = endere�o da matriz
    
    li $t0, 0       # t0 = i (contador da linha)
    loop_linhas:
        bge $t0, $s0, fim_loop_linhas
        
        li $t1, 0   # t1 = j (contador da coluna)
        loop_colunas:
            bge $t1, $s0, fim_loop_colunas
            
            # Endere�o da matriz: matriz_base + i*n + j
            mul $t2, $t0, $s0
            add $t2, $t2, $t1
            add $t2, $t2, $a2
            
            lb $a0, 0($t2) # Carrega o caractere
            li $v0, 1      # sys_call para imprimir caractere
            syscall
            
            li $v0, 4      # sys_call para imprimir espa�o
            la $a0, space
            syscall
            
            addi $t1, $t1, 1
            j loop_colunas
        
        fim_loop_colunas:
            li $v0, 4      # sys_call para imprimir newline
            la $a0, newline
            syscall
            
        addi $t0, $t0, 1
        j loop_linhas
        
    fim_loop_linhas:
    jr $ra