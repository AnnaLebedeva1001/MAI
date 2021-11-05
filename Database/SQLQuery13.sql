USE Lebedeva_310;

SELECT aircraft_name
	FROM Aircrafts
	WHERE aircraft_name LIKE 'B%';
SELECT route_id, name_city_departure
	FROM Aircraft_routes
	WHERE name_city_departure LIKE '%à';
SELECT route_id, name_city_arrival
	FROM Aircraft_routes
	WHERE name_city_arrival LIKE '____à';