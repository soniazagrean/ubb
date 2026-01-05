
DROP TABLE IF EXISTS BakersPastries;
DROP TABLE IF EXISTS Addresses;
DROP TABLE IF EXISTS Descriptions;
DROP TABLE IF EXISTS Pastries;
DROP TABLE IF EXISTS Bakers;

CREATE TABLE Bakers
(
    baker_id INT PRIMARY KEY,
    name VARCHAR(500),
    specialty VARCHAR(500)
);

CREATE TABLE Pastries
(
    pastry_id INT PRIMARY KEY,
    name VARCHAR(300),
    origin VARCHAR(100)
);

CREATE TABLE Addresses
(
    address_id INT PRIMARY KEY,
    baker_id INT,
    street VARCHAR(300),
    city VARCHAR(200),
    country VARCHAR(100),
    FOREIGN KEY (baker_id) REFERENCES Bakers(baker_id)
);

CREATE TABLE Descriptions
(
    description_id INT PRIMARY KEY,
    pastry_id INT,
    description_text VARCHAR(1000),
    ingredients VARCHAR(500),
    FOREIGN KEY (pastry_id) REFERENCES Pastries(pastry_id)
);

CREATE TABLE BakersPastries
(
    baker_id INT,
    pastry_id INT,
    signature_style VARCHAR(100),
    price DECIMAL(5, 2),
    PRIMARY KEY (baker_id, pastry_id),
    FOREIGN KEY (baker_id) REFERENCES Bakers(baker_id),
    FOREIGN KEY (pastry_id) REFERENCES Pastries(pastry_id)
);

INSERT INTO Bakers
VALUES
    (1, 'ana', 'prajitura'),
    (2, 'maria', 'tarta'),
    (3, 'ioana', 'cheesecake'),
    (4, 'irina', 'croissants');

INSERT INTO Pastries
VALUES
    (7, 'mere', 'romania'),
    (8, 'lamaie', 'italia'),
    (9, 'morcov', 'belgia'),
    (10, 'capsune', 'franta'),
    (11, 'cirese', 'japonia'),
    (12, 'vanilie', 'brazilia'),
    (13, 'ciocolata', 'franta');

INSERT INTO BakersPastries
VALUES
    (1, 7, 'crocanta, cu scortisoara', 12.5),
    (1, 9, 'insiropat, cu crema de branza', 15.7),
    (2, 10, 'delicioasa, colorata', 10.2),
    (3, 8, 'fresh, aromat', 14.5),
    (4, 12, 'pufos, auriu', 6),
    (4, 13, 'pufos, delicios', 7);

INSERT INTO Addresses
VALUES
    (1, 1, 'str. florilor 12', 'bucuresti', 'romania'),
    (2, 2, 'via roma 88', 'milano', 'italia'),
    (3, 3, 'rue de la paix 14', 'bruxelles', 'belgia'),
    (4, 4, 'avenue des champs 27', 'paris', 'franta');

INSERT INTO Descriptions
VALUES
    (1, 7, 'placinta cu mere si scortisoara', 'faina, mere, zahar, scortisoara'),
    (2, 8, 'tarta cu lamaie si bezea', 'faina, lamaie, oua, zahar'),
    (3, 9, 'cheesecake cu morcov', 'branza, morcov, zahar, oua'),
    (4, 10, 'tarta cu capsune', 'capsune, faina, zahar, lapte'),
    (5, 12, 'ecler cu vanilie', 'faina, lamaie, oua, zahar'),
    (6, 13, 'brownie cu ciocolata', 'ciocolata, unt, zahar, faina');

SELECT *
FROM BakersPastries;

UPDATE Bakers
SET name = 'mircea', specialty = 'fursecuri'
WHERE baker_id = 1;

UPDATE Bakers
SET name = 'ramona'
WHERE baker_id = 4;

SELECT *
FROM Bakers;

UPDATE Addresses 
SET city = 'sibiu'
WHERE country = 'romania';

UPDATE Addresses
SET city = 'brasov'
WHERE country = 'romania' AND city <> 'bucuresti';

UPDATE BakersPastries
SET price = price + 2
WHERE price < 10 AND signature_style IS NOT NULL;

UPDATE Bakers
SET specialty = 'produse internaționale'
WHERE baker_id IN (SELECT baker_id
    FROM Addresses
    WHERE country <> 'romania') OR specialty IS NULL;


DELETE FROM BakersPastries WHERE price > 15;

DELETE FROM Descriptions
WHERE pastry_id IN (
    SELECT pastry_id
FROM Pastries
WHERE origin NOT IN ('romania', 'italia')
);

DELETE FROM Addresses WHERE country IS NULL;