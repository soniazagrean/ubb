package domain;

import java.io.Serializable;

public class Music {
    private final int id;
    private final String band;
    private final String title;
    private final String genre;
    private final String time;


    public Music(int id, String band, String title, String genre, String time) {
        this.id = id;
        this.band = band;
        this.title = title;
        this.genre = genre;
        this.time = time;
    }

    public int getId() {
        return id;
    }

    public String getBand() {
        return band;
    }

    public String getTitle() {
        return title;
    }

    public String getGenre() {
        return genre;
    }

    public String getTime() {
        return time;
    }

    @Override
    public String toString() {
        return "Music{" +
                "id=" + getId() +
                ", band='" + getBand() + '\'' +
                ", title='" + getTitle() + '\'' +
                ", genre='" + getGenre() + '\'' +
                ", time='" + getTime() + '\'' +
                '}';
    }
}
