package mvccalculator;

public class CalculatorModel {
    private int CalculationValue;
    
    void addTwoNumbers(int firstNumber, int secondNumber){
        CalculationValue = firstNumber + secondNumber;
    }
    
    int getCalculationValue(){
        return CalculationValue;
    }
}
