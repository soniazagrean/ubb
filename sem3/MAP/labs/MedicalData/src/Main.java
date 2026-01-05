import domain.BMI;
import domain.BP;
import repository.RepositoryBinaryFile;
import service.Service;
import ui.ConsoleUI;

import java.nio.file.Path;

void main() {
     Path textExportPath = Path.of("/Users/zagreansonia/Desktop/sem3/MAP/labs/MedicalData/health_export.txt");
//    Path textExportPath = Path.of("health_export.txt");

    RepositoryBinaryFile<BP> repoBP = new RepositoryBinaryFile<>("bp.bin");
    RepositoryBinaryFile<BMI> repoBMI = new RepositoryBinaryFile<>("bmi.bin");

    Service service = new Service(repoBMI, repoBP);

    ConsoleUI ui = new ConsoleUI(service, textExportPath);
    ui.start();
}