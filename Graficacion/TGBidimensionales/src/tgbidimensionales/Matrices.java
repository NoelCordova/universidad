package tgbidimensionales;

public class Matrices {
    Cuadrantes c = new Cuadrantes();
    static int contInt= 0; 
    
    public void matrizTraslacion(int tx, int ty, int px[], int py[], int POx,
            int POy, int pxT[], int pyT[]){
        
        int x1, x2, y1, y2;
        int [][] mT= new int [10][10], p1= new int [10][10], p2= new int[10][10];
        int [][] pT= new int [10][10];
        
        x1= px[1]+(-POx); 
        y1= py[1]+(-POy); y1= y1*-1;
        x2= px[2]+(-POx); 
        y2= py[2]+(-POy); y2= y2*-1;
        
        //Matriz de traslacion
        mT[1][1]= 1; mT[1][2]= 0; mT[1][3]= tx;
        mT[2][1]= 0; mT[2][2]= 1; mT[2][3]= ty;
        mT[3][1]= 0; mT[3][2]= 0; mT[3][3]= 1;
        
        p1[1][1]= x1; p1[2][1]= y1; p1[3][1]= 1;
        p2[1][1]= x2; p2[2][1]= y2; p2[3][1]= 1;
        
        for(int i=1; i<=3; i++){
            contInt= 0;
            for(int j=1; j<=3; j++){
                
                contInt+= (mT[i][j]*p1[j][1]);
                pT[i][1]= contInt;
            }
            pxT[1]= pT[1][1]; pyT[1]= pT[2][1];
        }

        for(int i=1; i<=3; i++){
            contInt=0;
            for(int j=1; j<=3; j++){
                contInt+= (mT[i][j]*p2[j][1]);
                pT[i][1]= contInt;
            }
            pxT[2]= pT[1][1]; pyT[2]= pT[2][1];
        }

        c.conversionPuntos(pxT, pyT, POx, POy);
    }
    
    public void matrizRotacion(double r, int px[], int py[], int pxT[], 
            int pyT[], int POx, int POy){
        
        int x1, x2, y1, y2;
        double [][] mR= new double[10][10], p1= new double[10][10], p2= new double[10][10];
        double [][] pR= new double[10][10];
        
        x1= px[1]+(-POx); 
        y1= py[1]+(-POy); y1= y1*-1;
        x2= px[2]+(-POx); 
        y2= py[2]+(-POy); y2= y2*-1;
        r= Math.toRadians(r);
        
        //Matriz de rotacion
        mR[1][1]= Math.cos(r); mR[1][2]= -Math.sin(r); mR[1][3]= 0;
        mR[2][1]= Math.sin(r); mR[2][2]= Math.cos(r); mR[2][3]= 0;
        mR[3][1]= 0; mR[3][2]= 0; mR[3][3]= 1;
        
        System.out.println(mR[1][1]);
        System.out.println(mR[1][2]);
        
        
        p1[1][1]= x1; p1[2][1]= y1; p1[3][1]= 1;
        p2[1][1]= x2; p2[2][1]= y2; p2[3][1]= 1;
        
        for(int i=1; i<=3; i++){
            contInt= 0;
            for(int j=1; j<=3; j++){
                contInt+= (mR[i][j]*p1[j][1]);
                pR[i][1]= contInt;
                System.out.println("pR: " + pR[i][1]);
            }
            pxT[1]= (int) pR[1][1]; pyT[1]= (int) pR[2][1];
        }
        
        for(int i=1; i<=3; i++){
            contInt= 0;
            for(int j=1; j<=3; j++){
                contInt+= (mR[i][j]*p2[j][1]);
                pR[i][1]= contInt;
            }
            pxT[2]= (int) pR[1][1]; pyT[2]= (int) pR[2][1];
        }

        c.conversionPuntos(pxT, pyT, POx, POy);
    }
    
    public void matrizEscalacion(double ex, double ey, int px[], int py[], 
            int pxT[], int pyT[], int POx, int POy){
        
        int x1, x2, y1, y2;
        double [][] mE= new double[10][10], p1= new double[10][10], p2= new double[10][10];
        double [][] pE= new double[10][10];
        
        x1= px[1]+(-POx); 
        y1= py[1]+(-POy); y1= y1*-1;
        x2= px[2]+(-POx); 
        y2= py[2]+(-POy); y2= y2*-1;
        
        //Matriz de escalacion
        mE[1][1]= ex; mE[1][2]= 0; mE[1][3]= 0;
        mE[2][1]= 0; mE[2][2]= ey; mE[2][3]= 0;
        mE[3][1]= 0; mE[3][2]= 0; mE[3][3]= 1;
        
        p1[1][1]= x1; p1[2][1]= y1; p1[3][1]= 1;
        p2[1][1]= x2; p2[2][1]= y2; p2[3][1]= 1;

        for(int i=1; i<=3; i++){
            contInt= 0;
            for(int j=1; j<=3; j++){
                contInt+= (mE[i][j]*p1[j][1]);
                pE[i][1]= contInt;
            }
            pxT[1]= (int) pE[1][1]; pyT[1]= (int) pE[2][1];
        }

        for(int i=1; i<=3; i++){
            contInt= 0;
            for(int j=1; j<=3; j++){
                contInt+= (mE[i][j]*p2[j][1]);
                pE[i][1]= contInt;
            }
            pxT[2]= (int) pE[1][1]; pyT[2]= (int) pE[2][1];
        }
        c.conversionPuntos(pxT, pyT, POx, POy);
    }
}
