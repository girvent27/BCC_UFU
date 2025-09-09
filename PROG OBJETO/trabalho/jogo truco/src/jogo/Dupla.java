package jogo;
import jogo.*;

public class Dupla {
    private Jogador j1;
    private Jogador j2;
    public int tentos;
    private int quedas, quedasGanhas;

    public Dupla (Jogador jogador1, Jogador jogador2){
        j1 = jogador1;
        j2 = jogador2;
    }
    Jogador getJ1(){
        return j1;
    }
    Jogador getJ2(){
        return j2;
    }
    void quedaJogada(){
        this.quedas++;
    }
    void quedaGanha(){
        this.quedasGanhas++;
        this.quedas++;
    }
    int getQuedas(){
        return this.quedas;
    }
    int getQuedasGanhas(){
        return this.quedasGanhas;
    }
}
