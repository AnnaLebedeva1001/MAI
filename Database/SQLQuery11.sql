USE Lebedeva_310;
/*Вывести авиакомпании, имеющие количество рейсов больше среднего
их количества среди всех авиакомпаний*/

SELECT name_airline AS 'Авиакомпания', AVG(Flight.airline_id) AS 'Среднее количество рейсов',
COUNT(Flight.airline_id) AS 'Количество рейсов'
FROM Flight, Airline
WHERE Flight.airline_id = Airline.airline_id
GROUP BY name_airline
HAVING COUNT(Flight.airline_id) > (SELECT AVG(Flight.airline_id))