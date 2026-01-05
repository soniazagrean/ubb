package domain;

public class Block extends Building {
    private int totalApartments;
    private int occupiedApartments;

    public Block(int constructionYear, int totalApartments, int occupiedApartments) {
        super(constructionYear);
        this.totalApartments = totalApartments;
        this.occupiedApartments = occupiedApartments;
    }

    @Override
    public boolean mustBeRestored() {
        double occupancyRate = (double) occupiedApartments / totalApartments;
        return getAge() > 40 && occupancyRate > 0.80;
    }

    @Override
    public boolean canBeDemolished() {
        double occupancyRate = (double) occupiedApartments / totalApartments;
        return occupancyRate < 0.05;
    }

    @Override
    public String toString() {
        return "BLOCK | " + super.toString() + " | Apartments: " + occupiedApartments + "/" + totalApartments +
                " | Restore: " + mustBeRestored() + " | Demolish: " + canBeDemolished();
    }
}