USE Lebedeva_310;
/*Получить результат, формируемый третьим представлением
(предыдущего задания) через выполнение нескольких запросов,
объединённых в процедуру*/

GO
CREATE PROCEDURE copy_view_3
AS BEGIN
       SELECT Airline.name_airline, COUNT(Plane_Flight.plane_id) AS 'Число самолётов',
		AVG(Plane.number_of_seats) AS 'Среднее число мест в самолете',
		COUNT(DISTINCT Flight.route_id) AS 'Количество различных маршрутов',
		COUNT(Flight.flight_id) AS 'Общее число рейсов'
		FROM Airline 
			JOIN Flight ON Flight.airline_id = Airline.airline_id
			JOIN Plane_Flight ON Flight.flight_id = Plane_Flight.flight_id
			JOIN Plane ON Plane_Flight.plane_id = Plane.plane_id
			JOIN Route ON Flight.route_id = Route.route_id
		GROUP BY Airline.name_airline;
END
GO