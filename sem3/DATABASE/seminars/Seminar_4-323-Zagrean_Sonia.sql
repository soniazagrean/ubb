-- CREATE PROCEDURE getPublicatii

--     @Autor varchar(50)
--     AS
--     BEGIN
--         SELECT titlu, autor FROM publicatie
--         WHERE autor = @Autor
--     END
--     GO


-- ALTER PROCEDURE getPublicatii 
-- 	(@Autor VARCHAR(50), @Number INT OUTPUT)
-- AS
-- BEGIN
-- 	SELECT @Number = COUNT(*) FROM publicatie
-- 	WHERE autor = @Autor
-- END
-- GO

-- ALTER PROCEDURE getPublicatii(@Autor varchar(50), @Number int OUTPUT)
--     AS
--     BEGIN
--     SELECT @Number = COUNT(*) FROM publicatie
--     WHERE autor = @Autor
--     IF @Number = 0
--         RAISERROR('Autorul precizat nu are publicatii', 10, 1)
-- END
-- GO

-- DECLARE @Nr INT
-- SET @Nr = 0
-- EXEC getPublicatii 'Michael Brodie', @Number = @Nr OUTPUT
-- PRINT @Nr


-- 1
-- CREATE PROCEDURE P1
-- AS
-- BEGIN
--     SELECT * FROM publicatie
-- END
-- GO
-- EXEC P1

-- 2
-- CREATE PROCEDURE P2
-- AS
-- BEGIN
--     SELECT TOP 1 P.autor, COUNT(P.id_publicatie) AS nr_publicatii
--     FROM publicatie P
--     GROUP BY P.autor
--     ORDER BY nr_publicatii DESC
-- END
-- GO
-- EXEC P2

-- 3
ALTER PROCEDURE P3
	(@id_publicatie INT, @titlu VARCHAR(50), @abstract VARCHAR(100), 
	@autor VARCHAR(100), @id_categorie INT)
AS
BEGIN
	DECLARE @number INT
	SET @number = 0
	DECLARE @number2 INT
	SET @number2 = 0
	SELECT @number = COUNT(*) FROM Publicatie WHERE id_publicatie = @id_publicatie
	SELECT @number2 = COUNT(*) FROM Categorie WHERE id_categorie = @id_categorie
	IF @number = 0 AND @number2 != 0
		INSERT INTO Publicatie VALUES
		(@id_publicatie, @titlu, @abstract, @autor, @id_categorie)
	ELSE IF @number != 0
		RAISERROR ('Publicatia exista deja.', 10, 1)
	ELSE IF @number2 = 0
		RAISERROR('Nu exista categoria introdusa', 10, 1)
END
GO
EXEC P3 234, 'nume', 'abstract2', 'nume_autor', 111

SELECT * FROM publicatie;