package banco.teste;
import banco.teste.*;
import banco.dados.*;

public class Testes {
    public static void teste(String[] args) {
        Pessoa p1 = new Pessoa("Joao", "123.456.789-10", 300),
               p2 = new Pessoa( "Clayton", "159.357.465-19", 900);
        Conta c1 = new Conta(p1, TipoConta.COMUM),
              c2 = new Conta(p2, TipoConta.ESPECIAL);
        c1.deposito(12);
        c2.deposito(1200);

    }
}