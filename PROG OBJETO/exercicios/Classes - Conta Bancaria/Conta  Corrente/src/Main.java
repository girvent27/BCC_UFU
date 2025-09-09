
public class Main {
    public static void main(String arg[]){
        Corrente c1 = new Corrente();
        Corrente c2 = new Corrente();
        System.out.println("\nInsercao de Dados: ");
        c1.insereDados("Joao Lucas", 4, Situacao.COMUM);
        c2.insereDados("Godofredo Lopes", 500, Situacao.ESPECIAL);

        System.out.println("\nTeste Deposito: ");
        c1.insere_saldo(50);
        c2.insere_saldo(20);
        c1.emitir();
        c2.emitir();

        System.out.println("\nTeste Saque: ");
        c1.saque_saldo(23);
        c2.saque_saldo(10);
        c1.emitir();
        c2.emitir();

        System.out.println("\nTeste Transferencia (Conta Especial e valor maior):  \n Godofredo tem uma conta especial e tenta fazer uma transferencia de 5.001,00");
        c2.transferencia(c1,5001);
        c1.emitir();
        c2.emitir();

        System.out.println("\nTeste Transferencia (Conta Comum e valor maior): \n Joao Lucas tem uma conta comum e tenta fazer uma transferencia de 10.000,00");
        c1.transferencia(c2,10000);
        c1.emitir();
        c2.emitir();
    }
}
