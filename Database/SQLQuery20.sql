USE Lebedeva_310;
/*Создать процедуру, вставляющую записи через первое представление
из предыдущего задания. Вставить как минимум 2 записи (т.е. вызвать
процедуру дважды)*/

GO
CREATE PROCEDURE insert_view_1(@price FLOAT, @arrival DATETIME2, @departure DATETIME2)
AS BEGIN
        INSERT INTO flights_10(ticket_price, date_time_arrival, date_time_departure)
		VALUES (@price, @arrival, @departure)
		SELECT * FROM flights_10
END
GO