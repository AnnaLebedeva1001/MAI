USE Lebedeva_310;
/*Создать процедуру с параметром по умолчанию и выходным
параметром*/
 
DECLARE @route_id INT
EXEC insert_route  @route_id OUTPUT, 'Екатеринбург', 'Москва'
PRINT @route_id;

SELECT * FROM Route;