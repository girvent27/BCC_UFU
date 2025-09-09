package jogo;
import jogo.*;

import java.util.ArrayList;
import java.util.Collections;
import java.util.List;

public class Mesa {
    public ArrayList<Dupla> duplas = new ArrayList<>();
    public ArrayList<Carta> baralho = new ArrayList<>();


    public Mesa(Dupla d1, Dupla d2){
        duplas.add(d1);
        duplas.add(d2);
    }

    void criaBaralho() {
        String[] naipes = {"Paus", "Copas", "Espadas", "Ouros"};
        String[] valores = {"4", "5", "6", "7", "Q", "J", "K", "Ás", "2", "3"};

        int forca = 1;
        for (String valor : valores) {
            for (String naipe : naipes) {
                int aux = forca;
                if (naipe == "Paus" && valor == "4") {
                    baralho.add(new Carta(naipe, valor, 14));
                }
                else if (naipe == "Copas" && valor == "7") {
                    baralho.add(new Carta(naipe, valor, 13));
                }
                else if (naipe == "Espadas" && valor == "Ás") {
                    baralho.add(new Carta(naipe, valor, 12));
                }
                else if (naipe == "Ouros" && valor == "7") {
                    baralho.add(new Carta(naipe, valor, 11));
                } else {
                baralho.add(new Carta(naipe, valor, aux));
                }

            }
            forca++;
        }
    }

    /*
    baralho.add(new Carta("Paus", "4", 10));
        baralho.add(new Carta("Copas", "7", 9));
        baralho.add(new Carta("Espadas", "Ás", 8));
        baralho.add(new Carta("Ouros", "7", 7));
    void descartar(){}
    void trucar (){}
    void correr(){}
    void chamar(){}
*/

    public void jogoExe (){
        criaBaralho();
        Collections.shuffle(baralho);
        System.out.println("Jogo começou. Tamanho do baralho: " + baralho.size());

        System.out.println("Cartas no baralho:");
        for (Carta c : baralho) {
            System.out.println("- " + c);
        }

    }

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
