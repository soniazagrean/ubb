import domain.FlightInstrument;
import domain.HardwareInstrument;
import domain.SoftwareInstrument;
import repository.InMemoryRepository;
import repository.RepositoryBinaryFile;
import service.Service;
import ui.ConsoleUI;

void main() {
//    Path path = Path.of("");

    InMemoryRepository<FlightInstrument> repositoryFlight = new InMemoryRepository<>();

    RepositoryBinaryFile<FlightInstrument> repoB = new RepositoryBinaryFile<>("bp.bin");

    Service service = new Service(repoB);
    ConsoleUI ui = new ConsoleUI(service);
    ui.start();

}