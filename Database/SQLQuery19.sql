USE Lebedeva_310;
/*������� ������������� �� ������������� � ��������� �����
���������, ������� ������ ����, ���������� ���������
��������� � ����� ������ ������*/

GO
CREATE VIEW view_3 AS SELECT Airline.name_airline, COUNT(Plane_Flight.plane_id) AS '����� ��������',
AVG(Plane.number_of_seats) AS '������� ����� ���� � ��������',
COUNT(DISTINCT Flight.route_id) AS '���������� ��������� ���������',
COUNT(Flight.flight_id) AS '����� ����� ������'
FROM Airline 
	JOIN Flight ON Flight.airline_id = Airline.airline_id
	JOIN Plane_Flight ON Flight.flight_id = Plane_Flight.flight_id
	JOIN Plane ON Plane_Flight.plane_id = Plane.plane_id
	JOIN Route ON Flight.route_id = Route.route_id
GROUP BY Airline.name_airline;