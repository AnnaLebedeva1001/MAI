USE Lebedeva_310;
/*���������� ������������, �������� �� 3 � ����� ������������*/

SELECT Airline.airline_id, name_airline AS '������������', COUNT(DISTINCT route_id) AS 'A�����������, �������� �� 3 � ����� ������������'
FROM Flight, Airline
WHERE Flight.airline_id = Airline.airline_id
GROUP BY name_airline, Airline.airline_id
HAVING COUNT(DISTINCT route_id) >= 3;