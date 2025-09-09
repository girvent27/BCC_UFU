#P6: DESENHO EM ZIG-ZAG

# Arquivo: zigzag.asm
# Descrição: Preenche uma matriz com os caracteres de uma string em zig-zag.

.data
	#ÁREA PARA DADOS NA MEMÓRIA PRINCIPAL.

    # string e o tamanho da matriz.
    str: .asciiz 
    n:   .word 7
    
    # Matriz para armazenar os caracteres. 7x7 = 49 bytes.
    matriz: .space 49
    
    # Caractere de espaço para preenchimento.
    space_char: .byte ' '
    
    # Mensagens para impressão.
    newline: .asciiz "\n"
    space:   .asciiz " "

.text
	#ÁREA PARA INSTRUÇOES DO PROGRAMA.
.globl main

main:
    # Configura os argumentos para a sub-rotina desenharZigZag.
    la $a0, str     # $a0 = endereço da string
    lw $a1, n       # $a1 = tamanho da matriz (n)
    la $a2, matriz  # $a2 = endereço da matriz
    
    jal desenharZigZag
    
    # Chamamos a sub-rotina para imprimir a matriz (agora presente no código).
    jal imprimir_matriz
    
    li $v0, 10
    syscall

# Sub-rotina: desenharZigZag
# Parâmetros:
#   $a0 - Endereço da string
#   $a1 - Tamanho da matriz (n)
#   $a2 - Endereço da matriz

desenharZigZag:
    # Salva o endereço de retorno e os registradores de trabalho.
    subi $sp, $sp, 16
    sw $ra, 0($sp)
    sw $s0, 4($sp) # s0 = n
    sw $s1, 8($sp) # s1 = k (índice da string)
    sw $s2, 12($sp) # s2 = len (tamanho da string)
    
    move $s0, $a1
    
    # Calcula o tamanho da string.
    jal strlen
    move $s2, $v0  # s2 = len
    
    # Inicializa o contador da string.
    li $s1, 0 # s1 = k
    
    # Laço externo para as linhas (i).
    li $t0, 0       # t0 = i
    loop_linhas_zigzag:
        bge $t0, $s0, fim_loop_linhas_zigzag
        
        # Verifica se a linha é par ou ímpar (if (i % 2 == 0)).
        andi $t1, $t0, 1
        bnez $t1, linha_impar # Se o resultado não for zero, é ímpar.
        
        # --- LINHA PAR ---
        # for (int j = 0; j < n; j++)
        li $t2, 0       # t2 = j
        loop_par:
            bge $t2, $s0, fim_loop_par
            
            jal preencher_posicao # Chama a sub-rotina para preencher a matriz.
            
            # O caractere está em $v0, endereço em $v1.
            sb $v0, 0($v1)
            
            addi $t2, $t2, 1 # j++
            j loop_par
        fim_loop_par:
        j proxima_linha
        
        # --- LINHA ÍMPAR ---
        linha_impar:
        # for (int j = n - 1; j >= 0; j--)
        subi $t2, $s0, 1 # t2 = j = n - 1
        loop_impar:
            blt $t2, $zero, fim_loop_impar
            
            jal preencher_posicao
            
            sb $v0, 0($v1)
            
            subi $t2, $t2, 1 # j--
            j loop_impar
        fim_loop_impar:
        
        proxima_linha:
        addi $t0, $t0, 1 # i++
        j loop_linhas_zigzag
    
    fim_loop_linhas_zigzag:
    
    # Restaura os registradores e retorna.
    lw $ra, 0($sp)
    lw $s0, 4($sp)
    lw $s1, 8($sp)
    lw $s2, 12($sp)
    addi $sp, $sp, 16
    jr $ra

# Sub-rotina auxiliar: preencher_posicao
# Esta sub-rotina decide se pega um caractere da string ou um espaço.
# Usa os registradores globais: $s1 (k), $s2 (len), $s0 (n), $t0 (i), $t2 (j).
# Retorna:
#   $v0 - Caractere a ser escrito
#   $v1 - Endereço da matriz onde o caractere deve ser escrito

preencher_posicao:
    # Calcula o endereço da matriz: matriz[i][j] = matriz_base + i*n + j
    la $v1, matriz
    mul $t3, $t0, $s0
    add $t3, $t3, $t2
    add $v1, $v1, $t3

    # if (k < len)
    bge $s1, $s2, usa_espaco
    
    # Pega o caractere da string.
    lb $v0, str($s1)
    addi $s1, $s1, 1 # k++
    j fim_preencher
    
    usa_espaco:
    # Pega o caractere de espaço.
    lb $v0, space_char
    
    fim_preencher:
    jr $ra

# Sub-rotina auxiliar: strlen
# Parâmetro:
#   $a0 - Endereço da string
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
# Usa os mesmos parâmetros globais de 'main' para a matriz.

imprimir_matriz:
    lw $s0, n       # s0 = n
    la $a2, matriz  # a2 = endereço da matriz
    
    li $t0, 0       # t0 = i (contador da linha)
    loop_linhas:
        bge $t0, $s0, fim_loop_linhas
        
        li $t1, 0   # t1 = j (contador da coluna)
        loop_colunas:
            bge $t1, $s0, fim_loop_colunas
            
            # Endereço da matriz: matriz_base + i*n + j
            mul $t2, $t0, $s0
            add $t2, $t2, $t1
            add $t2, $t2, $a2
            
            lb $a0, 0($t2) # Carrega o caractere
            li $v0, 1      # sys_call para imprimir caractere
            syscall
            
            li $v0, 4      # sys_call para imprimir espaço
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