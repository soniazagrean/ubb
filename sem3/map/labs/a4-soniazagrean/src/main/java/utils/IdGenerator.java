package utils;

import java.io.*;

public class IdGenerator {
    private int current;
    private final File file;

    public IdGenerator(String file) {
        this.file = new File(file);
        this.current = read();
        if (this.current < 100)
            this.current = 100;
    }

    private int read() {
        try (BufferedReader br = new BufferedReader(new FileReader(file))) {
            return Integer.parseInt(br.readLine());
        } catch (Exception e) {
            return 99;
        }
    }

    private void write() {
        try (BufferedWriter bw = new BufferedWriter(new FileWriter(file))) {
            bw.write(String.valueOf(current));
        } catch (IOException ignored) {

        }
    }

    public int peekNext() {
        return current + 1;
    }

    public int consumeNext() {
        current++;
        write();
        return current;
    }
}
