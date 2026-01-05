package domain;

public class BP extends HealthData {
    private final Integer systolic;
    private final Integer diastolic;

    public BP(String date, Integer systolic, Integer diastolic) {
        super(date);
        this.systolic = systolic;
        this.diastolic = diastolic;
    }

    @Override
    public boolean isNormalValue() {
        return (systolic > 100 && systolic < 130) && (diastolic > 60 && diastolic < 80);
    }

    @Override
    public String toString() {
        return "BP  | Date: " + getDate() + " | Values: " + systolic + "/" + diastolic + " | Normal: " + isNormalValue();
    }

    public String toFileString() {
        return "BP," + systolic + "/" + diastolic + "," + getDate();
    }
}