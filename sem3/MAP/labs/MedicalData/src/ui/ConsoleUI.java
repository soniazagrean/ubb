package ui;

import service.Service;

import java.nio.file.Path;
import java.util.Scanner;
import static java.lang.System.exit;

public class ConsoleUI {
    private final Service service;
    private final Scanner sc = new Scanner(System.in);
    private final Path path;

    public ConsoleUI(Service service, Path path) {
        this.service = service;
        this.path = path;
    }

    public void start() {
        while (true) {
            System.out.println("\n--- HEALTH MONITOR ---");
            System.out.println("1. Add a new value");
            System.out.println("2. Show all values");
            System.out.println("3. Check health status");
            System.out.println("4. Export new values to file");
            System.out.println("5. Export new values binary file");
            System.out.println("0. Exit");
            System.out.print("Choose: ");

            String option = sc.nextLine();
            switch (option) {
                case "1" -> addValue();
                case "2" -> showAll();
                case "3" -> checkHealth();
                case "4" -> exportFile();
                case "5" -> exportBinary();
                case "0" -> { System.out.println("Bye!"); exit(0); }
                default -> System.out.println("Invalid option.");
            }
        }
    }

    private void addValue() {
        System.out.print("Enter type (BMI or BP): ");
        String type = sc.nextLine().toUpperCase();
        System.out.print("Enter Date (YYYY-MM-DD): ");
        String date = sc.nextLine();

        try {
            if (type.equals("BMI")) {
                System.out.print("Enter Value (real number): ");
                float val = Float.parseFloat(sc.nextLine());
                service.addBMI(date, val);
            } else if (type.equals("BP")) {
                System.out.print("Enter Systolic (int): ");
                int sys = Integer.parseInt(sc.nextLine());
                System.out.print("Enter Diastolic (int): ");
                int dia = Integer.parseInt(sc.nextLine());
                service.addBP(date, sys, dia);
            } else {
                System.out.println("Unknown type. Use BMI or BP.");
            }
        } catch (NumberFormatException e) {
            System.out.println("Invalid number format.");
        }
    }

    private void showAll() {
        service.getAllSorted().forEach(System.out::println);
    }

    private void checkHealth() {
        try {
            System.out.print("Enter current month (1-12): ");
            int month = Integer.parseInt(sc.nextLine());
            if (service.isHealthy(month)) {
                System.out.println("Result: HEALTHY (All recent values are normal)");
            } else {
                System.out.println("Result: NOT HEALTHY (Some recent values are abnormal)");
            }
        } catch (Exception e) {
            System.out.println("Invalid month.");
        }
    }

    private void exportFile() {
        System.out.print("Export values newer than (YYYY-MM-DD): ");
        String date = sc.nextLine();
        service.exportData(this.path, date);
    }

    private void exportBinary() {
        System.out.print("Filename (report.bin): ");
        String f = sc.nextLine();
        System.out.print("Newer than (YYYY-MM-DD): ");
        String d = sc.nextLine();
        service.exportDataBinary(Path.of(f), d);
    }
}