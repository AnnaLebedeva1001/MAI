USE Lebedeva_310;
/*Определить авиакомпании, летающие по 3 и более направлениям*/
SELECT COUNT(route_id) AS 'Количество маршрутов для авиакомании', airline_id
	FROM Flights
	GROUP BY airline_id
	HAVING COUNT(route_id) >= 3;

SELECT * FROM Flights;