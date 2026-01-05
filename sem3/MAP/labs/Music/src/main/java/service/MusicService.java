package service;

import domain.Music;
import repository.IRepository;

import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class MusicService {
    private final IRepository<Music> repo;

    public MusicService(IRepository<Music> repo) {
        this.repo = repo;
    }

    public void addMusic(Music music) {
        repo.addElement(music);
    }

    public void deleteMusic(int id) {
        repo.deleteElement(id);
    }

    public void deleteMusic(Music music) {
        repo.deleteElement(music);
    }

    public void updateMusic(Music music) {
        repo.updateElement(music);
    }

    public ArrayList<Music> getAllMusic() {
        return repo.getAll();
    }

    public int countMusic() {
        return repo.size();
    }

    public List<Music> getSortedMusic() {
        return repo.getAll().stream()
                .sorted(Comparator.comparing(Music::getBand)
                        .thenComparing(Music::getTitle))
                .collect(Collectors.toList());
    }

    public List<String> getUniqueGenres() {
        return repo.getAll().stream()
                .map(Music::getGenre)
                .distinct()
                .sorted()
                .collect(Collectors.toList());
    }

    public List<Music> filterByGenre(String genre) {
        return repo.getAll().stream()
                .filter(m -> m.getGenre().equalsIgnoreCase(genre))
                .sorted(Comparator.comparing(Music::getBand)
                        .thenComparing(Music::getTitle))
                .collect(Collectors.toList());
    }
}
