USE Lebedeva_310;
/*���������� ������� ����� ��������� ��� ������ ������������*/
SELECT AVG(route_length) 'C������ ����� ���������', airline_id
	FROM Flights, Aircraft_routes
	WHERE Flights.route_id = Aircraft_routes.route_id
	GROUP BY airline_id;
SELECT * FROM Aircraft_routes;