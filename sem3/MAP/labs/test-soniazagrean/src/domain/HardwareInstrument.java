package domain;

public class HardwareInstrument extends FlightInstrument{

    private String measurementType;

    public HardwareInstrument(String code, boolean maintenance, String measurementType) {
        super(code, maintenance);
        this.measurementType = measurementType;
    }

    @Override
    public double getPrice() {
        if (measurementType.equals("altitudine") || measurementType.equals("directie"))
            return 50f;
        else if (measurementType.equals("stare_monitor"))
            return 500f;
        return 0;
    }

    @Override
    public String toString() {
        return "HardwareInstrument{" +
                "code=" + getCode() +
                " price=" + getPrice() +
                " measurementType='" + measurementType + '\'' +
                '}';
    }


}
