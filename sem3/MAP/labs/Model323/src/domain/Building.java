package domain;

import java.time.LocalDate;

public abstract class Building implements Comparable<Building> {
    private int constructionYear;

    public Building(int constructionYear) {
        this.constructionYear = constructionYear;
    }

    public int getConstructionYear() {
        return constructionYear;
    }
    public int getAge() {
        return LocalDate.now().getYear() - constructionYear;
    }

    public abstract boolean mustBeRestored();
    public abstract boolean canBeDemolished();

    @Override
    public int compareTo(Building other) {
        return Integer.compare(this.constructionYear, other.constructionYear);
    }

    @Override
    public String toString() {
        return "Year: " + constructionYear + " | Age: " + getAge();
    }
}