USE Lebedeva_310;
/*Вывести маршруты с указанием числа рейсов по ним, если рейсов
нет, написать «нет»*/

SELECT Route.departure_city, Route.arrival_city, CAST(COUNT(Flight.route_id) AS VARCHAR(10)) AS 'Число рейсов'
FROM Route
	JOIN Flight ON Route.route_id = Flight.route_id
	GROUP BY Route.departure_city, Route.arrival_city
	UNION
	SELECT Route.departure_city, Route.arrival_city, 'Нет' AS 'Число рейсов'
	FROM Route
	LEFT JOIN Flight ON Route.route_id = Flight.route_id
	GROUP BY Route.departure_city, Route.arrival_city, Flight.route_id
	HAVING COUNT(Flight.route_id) = 0;