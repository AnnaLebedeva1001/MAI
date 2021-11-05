USE Lebedeva_310;
/*Для каждой авиакомпании определить количество маршрутов, по
которым совершаются полеты*/
SELECT COUNT(route_id) AS 'Количество маршрутов для авиакомании', airline_id
	FROM Flights
	GROUP BY airline_id;

SELECT * FROM Flights;