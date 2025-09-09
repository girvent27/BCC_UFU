package banco.dados;
import banco.dados.*;


public class Transferencia {
    Conta origem, destin;
    double valor;

    public Transferencia (Conta org, Conta dest, double valor){
        this.destin = dest;
        this.origem = org;
        this.valor = valor;

        if (valor <= 0)
            return;
        if (org.getTipoConta() == TipoConta.COMUM && valor > org.getSaldo())
            return;
        else {
            org.saque(valor);
            dest.deposito(valor);
        }
    }
    public Transferencia getTransferencia(){
        return this;
    }

    public void transferencia(Conta orig,Conta dest, double valor){
        if (valor <= 0)
            return;
        if (orig.getTipoConta() == TipoConta.COMUM && valor > orig.getSaldo())
            return;
        else {
            orig.saque(valor);
            dest.deposito(valor);
        }
    }
}
