package alertas;
import alertas.*;

public class NotificadorPUSH implements Notificador{
    public void enviar(String msg){
        System.out.println("PUSH "+msg+"\n");
    }
}
