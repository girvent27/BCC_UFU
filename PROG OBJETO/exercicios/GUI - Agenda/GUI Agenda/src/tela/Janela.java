package tela;
import java.awt.*;
import javax.swing.*;

public class Janela{
     JFrame j = new JFrame("kkkkkkkkk");
     public Janela(){
         j.setSize(1000,300);
         j.setVisible(true);
         j.setDefaultCloseOperation(WindowConstants.EXIT_ON_CLOSE);
         j.add(new JButton("aaa"));
     }
}
