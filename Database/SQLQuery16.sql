USE Lebedeva_310;
/*���������� ������������, �������� �� 3 � ����� ������������*/
SELECT COUNT(route_id) AS '���������� ��������� ��� �����������', airline_id
	FROM Flights
	GROUP BY airline_id
	HAVING COUNT(route_id) >= 3;

SELECT * FROM Flights;