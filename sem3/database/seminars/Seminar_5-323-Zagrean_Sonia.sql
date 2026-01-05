-- 3

-- CREATE PROCEDURE P4
--     (@id_biblioteca INT, @site VARCHAR(30))
-- AS 
-- BEGIN 
--     DECLARE @number INT
--     SET @number = 0
--     SELECT @number = COUNT(*) FROM biblioteca WHERE id_biblioteca = @id_biblioteca
--     IF @number = 0
--         RAISERROR('biblioteca nu exista', 10, 1);
--     ELSE
--         BEGIN
--             UPDATE biblioteca SET site = @site WHERE id_biblioteca = @id_biblioteca
--             RAISERROR('site ul a fost actualizat', 10, 1)
--         END
-- END
-- GO

-- 4

-- SELECT * FROM biblioteca;
-- EXEC P4 101, 'www.biblio.ro'

-- CREATE PROCEDURE P5
--     (@autor VARCHAR(200), @number INT OUTPUT)
-- AS
-- BEGIN
--     SELECT @number = COUNT(@number) FROM publicatie
--     INNER JOIN categorie ON
--     publicatie.id_categorie = categorie.id_categorie
--     WHERE categorie.nume = 'jurnal' AND @autor = publicatie.autor

-- END
-- GO

-- DECLARE @number_publications INT = 0
-- EXEC P5 1, @number = @number_publications OUTPUT
-- PRINT @number_publications

-- 5

-- ALTER PROCEDURE P6
--     (@nume VARCHAR(200))
-- AS
-- BEGIN
--     -- IF EXISTS(
--     --     SELECT 1 FROM publicatie P INNER JOIN categorie C ON C.id_categorie = P.id_categorie
--     --     WHERE @nume = P.autor
--     --     AND C.nume = 'jurnal'
--     -- )
--     UPDATE publicatie SET id_categorie = 111 WHERE publicatie.autor = @nume AND publicatie.id_categorie != 111
-- END
-- GO 

-- SELECT * FROM publicatie
-- EXEC P6 'autorp1';

-- 6

-- ALTER PROCEDURE P7
--     (@nume VARCHAR(200), @id_publicatie INT, @titlu VARCHAR(200), @categorie INT)

-- AS
-- BEGIN
--     DECLARE @number INT = 0
--     SELECT @number = COUNT(*) FROM publicatie WHERE id_publicatie = @id_publicatie
--     -- se verifica existenta categoriei inainte de inserare
--     IF @number = 0
--         INSERT INTO publicatie(id_publicatie, titlu, autor, id_categorie)
--         VALUES (@id_publicatie, @titlu, @nume, @categorie)
--     ELSE
--         UPDATE publicatie SET id_publicatie = @id_publicatie, titlu = @titlu, autor = @nume, id_categorie = @categorie
-- END
-- GO


-- SELECT * FROM categorie;
-- EXEC P7 "nume7", 4, "titlu7", 111;
-- SELECT * FROM publicatie;

-- 7 
-- ALTER PROCEDURE P8
--     (@nume1 VARCHAR(200), @nume2 VARCHAR(200))
-- AS
-- BEGIN
--     DECLARE @count1 INT = 0
--     DECLARE @count2 INT = 0
--     EXEC P5 @nume1, @number = @count1 OUTPUT
--     EXEC P5 @nume2, @number = @count2 OUTPUT
--     IF @count1 > @count2
--         RAISERROR('Primul autor are mai multe publicatii de tip jurnal', 10, 1)
--     ELSE
--         RAISERROR('Al doilea autor are mai multe publicatii de tip jurnal', 10, 1)
-- END
-- GO

-- EXEC P8 'Michael Brodie', 'autorp1';
-- SELECT * FROM categorie;



-- ppt sem 5
-- functii scalare
-- CREATE FUNCTION getNrPublicatii(@autor VARCHAR(200))
-- RETURNS INT AS
-- BEGIN
--     DECLARE @nrpub INT = 0
--     SELECT @nrpub = COUNT(*) FROM publicatie
--     WHERE autor = @autor
--     RETURN @nrpub
-- END

-- PRINT dbo.getNrPublicatii('Michael Brodie')

-- -- functii inline
-- CREATE FUNCTION getPublicatii(@autor VARCHAR(50))
-- RETURNS TABLE AS
--     RETURN 
--     SELECT titlu, autor FROM publicatie
--     WHERE autor = @autor

-- SELECT * FROM dbo.getPublicatii('Michael Brodie');


CREATE FUNCTION getAutorByCat(@idcat INT)
RETURNS @AutorByCat TABLE (autor VARCHAR(200))
AS
BEGIN
    INSERT INTO @AutorByCat SELECT autor FROM publicatie
    WHERE id_categorie = @idcat
    IF @@ROWCOUNT = 0
        BEGIN
            INSERT INTO @AutorByCat VALUES ('nu a fost gasit niciun autor')
        END
    RETURN
END








