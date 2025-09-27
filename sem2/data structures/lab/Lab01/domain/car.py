from dataclasses import dataclass


@dataclass
class Car:
    _mark: str
    _model: str
    _token: str
    _buy_price: int
    _sold_price: int

    # @property
    # def mark(self):
    #     return self._mark
    #
    # @mark.setter
    # def mark(self, new):
    #     self._mark = new
    #
    # @property
    # def model(self):
    #     return self._model
    #
    # @model.setter
    # def model(self, new):
    #     self._model = new
    #
    # @property
    # def token(self):
    #     return self._token
    #
    # @token.setter
    # def token(self, new):
    #     self._token = new
    #
    # @property
    # def buy_price(self):
    #     return self._buy_price
    #
    # @buy_price.setter
    # def buy_price(self, new):
    #     self._buy_price = new
    #
    # @property
    # def sold_price(self):
    #     return self._sold_price
    #
    # @sold_price.setter
    # def sold_price(self, new):
    #     self._sold_price = new

    def __str__(self):
        return self._mark + " " + self._model + " " + self._token + f" {self._buy_price} {self._sold_price}"