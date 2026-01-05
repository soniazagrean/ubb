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
            System.out.println("\nApp");
            System.out.println("1. Delete instrument by code");
            System.out.println("2. Show instruments cheaper than value (sorted by code)");
            System.out.println("0. Exit");
            System.out.print("Choose: ");

            String option = sc.nextLine();
            switch (option) {
                case "1" -> deleteValue();
                case "2" -> listAll();
                case "0" -> { System.out.println("Bye!"); exit(0); }
                default -> System.out.println("Invalid option.");
            }
        }
    }

    public void deleteValue() {
        System.out.print("Enter instrument code to delete: ");
        int code = Integer.parseInt(sc.nextLine());

        service.deleteInstrument(String.valueOf(code));

        for (var i : service.getAllA()) {
            System.out.println(i);
        }
    }

    private void listAll() {
        System.out.print("Enter price value: ");
        int value = Integer.parseInt(sc.nextLine());

        var results = service.getAll(value);

        if (results.isEmpty()) {
            System.out.println("No instruments found cheaper than " + value);
        } else {
            results.forEach(System.out::println);
        }
    }
}