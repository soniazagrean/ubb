-- lab 3

-- afiseaza numele patiserilor care fie au specialitatea 'fursecuri', fie locuiesc în 'brasov'.
    SELECT name
    FROM Bakers
    WHERE specialty = 'fursecuri'
UNION
    SELECT T1.name
    FROM Bakers AS T1
        INNER JOIN Addresses AS T2 ON T1.baker_id = T2.baker_id
    WHERE T2.city = 'brasov';

-- lista a patiserilor, specialitatilor, denumirea produselor coapte, originea acestora si pretul
SELECT
    B.name AS Patiser,
    B.specialty AS Specialitate,
    P.name AS DenumireProdus,
    P.origin AS OrigineProdus,
    BP.price AS Pret
FROM
    Bakers AS B
    INNER JOIN
    BakersPastries AS BP ON B.baker_id = BP.baker_id
    INNER JOIN
    Pastries AS P ON BP.pastry_id = P.pastry_id
    INNER JOIN
    Addresses AS A ON B.baker_id = A.baker_id
ORDER BY
    BP.price;


-- afiseaza denumirea produselor coapte, stilul semnatura si numele patiserilor pentru produse
SELECT
    P.name AS DenumireProdus,
    BP.signature_style AS StilSemnatura,
    B.name AS Patiser
FROM
    Pastries AS P
    INNER JOIN
    BakersPastries AS BP ON P.pastry_id = BP.pastry_id
    INNER JOIN
    Bakers AS B ON BP.baker_id = B.baker_id
WHERE
    (P.origin = 'franta') OR (BP.price < 10)
ORDER BY
    P.name;


-- toate produsele coapte (Pastries) si dacă exista, descrierea lor (Descriptions) și pretul (BakersPastries)
SELECT
    P.name AS NumeProdus,
    P.origin AS Origine,
    D.description_text AS Descriere,
    BP.price AS PretVanzare
FROM
    Pastries AS P
    LEFT JOIN
    Descriptions AS D ON P.pastry_id = D.pastry_id
    LEFT JOIN
    BakersPastries AS BP ON P.pastry_id = BP.pastry_id
ORDER BY
    P.name;

-- nr produselor vandute, suma preturilor (total) și pretul mediu pe patiser
SELECT
    B.name AS Patiser,
    COUNT(BP.pastry_id) AS NumarProduseVandute,
    SUM(BP.price) AS VenitTotal,
    AVG(BP.price) AS PretMediu
FROM
    Bakers AS B
    INNER JOIN
    BakersPastries AS BP ON B.baker_id = BP.baker_id
GROUP BY
    B.name
ORDER BY
    VenitTotal DESC;

-- pretul minim si maxim pentru produsele coapte, grupate dupa tara de origine a produsului
SELECT
    P.origin AS OrigineProdus,
    MIN(BP.price) AS PretMinim,
    MAX(BP.price) AS PretMaxim
FROM
    Pastries AS P
    INNER JOIN
    BakersPastries AS BP ON P.pastry_id = BP.pastry_id
GROUP BY
    P.origin
ORDER BY
    P.origin;

-- specialitati care ofera cel putin 1 produs
SELECT
    B.specialty AS Specialitate,
    COUNT(DISTINCT P.name) AS NumarProduseDistincte,
    MIN(BP.price) AS PretMinimSpecialitate
FROM
    Bakers AS B
    INNER JOIN
    BakersPastries AS BP ON B.baker_id = BP.baker_id
    INNER JOIN
    Pastries AS P ON BP.pastry_id = P.pastry_id
GROUP BY
    B.specialty
HAVING
    COUNT(BP.pastry_id) >= 1
    AND (MIN(BP.price) < 120 AND NOT B.specialty = 'fursecuri')
ORDER BY
    NumarProduseDistincte DESC;

-- cauta numele patiserilor care vand produse coapte cu originea 'romania' SAU 'italia'
SELECT
    name AS Patiser
FROM
    Bakers
WHERE
    baker_id IN (
        SELECT BP.baker_id
FROM BakersPastries AS BP
    INNER JOIN Pastries AS P ON BP.pastry_id = P.pastry_id
WHERE P.origin = 'romania' OR P.origin = 'italia'
    );


-- cauta denumirile produselor coapte care au o descriere
SELECT
    P.name AS ProdusCuDescriere
FROM
    Pastries AS P
WHERE
    EXISTS (
        SELECT 1
FROM Descriptions AS D
WHERE D.pastry_id = P.pastry_id
    )
ORDER BY
    P.name;