from domain.car import Car
from repository.carrepository import CarRepository
from service.carservice import CarService
import time

file = "data/carfile.in"

def main():

    car_repository = CarRepository()
    car_service = CarService(car_repository)

    with open(file, "r") as f:
        for line in f:
            array = line.split()

            car = Car(array[0], array[1], array[2], int(array[3]), int(array[4]))
            car_service.add(car)

        while True:
            print("Sort the list or Search item by:\n"
                  "1. token\n"
                  "2. mark and model\n"
                  "3. mark, model, and token\n"
                  "4. profit\n"
                  "5. enter search token\n"
                  "6. exit")
            option = input("Option = ")

            if option == "6":
                break
            elif option == "5":
                start = time.time()
                token = input("token = ")
                cars = car_service.get_cars()  # Get the list of cars
                cars_sorted = sorted(cars, key=lambda car: car._token) # sort before binary search
                print(car_service.search_car_binary(token, 0, len(cars_sorted) - 1, cars_sorted), "\n")
                print("it took", time.time() - start, "seconds")

            elif option in {"1", "2", "3", "4"}:
                start = time.time()
                car_service.compare_func(int(option))
                car_service.list_all()
                print("it took", time.time() - start, "seconds")



if __name__ == "__main__":
    main()
