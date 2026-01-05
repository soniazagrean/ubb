package repository;

import domain.Music;

import java.sql.ResultSet;
import java.sql.SQLException;

public class MusicFactory implements Factory<Music> {
    @Override
    public Music fromTokens(String[] tokens) {
        if (tokens.length != 5) {
            throw new IllegalArgumentException("Invalid format");
        }
        int id = Integer.parseInt(tokens[0].trim());
        String band = tokens[1].trim();
        String title = tokens[2].trim();
        String genre = tokens[3].trim();
        String time = tokens[4].trim();
        return new Music(id, band, title, genre, time);
    }

    @Override
    public String toLine(Music entity) {
        return entity.getId() + ";" +
                entity.getBand() + ";" +
                entity.getTitle() + ";" +
                entity.getGenre() + ";" +
                entity.getTime();
    }

    @Override
    public Music createFromResultSet(ResultSet rs) throws SQLException {
        int id = rs.getInt("id");
        String band = rs.getString("band");
        String title = rs.getString("title");
        String genre = rs.getString("genre");
        String time = rs.getString("time");
        return new Music(id, band, title, genre, time);
    }
}
