#P4: //FATOR DE CORRELA��O//

# Arquivo: correlacao.asm
# Descri��o: Implementa o c�lculo do fator de correla��o de Pearson entre duas s�ries de dados.

.data
	#�REA PARA DADOS NA MEM�RIA PRINCIPAL.

    # Nossas duas listas de dados. Armazenadas como 'double' (ponto flutuante de 8 bytes).
    dados_x: .double 90.0, 80.0, 70.0, 60.0
    dados_y: .double 95.0, 85.0, 75.0, 65.0
    
    # O tamanho das listas.
    tamanho: .word 4
    
    # Constante de ponto flutuante zero, necess�ria para inicializar registradores.
    const_zero: .double 0.0
    
    # Mensagens para impress�o (para facilitar o entendimento do resultado).
    msg_correlacao: .asciiz "Fator de correlacao: "
    msg_zero:      .asciiz "0.000\n"
    


.text
	#�REA PARA INSTRU�OES DO PROGRAMA.
.globl main

main:
    # Registradores usados para os endere�os das listas e o tamanho.
    # $a0 = endere�o de dados_x
    # $a1 = endere�o de dados_y
    # $s0 = tamanho da lista
    
    la $a0, dados_x
    la $a1, dados_y
    lw $s0, tamanho
    
    # Chamando a sub-rotina para calcular a correla��o.
    jal calcular_correlacao

    # O resultado (double) est� em $f0. Vamos imprimi-lo.
    li $v0, 4             # sys_call para imprimir string
    la $a0, msg_correlacao
    syscall

    li $v0, 3             # sys_call para imprimir double
    mov.d $f12, $f0       # Move o resultado de $f0 para $f12 (argumento para syscall)
    syscall

    # Finaliza o programa.
    li $v0, 10
    syscall

# Sub-rotina: calcular_media
# Par�metros:
#   $a0 - Endere�o do array
#   $s0 - Tamanho do array
# Retorno:
#   $f0 - M�dia do array (double)

calcular_media:
    # Salvamos o endere�o de retorno.
    subi $sp, $sp, 4
    sw $ra, 0($sp)
    
    # $t0 = i (contador do loop)
    # $f2 = soma (acumulador)
    li $t0, 0
    
    # Carregando 0.0 da mem�ria para $f2
    l.d $f2, const_zero
    
    loop_media:
        # Se i >= tamanho, sa�mos do loop.
        bge $t0, $s0, fim_loop_media
        
        # Carrega o valor do array para $f4.
        # Endere�o = base + i * 8 (double tem 8 bytes)
        mul $t1, $t0, 8
        add $t1, $t1, $a0
        l.d $f4, 0($t1)
        
        # Adiciona o valor � soma.
        add.d $f2, $f2, $f4
        
        # Incrementa o contador i.
        addi $t0, $t0, 1
        j loop_media
        
    fim_loop_media:
        # Divide a soma pelo tamanho para obter a m�dia.
        # Carrega o tamanho para um registrador de ponto flutuante ($f6).
        mtc1 $s0, $f6
        cvt.d.w $f6, $f6     # Converte inteiro para double
        div.d $f0, $f2, $f6
        
    # Restaura o endere�o de retorno e volta.
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    jr $ra

# Sub-rotina: calcular_correlacao
# Par�metros:
#   $a0 - Endere�o de dados_x
#   $a1 - Endere�o de dados_y
#   $s0 - Tamanho da lista
# Retorno:
#   $f0 - Fator de correla��o (double)

calcular_correlacao:
    # Salva o endere�o de retorno.
    subi $sp, $sp, 4
    sw $ra, 0($sp)
    
    # 1. Calcular a m�dia de X
    jal calcular_media
    mov.d $f10, $f0 # $f10 = media_x
    
    # 2. Calcular a m�dia de Y
    # Passamos o endere�o de Y.
    move $a0, $a1
    jal calcular_media
    mov.d $f12, $f0 # $f12 = media_y
    
    # Resetamos o endere�o de X para o loop principal.
    la $a0, dados_x

    # 3. La�o principal para calcular o numerador e o denominador.
    # $s1 = i (contador do loop)
    # $f14 = numerador (acumulador)
    # $f16 = soma_x2 (acumulador)
    # $f18 = soma_y2 (acumulador)
    li $s1, 0
    
    # Carregando 0.0 da mem�ria para os acumuladores.
    l.d $f14, const_zero
    l.d $f16, const_zero
    l.d $f18, const_zero
    
    loop_calculo:
        bge $s1, $s0, fim_loop_calculo
        
        # Carrega x[i] e y[i].
        mul $t1, $s1, 8
        add $t2, $a0, $t1  # Endere�o de x[i]
        l.d $f2, 0($t2)    # $f2 = x[i]
        
        add $t2, $a1, $t1  # Endere�o de y[i]
        l.d $f4, 0($t2)    # $f4 = y[i]
        
        # Calcula (x[i] - mediaX)
        sub.d $f6, $f2, $f10
        
        # Calcula (y[i] - mediaY)
        sub.d $f8, $f4, $f12
        
        # Numerador += (x[i] - mediaX) * (y[i] - mediaY)
        mul.d $f20, $f6, $f8
        add.d $f14, $f14, $f20
        
        # soma_x2 += pow((x[i] - mediaX), 2)
        mul.d $f22, $f6, $f6
        add.d $f16, $f16, $f22
        
        # soma_y2 += pow((y[i] - mediaY), 2)
        mul.d $f24, $f8, $f8
        add.d $f18, $f18, $f24
        
        addi $s1, $s1, 1
        j loop_calculo
        
    fim_loop_calculo:
        # 4. Calcular o denominador
        # denominador = sqrt(soma_x2 * soma_y2)
        mul.d $f26, $f16, $f18
        sqrt.d $f28, $f26
        
        # 5. Dividir o numerador pelo denominador
        div.d $f0, $f14, $f28
        
    # Restaura o endere�o de retorno e volta.
    lw $ra, 0($sp)
    addi $sp, $sp, 4
    jr $ra