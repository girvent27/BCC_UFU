package jogo;

import java.util.ArrayList;

public class Jogador {
    public String nome;
    ArrayList<Carta> mao = new ArrayList<>();

    public Jogador (String nome){
        this.nome = nome;
    }
}
