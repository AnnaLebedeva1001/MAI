USE Lebedeva_310;
/*������� ������������ � ��������� ���������� ���������,
������� ��������� ����� �� 4 ��������� ������������(������ ���������, ��� ������������ ����������� ����� �� �������� ���������� �����������,
���� ������ �� 4 ��������� ������������, ���������� �������� ��� �� � �������� ���������� �� ������� ������� � �������)*/

SELECT Airline.name_airline AS '������������',
COUNT(Flight.flight_id) AS '���������� ��������',
COUNT(DISTINCT Flight.route_id) AS '���������� �����������'
FROM Airline
	 LEFT JOIN Flight ON Airline.airline_id = Flight.airline_id
	 GROUP BY Airline.name_airline
	 HAVING COUNT(DISTINCT Flight.route_id) >= 4;