USE Lebedeva_310;
/*ќпределить среднюю длину маршрутов дл€ каждой авиакомпании*/
SELECT AVG(route_length) 'Cредн€€ длина маршрутов', airline_id
	FROM Flights, Aircraft_routes
	WHERE Flights.route_id = Aircraft_routes.route_id
	GROUP BY airline_id;
SELECT * FROM Aircraft_routes;