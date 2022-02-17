USE Lebedeva_310;
/*Определить авиакомпании, не имеющие ни одного самолета*/

SELECT Airline.name_airline AS 'Авиакомпания', COUNT(Flight.flight_id) AS 'Количество самолётов'
FROM Airline
	LEFT JOIN Flight ON Airline.airline_id = Flight.airline_id
	GROUP BY Airline.name_airline
	HAVING COUNT(Flight.flight_id) = 0;