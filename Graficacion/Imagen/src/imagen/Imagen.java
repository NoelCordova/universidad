package imagen;
/*
    Librerias para input & output, JPanel & JFrame
*/
import java.awt.Color;
import java.awt.Graphics;
import java.io.*;
import java.util.*;
import javax.swing.JFrame;
import javax.swing.JPanel;

public class Imagen extends JPanel{
    /*
        Variables estaticas para obtenrlas desde el while donde se lee el 
        archivo. Cada arreglo representa una funcion en el metodo Paint
    */    
    static int [] Panel= new int[6], Triangulo= new int[10], TrianguloX= new int[3];
    static int [] TrianguloY= new int[3], Cuadrado= new int[8], Circulo= new int[8];
    static int [] Colores= new int [12];
    /*
        Graphics funcion para dibujar.
        - drawRect(punto x, punto y, alto, ancho)
        - drawPolygon(punto x1, punto y1, punto x2, punto y2, punto x3, punto y3)
        - drawOval(punto x, punto y, alto, ancho)
    */
    public void paint(Graphics g){
        Color colorTriangulo= new Color(Colores[0], Colores[1], Colores[2]);
        g.setColor (colorTriangulo);        
        g.drawPolygon (TrianguloX, TrianguloY, 3);
        Color colorCuadrado= new Color(Colores[3], Colores[4], Colores[5]);
        g.setColor(colorCuadrado);
        g.drawRect (Cuadrado[1], Cuadrado[2], Cuadrado[3], Cuadrado[4]);
        Color colorCirculo= new Color(Colores[6], Colores[7], Colores[8]);
        g.setColor(colorCirculo);
        g.drawOval(Circulo[1], Circulo[2], Circulo[3], Circulo[4]);
    }
    
    public static void main(String[] args) {
        /*
            Declaracion de JFrame
        */
        JFrame frame= new JFrame();
        frame.getContentPane().add(new Imagen());
        frame.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        frame.setTitle("Imagenes");
        frame.setVisible(true);
        
        final String file= "img.dat";
        Scanner in= null;
        
        try{
            in= new Scanner(new FileReader(file));  //Se lee todo el archivo
            /*
                Con el primer while se lee el primer dato del renglon en este 
                caso un String y a raiz de ese dato se leen los siguientes
            */
            while(in.hasNext()){   
                String figura= in.next();   //Se guarda el nombre de la figura 
                /*
                    Aqui se guardan los enteros del renglon
                */
                while(in.hasNextInt()){
                    if(figura.equals("JPanel")){    //JPanel
                        for(int cont=1; cont<=5; cont++){   //Contadores para ir 
                            int dato= in.nextInt();     //guardando cada dato al 
                            Panel[cont]= dato;              //arreglo
                        }
                        
                        Colores[9]= Panel[3];       //Color JFrame
                        Colores[10]= Panel[4];
                        Colores[11]= Panel[5];
                        
                        frame.setSize(Panel[1], Panel[2]);  //define tamaño Panel
                        Color colorFrame= new Color(Colores[9], Colores[10], Colores[11]);
                        frame.setBackground(colorFrame);
                        
                    } else if(figura.equals("Triangulo")){  //Triangulo
                        for(int cont=1; cont<=9; cont++){
                            int dato= in.nextInt();
                            Triangulo[cont]= dato;
                        }
                        
                        TrianguloX[0]= Triangulo[1];    //Valores independientes
                        TrianguloX[1]= Triangulo[3];    //para el arreglo de
                        TrianguloX[2]= Triangulo[5];    //Triangulo
                        TrianguloY[0]= Triangulo[2];
                        TrianguloY[1]= Triangulo[4];
                        TrianguloY[2]= Triangulo[6];
                        
                        Colores[0]= Triangulo[7];       //Colores Triangulo
                        Colores[1]= Triangulo[8];
                        Colores[2]= Triangulo[9];
                        
                    }else if(figura.equals("Cuadrado")){    //Cuadrado
                        for(int cont=1; cont<=7; cont++){
                            int dato= in.nextInt();
                            Cuadrado[cont]= dato;
                        }

                        Colores[3]= Cuadrado[5];            //Colores Cuadrado
                        Colores[4]= Cuadrado[6];
                        Colores[5]= Cuadrado[7];
                        
                    }else if(figura.equals("Circulo")){     //Circulo
                        for(int cont=1; cont<=7; cont++){
                            int dato= in.nextInt();
                            Circulo[cont]= dato;
                        }
                        
                        Colores[6]= Circulo[5];         //Colores Circulo
                        Colores[7]= Circulo[6];
                        Colores[8]= Circulo[7];
                    }
                }
            }
        }catch(FileNotFoundException fnfe){
        }
    }
}
