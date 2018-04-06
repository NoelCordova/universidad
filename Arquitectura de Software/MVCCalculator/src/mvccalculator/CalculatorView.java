package mvccalculator;

import java.awt.event.ActionListener;
import javax.swing.JButton;
import javax.swing.JLabel;
import javax.swing.JTextField;
import javax.swing.JFrame;
import javax.swing.JOptionPane;
import javax.swing.JPanel;

public class CalculatorView extends JFrame{
    JTextField firstNumber = new JTextField(30);
    JTextField secondNumber = new JTextField(30);
    JTextField calcSolution = new JTextField(30);
    JLabel additionLabel = new JLabel(" + ");
    JButton calculateButton = new JButton("Calculate");
    
    public CalculatorView(){
        JPanel calcPanel = new JPanel();
        this.setDefaultCloseOperation(JFrame.EXIT_ON_CLOSE);
        this.setSize(600, 200);
        calcPanel.add(firstNumber);
        calcPanel.add(additionLabel);
        calcPanel.add(secondNumber);
        calcPanel.add(calculateButton);
        calcPanel.add(calcSolution);
        this.add(calcPanel);
    }
    
    int getFirstNumber(){
        return Integer.parseInt(firstNumber.getText());
    }
    
    int getSecondNumber(){
        return Integer.parseInt(secondNumber.getText());
    }
    
    int getCalcSolution(){
        return Integer.parseInt(calcSolution.getText());
    }
    
    void setCalcSolution(int solution){
        calcSolution.setText(Integer.toString(solution));
    }
    
    void addCalculateListener(ActionListener ListenerForCalcButton){
        calculateButton.addActionListener(ListenerForCalcButton);
    }
    
    void displayErrorMessage(String errorMessage){
        JOptionPane.showMessageDialog(this, errorMessage);
    }
}
