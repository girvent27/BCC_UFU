import jogo.*;

public class Main {
    public static void main(String[] args) {
        System.out.println("Hello World");
        Jogador p1 = new Jogador("Joao");
        Jogador p2 = new Jogador("Rhyan");

        Jogador p3 = new Jogador("Galvao Bueno");
        Jogador p4 = new Jogador("Kaka");
        Dupla d1 = new Dupla(p1, p2);
        Dupla d2 = new Dupla(p3, p4);
        Mesa j = new Mesa(d1, d2);
        j.jogoExe();
    }
}