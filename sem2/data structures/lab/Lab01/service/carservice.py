import time

class CarService():
    def __init__(self, car_repository):
        self.car_service = car_repository

    def add(self, car):
        self.car_service.add_car(car)

    def list_all(self):
        for car in self.car_service.get_car():
            print(car)

    def get_cars(self):
        return self.car_service.get_car()

    def search_car_seq(self, token):
        for car in self.car_service.get_car():
            if car._token == token:
                return car

    def search_car_binary(self, token, left, right, cars):
        while left <= right:
            mid = (left + right) // 2
            if cars[mid]._token == token:
                return cars[mid]
            elif cars[mid]._token < token:
                left = mid + 1
            else:
                right = mid - 1
        return None

    def sort(self, comparator): # selection sort
        cars = self.car_service.get_car()
        for i in range(len(cars)):
            min_i = i
            for j in range(i + 1, len(cars)):
                if comparator(cars[j], cars[min_i]):
                    min_i = j
            cars[i], cars[min_i] = cars[min_i], cars[i]

    def quick_sort(self, comparator, left, right, cars):
        if left < right:
            pivot = cars[(left + right) // 2]
            i = left
            j = right

            while i <= j:
                while comparator(cars[i], pivot): i += 1
                while comparator(pivot, cars[j]): j -= 1

                if i <= j:
                    cars[i], cars[j] = cars[j], cars[i]
                    i += 1
                    j -= 1

            if left < j:
                self.quick_sort(comparator, left, j, cars)
            if i < right:
                self.quick_sort(comparator, i, right, cars)

    def compare_func(self, option):
        cars = self.car_service.get_car()
        if option == 1:
            #start = time.time()
            self.quick_sort(self.comp_by_token, 0, len(cars) - 1, cars)
            #print("it took", time.time() - start, "seconds")
        elif option == 2:
            self.quick_sort(self.comp_by_mark_model, 0, len(cars) - 1, cars)
        elif option == 3:
            self.quick_sort(self.comp_by_mark_model_token, 0, len(cars) - 1, cars)
        elif option == 4:
            self.quick_sort(self.comp_by_profit, 0, len(cars) - 1, cars)

    @staticmethod
    def comp_by_token(car1, car2):
        return car1._token < car2._token

    @staticmethod
    def comp_by_mark_model(car1, car2):
        if car1._mark == car2._mark:
            return car1._model < car2._model

        else:
            return car1._mark < car2._mark

    @staticmethod
    def comp_by_mark_model_token(car1, car2):
        if car1._mark == car2._mark:
            if car1._model == car2._model:
                return car1._token < car2._token
            else:
                return car1._model < car2._model
        else:
            return car1._mark < car2._mark

    @staticmethod
    def comp_by_profit(car1, car2):
        profit1 = car1._sold_price - car1._buy_price
        profit2 = car2._sold_price - car2._buy_price
        return profit2 < profit1