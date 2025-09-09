package alertas;
import alertas.*;


public class ServicoAlerta{
    private String msg;
    private Notificador notificador;
    public ServicoAlerta(Notificador notificador, String msg){
        notificador.enviar("Alerta Critico: " + msg);
    }
}
