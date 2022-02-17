USE Lebedeva_310;
/*Определить авиакомпании, летающие по 3 и более направлениям*/

SELECT Airline.airline_id, name_airline AS 'Авиакомпания', COUNT(DISTINCT route_id) AS 'Aвиакомпании, летающие по 3 и более направлениям'
FROM Flight, Airline
WHERE Flight.airline_id = Airline.airline_id
GROUP BY name_airline, Airline.airline_id
HAVING COUNT(DISTINCT route_id) >= 3;