package domain;

public class House extends Building {
    private boolean isHistorical;

    public House(int constructionYear, boolean isHistorical) {
        super(constructionYear);
        this.isHistorical = isHistorical;
    }

    @Override
    public boolean mustBeRestored() {
        return getAge() > 100 && isHistorical;
    }

    @Override
    public boolean canBeDemolished() {
        return !isHistorical;
    }

    @Override
    public String toString() {
        return "HOUSE | " + super.toString() + " | Historical: " + isHistorical +
                " | Restore: " + mustBeRestored() + " | Demolish: " + canBeDemolished();
    }
}