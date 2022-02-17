USE Lebedeva_310;
/*Создать процедуру с параметром по умолчанию и выходным
параметром*/

GO
CREATE PROCEDURE insert_route
	@route_id INT OUTPUT,
    @departure_city VARCHAR(50),
    @arrival_city VARCHAR(50),
	@distance FLOAT = 1
AS
    INSERT INTO Route(distance, departure_city, arrival_city)
    VALUES(@distance, @departure_city, @arrival_city)
    SET @route_id = @@IDENTITY
