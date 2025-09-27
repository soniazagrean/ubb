class Masina:
    _marca: str
    _model: str
    _token: str
    _pretAchizitie: int
    _pretVanzare: int

    @property
    def marca(self):
        return self._marca

    @marca.setter
    def marca(self, new):
        self._marca = new

    @property
    def model(self):
        return self._model

    @model.setter
    def model(self, new):
        self._model = new

    @property
    def token(self):
        return self._token

    @token.setter
    def token(self, new):
        self._token = new

    @property
    def pretAchizitie(self):
        return self._pretAchizitie

    @pretAchizitie.setter
    def pretAchizitie(self, new):
        self._pretAchizitie = new

    @property
    def pretVanzare(self):
        return self._pretVanzare

    @pretVanzare.setter
    def pretVanzare(self, new):
        self._pretVanzare = new

    def __str__(self):
        return self._marca + " " + self._model + " " + self._token + f" {self._pretAchizitie} {self._pretVanzare}\n"