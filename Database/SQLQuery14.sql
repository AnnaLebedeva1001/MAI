USE Lebedeva_310;
/*���������� ������������, �� ������� �� ������ ��������*/

SELECT Airline.name_airline AS '������������', COUNT(Flight.flight_id) AS '���������� ��������'
FROM Airline
	LEFT JOIN Flight ON Airline.airline_id = Flight.airline_id
	GROUP BY Airline.name_airline
	HAVING COUNT(Flight.flight_id) = 0;