

public class Corrente {
    String nome;
    double saldo;
    Situacao situacao;

    void insereDados(String n, double sa, Situacao si){
        nome = n;
        saldo = sa;
        situacao = si;
        emitir();
    }
    void emitir () {
        System.out.println("Saldo de "+ this.nome + " | Conta "+ this.situacao +" | R$ " + this.saldo);
    }

    void insere_saldo(double value){
        this.saldo = this.saldo + value;
    }
    void saque_saldo(double value){
        this.saldo = this.saldo - value;
    }

    void transferencia(Corrente conta, double valor){

        if (this.situacao != Situacao.ESPECIAL && this.saldo < valor){
            System.out.println("\nNao eh possivel fazer transferencia maior que saldo pois conta eh do tipo "+ this.situacao);
            return;
        } else {
            conta.insere_saldo(valor);
            saque_saldo(valor);
        }
    }
}

