package ui;

import service.Service;

import java.nio.file.Path;
import java.util.Scanner;
import static java.lang.System.exit;

public class ConsoleUI {
    private final Service service;
    private final Scanner sc = new Scanner(System.in);

    public ConsoleUI(Service service) {
        this.service = service;
    }

    public void start() {
        while (true) {
            System.out.println("\nCITY BUILDING MANAGER");
            System.out.println("1. Add a new building");
            System.out.println("2. Show all buildings (Sorted by Year)");
            System.out.println("3. Show buildings to RESTORE");
            System.out.println("4. Export reports to files");
            System.out.println("5. Export new values binary file");
            System.out.println("0. Exit");
            System.out.print("Choose: ");

            String option = sc.nextLine();
            switch (option) {
                case "1" -> addBuilding();
                case "2" -> showAll();
                case "3" -> showRestorable();
                case "4" -> exportFiles();
                case "5" -> exportBinary();
                case "0" -> { System.out.println("Bye"); exit(0); }
                default -> System.out.println("Invalid option.");
            }
        }
    }

    private void exportBinary() {
        System.out.print("Filename (report.bin): ");
        String f = sc.nextLine();
        System.out.print("Newer than (YYYY): ");
        int d = Integer.parseInt(sc.nextLine());
        service.exportDataBinary(Path.of(f), d);
    }

    private void addBuilding() {
        System.out.print("Type (Block/House): ");
        String type = sc.nextLine().toLowerCase();

        try {
            System.out.print("Construction Year: ");
            int year = Integer.parseInt(sc.nextLine());

            if (type.equals("block")) {
                System.out.print("Total Apartments: ");
                int total = Integer.parseInt(sc.nextLine());
                System.out.print("Occupied Apartments: ");
                int occupied = Integer.parseInt(sc.nextLine());
                service.addBlock(year, total, occupied);
            } else if (type.equals("house")) {
                System.out.print("Is Historical? (true/false): ");
                boolean hist = Boolean.parseBoolean(sc.nextLine());
                service.addHouse(year, hist);
            } else {
                System.out.println("Unknown type.");
            }
        } catch (NumberFormatException e) {
            System.out.println("Invalid number input.");
        }
    }

    private void showAll() {
        service.getAllSorted().forEach(System.out::println);
    }

    private void showRestorable() {
        System.out.println("Buildings to be restored");
        service.getRestorableBuildings().forEach(System.out::println);
    }

    private void exportFiles() {
        service.exportReports("restore.txt", "demolish.txt");
    }
}