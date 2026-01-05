package domain;

import java.io.Serializable;

public abstract class FlightInstrument implements Comparable<FlightInstrument>, Serializable {

    public String getCode() {
        return code;
    }

    private String code;
    private boolean maintenance;

    public FlightInstrument(String code, boolean maintenance) {
        this.code = code;
        this.maintenance = maintenance;
    }

    public abstract double getPrice();

    @Override
    public String toString() {
        return "FlightInstrument{" +
                " price=" + getPrice() +
                " code='" + code + '\'' +
                ", maintenance=" + maintenance +
                '}';
    }

    @Override
    public int compareTo(FlightInstrument other) {
        return this.code.compareTo(other.code);
    }
}
