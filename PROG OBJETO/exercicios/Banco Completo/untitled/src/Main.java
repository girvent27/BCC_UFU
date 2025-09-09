import banco.dados.Conta;
import banco.dados.Pessoa;
import banco.dados.TipoConta;

public class Main {
    public static void main(String[] args) {
        Pessoa p1 = new Pessoa("Joao", "123.456.789-10", 700);
        Conta c1 = new Conta(p1, TipoConta.COMUM);
        c1.deposito(10);
    }
}
