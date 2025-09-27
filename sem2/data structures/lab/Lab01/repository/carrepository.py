class CarRepository():
    def __init__(self):
        self.car_repository = []

    def add_car(self, car):
        self.car_repository.append(car)

    def get_car(self):
        return self.car_repository