USE Lebedeva_310;
/*¬ывести авиакомпании с указанием количества самолетов,
которые выполн€ют рейсы по 4 различным направлени€м(решила посчитать, что авиакомпании совершающие полЄты по большему количеству направлений,
тоже летают по 4 различным направлени€м, количество самолЄтов как вы и говорили определ€ла по главной таблице с рейсами)*/

SELECT Airline.name_airline AS 'јвиакомпани€',
COUNT(Flight.flight_id) AS ' оличество самолЄтов',
COUNT(DISTINCT Flight.route_id) AS ' оличество направлений'
FROM Airline
	 LEFT JOIN Flight ON Airline.airline_id = Flight.airline_id
	 GROUP BY Airline.name_airline
	 HAVING COUNT(DISTINCT Flight.route_id) >= 4;