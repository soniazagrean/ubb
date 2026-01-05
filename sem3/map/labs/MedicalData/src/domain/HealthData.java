package domain;

import java.io.Serializable;

public abstract class HealthData implements Comparable<HealthData>, Serializable {
    private String date;

    public HealthData(String date) {
        this.date = date;
    }

    public String getDate() {
        return date;
    }

    public int getMonth() {
        return Integer.parseInt(date.split("-")[1]);
    }

    public abstract boolean isNormalValue();

    @Override
    public int compareTo(HealthData other) {
        return this.date.compareTo(other.date);
    }
}