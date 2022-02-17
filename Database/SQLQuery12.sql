USE Lebedeva_310;
/*Определить маршруты, по которым выполняется более чем 5 рейсов*/

SELECT Route.route_id, Route.departure_city, Route.arrival_city, COUNT(Flight.route_id) AS 'Количество рейсов для маршрута'
FROM Flight, Route
WHERE Flight.route_id = Route.route_id
GROUP BY Route.route_id, Route.departure_city, Route.arrival_city
HAVING (SELECT COUNT(Flight.route_id)) > 5;