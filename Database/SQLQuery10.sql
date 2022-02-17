USE Lebedeva_310;
/*Определить среднюю длину маршрутов для каждой авиакомпании*/

SELECT Airline.airline_id, name_airline AS 'Авиакомпания', AVG(Route.distance) AS 'Среднюю длина маршрутов для каждой авиакомпании'
FROM Flight, Airline, Route
WHERE Flight.airline_id = Airline.airline_id AND Flight.route_id = Route.route_id
GROUP BY name_airline, Airline.airline_id;