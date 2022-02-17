USE Lebedeva_310;
/*Для каждой авиакомпании определить количество маршрутов, по
которым совершаются полеты*/
SELECT Airline.airline_id, name_airline AS 'Авиакомпания', COUNT(DISTINCT route_id) AS 'Количество маршрутов для каждой авиакомпании, по которым совершаются полеты'
FROM Flight, Airline
WHERE Flight.airline_id = Airline.airline_id
GROUP BY name_airline, Airline.airline_id;