package domain;

public class SoftwareInstrument extends FlightInstrument{

    private int version;

    public SoftwareInstrument(String code, boolean maintenance, int version) {
        super(code, maintenance);
        this.version = version;
    }

    @Override
    public double getPrice() {
        if (version < 10)
            return 100f;
        return 200f;
    }

    @Override
    public String toString() {
        return "SoftwareInstrument{" +
                " code= " + getCode()+
                " price=" + getPrice() +
                " version=" + version +
                '}';
    }

}
