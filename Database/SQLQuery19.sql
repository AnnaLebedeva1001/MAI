USE Lebedeva_310;
/*Создать представление по авиакомпаниям с указанием числа
самолетов, средним числом мест, количества различных
маршрутов и общим числом рейсов*/

GO
CREATE VIEW view_3 AS SELECT Airline.name_airline, COUNT(Plane_Flight.plane_id) AS 'Число самолётов',
AVG(Plane.number_of_seats) AS 'Среднее число мест в самолете',
COUNT(DISTINCT Flight.route_id) AS 'Количество различных маршрутов',
COUNT(Flight.flight_id) AS 'Общее число рейсов'
FROM Airline 
	JOIN Flight ON Flight.airline_id = Airline.airline_id
	JOIN Plane_Flight ON Flight.flight_id = Plane_Flight.flight_id
	JOIN Plane ON Plane_Flight.plane_id = Plane.plane_id
	JOIN Route ON Flight.route_id = Route.route_id
GROUP BY Airline.name_airline;