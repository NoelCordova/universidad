package tgbidimensionales; //Transformaciones geometricas bidimensionales

import java.awt.Color;
import java.awt.Graphics;
import java.util.Scanner;
import javax.swing.JPanel;

public class TGBidimensionales extends JPanel{
    
    /*
    SizeX: tamaño original horinzontal, SizeY: tamaño original vertical
    PO(x, y): puntos origen respectivos, t(x, y): traslacion respectiva
    p[x, y]: puntos en coordenadas de monitor, pT[x, y]: nuevo punto
    r: angulo de rotacion, e[x, y]: escalacion respectiva
    */
    static int SizeX= 1250, SizeY= 800, POx= SizeX/2, POy= SizeY/2, tx, ty;
    static int [] px= new int [3], py= new int [3], pxT= new int[3], pyT= new int[3];
    static double r, ex, ey;
    
    public void paint(Graphics g){
        g.drawLine(1,POy,SizeX,POy);  //Lineas de plano cartesiano
        g.drawLine(POx,1,POx,SizeY);
        
        g.setColor(Color.blue);
        g.drawLine(px[1], py[1], px[2], py[2]); //Linea original
        
        g.setColor(Color.red);
        g.drawLine(pxT[1], pyT[1], pxT[2], pyT[2]); //Linea nueva
    }
    
    public static void main(String[] args) {
        int opc;
        Cuadrantes c = new Cuadrantes(); //Declaracion de constructor
        Matrices m = new Matrices();
        Scanner in= new Scanner(System.in);
        
        System.out.println("\n");
        //Ingreso de puntos
        for(int cont= 1; cont<=2; cont++){
            System.out.print("Ingrese las coordenadas del punto x" + cont + ": ");
            int X= in.nextInt();
            px[cont]= X;
            
            System.out.print("Ingrese las coordenadas del punto y" + cont + ": ");
            int Y= in.nextInt();
            py[cont]= Y;
        }
        
        //definicion de cuadrantes
        if(px[1] > 0 && py[1] > 0 && px[2] > 0 && py[2] > 0){
            c.cuadrante1(px, py, POx, POy);
        } else if(px[1] < 0 && py[1] > 0 && px[2] < 0 && py[2] > 0){
            c.cuadrante2(px, py, POx, POy);
        } else if(px[1] < 0 && py[1] < 0 && px[2] < 0 && py[2] < 0){
            c.cuadrante3(px, py, POx, POy);
        } else if(px[1] > 0 && py[1] < 0 && px[2] > 0 && py[2] < 0){
            c.cuadrante4(px, py, POx, POy);
        } else{
            c.cuadranteCombinado(px, py, POx, POy);
        }
        
        System.out.println("\n");
        
        //Seleccion de matriz
        do{
            System.out.println("\nIngrese la opcion para calcular:");
            System.out.print("\n1) Traslacion\n2) Rotacion\n3) Escalacion\n"
                    + "4) Salir\nOpcion: ");
            opc= in.nextInt();
            
            switch(opc){
                case 1:{ //Traslacion
                    System.out.print("\nIngrese traslacion en X: ");
                    tx= in.nextInt();
                    
                    System.out.print("Ingrese traslacion en Y: ");
                    ty= in.nextInt();
                    m.matrizTraslacion(tx, ty, px, py, POx, POy, pxT, pyT);
                    c.Ventana(SizeX, SizeY);
                }break;
                    
                case 2:{ //Rotacion
                    System.out.print("\nIngrese el angulo de rotacion: ");
                    r= in.nextDouble();
                    
                    m.matrizRotacion(r, px, py, pxT, pyT, POx, POy);
                    c.Ventana(SizeX, SizeY);
                }break;
                    
                case 3:{ //Escalacion
                    System.out.print("\nIngrese escalamiento: ");
                    ex= in.nextDouble();
                    
                    System.out.print("\nIngrese escalamiento: ");
                    ey= in.nextDouble();
                    
                    m.matrizEscalacion(ex, ey, px, py, pxT, pyT, POx, POy);
                    c.Ventana(SizeX, SizeY);
                }break;
                    
                default: System.out.println("Hasta luego :)");
            }           
        }while(opc<=3);
    }
}
