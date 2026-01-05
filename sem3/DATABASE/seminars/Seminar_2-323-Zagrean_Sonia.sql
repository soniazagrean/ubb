
DROP TABLE IF EXISTS indexare;
DROP TABLE IF EXISTS publicatie;
DROP TABLE IF EXISTS biblioteca;
DROP TABLE IF EXISTS categorie;

-- Creare tabele
CREATE TABLE categorie
(
    id_categorie INT PRIMARY KEY,
    nume VARCHAR(50),
    descriere VARCHAR(100)
);

CREATE TABLE publicatie
(
    id_publicatie INT PRIMARY KEY,
    titlu VARCHAR(50),
    abstract VARCHAR(100),
    autor VARCHAR(100),
    id_categorie INT,
    FOREIGN KEY (id_categorie) REFERENCES categorie(id_categorie) ON DELETE CASCADE
);

CREATE TABLE biblioteca
(
    id_biblioteca INT PRIMARY KEY,
    nume VARCHAR(50),
    site VARCHAR(50)
);

CREATE TABLE indexare
(
    id_publicatie INT,
    id_biblioteca INT,
    FOREIGN KEY (id_publicatie) REFERENCES publicatie(id_publicatie) ON DELETE CASCADE,
    FOREIGN KEY (id_biblioteca) REFERENCES biblioteca(id_biblioteca),
    CONSTRAINT PK_indexare PRIMARY KEY (id_publicatie, id_biblioteca)
);


-- Adaugam inregistrari in tabele
INSERT INTO categorie
    (id_categorie, nume, descriere)
VALUES
    (111, 'jurnal descr', 'jurnal'),
    (122, 'conferinta descr', 'conf');

INSERT INTO publicatie
    (id_publicatie, titlu, abstract, autor, id_categorie)
VALUES
    (2919, 'titlu 1', 'abstract 1', 'autorp1', 122),
    (3310, 'titlu 2', 'abstract 2', 'autorp 2', 111);

INSERT INTO biblioteca
    (id_biblioteca, nume, site)
VALUES
    (101, 'ACM', 'https://dl.acm.org/'),
    (335, 'dblp', 'http://dblp.uni-trier.de/');

INSERT INTO indexare
    (id_publicatie, id_biblioteca)
VALUES
    (2919, 101),
    (2919, 335),
    (3310, 101);

-- Updatam datele pt inregistrarea cu id = 101
UPDATE biblioteca
SET nume = 'nume2'
WHERE id_biblioteca = 101;

SELECT *
FROM publicatie;
SELECT *
FROM indexare;
SELECT *
FROM biblioteca;

-- Stergem din tabela publicatia cu id = 3310
DELETE FROM publicatie WHERE id_publicatie = 3310;

SELECT DISTINCT id_publicatie
FROM indexare;
