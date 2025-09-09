package alertas;
import alertas.*;

public class NotificadorEmail implements Notificador{
    public void enviar(String msg){
        System.out.println("De: jean.deu@ufu.br \nAssunto: "+msg+"\n"+msg+"\n");
    }
}
