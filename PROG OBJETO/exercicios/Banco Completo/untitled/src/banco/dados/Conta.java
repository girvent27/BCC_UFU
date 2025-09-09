package banco.dados;
import banco.dados.*;

import javax.swing.*;
import java.util.ArrayList;
import java.util.List;

public class Conta {
    private Pessoa cliente;
    private double saldo;
    private TipoConta tipoConta;
    private List<Transferencia> extrato = new ArrayList<>();

    public Conta(Pessoa cliente, TipoConta tipoConta){
        this.cliente = cliente;
        this.saldo = 0;
        this.tipoConta = tipoConta;
    }
    
    public void addTransferencia(Transferencia transferencia){

        this.extrato.add(transferencia);
    }
    public void imprimeTransferencia(){

        for (Transferencia t: extrato){
            System.out.println(""+ extrato.getTransferencia(t));
        }
    }
    public TipoConta getTipoConta(){
        return this.tipoConta;
    }
    public double getSaldo(){
        return this.saldo;
    }
    public void deposito(double valor){
        this.saldo += valor;
    }
    public void saque(double valor){
        if (valor <= this.saldo)
            this.saldo -= valor;
        else
            return;
    }

}
