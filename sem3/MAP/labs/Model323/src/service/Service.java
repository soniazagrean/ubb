package service;

import domain.Block;
import domain.Building;
import domain.House;
import repository.IRepository;

import java.io.BufferedWriter;
import java.io.FileWriter;
import java.io.IOException;
import java.io.ObjectOutputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;
import java.util.stream.Collectors;

public class Service {
    private final IRepository<Block> repoBlock;
    private final IRepository<House> repoHouse;

    public Service(IRepository<Block> repoBlock, IRepository<House> repoHouse) {
        this.repoBlock = repoBlock;
        this.repoHouse = repoHouse;
    }


    public void addBlock(int year, int total, int occupied) {
        repoBlock.addElement(new Block(year, total, occupied));
    }

    public void addHouse(int year, boolean isHistorical) {
        repoHouse.addElement(new House(year, isHistorical));
    }

    public List<Building> getAllSorted() {
        List<Building> all = new ArrayList<>();
        all.addAll(repoBlock.getAll());
        all.addAll(repoHouse.getAll());
        all.sort(Comparator.comparingInt(Building::getConstructionYear));
        return all;
    }

    public List<Building> getRestorableBuildings() {
        return getAllSorted().stream()
                .filter(Building::mustBeRestored)
                .collect(Collectors.toList());
    }

    public List<Building> getDemolishableBuildings() {
        return getAllSorted().stream()
                .filter(Building::canBeDemolished)
                .collect(Collectors.toList());
    }

    public void exportReports(String restoreFile, String demolishFile) {
        writeToFile(restoreFile, getRestorableBuildings());
        writeToFile(demolishFile, getDemolishableBuildings());
    }

    private void writeToFile(String filename, List<Building> buildings) {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(filename))) {
            for (Building b : buildings) {
                bw.write(b.toString());
                bw.newLine();
            }
            System.out.println("Successfully exported to: " + filename);
        } catch (IOException e) {
            System.out.println("Error writing to file " + filename);
        }
    }

    public void exportDataBinary(Path path, int b) {
        List<Building> all = getAllSorted();

        List<Building> filtered = new ArrayList<>();
        for(Building item : all) {
            if(item.getConstructionYear() > b) {
                filtered.add(item);
            }
        }

        try (ObjectOutputStream out = new ObjectOutputStream(Files.newOutputStream(path))) {
            out.writeObject(filtered);
            System.out.println("Binary Export successful to " + path);
        } catch (IOException e) {
            System.out.println("Error writing binary export: " + e.getMessage());
        }
    }
}