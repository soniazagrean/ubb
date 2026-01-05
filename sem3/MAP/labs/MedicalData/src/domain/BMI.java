package domain;

public class BMI extends HealthData {
    private Float value;

    public BMI(String date, Float value) {
        super(date);
        this.value = value;
    }

    @Override
    public boolean isNormalValue() {
        return value > 18.5 && value < 25;
    }

    @Override
    public String toString() {
        return "BMI | Date: " + getDate() + " | Value: " + value + " | Normal: " + isNormalValue();
    }

    public String toFileString() {
        return "BMI," + value + "," + getDate();
    }
}