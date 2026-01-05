DELETE FROM publicatie WHERE id_publicatie IN (3, 19, 9);
DELETE FROM categorie WHERE id_categorie IN (5, 222);


INSERT INTO publicatie
VALUES
    (3, 'titlu3', 'abstract 3', 'Michael Brodie', 111);

-- exercitiul 1
SELECT titlu
FROM publicatie
WHERE autor = 'Michael Brodie';

SELECT titlu
FROM publicatie
WHERE autor = 'Michael Brodie' and id_categorie = 111;

SELECT site
FROM biblioteca
WHERE nume = 'ACM' or nume = 'DBLP';

INSERT INTO publicatie
VALUES
    (19, 'title 19', 'abstract', 'STHBianchini', 122);
INSERT INTO publicatie
VALUES
    (9, 'title 9', 'abstract 9', 'jwefdnwksBianchini', 122);

SELECT autor
FROM publicatie
WHERE autor LIKE '%Bianchini';

INSERT INTO categorie
VALUES
    (5, 'catg 1', 'descp 1'),
    (222, 'catg 2', ' descp 2');

SELECT nume, descriere
FROM categorie
WHERE id_categorie NOT IN (111, 222, 333);
-- se face join dupa cheia primara in prima tabela cu referinta la cheia primara din tabela a doua

-- exercitiul 2
SELECT P.titlu, C.nume
FROM publicatie P INNER JOIN
    categorie C ON P.id_categorie = C.id_categorie
WHERE P.autor = 'Michael Brodie';

-- LEFT OUTER JOIN, RIGHT OUTER JOIN vede toate nepotrivirile care exista chiar daca nu avem perechile inserate

SELECT P.titlu, I.id_biblioteca
FROM publicatie P LEFT OUTER JOIN indexare I ON P.id_publicatie = I.id_publicatie;

UPDATE categorie
SET nume = 'jurnal'
WHERE descriere = 'jurnal';

UPDATE categorie
SET nume = 'conferinta'
WHERE descriere = 'conf';

SELECT B.site, B.nume
FROM biblioteca B INNER JOIN indexare I ON B.id_biblioteca = I.id_biblioteca
    INNER JOIN publicatie P ON i.id_publicatie = P.id_publicatie
    INNER JOIN categorie C ON P.id_categorie = C.id_categorie
WHERE C.nume = 'jurnal';

SELECT P.autor
FROM publicatie P INNER JOIN indexare I ON P.id_publicatie = I.id_publicatie
    INNER JOIN biblioteca B ON B.id_biblioteca = I.id_biblioteca
WHERE nume = 'dblp';

-- exercitiul 3
    SELECT P.autor
    FROM publicatie P INNER JOIN categorie C ON P.id_categorie = C.id_categorie
    WHERE C.nume = 'jurnal'
INTERSECT
    SELECT P.autor
    FROM publicatie P INNER JOIN categorie C ON P.id_categorie = C.id_categorie
    WHERE C.nume = 'conferinta'
-- si si

    SELECT P.autor
    FROM publicatie P INNER JOIN categorie C ON P.id_categorie = C.id_categorie
    WHERE C.nume = 'conferinta'
EXCEPT
    SELECT P.autor
    FROM publicatie P INNER JOIN categorie C ON P.id_categorie = C.id_categorie
    WHERE C.nume = 'jurnal'
-- conferinta nu si jurnal

    SELECT P.autor
    FROM publicatie P INNER JOIN categorie C ON P.id_categorie = C.id_categorie
    WHERE C.nume = 'conferinta'
UNION
    SELECT P.autor
    FROM publicatie P INNER JOIN categorie C ON P.id_categorie = C.id_categorie
    WHERE C.nume = 'jurnal'
-- sau sau

-- exercitiul 4
SELECT P.titlu, P.autor, C.nume
FROM publicatie P INNER JOIN categorie C ON P.id_categorie = C.id_categorie


-- exercitiul 5
SELECT autor, COUNT(id_publicatie) as nr
FROM publicatie
GROUP BY autor
ORDER BY nr DESC

-- pt fiecare GROUP BY + conditie

SELECT P.autor, COUNT(P.id_publicatie) as nr
FROM publicatie P INNER JOIN categorie C ON P.id_categorie = C.id_categorie
WHERE C.nume = 'jurnal'
GROUP BY P.autor
ORDER BY nr DESC;

SELECT P.autor, COUNT(P.id_publicatie)
FROM publicatie P
GROUP BY P.autor
HAVING COUNT(id_publicatie) >= 2;

SELECT DISTINCT P.autor
FROM publicatie P INNER JOIN categorie C ON P.id_categorie = C.id_categorie
WHERE C.nume = 'jurnal';

SELECT autor, COUNT(id_publicatie) AS nr
FROM publicatie
GROUP BY autor
ORDER BY nr DESC;


