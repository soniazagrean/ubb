import domain.Block;
import domain.House;
import repository.InMemoryRepository;
import repository.RepositoryBinaryFile;
import service.Service;
import ui.ConsoleUI;

void main() {
//    InMemoryRepository<Block> repoBlock = new InMemoryRepository<>();
//    InMemoryRepository<House> repoHouse = new InMemoryRepository<>();

    RepositoryBinaryFile<House> repoH = new RepositoryBinaryFile<>("house.bin");
    RepositoryBinaryFile<Block> repoB = new RepositoryBinaryFile<>("block.bin");

    Service service = new Service(repoB, repoH);

    ConsoleUI ui = new ConsoleUI(service);
    ui.start();
}