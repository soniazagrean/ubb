import domain.Music;
import repository.IRepository;
import repository.MusicFactory;
import repository.RepositorySql;
import service.MusicService;
import ui.gui.HelloApplication;

import java.util.Properties;

public class Main {
    public static void main(String[] args) {
        Properties props = new Properties();

        String rawUrl = props.getProperty("JdbcUrl", "jdbc:sqlite:data/music.db");
        final String dbPath = rawUrl.replace("jdbc:sqlite:", "");

        IRepository<Music> repo = new RepositorySql<>(dbPath, new MusicFactory(), "music");
        MusicService service = new MusicService(repo);

        HelloApplication.setService(service);
        javafx.application.Application.launch(HelloApplication.class, args);
    }
}
