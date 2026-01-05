package service;

import domain.FlightInstrument;
import domain.HardwareInstrument;
import domain.SoftwareInstrument;
import repository.IRepository;
import repository.InMemoryRepository;

import java.io.IOException;
import java.io.ObjectOutputStream;
import java.nio.file.Files;
import java.nio.file.Path;
import java.sql.ClientInfoStatus;
import java.util.ArrayList;
import java.util.Comparator;
import java.util.List;

public class Service {

    public Service(IRepository<FlightInstrument> repoFlight) {
        this.repoFlight = repoFlight;
        initData();
    }

    IRepository<FlightInstrument> repoFlight;

    void initData() {
        repoFlight.addElement(new SoftwareInstrument("12", true, 11));
        repoFlight.addElement(new SoftwareInstrument("14", false, 9));
        repoFlight.addElement(new HardwareInstrument("78", true, "altitudine"));
        repoFlight.addElement(new HardwareInstrument("67", true, "stare_motor"));
//        repoFlight.addElement(new HardwareInstrument("12", true, "stare_motor"));
//        repoFlight.addElement(new HardwareInstrument("9", true, "directie"));
//        repoFlight.addElement(new SoftwareInstrument("7", true, 4));
//        repoFlight.addElement(new SoftwareInstrument("12", true, 1));
    }

    public List<FlightInstrument> getAll(int value) {
        List<FlightInstrument> list = new ArrayList<>();
        for (FlightInstrument instrument : repoFlight.getAll())
            if (instrument.getPrice() < value)
                list.add(instrument);

        list.sort(Comparator.comparing(FlightInstrument::getCode));
        return list;
    }

    public void deleteInstrument(String code) {
        repoFlight.deleteElement(code);
    }

    public ArrayList<FlightInstrument> getAllA() {
        return repoFlight.getAll();
    }

    public void exportDataBinary(Path path, String dateThreshold) {
        List<FlightInstrument> all = getAllA();

        List<FlightInstrument> filtered = new ArrayList<>();

        try (ObjectOutputStream out = new ObjectOutputStream(Files.newOutputStream(path))) {
            out.writeObject(filtered);
            System.out.println("Binary Export successful to " + path);
        } catch (IOException e) {
            System.out.println("Error writing binary export: " + e.getMessage());
        }
    }

}
