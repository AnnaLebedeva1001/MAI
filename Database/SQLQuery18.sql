USE Lebedeva_310;
/*������� ������������� �� ������ � ��������� ��������,
������������ � �������� ����� ���� � ��������*/
GO
CREATE VIEW view_2 AS SELECT Flight.flight_id, Route.departure_city, Route.arrival_city, Airline.name_airline, 
AVG(Plane.number_of_seats) AS '������� ����� ���� � ��������'
FROM Flight
	JOIN Route ON Flight.route_id = Route.route_id
	JOIN Airline ON Flight.airline_id = Airline.airline_id
	JOIN Plane_Flight ON Flight.flight_id = Plane_Flight.flight_id
	JOIN Plane ON Plane_Flight.plane_id = Plane.plane_id
GROUP BY Route.departure_city, Route.arrival_city, Airline.name_airline, Flight.flight_id;
GO
SELECT * FROM view_2;