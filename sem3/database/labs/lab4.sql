
ALTER FUNCTION ValidateText (@text VARCHAR(500))
RETURNS BIT
AS
BEGIN
    IF @text IS NOT NULL AND LEN(@text) > 2   -- verifica sa nu fie textul null si sa aiba mai mult de 2 ch
        RETURN 1
    RETURN 0
END
GO

ALTER FUNCTION ValidatePrice (@price DECIMAL(5, 2))
RETURNS BIT
AS
BEGIN
    IF @price > 0  -- pret pozitiv
        RETURN 1
    RETURN 0
END
GO

ALTER FUNCTION ValidateID (@id INT)
RETURNS BIT
AS
BEGIN
    IF @id > 0   -- id pozitiv
        RETURN 1
    RETURN 0
END
GO


-- ex 1 -- stored procedures AddBaker, AddPastry, AddBakerPastry

ALTER PROCEDURE AddBaker
    (@name VARCHAR(500), @specialty VARCHAR(500))   -- adauga in Bakers daca textul e valid si acel baker nu exista deja
AS
BEGIN
    IF dbo.ValidateText(@name) = 0
    BEGIN
        RAISERROR('Name is too short.', 10, 1)
        RETURN
    END

    DECLARE @count INT
    SET @count = 0
    SELECT @count = COUNT(*) FROM Bakers WHERE name = @name

    IF @count = 0
    BEGIN
        DECLARE @newId INT
        SELECT @newId = ISNULL(MAX(baker_id), 0) + 1 FROM Bakers
        
        INSERT INTO Bakers VALUES (@newId, @name, @specialty)
        PRINT 'Baker added successfully.'
    END
    ELSE
    BEGIN
        RAISERROR('Baker already exists.', 10, 1)
    END
END
GO




ALTER PROCEDURE AddPastry
    (@name VARCHAR(300), @origin VARCHAR(100))  -- insert in Pastries daca numele e valid
AS
BEGIN
    IF dbo.ValidateText(@name) = 0
    BEGIN
        RAISERROR('Pastry name is invalid.', 10, 1)
        RETURN
    END

    DECLARE @count INT
    SET @count = 0
    SELECT @count = COUNT(*) FROM Pastries WHERE name = @name

    IF @count = 0
    BEGIN
        DECLARE @newId INT
        SELECT @newId = ISNULL(MAX(pastry_id), 0) + 1 FROM Pastries

        INSERT INTO Pastries VALUES (@newId, @name, @origin)
        PRINT 'Pastry added successfully.'
    END
    ELSE
    BEGIN
        RAISERROR('Pastry already exists.', 10, 1)
    END
END
GO





ALTER PROCEDURE AddBakerPastry
    (@bakerId INT, @pastryId INT, @style VARCHAR(100), @price DECIMAL(5,2))  -- verif sa nu existe deja baker si pastry si linkingul dintre si adauga
AS
BEGIN
    IF dbo.ValidatePrice(@price) = 0
    BEGIN
        RAISERROR('Price must be positive.', 10, 1)
        RETURN
    END

    DECLARE @nrBaker INT
    SET @nrBaker = 0
    
    DECLARE @nrPastry INT
    SET @nrPastry = 0

    DECLARE @nrLink INT
    SET @nrLink = 0

    SELECT @nrBaker = COUNT(*) FROM Bakers WHERE baker_id = @bakerId
    SELECT @nrPastry = COUNT(*) FROM Pastries WHERE pastry_id = @pastryId
    SELECT @nrLink = COUNT(*) FROM BakersPastries WHERE baker_id = @bakerId AND pastry_id = @pastryId
    -- procedure must insert into a table with a composite primary key
    IF @nrBaker = 0
        RAISERROR('Baker ID does not exist.', 10, 1)
    ELSE IF @nrPastry = 0
        RAISERROR('Pastry ID does not exist.', 10, 1)
    ELSE IF @nrLink > 0
        RAISERROR('This Baker-Pastry link already exists.', 10, 1)
    ELSE
    BEGIN
        INSERT INTO BakersPastries VALUES (@bakerId, @pastryId, @style, @price)
        PRINT 'Link added successfully.'
    END
END
GO




-- ex 2
-- CREATE VIEW ViewFullMenu AS
-- SELECT 
--     B.name AS BakerName,    -- three tables Bakers, BakersPastries, Pastries
--     P.name AS PastryName,
--     P.origin AS Origin,
--     BP.price AS Price
-- FROM Bakers B
-- INNER JOIN BakersPastries BP ON B.baker_id = BP.baker_id
-- INNER JOIN Pastries P ON BP.pastry_id = P.pastry_id
-- GO



-- ex 3

-- trigger for insert
ALTER TRIGGER TriggerAddressInsert
ON Addresses
AFTER INSERT
AS
BEGIN
    PRINT 'Action insert | Table Addresses | Time ' + CAST(GETDATE() AS VARCHAR(50))
END
GO

-- trigger for delete
ALTER TRIGGER TriggerAddressDelete
ON Addresses
AFTER DELETE
AS
BEGIN
    PRINT 'Action delete | Table Addresses | Time ' + CAST(GETDATE() AS VARCHAR(50))
END
GO




-- add new data using procedures
-- EXEC AddBaker 'Chef Mario', 'Italian'
-- EXEC AddPastry 'Cannoli', 'Sicily'

-- retrieve ids
DECLARE @bId INT
DECLARE @pId INT
SELECT @bId = MAX(baker_id) FROM Bakers
SELECT @pId = MAX(pastry_id) FROM Pastries

-- -- create link
-- EXEC AddBakerPastry @bId, @pId, 'Crispy Shell', 12.00

-- -- raiserror called 
-- EXEC AddBakerPastry @bId, @pId, 'Crispy Shell', 12.00

-- view all data
SELECT * FROM ViewFullMenu



-- insert address
INSERT INTO Addresses VALUES (888, @bId, 'Rome St', 'Rome', 'Italy')
-- delete address
DELETE FROM Addresses WHERE address_id = 888

