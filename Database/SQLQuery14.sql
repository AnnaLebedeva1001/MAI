USE Lebedeva_310;

SELECT DISTINCT name_city_departure
FROM Aircraft_routes;

SELECT aircraft_name
FROM Aircrafts
WHERE NOT aircraft_name IS NULL;

SELECT airline_name
FROM Airlines
WHERE airline_name IS NULL;