package tgbidimensionales;

import java.awt.Color;
import javax.swing.JFrame;

public class Cuadrantes {
    
    //Dibuja el plano cartesiano
    public void Ventana(int SizeX, int SizeY){
        JFrame frame= new JFrame();
        frame.getContentPane().add(new TGBidimensionales());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setSize(SizeX, SizeY);
        frame.setBackground(Color.white);
        frame.setTitle("Transformaciones geometricas bidimencionales");
        frame.setVisible(true);
    }
    
    //Conversion de puntos cartesianos a coordenadas de monitor
    public void conversionPuntos(int px[], int py[], int POx, int POy){
        px[1]= POx + (px[1]);
        py[1]= POy + (-py[1]);
        px[2]= POx + (px[2]);
        py[2]= POy + (-py[2]);
    }

    public void cuadrante1(int px[], int py[], int POx, int POy){
        if(px[1] > 0 && py[1] > 0 && px[2] > 0 && py[2] > 0){
            conversionPuntos(px, py, POx, POy);
        }
    }
    
    public void cuadrante2(int px[], int py[], int POx, int POy){
        if(px[1] < 0 && py[1] > 0 && px[2] < 0 && py[2] > 0){
            conversionPuntos(px, py, POx, POy);
        }
    }
    
    public void cuadrante3(int px[], int py[], int POx, int POy){
        if(px[1] < 0 && py[1] < 0 && px[2] < 0 && py[2] < 0){
            conversionPuntos(px, py, POx, POy);
        }
    }
    
    public void cuadrante4(int px[], int py[], int POx, int POy){
        if(px[1] > 0 && py[1] < 0 && px[2] > 0 && py[2] < 0){
            conversionPuntos(px, py, POx, POy);
        }
    }
    
    public void cuadranteCombinado(int px[], int py[], int POx, int POy){
        if(px[1] > 0 && py[1] < 0 && px[2] > 0 && py[2] > 0){ //cuadrante 4 y 1
            conversionPuntos(px, py, POx, POy);
        } else if(px[1] > 0 && py[1] > 0 && px[2] > 0 && py[2] < 0){ // 1 y 4
            conversionPuntos(px, py, POx, POy);
        } else if(px[1] > 0 && py[1] > 0 && px[2] < 0 && py[2] > 0){ // 1 y 2
            conversionPuntos(px, py, POx, POy);
        } else if(px[1] < 0 && py[1] > 0 && px[2] > 0 && py[2] > 0){ // 2 y 1
            conversionPuntos(px, py, POx, POy);
        } else if(px[1] < 0 && py[1] > 0 && px[2] < 0 && py[2] < 0){ // 2 y 3
            conversionPuntos(px, py, POx, POy);
        } else if(px[1] < 0 && py[1] < 0 && px[2] < 0 && py[2] > 0){ // 3 y 2
            conversionPuntos(px, py, POx, POy);
        } else if(px[1] < 0 && py[1] < 0 && px[2] > 0 && py[2] < 0){ // 3 y 4
            conversionPuntos(px, py, POx, POy);
        } else if(px[1] > 0 && py[1] < 0 && px[2] < 0 && py[2] < 0){ // 4 y 3
            conversionPuntos(px, py, POx, POy);
        } else if(px[1] > 0 && py[1] > 0 && px[2] < 0 && py[2] < 0){ // 1 y 3
            conversionPuntos(px, py, POx, POy);
        } else if(px[1] < 0 && py[1] < 0 && px[2] > 0 && py[2] > 0){ // 3 y 1
            conversionPuntos(px, py, POx, POy);
        } else if(px[1] < 0 && py[1] > 0 && px[2] > 0 && py[2] < 0){ // 2 y 4
            conversionPuntos(px, py, POx, POy);
        } else if(px[1] > 0 && py[1] < 0 && px[2] < 0 && py[2] > 0){ // 4 y 2
            conversionPuntos(px, py, POx, POy);
        }
    }
}
