package service;

import domain.BMI;
import domain.BP;
import domain.HealthData;
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

public class Service {
    private final IRepository<BMI> repoBMI;
    private final IRepository<BP> repoBP;

    public Service(IRepository<BMI> repoBMI, IRepository<BP> repoBP) {
        this.repoBMI = repoBMI;
        this.repoBP = repoBP;

        if (repoBMI.getAll().isEmpty() && repoBP.getAll().isEmpty()) {
            initData();
        }
    }

    private void initData() {
        addBMI("2024-01-15", 22.0f);
        addBMI("2024-02-20", 28.5f);
        addBP("2024-01-10", 120, 70);
        addBP("2024-03-01", 140, 90);
    }

    public void addBP(String date, Integer sv, Integer dv) {
        repoBP.addElement(new BP(date, sv, dv));
    }

    public void addBMI(String date, Float value) {
        repoBMI.addElement(new BMI(date, value));
    }

    public List<HealthData> getAllSorted() {
        List<HealthData> all = new ArrayList<>();
        all.addAll(repoBMI.getAll());
        all.addAll(repoBP.getAll());
        all.sort(Comparator.comparing(HealthData::getDate));
        return all;
    }

    public boolean isHealthy(Integer currentMonth) {
        List<HealthData> all = getAllSorted();

        for (HealthData item : all) {
            int m = item.getMonth();
            boolean checkThisItem = (m == currentMonth);
            if (currentMonth > 1 && m == currentMonth - 1) {
                checkThisItem = true;
            }

            if (checkThisItem) {
                if (!item.isNormalValue()) {
                    return false;
                }
            }
        }
        return true;
    }

    public void exportData(Path path, String dateThreshold) {
        List<HealthData> all = getAllSorted();

        try (BufferedWriter bw = new BufferedWriter(new FileWriter(path.toFile()))) {
            for (HealthData item : all) {
                if (item.getDate().compareTo(dateThreshold) > 0) {
                    bw.write(item.toString());
                    bw.newLine();
                }
            }
            System.out.println("Export successful to " + path);
        } catch (IOException e) {
            System.out.println("Error writing export file: " + e.getMessage());
        }
    }

    public void exportDataBinary(Path path, String dateThreshold) {
        List<HealthData> all = getAllSorted();

        List<HealthData> filtered = new ArrayList<>();
        for(HealthData item : all) {
            if(item.getDate().compareTo(dateThreshold) > 0) {
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