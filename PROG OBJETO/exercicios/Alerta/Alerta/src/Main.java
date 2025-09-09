import alertas.*;

//TIP To <b>Run</b> code, press <shortcut actionId="Run"/> or
// click the <icon src="AllIcons.Actions.Execute"/> icon in the gutter.
public class Main {
    public static void main(String[] args) {
        NotificadorEmail ne = new NotificadorEmail();
        NotificadorSMS ns = new NotificadorSMS();
        NotificadorPUSH np = new NotificadorPUSH();

        ServicoAlerta ae = new ServicoAlerta(ne, "Alerta teste");
        ServicoAlerta as = new ServicoAlerta(ns, "Alerta teste");
        ServicoAlerta ap = new ServicoAlerta(np, "Alerta teste");

    }
}
